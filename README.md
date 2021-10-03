# R3-SoftwareTask1-Dix_Paulson
 Wiring 2, 7-segment displays to an Arduino using 2 BCD to 7-segment decoders along with a potentiometer and then programming the 2 7-segment displays to display a number between 0 and 99 based on the potentiometer's output/position
 
**Potentiometer**
The potentiometer values range from 0 to 1023. The analog signals from the potentiometer is fed to the analog input "A0" pin of the arduino. 

**Arduino UNO**
Arduino Uno fetches the analog input signal from the potentiometer (A0 pin) ranging between 0 to 1023.
This value is then mapped to a value ranging from 0 to 99. 
The obtained number is split to two separate digits. The number in the unit place is found by calculating the remainder after dividing by 10 and the number in the ten's place is found by calculating the quotient after dividing by 10. The two separated digits are outputted to the two 7-segmented displays using eight output pins (pins 6 to 13) of the Arduino UNO.
 
 **CD4511**
 The microchip uses the output coming from the 4 Arduino Uno pins to light the 7-segment display according to the potentiometer. 8 output pins labelled a-g is connected to the 7-segmented display. The power, lamp test and the blank pins of the CD4511 are kept at high while the latch enable and groupnd pins are kept low.
 
 **7-Segment Display**
 The 7-segment display is connected to the CD4511 with the resistors in between. The labelled pins (a to g) of the 7-segment display are connected to the corresponding pins of CD4511. One of the common pins is kept low by connecting to the ground.
 
 **Code**
 The code uses two functions display1 and display2 to convert the digit which is then supplied to CD4511 and then to the 7-segment display.
 
 TinkerCAD link: https://www.tinkercad.com/things/bx41dNNaUS0
 
 
![Circuit Diagram](https://user-images.githubusercontent.com/89948982/135772672-e83e9d27-2d5f-47cd-981c-4fa81a46996d.PNG)
