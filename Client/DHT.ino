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

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);

os_timer_t dhtTimer;

void timerCallback(void *pArg) {
  float h = dht.readHumidity();
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  humidity = h;

  Serial.print("Humidity: ");
  Serial.println(humidity);
}

void setupDHT() {
  os_timer_setfn(&dhtTimer, timerCallback, NULL);
  os_timer_arm(&dhtTimer, 2000, true);
  dht.begin();
}

void loopDHT() {
}
