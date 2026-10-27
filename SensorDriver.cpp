#include "SensorDriver.h"
#include <DHT.h>
#include <math.h>

namespace {
  constexpr uint8_t DHT_PIN = 2;
  constexpr uint8_t DHT_TYPE = DHT22;
  DHT dht(DHT_PIN, DHT_TYPE);
}

void SensorDriver_Init(void) {
  dht.begin();
}

bool SensorDriver_Read(float *temperatureC, float *humidityPercent) {
  if (temperatureC == nullptr || humidityPercent == nullptr) {
    return false;
  }

  const float temperature = dht.readTemperature();
  const float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    return false;
  }

  *temperatureC = temperature;
  *humidityPercent = humidity;
  return true;
}
