/*
SparkFun Inventor's Kit
Example sketch 02

POTENTIOMETER

  Measure the position of a potentiometer and use it to
  control the blink rate of an LED. Turn the knob to make
  it blink faster or slower!

What's a potentiometer?

  A potentiometer, or "pot" for short, is a control knob.
  It's the same type of control you'd use to change volume, 
  dim a lamp, etc. A potentiometer changes resistance as it
  is turned. By using it as a "voltage divider", the Arduino
  can sense the position of the knob, and use that value to
  control whatever you wish (like the blink rate of an LED,
  as we're doing here).
	
Hardware connections:

  Potentiometer:
	
    Potentiometers have three pins. When we're using it as a
    voltage divider, we connect the outside pins to power and
    ground. The middle pin will be the signal (a voltage which
    varies from 0 Volts to 5 Volts depending on the position of
    the knob).

    Connect the middle pin to ANALOG IN pin 0 on the Arduino.
    Connect one of the outside pins to 5V.
    Connect the other outside pin to GND.

    (TIP: if once your program is running, the knob feels
    "backwards", you can swap the 5V and GND pins to reverse
    the direction.)
		
  LED:

    Most Arduinos already have an LED and resistor connected to
    pin 13, so you may not need any additional circuitry.

    But if you'd like to connect a second LED to pin 13, or use
    a different pin, follow these steps:

      Connect the positive side of your LED (longer leg) to
      Arduino digital pin 13 (or another digital pin, but don't
      forget to change the code to match).
      
      Connect the negative side of your LED (shorter leg) to a
      330 Ohm resistor (orange-orange-brown).
      
      Connect the other side of the resistor to ground.

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
*/


// Welcome back! In this sketch we'll start using "variables".

// A variable is a named number. We'll often use these to store
// numbers that change, such as measurements from the outside
// world, or to make a sketch easier to understand (sometimes a
// descriptive name makes more sense than looking at a number).

// Variables can be different "data types", which is the kind of
// number we're using (can it be negative? Have a decimal point?)
// We'll introduce more data types later, but for the moment we'll
// stick with good old "integers" (called "int" in your sketch).

// Integers are whole numbers (0, 3, 5643), can be negative, and
// for reasons we won't go into right now, can range from -32768
// to 32767. (Don't worry, if you need to work with larger numbers,
// there are other data types for that. See:
// http://arduino.cc/en/Reference/VariableDeclaration
// for a list of all the data types you can use).

// You must "declare" variables before you use them, so that the
// computer knows about them. Here we'll declare two integer
// variables, and at the same time, initialize them to specific
// values. We're doing this so that further down, we can refer to
// the pins by name rather than number.

// Note that variable names are case-sensitive! If you get an
// "(variable) was not declared in this scope" error, double-check
// that you typed the name correctly.

// Here we're creating a variable called "sensorPin" of type "int"
// and initializing it to have the value "0":
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "RTClib.h"
RTC_PCF8523 rtc;
const int chipSelect = 10;
int sensorPin1 = 0;    // The potentiometer is connected to
                      // analog pin 0
int sensorPin2 = 1;
int sensorPin3 = 2;
int sensorPin4 = 3;
                      

// One more thing. If you declare variables outside of a function,
// as we have here, they are called "global variables" and can be
// seen by all the functions. If you declare variables within a 
// function, they can only be seen within that function. It's good
// practice to "limit the scope" of a variable whenever possible,
// but as we're getting started, global variables are just fine.


void setup() // this function runs once when the sketch starts up
{
  // We'll be using pin 13 to light a LED, so we must configure it
  // as an output.
 
  // Because we already created a variable called ledPin, and
  // set it equal to 13, we can use "ledPin" in place of "13".
  // This makes the sketch easier to follow.
    Serial.begin(9600);
	 if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.initialized()) {
    Serial.println("RTC is NOT running!");
}

  Serial.begin(57600);  // sets the serial port to 9600
   while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");

}


