#ifndef SENSOR_DRIVER_H
#define SENSOR_DRIVER_H

#include <Arduino.h>

void SensorDriver_Init(void);
bool SensorDriver_Read(float *temperatureC, float *humidityPercent);

#endif
