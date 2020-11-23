#include "include/DataToPi.h"

// checks if the wifi network specified is available

void DataToPi::scanForWifi(float tempF, float humidity, float light, float soilMoisture)
{
  if ((millis() - lastUpdatePi) > updatePi)
  {
    lastUpdatePi = millis();
    if (WiFi.status() == WL_CONNECTED)
    {
        
        http.begin(serverName);
        http.addHeader("Content-Type", "application/x-www-form-urlencoded");
        sendToPi(tempF, humidity, light, soilMoisture);
        http.end();
    }
    else
    {
        Serial.println("WiFi Disconnected");
    }
  }
}

// sends chosen variables to server on Raspberry Pi through wifi network

void DataToPi::sendToPi(float tempF, float humidity, float light, float soilMoisture)
{
    String httpRequestData = "api_key=" + apiKeyValue + "&plant=" + plantName + "&dataTemperature=" + String(tempF)
                          + "&dataHumidity=" + String(humidity) + "&dataLight=" + String(light) + "&dataSoilMoisture=" + String(soilMoisture) + "";
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    int httpResponseCode = http.POST(httpRequestData);
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
 
}

void DataToPi::wifiInit()
{
  WiFi.begin(ssid, password);
//  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) 
  {
    delay(350);
//    Serial.print(".");
  }
//  Serial.println("");
//  Serial.print("Connected to WiFi network with IP Address: ");
//  Serial.println(WiFi.localIP());
}