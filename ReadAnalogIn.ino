/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The photoresistor will change the analog value in the input.
 
 The circuit:
 * Photoresistor attached to analog input 0
 * output  pin of the photoresistor to the analog pin
 * other pin to ground
 * other pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.

 Created by Carlos R Lacerda
  This example code is in the public domain.

 https://youtu.be/v7kvMEdjLxA

 */

int sensorPin = A0;     // select the input pin for the photoresistor
int ledPin = 13;        // select the pin for the LED
int sensorValue = 0;    // variable to store the value coming from the sensor
float voltageValue = 0; // variable to store the voltage
#define baud 9600       // define the baud rate

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  // initialize serial
  Serial.begin(baud);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  voltageValue = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltageValue);
  if(voltageValue > 2.0)
    // turn the ledPin on
    digitalWrite(ledPin, HIGH);
  else
    // turn the ledPin off
    digitalWrite(ledPin, LOW);
  // stop the program for for 200 milliseconds:
  delay(200);
  //Serial.println(voltageValue);
}
