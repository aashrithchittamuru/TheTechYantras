//#include<SoftwareSerial.h>

static int8_t Send_buf[8] = {0} ;

#define CMD_PLAY_W_INDEX 0X03
#define CMD_SET_VOLUME 0X06
#define CMD_SEL_DEV 0X09
#define DEV_TF 0X02
#define CMD_PLAY 0X0D
#define CMD_PAUSE 0X0E
#define CMD_SINGLE_CYCLE 0X19
#define SINGLE_CYCLE_ON 0X00
#define SINGLE_CYCLE_OFF 0X01
#define CMD_PLAY_W_VOL 0X22


#include "time.h"
#include "esp_sntp.h"
#include "SPI.h"
#include <WebServer.h>
#include <WiFi.h>
#include <esp32cam.h>
static auto loRes = esp32cam::Resolution::find(320, 240);
static auto midRes = esp32cam::Resolution::find(350, 530);
static auto hiRes = esp32cam::Resolution::find(800, 600);
const char *WIFI_SSID = "Roboprenr_HSR";
const char *WIFI_PASS = "Robop@123";
const char *ntpServer1 = "pool.ntp.org";
const char *ntpServer2 = "time.nist.gov";
const long gmtOffset_sec = 19800;
const int daylightOffset_sec = 0;
const char *time_zone = "CET-1CEST,M3.5.0,M10.5.0/3";

WebServer server(80);
void setup() {
  Serial.begin(9600);
  sendCommand(CMD_SEL_DEV, DEV_TF);
  Serial.println();
  pinMode(14, OUTPUT);  // buzzer
  pinMode(4, OUTPUT);   // flashlight of esp32 cam
  // digitalWrite(13, HIGH);
  digitalWrite(14, HIGH);
  using namespace esp32cam;
  Config cfg;
  cfg.setPins(pins::AiThinker);
  cfg.setResolution(hiRes);
  cfg.setBufferCount(2);
  cfg.setJpeg(80);

  bool ok = Camera.begin(cfg);
  Serial.println(ok ? "CAMERA OK" : "CAMERA FAIL");

  WiFi.mode(WIFI_STA);  //Set Wi-Fi Mode as station
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  esp_sntp_servermode_dhcp(1);
  Serial.println("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.print("http://");
  Serial.println(WiFi.localIP());
  Serial.println("  /cam-lo.jpg");
  Serial.println("  /cam-hi.jpg");
  Serial.println("  /cam-mid.jpg");

  server.on("/cam-lo.jpg", handleJpgLo);
  server.on("/cam-hi.jpg", handleJpgHi);
  server.on("/cam-mid.jpg", handleJpgMid);

  server.on("/person-detected", personDetected);
  server.on("/bird-detected", birdDetected);
  server.on("/test", fun);


  sntp_set_time_sync_notification_cb(timeavailable);
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer1, ntpServer2);

  server.begin();
}

void printLocalTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("No time available (yet)");
    return;
  }
  if (timeinfo.tm_hour >= 18 || timeinfo.tm_hour <= 5) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }
  //Serial.println(timeinfo.tm_hour);
}

void timeavailable(struct timeval *t) {
  Serial.println("Got time adjustment from NTP!");
  printLocalTime();
}

void initWiFi() {
  WiFi.mode(WIFI_STA);  //Set Wi-Fi Mode as station
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  Serial.println("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
}
void serveJpg() {
  auto frame = esp32cam::capture();
  if (frame == nullptr) {
    //Serial.println("CAPTURE FAIL");
    server.send(503, "", "");
    return;
  }
  //Serial.printf("CAPTURE OK %dx%d %db\n", frame->getWidth(), frame->getHeight(),
  //              static_cast<int>(frame->size()));

  server.setContentLength(frame->size());
  server.send(200, "image/jpeg");
  WiFiClient client = server.client();
  frame->writeTo(client);
}

void handleJpgLo() {
  if (!esp32cam::Camera.changeResolution(loRes)) {
    //Serial.println("SET-LO-RES FAIL");
  }
  serveJpg();
}

void handleJpgHi() {
  if (!esp32cam::Camera.changeResolution(hiRes)) {
    //Serial.println("SET-HI-RES FAIL");
  }
  serveJpg();
}

void handleJpgMid() {
  if (!esp32cam::Camera.changeResolution(midRes)) {
    //Serial.println("SET-MID-RES FAIL");
  }
  serveJpg();
}

void personDetected() {
  server.send(200, "done");
  sendCommand(CMD_PLAY_W_VOL, 0X1E01);
  delay(5000);
}

void birdDetected() {
  server.send(200, "done");
  sendCommand(CMD_PLAY_W_VOL, 0X1E01);
  delay(5000);
}

void fun() {
  server.send(200, "tested");
}


void sendCommand(int8_t command, int16_t dat)
{
  delay(20);
  Send_buf[0] = 0x7e; //starting byte
  Send_buf[1] = 0xff; //version
  Send_buf[2] = 0x06; //the number of bytes of the command without starting byte and ending byte
  Send_buf[3] = command; //
  Send_buf[4] = 0x00;//0x00 = no feedback, 0x01 = feedback
  Send_buf[5] = (int8_t)(dat >> 8);//datah
  Send_buf[6] = (int8_t)(dat); //datal
  Send_buf[7] = 0xef; //ending byte
  for (uint8_t i = 0; i < 8; i++) //
  {
    Serial.write(Send_buf[i]) ;
  }
}

void loop() {
  printLocalTime();
  server.handleClient();
}
