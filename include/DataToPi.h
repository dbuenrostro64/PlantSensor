#ifndef DATATOPI_H
#define DATATOPI_H

#include <WiFi.h>
#include <HTTPClient.h>

class DataToPi{
    private:
        const char* ssid       = "SpectrumSetup-08";
        const char* password   = "brightcountry804";
        const char* serverName = "http://192.168.1.168/post-esp-data.php";
        String apiKeyValue     = "tPmAT5Ab3j7F9";
        String plantName       = "fern";
        unsigned long lastUpdatePi = 0;
        int updatePi = 15000;
        void scanForWifi(float tempF, float humidity, float light, float soilMoisture);
        void sendToPi(float tempF, float humidity, float light, float soilMoisture);
    public:
        HTTPClient http;
        void wifiInit();
};

#endif