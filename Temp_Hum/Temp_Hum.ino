// DHT11 - Temperatura and humidity sensor //

#include "DHT11.h"

DHT11 Sensor(2);

void setup() {

    Serial.begin(9600);
    Sensor.setDelay(100);

}

void loop() {

    int temperature = 0;
    int humidity = 0;

    int result = Sensor.readTemperatureHumidity(temperature, humidity);

    if (result == 0) {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print(" °C\tHumidity: ");
        Serial.print(humidity);
        Serial.println(" %");
    }

}