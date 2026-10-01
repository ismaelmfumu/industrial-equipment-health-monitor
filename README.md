# Industrial Equipment Health Monitoring System

## By: Ismael Mfumu

**Prototype Embedded Systems Engineering Project**

---

## Overview

The **Industrial Equipment Health Monitoring System** is an embedded condition-monitoring prototype designed to demonstrate how an embedded controller can continuously monitor the operating condition of industrial equipment and identify potential abnormal conditions.

The system acquires sensor data representing equipment parameters such as **temperature and vibration**, processes the measurements using an Arduino-based embedded controller, evaluates the equipment's condition against defined thresholds, and provides an operator-facing health status.

The prototype classifies equipment condition into four states:

* **NORMAL** – Equipment is operating within expected limits.
* **WARNING** – An abnormal condition has been detected and requires attention.
* **CRITICAL** – Measurements indicate a potentially serious equipment condition.
* **SENSOR_FAULT** – Sensor data is invalid, unavailable, or outside expected measurement behavior.

The project is structured using an engineering-oriented development approach that connects **requirements, system architecture, implementation, state behavior, verification, and test results**.

---

## Engineering Problem

Industrial equipment can develop abnormal operating conditions before complete failure. Changes in parameters such as temperature and vibration can provide an indication that equipment may be operating outside its expected condition.

A condition-monitoring system can continuously observe these parameters and provide an early indication of abnormal behavior, allowing an operator or maintenance team to investigate the equipment before a more serious failure occurs.

This project explores the design of a small-scale embedded monitoring system for a **simulated industrial asset**.

The goal is not to reproduce a production industrial monitoring system, but to demonstrate the engineering principles involved in designing one.

---

## Project Objectives

The prototype was developed to demonstrate the following engineering capabilities:

* Embedded sensor acquisition
* Microcontroller programming
* Hardware/software integration
* Real-time condition monitoring
* Threshold-based fault detection
* Equipment health-state classification
* Sensor fault handling
* Operator notification
* Data logging
* State-machine design
* Requirements definition
* Requirements traceability
* System verification and testing
* Engineering documentation

---

# Repository Structure

```text
Industrial Equipment Health Monitoring System
│
├── README.md
│
├── src/
│   └── equipment_monitor.ino
│
└── docs/
    ├── requirements.md
    ├── requirements_traceability.md
    ├── state_machine.png
    ├── system_architecture.png
    ├── test_plan.md
    ├── test_results.md
    └── wiring_diagram.png
```

The repository is organized to separate the **embedded implementation** from the **engineering design and verification documentation**.

---

# File Descriptions

## `README.md`

This document provides the overall project description and serves as the entry point to the repository.

It explains:

* The engineering problem
* Project objectives
* System concept
* Repository structure
* Engineering workflow
* Prototype limitations
* How the different project artifacts relate to one another

The README provides the high-level context needed to understand the rest of the project.

---

# Source Code

## `src/equipment_monitor.ino`

This is the main embedded software implementation for the prototype.

The `.ino` file contains the Arduino firmware responsible for implementing the monitoring system's operational behavior.

The firmware is responsible for functions such as:

1. Initializing the monitoring system
2. Reading sensor inputs
3. Processing sensor measurements
4. Comparing measurements against defined limits
5. Determining the equipment health state
6. Detecting potential sensor faults
7. Updating operator-facing indications
8. Logging or displaying monitoring information
9. Continuously repeating the monitoring cycle

Conceptually, the software implements the following flow:

```text
Sensor Inputs
     │
     ▼
Data Acquisition
     │
     ▼
Measurement Processing
     │
     ▼
Condition Evaluation
     │
     ├── NORMAL
     ├── WARNING
     ├── CRITICAL
     └── SENSOR_FAULT
     │
     ▼
Operator Notification
     │
     ▼
Data Logging / Monitoring Output
```

The firmware represents the **implementation layer** of the system.

---

# Engineering Documentation

The `docs/` directory contains the engineering artifacts used to define, design, and verify the prototype.