void loop() // this function runs repeatedly after setup() finishes
{
  // First we'll declare another integer variable
  // to store the value of the potentiometer:

  int sensorValue1;
  int sensorValue2;
  int sensorValue3;
  int sensorValue4;

  // The potentiometer is set up as a voltage divider, so that
  // when you turn it, the voltage on the center pin will vary
  // from 0V to 5V. We've connected the center pin on the
  // potentiometer to the Arduino's analog input 0.

  // The Arduino can read external voltages on the analog input
  // pins using a built-in function called analogRead(). This
  // function takes one input value, the analog pin we're using
  // (sensorPin, which we earlier set to 0). It returns an integer
  // number that ranges from 0 (0 Volts) to 1023 (5 Volts).
  // We're sticking this value into the sensorValue variable:

  sensorValue1 = analogRead(sensorPin1);   
  sensorValue2 = analogRead(sensorPin2); 
  sensorValue3 = analogRead(sensorPin3);   
  sensorValue4 = analogRead(sensorPin4); 
  
  // Now we'll blink the LED like in the first example, but we'll
  // use the sensorValue variable to change the blink speed
  // (the smaller the number, the faster it will blink).

  // Note that we're using the ledPin variable here as well:
  int sensorValue = analogRead(A0);
  float voltage1 = sensorValue1 * (5.0 / 1023.0);
  float voltage2 = sensorValue2 * (5.0 / 1023.0);  
  float voltage3 = sensorValue3 * (5.0 / 1023.0);
  float voltage4 = sensorValue4 * (5.0 / 1023.0);  
  //digitalWrite(ledPin, HIGH);     // Turn the LED on

  delay(5000);             // Pause for sensorValue
                                  // milliseconds
    DateTime now = rtc.now();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.print("  ");
    Serial.print("Voltage 1: ");
    Serial.print(voltage1*4.3);
    Serial.print("  UV Level:  ");
    Serial.print(voltage1/.1);
    Serial.print("  Voltage 2: ");
    Serial.print(voltage2*4.3);
    Serial.print("  UV Level:  ");
    Serial.print(voltage2/.1);
    Serial.print("Voltage 3: ");
    Serial.print(voltage3*4.3);
    Serial.print("  UV Level:  ");
    Serial.print(voltage3/.1);
    Serial.print("  Voltage 4: ");
    Serial.print(voltage4*4.3);
    Serial.print("  UV Level:  ");
    Serial.println(voltage4/.1);
 File dataFile = SD.open("datalog.txt", FILE_WRITE);
     if (dataFile) {
    dataFile.print(now.year(), DEC);
    dataFile.print('/');
    dataFile.print(now.month(), DEC);
    dataFile.print('/');
    dataFile.print(now.day(), DEC);
    dataFile.print(" (");
    dataFile.print(") ");
    dataFile.print(now.hour(), DEC);
    dataFile.print(':');
    dataFile.print(now.minute(), DEC);
    dataFile.print(':');
    dataFile.print(now.second(), DEC);
    dataFile.print("  ");
    dataFile.print("Voltage 1: ");
    dataFile.print(voltage1*4.3);
    dataFile.print("  UV Level:  ");
    dataFile.print(voltage1/.1);
    dataFile.print("  Voltage 2: ");
    dataFile.print(voltage2*4.3);
    dataFile.print("  UV Level:  ");
    dataFile.print(voltage2/.1);
    dataFile.print("Voltage 3: ");
    dataFile.print(voltage3*4.3);
    dataFile.print("  UV Level:  ");
    dataFile.print(voltage3/.1);
    dataFile.print("  Voltage 4: ");
    dataFile.print(voltage4*4.3);
    dataFile.print("  UV Level:  ");
    dataFile.println(voltage4/.1);
    dataFile.close();
  //digitalWrite(ledPin, LOW);      // Turn the LED off

  //delay(5000);             // Pause for sensorValue
                                  // milliseconds
  
  // Remember that loop() repeats forever, so we'll do all this
  // again and again.
     }}
