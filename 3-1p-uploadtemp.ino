#include "Adafruit_DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
	dht.begin();
}

void loop() 
{
	delay(2000);
	float t = dht.getTempCelcius();
	
	if(isnan(t))
	{
		return;
	}
	
    	String temp = String(t);
    	Particle.publish("temp", temp, PRIVATE);
}
