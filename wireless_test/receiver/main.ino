//nrf2401 receiver
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 nrf(9, 8);  // CE, CSN
const byte linkAddress[6] = "00001";  //address through which two modules communicate.
const byte greenLED = 2;
float data[3];
/////////////////////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600); 
  Serial.println("Starting");
  pinMode(greenLED, OUTPUT);
 
  nrf.begin();    
  nrf.openReadingPipe(0, linkAddress);  //set the address 
  nrf.startListening();   //Set nrf as receiver
}
///////////////////////////////////////////////////
void loop()
{
//    digitalWrite(greenLED, HIGH);
   delay(50);
//    digitalWrite(greenLED, LOW);
   delay(50);
   
   if (nrf.available())  //Read the data if available in buffer
     {
    digitalWrite(greenLED, LOW);
    // digitalWrite(greenLED, HIGH);
      nrf.read(&data, sizeof(data));
     Serial.print(data[0]); Serial.print("hPa  ");
     Serial.print(data[1]); 
     Serial.write(0xC2);  //send degree symbol
     Serial.write(0xB0);  //send degree symbol
     Serial.print("C   ");  
     Serial.print(data[2]); Serial.println("m");  
     }  
}
//////////////////////////////////////////////