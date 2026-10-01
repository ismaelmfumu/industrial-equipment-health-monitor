# Industrial Equipment Health Monitoring System
## By: Ismael Mfumu

## Overview

An embedded condition-monitoring prototype designed to demonstrate
temperature and vibration monitoring, equipment health assessment,
fault detection, operator notification, and data logging.

The system uses an Arduino-based embedded controller to acquire
sensor data and classify equipment condition as NORMAL, WARNING,
CRITICAL, or SENSOR_FAULT.

## Engineering Problem

Industrial equipment can develop abnormal operating conditions
before complete failure. A monitoring system can continuously
observe operating parameters and provide an operator with an
early indication of abnormal behavior.

This project explores the design of a small embedded monitoring
system for a simulated industrial asset.

## System Architecture

```text
Sensors
   ↓
Sensor Acquisition
   ↓
Signal Processing
   ↓
Health Assessment
   ↓
State Machine
   ↓
HMI / Alarm / Logging
