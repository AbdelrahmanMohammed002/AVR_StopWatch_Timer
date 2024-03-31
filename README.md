Stop Watch System Readme
Description
This project implements a Stop Watch system using an ATmega32 microcontroller. The Stop Watch system utilizes Timer1 in CTC mode to count time, and it features six Common Anode 7-segment displays multiplexed using a 7447 decoder. The system allows starting, pausing, and resuming the Stop Watch functionality through external interrupts connected to push buttons.

Hardware Components
ATmega32 Microcontroller (1 MHz)
Six Common Anode 7-segment displays
7447 decoder for multiplexing
NPN BJT transistors for enabling/disabling 7-segments
Push buttons for external interrupts (INT0, INT1, INT2)
Functionality
Start/Stop: The Stop Watch automatically starts counting upon power connection to the microcontroller.
Reset: Pressing a push button connected to INT0 with a falling edge resets the Stop Watch time.
Pause: Pressing a push button connected to INT1 with a rising edge pauses the Stop Watch time.
Resume: Pressing a push button connected to INT2 with a falling edge resumes the Stop Watch time.
Wiring Diagram

Usage
Connect the hardware components according to the provided wiring diagram.
Upload the firmware to the ATmega32 microcontroller.
Power on the microcontroller to start the Stop Watch.
Use the push buttons to control the Stop Watch functionality (reset, pause, resume).
Note
Make sure to adjust the pin configurations in the code according to your wiring setup.
Refer to the datasheets of the components for detailed pinouts and specifications.
Author
Abdelrahman (Ta'laab) Mohammed
GitHub: AbdelrahmanMohammed002




