#include "include/DataToPi.h"

void DataToPi::wifiInit()
{
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) 
  {
    delay(350);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

// checks if the wifi network specified is available

void DataToPi::scanForWifi(float tempF, float humidity, float light, float soilMoisture, float battery)
{
  if ((millis() - lastUploadToPi) > (uploadToPiSeconds*1000))
  {
    lastUploadToPi = millis();
    if (WiFi.status() == WL_CONNECTED)
    {
        http.begin(serverName);
        http.addHeader("Content-Type", "application/x-www-form-urlencoded");
        sendToPi(tempF, humidity, light, soilMoisture, battery);
        http.end();
    }
    else
    {
        Serial.println("WiFi Disconnected");
    }
  }
}

// sends chosen variables to server on Raspberry Pi through wifi network

void DataToPi::sendToPi(float tempF, float humidity, float light, float soilMoisture, float battery)
{
    String httpRequestData = "api_key=" + apiKeyValue + "&tempF=" + String(tempF)
                          + "&humidity=" + String(humidity) + "&light=" + String(light) 
                          + "&soilMoisture=" + String(soilMoisture) + "&battery=" + String(battery) + "";
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    int httpResponseCode = http.POST(httpRequestData);
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      //Sleep Mode Functions
      //esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP*uS_TO_S_FACTOR);
      //esp_deep_sleep_start();
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
}