Rather than treating the Arduino code as the entire project, these documents demonstrate the engineering process used to develop the system.

---

## `docs/requirements.md`

This document defines the system requirements.

Requirements describe what the monitoring system is expected to do without necessarily describing how the functionality must be implemented.

Examples include requirements for:

* Sensor data acquisition
* Temperature monitoring
* Vibration monitoring
* Equipment health classification
* Warning and critical conditions
* Sensor fault detection
* Operator notification
* Monitoring cycle behavior
* Data logging

The requirements document establishes the **expected system behavior** that the implementation and testing activities are based on.

---

## `docs/requirements_traceability.md`

The requirements traceability document connects individual system requirements to their corresponding implementation and verification activities.

It provides a structured relationship between:

```text
Requirement
     │
     ▼
System / Software Function
     │
     ▼
Implementation
     │
     ▼
Verification Test
     │
     ▼
Test Result
```

This demonstrates how each requirement can be traced through the development process and verified through testing.

Requirements traceability is particularly important in engineering projects because it helps demonstrate that the implemented system addresses the defined requirements.

---

## `docs/system_architecture.png`

The system architecture diagram provides a high-level representation of the major components of the monitoring system and how they interact.

The architecture illustrates the relationship between elements such as:

```text
       Sensor Inputs
            │
            ▼
   ┌──────────────────┐
   │ Embedded         │
   │ Controller       │
   │                  │
   │ Data Acquisition │
   │ Condition Logic  │
   └────────┬─────────┘
            │
       ┌────┴─────┐
       ▼          ▼
 Health Status   Data Output
       │
       ▼
Operator Notification
```

The diagram provides a system-level view before considering the detailed implementation.

---

## `docs/state_machine.png`

The state-machine diagram describes how the monitoring system transitions between equipment health states.

The system can transition between states such as:

```text
             ┌──────────┐
             │  NORMAL  │
             └────┬─────┘
                  │
            Abnormal Reading
                  ▼
             ┌──────────┐
             │ WARNING  │
             └────┬─────┘
                  │
           Severe Condition
                  ▼
             ┌──────────┐
             │ CRITICAL │
             └──────────┘

Invalid Sensor Data
        │
        ▼
 ┌──────────────┐
 │ SENSOR_FAULT │
 └──────────────┘
```

The state machine provides a formal representation of the system's behavioral logic and helps ensure that the firmware implements predictable transitions between operating conditions.

---

## `docs/wiring_diagram.png`

The wiring diagram documents the physical hardware configuration of the prototype.

It identifies the connections between the Arduino-based controller and the sensors, indicators, and other hardware components used by the system.

The diagram supports:

* Hardware implementation
* Hardware/software interface understanding
* Troubleshooting
* Prototype reproduction
* Verification of electrical connections

It provides the physical implementation view that complements the higher-level system architecture.

---

# Verification & Testing

## `docs/test_plan.md`

The test plan defines how the monitoring system will be evaluated against its requirements.

Testing focuses on verifying that the prototype behaves correctly under different operating conditions.

Example test categories include:

* Normal sensor conditions
* Elevated temperature
* Elevated vibration
* Critical measurements
* Invalid sensor readings
* Sensor disconnection/fault conditions
* State transitions
* Operator notifications
* System recovery after abnormal conditions

The test plan establishes the **verification approach before evaluating the system**.

---

## `docs/test_results.md`

The test results document records the outcome of executing the defined tests.

It provides evidence of whether the implemented prototype behaved as expected under the tested conditions.

The relationship between the testing documents is:

```text
requirements.md
       │
       ▼
test_plan.md
       │
       ▼
Prototype Testing
       │
       ▼
test_results.md
       │
       ▼
requirements_traceability.md
```

This creates a basic verification workflow connecting system requirements to actual test evidence.

---

# Engineering Development Workflow

The project follows an engineering workflow rather than developing the Arduino code in isolation.

