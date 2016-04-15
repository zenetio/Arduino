/********************************************************************************************
 Led controller
  Turns a LED on/off using the serial monitor.
  Coursera course: LED controller.

  Description: The program allows the user to control the LED connected to pin 13 of the Arduino. 
  When the program is started, the LED goes to off. The user can open the serial monitor to communicate 
  with the Arduino. If the user sends the character '1' through the serial monitor then the LED is turned on. 
  If the user sends the character '0' through the serial monitor then the LED is turned off.
  
  modified 11 Mar 2016
  by Carlos Roberto
 */

#define pinLED 13     // define the pin to use
#define baud 9600     // define the baud rate
int bytenum;
int bval;

//** the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin as an output.
  pinMode(pinLED, OUTPUT);
  // initialize serial
  Serial.begin(baud);
  // set led to start in off
  digitalWrite(pinLED, LOW);
}

//** Update the led and send mesg to serial
void updateLed(int status, char* mesg)
{
  digitalWrite(pinLED, status);
  Serial.println(mesg);
}

//** the loop function runs over and over again forever
void loop() {

  bytenum = Serial.available();
  
  if(bytenum)
  {
    bval = -1;
    bval = Serial.read();
    if(bval == '1')
      updateLed(HIGH, "Led is On");    // make led on
    else if(bval == '0')
      updateLed(LOW, "Led is Off");    // make led off
  }
  delay(1000);
}
