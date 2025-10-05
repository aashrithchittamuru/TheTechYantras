# The Tech Yantras: About the team

1. Vatsal : Vatsal is a 15 year old who loves to build and create and has been building since a young age and still continues to do what he loves ​
2. Jeevan: Jeevan is a 14 year old who has developed his skills in designing and hardware. He uses his skills to build the project.​
3. Aashrith: Aashrith is a 15 year old who has a passion for robotics and coding. He has been coding since he was 12 years old.​
4. Krishna: A Coach who is passionate and keen of technology 

# Table Of contents

| S.No | Content
| --- | --- |
| 1. | Introduction
| 2. | Solution
| 3. | Other Ideas & Challenges we can face
| 4. | Social Impact & Other Components
| 5. | Sources

# Project Idea
Description: A broken/cut wire can cause multiple problems to life. If cut during a storm and falls in a puddle of water, any living thing that comes in contact with it, its life is in danger. Every Year more than 14000 people, and many animals and birds are dying due to this in the world. Whenever any animal, birds, humans touches the Phase and Neutral wires they get electrocuted

# Our Solution: Guardian Wire

To implement a system that immediately cuts off electrical supply when the phase and neutral wires come into contact we will make a system which will have all the following features:
1. Current Sensing: Install current sensors on both the phase and neutral wires. These sensors detect the flow of current through the wires and provide feedback to the control system.
2. Control System: Use a microcontroller, such as Arduino, ESP32 to monitor the output of the current sensors. The control system continuously checks for any discrepancy between the currents in the phase and neutral wires.
3. Threshold Detection: Set a threshold for the allowable difference in current between the phase and neutral wires. If the difference exceeds this threshold, it indicates a fault, such as contact between the phase and neutral wires.
4. Relay or Circuit Breaker: Connect a relay or circuit breaker to the output of the control system. When a fault is detected, the control system triggers the relay or circuit breaker to open, cutting off electrical supply to the circuit.
5. Response Time: Ensure that the control system can respond quickly to faults to minimize the duration of the electrical supply interruption. This may involve optimizing the control algorithm and using fast-acting relays or circuit breakers.
6. Testing and Calibration: Test the system extensively to ensure its reliability and effectiveness in detecting faults and cutting off electrical supply when necessary. Calibrate the system parameters, such as the current threshold, to achieve optimal performance.
7. Safety Mechanisms: Implement safety mechanisms to prevent unintended interruptions of electrical supply, such as manual reset switches or override controls.

# Benefits of our project
1. Our project ensures thousands of human lives are saved, especially the ones in rural areas. It also saves animal lives.
2. The project also helps save electricity and ensures its not wasted.
3. It also helps with efficiency where it sends notification to the authorities about the broken wires which is far more efficient than people calling the authorities about the wire after the storm or disaster has taken place. It gives the authorities the number of places that are affected too

# Our hardware

To implement the idea of immediately cutting off electrical supply when the phase and neutral wires come into contact, the solution requires several hardware components. Here's a list of the necessary hardware:
1. Current Sensors: These sensors detect the flow of current through the phase and neutral wires. They are typically Hall effect sensors or current transformers that provide an analog or digital output proportional to the current passing through them.
2. Microcontroller: A microcontroller serves as the brain of the system, responsible for processing sensor data, executing control logic, and activating the cutoff mechanism. we are using Arduino boards and ESP32 boards and cameras to send the notification to power houses. 
3. Relay or Circuit Breaker: A relay or circuit breaker is used to physically interrupt the electrical supply when a fault is detected. It is controlled by the microcontroller and opens the circuit to stop the flow of electricity.
4. Power Supply: A stable power supply is needed to power the microcontroller and other electronic components. This can be a DC power adapter or batteries, depending on the application.
5. Protection Diodes: Diodes may be used to protect the circuit from voltage spikes or reverse polarity conditions. They prevent damage to sensitive components by limiting the voltage or current in the event of an overvoltage or reverse voltage scenario.
6. Enclosure: An enclosure is used to house the electronic components and protect them from environmental factors such as dust, moisture, and physical damage. The enclosure should be designed to provide adequate ventilation and access for maintenance.

# Other ideas we came across

We came up with many ideas, they are unrelated to electricity and we chose to not go with them as we ran into multiple problems and issues:​
1. Coral reef restoration: Where we pick up broken pieces of corals from the sea bed and bring it to nurseries, treat them and plant/place them back in its habitat with corals that are already rooted. ​
2. Desulphurization : In vehicles there is a lot of fuel used to run it . So, In that process ,The burning of sulfur-containing fuels results to getting sulfur dioxide. This sulfur dioxide is released into the atmosphere .And is very harmful for the environment.  But , When we use desulfurization it can completely remove the sulfur from sulfur dioxide and oxygen is released into the air.​
3. Collecting microplastics from water Search and rescue bot which is used after disasters

# Challenges we can face

1. Problem with the circuit, the insulating tester does not work the way we wanted it to. Sending the message/email using iot can be​
2. Slower due to problems like lag or functionality. Implementation on large scale The whole unit might stop providing ​
3. electricity Which in turn might not send electricity to the houses in the ​
4. Village so an alternative to pass electricity can be implemented. We can switch off only the electricity passed through that particular unit.

