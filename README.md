# CPE301 Final Project - Spring '25

**Thomas Kelly**

## Project Description:

This project involves the simulation of a swamp cooler using an Arduino microcontroller as well as several inputs and sensors. The system relies on temperature & humidity sensing, water level readings, motors to control the fan and its direction, input buttons, and an LCD and four LEDs to communicate the system's status to the user. Starting from a disabled state with a yellow LED indicating the system's status, the user can enable the system with a press of the on/off button and a green status LED will turn on. From here, when the temperature reaches a certain level the fan will automatically kick on and a blue status LED will turn on. When the temperature falls under the desired level, the fan automatically shuts off, the blue LED shuts off and the green LED turns back on. While monitoring the temperature, the temp and humidity readings will be displayed on the LCD. If the system detects that it has run out of water it will display an error to the user along with a red status LED, requiring him to press the reset button to return to its idle state, where it will again monitor the ambient temperature.

## Component Details:

* [Arduino ATMega 2560 Microcontroller](https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/DataSheets/ATmega640-1280-1281-2560-2561-Datasheet-DS40002211A.pdf)  
  This is the "brain" of this system. This is where the program is flashed and the cooler is controlled by this board. All inputs and outputs run through this board.  
* [1602 LCD](https://www.openhacks.com/uploadsproductos/eone-1602a1.pdf)  
  This is the display used to show the user the temperature and humidity levels, as well as any errors that occur.  
* [External Power Supply Board](https://handsontec.com/dataspecs/mb102-ps.pdf)  
  This board provides 3.3v and 5v power from an external source, keeping load off of the Arduino itself.  
* [Water Level Sensor](https://www.datasheethub.com/arduino-water-level-sensor/)  
  This sensor is used to check and report the water levels in the cooler.  
* [Real Time Clock](https://www.analog.com/media/en/technical-documentation/data-sheets/DS1307.pdf)  
  This clock is used to keep track of the time for logging events and errors.  
* [DHT11 Temperature/Humidity Sensor (3-pin)](https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf)  
  This sensor reports the ambient temperature and humidity.  
* [28BYJ Stepper Motor with Controller](https://www.mouser.com/datasheet/2/758/stepd-01-data-sheet-1143075.pdf)  
  This stepper motor is used to control the angle of ducting, and control the flow of air. This is run through a stepper motor controller.  
* [Brushless DC Motor with Fan](https://media.digikey.com/pdf/Data%20Sheets/DFRobot%20PDFs/FIT0441_Web.pdf)  
  This is the cooler's fan. It is run through a motor driver.
* 3x 4-pin Buttons  
  These buttons are used to give the user control over the system. These buttons allow for on/off, reset, and duct control.
* Potentiometer  
  This is used to control the LCD's backlight.
* 4x LED  
  Four LEDs were used to indicate the cooler's status to the user (blue, green, yellow, red).  

## Project Constraints:

The control over the stepper motor, used to simulate fan ducting, was limited to simple on/off with a single button. This simplified the required logic for the system. However, an additional button could be added to allow for a reverse operation to allow for faster control over moving the ducts to the desired location.  

## Cooler Circuit:

![cooler-circuit](https://github.com/user-attachments/assets/d3ae8947-58fc-41fe-8e08-6346f4b3c264)

## Schematic Diagram:

![circuit-diagram](https://github.com/user-attachments/assets/0b362eed-94be-4b23-bfeb-71d3dc93c86e)

## System Demonstration:

**System in operation: [(video)](https://nevada-my.sharepoint.com/:f:/g/personal/thomaskelly_unr_edu/ErPt6ememExJrShr4saoSN4B4aUR435HmLiymOVB9IwCDQ?e=nD5ACh)**  
**[Additional system images](https://nevada-my.sharepoint.com/:f:/g/personal/thomaskelly_unr_edu/ErPt6ememExJrShr4saoSN4B4aUR435HmLiymOVB9IwCDQ?e=nD5ACh)**
