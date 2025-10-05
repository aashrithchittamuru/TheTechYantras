#include <WiFi.h>

#include <ESP_Mail_Client.h>

#define WIFI_SSID "Roboprenr_HSR"

#define WIFI_PASSWORD "Robop@123"

#define SMTP_server "smtp.gmail.com"

#define SMTP_Port 465

#define sender_email "esp32testroboprenr@gmail.com"

#define sender_password "ucru xrgf zjqm nptu"

#define Recipient_email "jeevansakthi2020@gmail.com"

#define Recipient_name "Jeevan"
int a = 0;
float threshold = 0;

SMTPSession smtp;

  ESP_Mail_Session session;
  SMTP_Message message;

void setup() {
Serial.begin(9600);
  pinMode(35, INPUT);
  pinMode(32, OUTPUT);  //relay
  digitalWrite(32, LOW);
  delay(5000);
  Serial.println("Sample collection started...");
  for (int i = 0; i <= 99; i++) {
    unsigned int x = 0;
    double AcsValue = 0.0, Samples = 0.0, AvgAcs = 0.0;

    for (int x = 0; x < 9800; x++) {
      AcsValue = analogRead(35);
      Samples = Samples + pow(AcsValue, double(2));
      delayMicroseconds(1);
    }
    AvgAcs = pow(Samples / double(9800.0), double(1.0 / 2.0));
    AvgAcs /= 10;
    threshold = threshold + AvgAcs;
    Serial.print(i + 1);
    Serial.println(" samples collected...");
  }
  threshold = threshold / 100;
  Serial.println(threshold);


  Serial.println();

  Serial.print("Connecting...");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)

  { Serial.print(".");

    delay(200);

   }

ESP_Mail_Session session;
  SMTP_Message message;
  Serial.println("");

  Serial.println("WiFi connected.");

  Serial.println("IP address: ");

  Serial.println(WiFi.localIP());

}

void loop() {
  
  unsigned int x = 0;
  double AcsValue = 0.0, Samples = 0.0, AvgAcs = 0.0;

  for (int x = 0; x < 9800; x++) {
    AcsValue = analogRead(35);
    Samples = Samples + pow(AcsValue, double(2));
    delayMicroseconds(1);
  }
  AvgAcs = pow(Samples / double(9800.0), double(1.0 / 2.0));
  AvgAcs /= 10;
  Serial.println(AvgAcs);

  // Values for smaller bulb
  if (abs(AvgAcs - threshold) > 2) {

    digitalWrite(32, HIGH);  //relay bulb off
  

    message.text.charSet = "us-ascii";
      message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

  session.server.host_name = SMTP_server ;

  session.server.port = SMTP_Port;

  session.login.email = sender_email;

  session.login.password = sender_password;

     message.sender.email = sender_email;

     message.sender.name = "Pole_1";

      message.subject = "Electrical Pole Damaged";

      message.addRecipient(Recipient_name,Recipient_email);


      String htmlMsg = "<div style=\"color:#000000;\"><h1>In your area, the electrical poles have been damaged due to which there is a power cut in that area.<br> Please get it fixed at earliest.</h1><p>Mail sent by Electric Pole at Roboprenr Makerlab</p></div>";
          message.html.content = htmlMsg.c_str();
            session.login.user_domain = "";
  Serial.println();

  smtp.debug(1);

  if (!smtp.connect(&session)){

    return;

    }


  if (!MailClient.sendMail(&smtp, &message)){

    Serial.println("Error sending Email, ");
    Serial.println(smtp.errorReason());

  }

  

  delay(50);
}
}