# Social Impact

The idea of immediately cutting off electrical supply when the phase and neutral wires come into contact can have several significant social impacts:
1. Enhanced Electrical Safety: Implementing such a system can significantly improve electrical safety, reducing the risk of electric shock, electrocution, and electrical fires. This enhances the safety and well-being of individuals, families, and communities, especially in residential areas, workplaces, and public spaces.
2. Protection of Life and Property: By preventing electrical accidents and fires, the system helps protect human lives, property, and valuable assets. It reduces the likelihood of injuries, fatalities, property damage, and financial losses associated with electrical hazards and accidents.
3. Peace of Mind: Knowing that there are measures in place to promptly cut off electrical supply in the event of phase-neutral contact can provide peace of mind to individuals, homeowners, and facility managers. They can feel more confident in the safety and reliability of their electrical systems, reducing anxiety and stress related to potential hazards.
4. Community Resilience: Building resilient communities involves mitigating risks and ensuring the continuity of essential services. By implementing safety measures for electrical infrastructure, communities can enhance their resilience to emergencies, natural disasters, and other disruptions, minimizing the impact on public safety and infrastructure.
5. Accessibility and Inclusion: Improving electrical safety benefits everyone, including vulnerable populations such as children, elderly individuals, people with disabilities, and low-income communities. Ensuring that electrical systems are safe and reliable promotes inclusivity and accessibility to essential services and amenities for all members of society.
6. Educational Opportunities: The implementation of safety systems provides opportunities for education and awareness about electrical safety practices, risks, and preventive measures. Public outreach campaigns, training programs, and community workshops can empower individuals with knowledge and skills to prevent electrical accidents and protect themselves and others.

# Concrete Evidence

1. Consider a densely populated neighborhood in Chennai, India. During a monsoon storm, a strong gust of wind tears down a power line. With your system in place:
2. The cut wire is detected, and electricity flow to the neighborhood substation is automatically shut off.
3. A notification is sent to the local power company, pinpointing the exact location of the downed wire.
4. Repair crews are dispatched immediately, minimizing the risk of electrocution and property damage.
5. Power is restored to the neighborhood much faster than with traditional methods, minimizing disruption for residents and businesses

# Who it helps

1. General Public: Everyone in areas prone to downed wires benefits from the increased safety and faster restoration times. This includes families, children, the elderly, and individuals vulnerable to electrical hazards.
2. Emergency Responders: Firefighters, police officers, and other emergency personnel face reduced risk from downed wires with this system in place.
3. Power Companies: Faster identification and repair of outages improves efficiency and reduces repair costs. Businesses: Minimized power outages benefit businesses by reducing lost productivity and revenue.

# Additional components: Transformer

A transformer is a passive component that transfers electrical energy from one electrical circuit to another circuit, or multiple circuits. Transformers are used to change AC voltage levels, such transformers being termed step-up or step-down type to increase or decrease voltage levels, respectively. Transformers can also be used to provide galvanic isolation between circuits as well as to couple stages of signal-processing circuits. Since the invention of the first constant-potential transformer in 1885, transformers have become essential for the transmission, distribution, and utilization of alternating current electric power.

# GCFI

GFCI stands for Ground Fault Circuit Interrupter. It's an electrical device designed to protect against electric shock by quickly shutting off power to a circuit when it detects that current is flowing along an unintended path, such as through water or a person. This can happen if an electrical appliance falls into water, if there's a frayed wire in a damp location, or if someone accidentally touches a live wire.
GFCIs are commonly found in areas where water and electricity are close together, such as bathrooms, kitchens, outdoor outlets, and garages. They're typically installed in outlets, circuit breakers, or as part of extension cords.
The way GFCIs work is by constantly monitoring the flow of electricity in a circuit. If they detect even a small imbalance in the flow of current (as little as 5 milliamps), they trip the circuit, cutting off power and preventing electric shock. This rapid response is crucial for preventing serious injury or even death in the event of a ground fault.

# Even when GFCIs are present, There are so many problems which can occur for example

1. Tripping Frequently: GFCIs may trip frequently due to various reasons such as overloading, faulty wiring, or a ground fault. Identifying the cause of frequent tripping is essential. It could be a malfunctioning appliance, water leakage, or wiring issues. Resetting the GFCI and investigating the root cause is necessary to prevent future occurrences.
2. Aging and Wear: Over time, GFCIs can wear out or become less sensitive, reducing their effectiveness. Regular testing of GFCIs is essential to ensure they are functioning correctly. If an older GFCI is found to be less reliable, it should be replaced.
3. Moisture and Corrosion: GFCIs installed in outdoor or damp environments are susceptible to moisture and corrosion, which can affect their performance. Regular inspection and maintenance, including cleaning and tightening connections, can help prevent issues related to moisture and corrosion.
4. Improper Installation: Incorrect installation can lead to GFCIs not functioning as intended. It's crucial to follow manufacturer instructions and local electrical codes when installing GFCIs. Hiring a qualified electrician to install or inspect GFCIs ensures proper installation and compliance with safety standards.

# Sources

1. Times Of India
2. Electrical Safety Foundation International (ESFI): Website: ESFI
3. Spoke to Power supply stations communicated with Electricians and senior Engineers
4. Quara.com
