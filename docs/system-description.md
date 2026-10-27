# System Description — AUTOSAR-Inspired Embedded Application

## Purpose

The system monitors ambient temperature and relative humidity with a DHT22 connected to an Arduino Uno. It prints each valid reading over serial and controls a red warning LED based on a 30.0 °C temperature threshold.

## Functional behavior

- The application is initialized from `src/sketch.ino` after serial output is configured to 115200 baud.
- The main loop calls `SensorMonitor_Run()` every 2,000 ms.
- The sensor driver reads temperature and humidity from the DHT22.
- If the readings are valid, the application sets the warning state to ON when `temperature >= 30.0 °C`, and OFF otherwise.
- If either reading is invalid, the driver reports failure; the application turns the warning LED ON and writes an error message to serial.
- Valid readings are printed in the format `Temperature: xx.x C | Humidity: xx.x % | Warning: ON/OFF`.

## Software modules

| Module | Responsibility |
|---|---|
| `SensorMonitor.cpp/.h` | Application logic, threshold evaluation, serial reporting |
| `Rte_SensorMonitor.cpp/.h` | RTE-style interface between the application and drivers |
| `SensorDriver.cpp/.h` | DHT22 initialization and measurement retrieval |
| `LedDriver.cpp/.h` | Initialization and digital control of the warning LED |
| `src/sketch.ino` | Arduino setup and periodic execution |

## Hardware connections

| Signal | Connection |
|---|---|
| DHT22 VCC | Arduino 5V |
| DHT22 DATA | Arduino D2 |
| DHT22 GND | Arduino GND |
| LED output | Arduino D7 through a 220 Ω resistor to LED anode |
| LED return | LED cathode to Arduino GND |

## Conceptual architecture

```text
DHT22 Sensor
    │
    ▼
SensorDriver ──► Rte_Read_SensorData()
                       │
                       ▼
                SensorMonitor
                 (threshold logic)
                       │
                       ▼
              Rte_Write_WarningLed()
                       │
                       ▼
                  LedDriver
                       │
                       ▼
                Warning LED (D7)
```

## Test evidence

The provided log contains ten samples with humidity fixed at 40.0%. Six readings at 24.0 °C and the 29.9 °C reading report `Warning: OFF`; 31.0 °C and 35.2 °C report `Warning: ON`; the final reading of 25.6 °C returns to `Warning: OFF`. This demonstrates normal state changes above and below the configured threshold. The supplied run does not include a measurement at exactly 30.0 °C or a failed sensor read.

## Scope and limitations

The layered structure is a teaching aid inspired by AUTOSAR concepts. It is not AUTOSAR-compliant, and does not implement generated RTE artifacts, ARXML, AUTOSAR BSW modules, an AUTOSAR OS, or formal automotive qualification. Hardware-specific details should be checked against the sensor module and board documentation before constructing a physical circuit.
