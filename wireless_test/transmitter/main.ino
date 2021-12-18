//nrf2401 transmitter:
// #include "DHT.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
// #define DHTPIN 2
// #define DHTTYPE DHT11
RF24 nrf(9, 8);  // CE, CSN

// DHT dht(DHTPIN, DHTTYPE);

const byte linkAddress[6] = "00001";

float humidity;
float temperature;  
float heatIndex; 
float data[3];
char charVal[17];
////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600);
  Serial.println("NRF24L01 link");
  nrf.begin();   
//   dht.begin();
  nrf.openWritingPipe(linkAddress);  //set the address 
  //nrf.setPALevel(RF24_PA_LOW);   //keep tx level low to stop psu noise, can remove this but then put in decoupling caps
  // Options are: RF24_PA_MIN=-18dBm, RF24_PA_LOW=-12dBm,  RF24_PA_HIGH=0dBm.
  nrf.setPALevel(RF24_PA_MIN); 
  nrf.stopListening();  //act as a transmitter
}
///////////////////////////////////////////////////
void loop()
{  
//  humidity = dht.readHumidity();
//  temperature = dht.readTemperature(true);
//  heatIndex = dht.computeHeatIndex(temperature, humidity);

 humidity = 10.0;
 temperature = 11.0;
 heatIndex = 12.0;
  
 data[0] = humidity;
 data[1] = temperature;
 data[2] = heatIndex;
//  ----- display on local monitor: ------------
 Serial.print("Humidity: ");
 Serial.print(data[0]);
 Serial.print("% ");
 Serial.print("Temp: ");
 Serial.print(data[1]); 
 Serial.write(0xC2);  //send degree symbol
 Serial.write(0xB0);  //send degree symbol
 Serial.print("F   ");  
 Serial.print("Heat Index: ");
 Serial.print(data[2]);
 Serial.write(0xC2);  //send degree symbol
 Serial.write(0xB0);  //send degree symbol
 Serial.println("F   ");  
//  ---------------------------------------------
 
  nrf.write(data, sizeof(data)); //spit out the data array
  
  delay(300);
}
/////////////////////////////////////////////////