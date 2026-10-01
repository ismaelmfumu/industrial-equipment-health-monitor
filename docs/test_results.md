# Test Results

| Test ID | Expected Result | Actual Result | Pass/Fail |
|---------|-----------------|---------------|-----------|
| TC-01 | ~25°C reading | 24.8°C reading | PASS |
| TC-02 | WARNING;  | WARNING | PASS |
| TC-03 | CRITICAL | CRITICAL | PASS |
| TC-04 | One vibration event | One Vibration event | PASS |
| TC-05 | Debounced events | Debounced events | PASS |
| TC-06 | WARNING | WARNING | PASS |
| TC-07 | CRITICAL | WARNING (only reaches 4 debounces before timer) | FAIL |
| TC-08 | Warning HMI | WARNING (via 48.2) | PASS |
| TC-09 | Critical alarm | WARNING (via debounce) | FAIL |
| TC-10 | Timestamped data | Timestamped Data (10s) | PASS |
| TC-11 | SENSOR_FAULT | SENSOR_FAULT (via -40.2°C) | PASS |
| TC-12 | Correct recovery | Correct recovery (-40.0°C -> 30.2°C) | PASS |
