# System Requirements

## 1. Purpose

The Industrial Equipment Health Monitoring System is an embedded
monitoring prototype designed to demonstrate condition monitoring
of simulated industrial equipment.

The system acquires temperature and vibration information,
evaluates equipment condition, communicates the current health
state to an operator, and generates timestamped monitoring data.

## 2. Functional Requirements

### FR-01 — Temperature Acquisition

The system shall acquire temperature measurements from the
temperature sensor at a defined sampling interval.

### FR-02 — Vibration Detection

The system shall detect discrete vibration events from the
vibration sensor using debounced edge detection.

### FR-03 — Equipment Health Classification

The system shall classify equipment condition into one of four
states:

- NORMAL
- WARNING
- CRITICAL
- SENSOR_FAULT

### FR-04 — Operator Notification

The system shall communicate equipment health through visual
and audible indicators.

### FR-05 — Local Display

The system shall display equipment health, temperature, and
vibration information on the LCD.

### FR-06 — Data Logging

The system shall output timestamped temperature, vibration,
and equipment-state information through the serial interface.

### FR-07 — Sensor Fault Detection

The system shall identify temperature measurements outside
the defined prototype operating range.

### FR-08 — State Recovery

The system shall return to the appropriate operating state
when valid sensor conditions are restored.

## 3. Prototype Health Thresholds

The current prototype uses the following demonstration
thresholds:

| Parameter | NORMAL | WARNING | CRITICAL |
|-----------|--------|---------|----------|
| Temperature | < 40°C | 40–60°C | > 60°C |
| Vibration | 0–2 events | 3–5 events | ≥ 6 events |

These thresholds are demonstration values for the prototype
and are not intended to represent real industrial equipment
operating limits.

## 4. Sensor Fault Range

The current prototype identifies temperature readings below
-40°C or above 125°C as a sensor fault.

These limits are used for prototype fault detection and should
be replaced by application-specific limits for a real industrial
system.
