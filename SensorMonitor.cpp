#include "SensorMonitor.h"
#include "Rte_SensorMonitor.h"

namespace {
  constexpr float TEMPERATURE_WARNING_LIMIT_C = 30.0f;
}

void SensorMonitor_Init(void) {
  Rte_SensorMonitor_Init();
  Serial.println();
  Serial.println(F("AUTOSAR-inspired Sensor Monitor"));
  Serial.println(F("Arduino Uno + DHT22 + warning LED"));
  Serial.println(F("Temperature warning threshold: 30.0 C"));
  Serial.println(F("Note: educational architecture; not AUTOSAR-compliant."));
  Serial.println(F("---------------------------------------------"));
}

void SensorMonitor_Run(void) {
  float temperatureC = 0.0f;
  float humidityPercent = 0.0f;

  if (!Rte_Read_SensorData(&temperatureC, &humidityPercent)) {
    // For this demo, indicate an invalid sensor reading with the warning LED.
    Rte_Write_WarningLed(true);
    Serial.println(F("SENSOR ERROR: invalid DHT22 reading; warning LED ON."));
    return;
  }

  const bool overTemperature =
    (temperatureC >= TEMPERATURE_WARNING_LIMIT_C);

  Rte_Write_WarningLed(overTemperature);

  Serial.print(F("Temperature: "));
  Serial.print(temperatureC, 1);
  Serial.print(F(" C | Humidity: "));
  Serial.print(humidityPercent, 1);
  Serial.print(F(" % | Warning: "));
  Serial.println(overTemperature ? F("ON") : F("OFF"));
}
