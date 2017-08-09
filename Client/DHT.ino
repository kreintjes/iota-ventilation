/* DHT Shield - Simple
 *
 * Example testing sketch for various DHT humidity/temperature sensors
 * Written by ladyada, public domain
 *
 * Depends on Adafruit DHT Arduino library
 * https://github.com/adafruit/DHT-sensor-library
 */

#include "DHT.h"

#define DHTPIN D4     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);

unsigned long lastReadTime;

void setupDHT() {
  dht.begin();
}

void loopDHT() {
  if(lastReadTime != NULL && millis() - lastReadTime < DHT_READ_INTERVAL) {
    return;
  }
  float h = dht.readHumidity();
  if(isnan(h)) {
    Serial.println("Failed to read from DHT sensor");
    delay(2000); // Time needed for sensor to get fresh reading.
    return;
  }

  humidity = (int) h;
  Serial.printf("humidity: %d\%\n", humidity);
  lastReadTime = millis();
}
