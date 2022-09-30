#pragma once

#include <ArduinoJson.h>


class SingleDeviceConfig {

   public:
  
    char name[32];
    char mapping[20];
    int type2;
    int default2;
    bool connected;

    void fromJson(const JsonObject& json) {
        strlcpy(name, json["name"], sizeof(name));
        strlcpy(mapping, json["mapping"], sizeof(mapping));
        type2 = json["type"];
        default2 = json["default"];
        connected = json["connected"];
    }
};