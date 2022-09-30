#pragma once

#include <SPIFFS.h>
#include <Arduino.h>
#include <ArduinoJson.h>

class FileSystem {

public:

void initSerialAndFS(){
  Serial.begin(115200);
  Serial.setDebugOutput(true);

  if(!SPIFFS.begin(true)){
        Serial.println(F("An Error has occurred while mounting SPIFFS"));
        return;
  }
  Serial.println(F("FS initialized"));
}

void loadConfiguration(const char *filename, DynamicJsonDocument &doc) {
  File file = SPIFFS.open(filename, "r+");

  // Deserialize the JSON document
  DeserializationError error = deserializeJson(doc, file);
  if (error){
    Serial.println(F("Failed to read file, using default configuration"));
    Serial.println(error.c_str());
  }
  file.close();
}


};