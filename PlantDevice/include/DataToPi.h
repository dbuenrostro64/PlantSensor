#ifndef DATATOPI_H
#define DATATOPI_H

// to connect to wifi network
#include <WiFi.h>
// to get and put requests to a web server
#include <HTTPClient.h>

class DataToPi{
    private:
        const char* ssid       = "";
        const char* password   = "";
        // ip address of local server/file on server
        const char* serverName = "http://192.168.1.168/post-esp-data.php";
        // apikey must be same as on the server
        String apiKeyValue     = "tPmAT5Ab3j7F9";
        String plantName       = "fern";
        unsigned long lastUpdatePi = 0;
        int updatePi = 15000;
        // checks if the wifi network specified is available
        void scanForWifi(float tempF, float humidity, float light, float soilMoisture);
        // sends chosen variables to server on Raspberry Pi through wifi network
        void sendToPi(float tempF, float humidity, float light, float soilMoisture);
    public:
        HTTPClient http;
        void wifiInit();
};

#endif