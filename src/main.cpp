#define DYNAMIC_JSON_DOCUMENT_SIZE 15000

#include <Arduino.h>
#include <ArduinoJson.h>

#include "FileSystem.cpp"
#include "SystemConfiguration.cpp"
#include "DeviceConfiguration.cpp"

FileSystem fileSystem;
SystemConfiguration systemConfig;
DeviceConfiguration deviceConfig;


void readSystemConfiguration(){
  Serial.println(F("readSystemConfiguration call"));

  DynamicJsonDocument doc(5000);
  fileSystem.loadConfiguration("/systemConfig.json", doc);
  systemConfig.fromJson(doc.as<JsonObject>());
  doc.clear();
}


void readDeviceConfiguration(){
 Serial.println(F("readDeviceConfiguration call"));

  DynamicJsonDocument doc(8000); 
  fileSystem.loadConfiguration("/deviceConfig.json", doc);

  Serial.println("SystemConfig is correct here:");
  Serial.println(systemConfig.wifiName);
  
  deviceConfig.fromJson(doc.as<JsonVariant>());

  Serial.println("At this point system config is broken:");
  Serial.println(systemConfig.wifiName);

  doc.clear();
}



void setup(){
  delay(1000);
  fileSystem.initSerialAndFS();

  readSystemConfiguration();
  readDeviceConfiguration();

}

void loop(){

}