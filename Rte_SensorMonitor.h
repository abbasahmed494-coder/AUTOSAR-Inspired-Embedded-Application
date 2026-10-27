#ifndef RTE_SENSOR_MONITOR_H
#define RTE_SENSOR_MONITOR_H

#include <Arduino.h>

void Rte_SensorMonitor_Init(void);
bool Rte_Read_SensorData(float *temperatureC, float *humidityPercent);
void Rte_Write_WarningLed(bool active);

#endif
