#include "Adafruit_DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
	dht.begin();
	delay(2000);
}

void loop() 
{
	float t = dht.getTempCelcius();
	
	if(isnan(t))
	{
		return;
	}
	
    String temp = String(t);
    Particle.publish("temp", temp, PRIVATE);
	delay(5000);
}