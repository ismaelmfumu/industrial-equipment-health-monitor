# Verification Test Plan

## Objective

The purpose of testing is to verify that the embedded monitoring
system satisfies its defined functional requirements.

## Test Cases

### TC-01 — Temperature Acquisition

**Procedure**

1. Set the TMP36 temperature to approximately 25°C.
2. Run the system.
3. Observe the serial output.

**Expected Result**

The measured temperature should be approximately 25°C.

---

### TC-02 — Temperature Warning

**Procedure**

1. Set the temperature to approximately 45°C.
2. Run the monitoring system.

**Expected Result**

System state = WARNING.

Yellow LED = ON.

LCD displays WARNING.

---

### TC-03 — Temperature Critical

**Procedure**

1. Set temperature above 60°C.

**Expected Result**

System state = CRITICAL.

Red LED = ON.

Buzzer = ON.

---

### TC-04 — Vibration Detection

**Procedure**

1. Trigger the vibration sensor once.
2. Observe the vibration counter.

**Expected Result**

One vibration event is detected.

---

### TC-05 — Vibration Debouncing

**Procedure**

1. Trigger the vibration sensor rapidly.
2. Observe the event counter.

**Expected Result**

Rapid sensor transitions should not produce
excessive duplicate events.

---

### TC-06 — Vibration Warning

**Procedure**

Generate 3–5 vibration events within the
defined monitoring window.

**Expected Result**

System state = WARNING.

---

### TC-07 — Vibration Critical

**Procedure**

Generate 6 or more vibration events.

**Expected Result**

System state = CRITICAL.

---

### TC-08 — Local HMI

**Procedure**

Trigger a warning condition.

**Expected Result**

Yellow LED activates and LCD displays WARNING.

---

### TC-09 — Critical Alarm

**Procedure**

Trigger a critical condition.

**Expected Result**

Red LED and buzzer activate.

---

### TC-10 — Data Logging

**Procedure**

Run the monitoring system for at least 10 seconds.

**Expected Result**

Timestamped temperature, vibration, and state
records are generated through the serial interface.

---

### TC-11 — Sensor Fault

**Procedure**

Produce a temperature reading outside the
defined prototype operating range.

**Expected Result**

System enters SENSOR_FAULT.

---

### TC-12 — State Recovery

**Procedure**

Return the sensor to a valid operating condition.

**Expected Result**

System returns to the appropriate health state.
