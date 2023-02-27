// DHT Temperature & Humidity Sensor
// Unified Sensor Library Example
// Written by Tony DiCola for Adafruit Industries
// Released under an MIT license.

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT11

//Paso 3
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    //Paso 4
    Serial.begin(9600);
    Serial.println("DHTxx test!");
    dht.begin();
}

void loop() {  
    delay(5000);
    
    //Paso 5
    float h = dht.readHumidity();
    
    //Paso 6
    float t = dht.readTemperature();
    
    //Paso 7
    float f = dht.readTemperature(true);

    //Paso 8
    if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
    }

    //Paso 9
    float hif = dht.computeHeatIndex(f, h);
    float hic = dht.computeHeatIndex(t, h, false);

    //Paso 10
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print(f);
    Serial.print(" *F\t");
    Serial.print("Heat index: ");
    Serial.print(hic);
    Serial.print(" *C ");
    Serial.print(hif);
    Serial.println(" *F");

    if(t>=36){
          Serial.print("WARNING");
    }else{

    }
    if(h>=36){
          Serial.print("WARNING");
    }
}