#include "include/CollectData.h"

void CollectData::dataInit()
{
    dht.begin();
    pinMode(BATTERY_PIN, INPUT);
}

// returns data from soil moisture sensor

void CollectData::moistureSensor(void){
    soilMoisture = analogRead(SOIL_SENSOR_PIN);  //put Sensor insert into soil
}

// returns data from temp and humidity sensor

void CollectData::dhtSensor(void){
    humidity = dht.readHumidity();
    tempF = dht.readTemperature(true);
}

// returns data from photoresistor

void CollectData::lightSensor(void){
    light = analogRead(LIGHT_SENSOR_PIN);
}

// measures how much battery life is left

void CollectData::batteryIndic(void)
{
  batteryLife = analogRead(BATTERY_PIN);
}

// takes data from sensors and puts them in variables

void CollectData::takeMeasurement(void){
    if ((millis() - lastUpdateData) > updateData)
  {
    lastUpdateData = millis();
    moistureSensor();
    dhtSensor();
    lightSensor();
    batteryIndic();
  }
}

void CollectData::debugging(void){
    Serial.print(F("Soil Moisture: "));
    Serial.print(soilMoisture);
    Serial.print(F("  Humidity: "));
    Serial.print(humidity);
    Serial.print(F("%  Temperature: "));
    Serial.print(tempF);
    Serial.print(F("°F  Light: "));
    Serial.println(light);
    Serial.print(F("Battery Life: "));
    Serial.println(batteryLife);
}