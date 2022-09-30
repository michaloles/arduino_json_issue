#pragma once

#include <ArduinoJson.h>

class SystemConfiguration {
   
   public:

    char wifiName[32] = "SmartRoad";
    char wifiPassword[32] = "smartroad123";
    bool connectToExistingWifi = false;
    bool dhcp = true;
    char ip[32];
    char gateway[32];
    char subnet[32];
    char user[32] = "admin";
    char password[32] = "admin";
    char phone[16] = "";
    char pin[16] = "";

    void fromJson(const JsonObject& json) {
        strlcpy(wifiName, json["wifiName"] | "SmartRoad", sizeof(wifiName));
        strlcpy(wifiPassword, json["wifiPassword"] | "smartroad123", sizeof(wifiPassword));
        connectToExistingWifi = json["connectToExistingWifi"];
        dhcp = json["dhcp"];

        strlcpy(ip, json["ip"] | "192.168.1.1", sizeof(ip));
        strlcpy(gateway, json["gateway"] | "192.168.1.1", sizeof(gateway));
        strlcpy(subnet, json["subnet"] | "255.255.0.0", sizeof(subnet));

        strlcpy(user, json["user"] | "admin", sizeof(user));
        strlcpy(password, json["password"] | "admin", sizeof(password));

        strlcpy(phone, json["phone"] | "", sizeof(phone));
        strlcpy(pin, json["pin"] | "", sizeof(pin));
    }

};