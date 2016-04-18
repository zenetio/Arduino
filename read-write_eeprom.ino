/*
 * Author: Carlos R Lacerda
 * Date: Abr/17/2016
 *
 * Description: The scketch allows the user to read a memory address ou write 
 *              a value to a memory address. The user is prompted to pass
 *              the read or write command.
 *
 */

#include <EEPROM.h>

int address=0;
int value=0;
String addressAndValue;

//-------------------------------------------------------------
void printInfo(int addr, int val)
{
	Serial.print(addr);
    Serial.print("\t");
    Serial.print(val, DEC);
    Serial.println(); 
  	Serial.println();
}

//-------------------------------------------------------------
String getValueBySeparator(String data, char separator, int index)
{
	int found = 0;
  	int strIndex[] = {0, -1  };
  	int maxIndex = data.length()-1;
    for(int i=0; i <= maxIndex && found <= index; i++){
      if(data.charAt(i) == separator || i == maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
      }
    }
  	return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

//-------------------------------------------------------------
void doReadMemory(int addr)
{
	value = EEPROM.read(addr);
    printInfo(addr, value);
}

//-------------------------------------------------------------
void doWriteMemory(int addr, int val)
{
	EEPROM.write(addr,val);
  	val = EEPROM.read(addr);
    printInfo(addr, val);  
}

//-------------------------------------------------------------
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial monitor
  Serial.begin(9600);
}

//-------------------------------------------------------------
// the loop routine runs over and over again forever:
void loop() {
  
  Serial.println("Please enter \n'read address'\n to read an address or \n'write address value'\n to write a value to memory.\n"); //Prompt User for address and value input
  while (Serial.available()==0) { }            //Wait for user input
  
  // get the command from the user
  addressAndValue = Serial.readString(); 
  addressAndValue.trim();
  int len = addressAndValue.length();
  int idx = addressAndValue.indexOf(' ');
  // check if is valid
  if(len > 0 && idx != -1)
  {
    String cmd  = getValueBySeparator(addressAndValue, ' ', 0);
    String val1 = getValueBySeparator(addressAndValue, ' ', 1);
    String val2 = getValueBySeparator(addressAndValue, ' ', 2);
    
    cmd.trim();
    cmd.toUpperCase();
    val1.trim();
   	address = val1.toInt();
    if(cmd == "READ"){
      	doReadMemory(address);
    }
    else if(cmd == "WRITE"){
    	val2.trim();
   		value = val2.toInt();
    	doWriteMemory(address, value);  
    }
    
  }
}