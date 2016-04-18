/*
 LED dimmer with Analog Input
 Reading a potentiometer connected to an analog input and writing the value to
 pin 9 where there is a LED. The value in pin 9 will progressivelly increase the
 led brightness as a dimmer. The input and output are done using 
 analogRead() and analogWrite().
 
 The circuit:
 * Potentiometer of 10 km attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 9
 * LED cathode (short leg) attached to ground

 Created by Carlos R Lacerda
 in 18 Apr 2016
 
 This example code is in the public domain.

 https://www.youtube.com/watch?v=hn74PTh3voY

 */

int sensorPin = A0;     // select the input pin for the potentiometer
int ledPin = 9;         // select the pin for the LED
int sensorValue = 0;    // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // read the analog value from the input:
  sensorValue = analogRead(sensorPin);
  // Convert the analog reading (which goes from 0 - 1023) to analog value (0 - 255):
  analogWrite(ledPin,sensorValue/4);  
  //Serial.println(sensorValue/4);
  // stop the program for 50 milliseconds:
  delay(50);
}
