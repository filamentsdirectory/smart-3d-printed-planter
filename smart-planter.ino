/*
 *     This program is free software: you can redistribute it and/or modify 
 *     it under the terms of the GNU General Public License as published by 
 *     the Free Software Foundation, either version 3 of the License, or 
 *     (at your option) any later version. 
 *     
 *     This program is distributed in the hope that it will be useful, 
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 *     GNU General Public License for more details.
 *     
 *     You should have received a copy of the GNU General Public License 
 *     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 *     Design by Agustin Flowalistik http://www.flowalistik.com/
 *     IOT by Gauthier de Valensart https://www.filaments.directory
 *     
 *     Version 1.0a0 08/03/2017
 *     Compiled with Arduino 1.8.1
 *     
 *     Dependencies :
 *     Board library http://arduino.esp8266.com/versions/2.3.0/package_esp8266com_index.json
 *     Libraries : Adafruit Unified Sensor 1.0.2, Adafruit IO Arduino 1.0.1
 *    
 *     Based on Adafruit HUZZAH ESP8266 board https://cdn-learn.adafruit.com/downloads/pdf/adafruit-feather-huzzah-esp8266.pdf
 *     Sensor design from  http://gardenbot.org/howTo/soilMoisture/
 *     Low power code from  https://openhomeautomation.net/esp8266-battery/
 */

#define DEBUGGING(...) Serial.println( __VA_ARGS__ )
#define DEBUGGING_L(...) Serial.print( __VA_ARGS__ )

#include <ESP8266WiFi.h>
#include "Adafruit_IO_Client.h"

#define voltageFlipPin1 12
#define voltageFlipPin2 14
#define sensorPin A0

/* Configuration */
const char* aio_key  = "PleaseChangeThisWithYourAPIKey"; // Adafruit Key
const char* ssid     = "Planter"; // Wifi SSID
const char* password = "FilamentsDirectory"; // Wifi key

/* Do not modify anything below if you are unsure */
const int sleepTimeS = 15*60; // Time to sleep between measures in seconds
const int flipTimer = 1000; // Time between two readings

/* Globals */
WiFiClient client;   // Wifi library
Adafruit_IO_Client aio = Adafruit_IO_Client(client, aio_key); // Adafruit IO library
Adafruit_IO_Feed airTemperature = aio.getFeed("air-temperature"); // Adafruit IO feed
Adafruit_IO_Feed soilHumidity = aio.getFeed("soil-humidity"); // Adafruit IO feed

void setup() { 
  Serial.begin(115200); // Open serial communication for debug purpose

  pinMode(voltageFlipPin1, OUTPUT); // Set the first voltage flip pin to output
  pinMode(voltageFlipPin2, OUTPUT); // Set the second voltage flip pin to output
  pinMode(sensorPin, INPUT); // Set the ADC pin

  WiFi.begin(ssid, password); // Connect to the Wifi Access Point
  
  while (WiFi.status() != WL_CONNECTED) { // Loop until connected
    delay(500);
    DEBUGGING(".");
  }
  
  /* Soil Humidity Measurement */
  setSensorPolarity(true); // Change the voltage flip
  delay(flipTimer); // Wait
  int val1 = analogRead(sensorPin); // Read the value
  delay(flipTimer); // Wait
  setSensorPolarity(false); // Change the voltage flip
  delay(flipTimer); // Wait
  int val2 = analogRead(sensorPin);   // Invert the reading
  int soilHumidityValue = (val1 + 1023 - val2)/20; // Calculate the average
  DEBUGGING_L("Soil Humidity : ");
  DEBUGGING(soilHumidityValue);

  /* Adafruit IO */
  soilHumidity.send(soilHumidityValue);

  DEBUGGING("Nap time");
  
  ESP.deepSleep(sleepTimeS * 1000000); // Sleep until next reading
}
void loop() {
}

void setSensorPolarity(boolean flip){
  if(flip){
    digitalWrite(voltageFlipPin1, HIGH);
    digitalWrite(voltageFlipPin2, LOW);
  }else{
    digitalWrite(voltageFlipPin1, LOW);
    digitalWrite(voltageFlipPin2, HIGH);
  }
}
