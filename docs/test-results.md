# Test Results — AUTOSAR-Inspired Sensor Monitor

## Test setup

- **Controller:** Arduino Uno
- **Sensor:** DHT22 temperature/humidity sensor
- **Output:** Red warning LED
- **Warning threshold:** 30.0 °C (the application checks `temperature >= 30.0 °C`)
- **Sampling interval:** 2,000 ms
- **Serial Monitor:** 115200 baud
- **Run type:** User-provided simulation output and screenshots

## Recorded results

| Sample(s) | Temperature | Humidity | Expected warning | Recorded warning | Result |
|---|---:|---:|---|---|---|
| 1–6 | 24.0 °C | 40.0% | OFF | OFF | Pass — all six readings |
| 7 | 29.9 °C | 40.0% | OFF | OFF | Pass |
| 8 | 31.0 °C | 40.0% | ON | ON | Pass |
| 9 | 35.2 °C | 40.0% | ON | ON | Pass |
| 10 | 25.6 °C | 40.0% | OFF | OFF | Pass |

**Summary:** 10 recorded samples were supplied. Each observed warning state matches the expected behavior for the reported temperature. The LED returns to OFF when the final temperature drops below the warning threshold. Humidity remained at 40.0% throughout the supplied log.

## Supplied serial output

```text
AUTOSAR-inspired Sensor Monitor
Arduino Uno + DHT22 + warning LED
Temperature warning threshold: 30.0 C
Note: educational architecture; not AUTOSAR-compliant.
---------------------------------------------
Temperature: 24.0 C | Humidity: 40.0 % | Warning: OFF
Temperature: 24.0 C | Humidity: 40.0 % | Warning: OFF
Temperature: 24.0 C | Humidity: 40.0 % | Warning: OFF
Temperature: 24.0 C | Humidity: 40.0 % | Warning: OFF
Temperature: 24.0 C | Humidity: 40.0 % | Warning: OFF
Temperature: 24.0 C | Humidity: 40.0 % | Warning: OFF
Temperature: 29.9 C | Humidity: 40.0 % | Warning: OFF
Temperature: 31.0 C | Humidity: 40.0 % | Warning: ON
Temperature: 35.2 C | Humidity: 40.0 % | Warning: ON
Temperature: 25.6 C | Humidity: 40.0 % | Warning: OFF
---------------------------------------------
```

## Screenshot evidence

- `wiring-diagram.png` (the supplied **Before** screenshot) shows the circuit with the warning LED visually not illuminated.
- `../media/circuit.png` (the supplied **After** screenshot) shows the warning LED illuminated.
- `../media/demo.gif` alternates between the two supplied screenshots for a quick visual comparison.

The screenshots support the visible OFF/ON change; the temperature values and exact state sequence above come from the serial results supplied with the task.

## Coverage and items not yet verified

- **Verified in supplied results:** below-threshold readings at 24.0 °C and 29.9 °C; above-threshold readings at 31.0 °C and 35.2 °C; return to OFF at 25.6 °C.
- **Not shown in supplied results:** an exact 30.0 °C reading, a disconnected/invalid DHT22 reading, humidity variation, and long-duration reliability.
- The code is written to turn the warning LED ON at exactly 30.0 °C because its condition uses `>=`, but that boundary behavior should be recorded with a dedicated simulation test before it is reported as empirically verified.

## Conclusion

For the recorded samples, the application demonstrated the expected temperature-threshold warning behavior. Further boundary and sensor-failure tests are recommended before drawing conclusions beyond this simulation run.
