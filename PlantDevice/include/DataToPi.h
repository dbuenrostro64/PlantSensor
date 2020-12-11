#ifndef DATATOPI_H
#define DATATOPI_H

#define uS_TO_S_FACTOR 1000000
#define TIME_TO_SLEEP 300//in seconds

#include <WiFi.h>
#include <HTTPClient.h>

class DataToPi{
    private:
        const char* ssid       = "SpectrumSetup-08";
        const char* password   = "brightcountry804";
        const char* serverName = "http://192.168.1.168/post-light-moisture.php";
        String apiKeyValue     = "tPmAT5Ab3j7F9";
        String plantName       = "fern";
        unsigned long lastUploadToPi = 0;
        int uploadToPiSeconds = 300;
    public:
        HTTPClient http;
        void wifiInit();
        void scanForWifi(float tempF, float humidity, float light, float soilMoisture, float battery);
        void sendToPi(float tempF, float humidity, float light, float soilMoisture, float battery);
        
};

#endif