```text
1. Define Engineering Problem
             │
             ▼
2. Define System Requirements
             │
             ▼
3. Develop System Architecture
             │
             ▼
4. Define System States
             │
             ▼
5. Design Hardware / Wiring
             │
             ▼
6. Implement Embedded Firmware
             │
             ▼
7. Develop Verification Test Plan
             │
             ▼
8. Execute Tests
             │
             ▼
9. Record Test Results
             │
             ▼
10. Maintain Requirements Traceability
```

Each repository artifact supports a different stage of this process.

---

# Engineering Artifact Relationship

The files can be viewed as different representations of the same system:

| Artifact                       | Engineering Purpose                                     |
| ------------------------------ | ------------------------------------------------------- |
| `README.md`                    | Project overview and engineering context                |
| `requirements.md`              | Defines what the system must do                         |
| `system_architecture.png`      | Defines the high-level system structure                 |
| `state_machine.png`            | Defines system behavior and state transitions           |
| `wiring_diagram.png`           | Defines the physical hardware implementation            |
| `equipment_monitor.ino`        | Implements the embedded software                        |
| `test_plan.md`                 | Defines how requirements will be verified               |
| `test_results.md`              | Records verification results                            |
| `requirements_traceability.md` | Connects requirements, implementation, and verification |

Together, these artifacts provide a simplified **systems engineering lifecycle** for the prototype.

---

# Prototype Scope

This project is an **educational embedded systems prototype** representing a simplified industrial equipment monitoring application.

The monitored equipment is simulated using sensor inputs rather than connected to actual industrial machinery.

The prototype is intended to demonstrate:

* Embedded systems engineering
* Sensor integration
* Hardware/software interfaces
* Monitoring algorithms
* Fault detection
* State-based system behavior
* Verification and validation concepts
* Engineering documentation

It is **not intended for direct deployment on safety-critical or production industrial equipment**.

A production implementation would require additional considerations such as industrial-grade sensors, signal conditioning, calibration, electrical protection, environmental qualification, communications infrastructure, cybersecurity, redundancy, alarm management, and applicable industrial standards.

---

# Skills Demonstrated

This project demonstrates practical application of:

### Embedded Systems

* Arduino/microcontroller programming
* C/C++ firmware development
* Sensor interfacing
* Real-time monitoring
* Hardware/software integration

### Systems Engineering

* Requirements definition
* System architecture
* Functional decomposition
* State-machine modeling
* Requirements traceability
* Verification planning

### Engineering Design

* Hardware integration
* Sensor-based condition monitoring
* Fault detection
* Threshold-based decision logic
* Operator notification
* System troubleshooting

### Verification & Validation

* Test planning
* Requirement-based testing
* Functional verification
* Test-result documentation
* Traceability between requirements and verification

---

# Future Improvements

Potential future development could include:

* Additional vibration sensing and signal analysis
* RMS vibration calculations
* Moving-average filtering
* Sensor calibration routines
* SD-card data logging
* Historical trend analysis
* LCD or graphical operator interface
* Web-based monitoring dashboard
* Ethernet/Wi-Fi connectivity
* MQTT-based telemetry
* Remote equipment monitoring
* Predictive-maintenance algorithms
* More sophisticated anomaly detection
* Event and alarm logging
* Watchdog and recovery mechanisms
* Industrial communication protocols

These improvements would allow the prototype to evolve from a basic threshold-based monitoring system toward a more advanced **condition-monitoring and predictive-maintenance platform**.

---

# Project Summary

The **Industrial Equipment Health Monitoring System** demonstrates how an embedded system can be developed using an engineering-oriented approach.

Rather than focusing only on firmware, the project connects:

**Requirements → Architecture → Hardware → Software → System Behavior → Verification → Traceability**

The resulting repository provides both a working embedded prototype and the supporting engineering documentation used to define, implement, and verify the system.

**Project:** Industrial Equipment Health Monitoring System
**Author:** Ismael Mfumu
**Type:** Embedded Systems / Systems Engineering Prototype
**Platform:** Arduino-based embedded controller
