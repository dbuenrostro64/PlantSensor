#ifndef COLLECTDATA_H
#define COLLECTDATA_H

#include <DHT.h>

class CollectData{
  friend class DisplayActions;
  private:
    const byte BATTERY_PIN = 4;
    const byte TEMP_SENSOR_PIN = 23;
    const byte SOIL_SENSOR_PIN = 34;
    const byte LIGHT_SENSOR_PIN = 35;
    float soilMoisture;
    float humidity;
    float tempF;
    float light;
    float batteryLife;
    unsigned long lastUpdateData = 0;
    int updateData = 250;
  public:
    CollectData() : dht(TEMP_SENSOR_PIN,DHT11) {}
    DHT dht;
    void dataInit();
    // returns data from soil moisture sensor
    void moistureSensor(void);
    float getMoisture() {return soilMoisture;}
    // returns data from temp and humidity sensor
    void dhtSensor(void);
    float getHumidity() {return humidity;}
    float getTemp() {return tempF;}
    // returns data from photoresistor
    void lightSensor(void);
    float getLight() {return light;}
    // measures how much battery life is left
    void batteryIndic(void);
    float getBattery() {return batteryLife;}
    // takes data from sensors and puts them in variables
    void takeMeasurement(void);

    void debugging(void);
};

#endif