#pragma once

#include <ArduinoJson.h>
#include "SingleDeviceConfig.cpp"

class DeviceConfiguration {
    public:

    SingleDeviceConfig device[15];
    int mpptType;
    
    void fromJson(const JsonVariant& json){
        JsonArray array = json["devices"].as<JsonArray>();
        mpptType = json["mpptType"];
        int i=0;
        for(JsonObject item: array){
            device[i].fromJson(item);
            i++;
        }
    }

    DynamicJsonDocument toJson(){
        DynamicJsonDocument doc(3000);
            doc["mpptType"] = mpptType;
            JsonArray array = doc.createNestedArray("devices");
            for(int i=0; i<15; i++){
                array[i]["id"] = i;
                array[i]["name"] = device[i].name;
                array[i]["mapping"] = device[i].mapping;
                array[i]["type"] = device[i].type2;
                array[i]["default"] = device[i].default2;
                array[i]["connected"] = device[i].connected;
            }
        return doc;
    }

};