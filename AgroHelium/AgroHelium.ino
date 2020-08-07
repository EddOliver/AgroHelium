#include <ArduinoJson.h>
#include <avr/dtostrf.h>
#include <HTS221Sensor.h>
#include "LoRaWAN.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#define DEV_I2C Wire
#define ONE_WIRE_BUS 7
#define Moisture A0

const char *devEui = "DEVEUI";
const char *appEui = "APPEUI";
const char *appKey = "APPKEY";

// Components
HTS221Sensor *HumTemp;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

unsigned long time1;

String LoraJSON="{";

void setup() {
  StaticJsonDocument<200> doc;
  Serial.begin(115200);
  sensors.begin();
  delay(1);  
  DEV_I2C.begin();
  HumTemp = new HTS221Sensor (&DEV_I2C);
  HumTemp->Enable();
  LoRaWAN.begin(US915);                   // Helium SubBand
  LoRaWAN.setSubBand(2);
  LoRaWAN.setADR(false);
  LoRaWAN.setDataRate(3);
  LoRaWAN.joinOTAA(appEui, appKey, devEui);
  Serial.println("Start...");
  time1=millis();
}

void loop() {
  if((millis() - time1) > 60000)
  {  
  float humidity = 0, temperature = 0;
  HumTemp->GetHumidity(&humidity);
  HumTemp->GetTemperature(&temperature);
  LoraJSON="{";
  LoraJSON += "\"h\":";
  LoraJSON += String(humidity);
  LoraJSON += ",";
  LoraJSON += "\"t\":";
  LoraJSON += String(temperature);
  LoraJSON += ",";
  LoraJSON += "\"m\":";
  LoraJSON += String(map(analogRead(Moisture), 0, 2400, 0, 100));
  LoraJSON += ",";
  LoraJSON += "\"st\":";
  LoraJSON += String(sensors.getTempCByIndex(0));
  LoraJSON += "}";

  if (LoRaWAN.joined() && !LoRaWAN.busy())
    {   
        // Send Packet
        uint8_t payload[] ="";
        LoraJSON.getBytes(payload, sizeof(LoraJSON));
        LoRaWAN.sendPacket(1, payload, sizeof(payload));
        Serial.println("Data Sent");
    }
  time1=millis(); 
  Serial.println(LoraJSON);
  } 
}
