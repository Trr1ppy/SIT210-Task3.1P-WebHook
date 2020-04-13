// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_Sensor.h>

// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>

#define DHTPIN 6
#define DHTTYPE DHT22   // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE); // Setup object for DHT 22 sensor

void setup() {
    dht.begin();          // Initialise DHT 22 sensor
    delay(1000);        // Delay 1s to let the sensor settle
}

void loop() {
    float t = dht.getTempCelcius();      // Get the temperature 
    String temp = String(t);            //Convert the float value to a string
    Particle.publish("temp", temp, PRIVATE); //Publish the string temp
    delay(30000);               // Wait 30 seconds
    
}
