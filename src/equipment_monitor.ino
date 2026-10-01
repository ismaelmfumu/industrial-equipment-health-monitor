
/*
 * ============================================================
 * INDUSTRIAL EQUIPMENT HEALTH MONITORING SYSTEM
 * Embedded Systems Engineering Prototype
 *
 * Author: Ismael Mfumu
 * Project Type: Computer Systems Engineering Project
 * Platform: Arduino / Embedded Microcontroller
 *
 * Description:
 * This project is an embedded condition-monitoring prototype
 * designed to demonstrate the acquisition, processing, and
 * classification of industrial equipment health data.
 *
 * The system monitors temperature and vibration inputs,
 * evaluates equipment condition using defined health states,
 * detects sensor faults, provides local operator feedback,
 * and logs monitoring data for analysis.
 *
 * Health States:
 *   - NORMAL
 *   - WARNING
 *   - CRITICAL
 *   - SENSOR_FAULT
 *
 * NOTE:
 * This is an engineering prototype for demonstration,
 * testing, and portfolio purposes. Thresholds and hardware
 * are simplified and are not intended for direct industrial
 * deployment without further engineering validation.
 *
 * ============================================================
 */



#include <LiquidCrystal.h>

// =====================================================
// PIN DEFINITIONS
// =====================================================

#define TEMP_SENSOR A0

#define GREEN_LED 7
#define YELLOW_LED 6
#define RED_LED 8

#define BUZZER 9

#define VIBRATION_SENSOR 10


// =====================================================
// LCD
// RS, E, D4, D5, D6, D7
// =====================================================

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


// =====================================================
// EQUIPMENT STATES
// =====================================================

enum EquipmentState {

  NORMAL,

  WARNING,

  CRITICAL,

  SENSOR_FAULT
};


EquipmentState currentState = NORMAL;


// =====================================================
// SENSOR VARIABLES
// =====================================================

float temperatureC = 0.0;

int vibrationCount = 0;


// =====================================================
// VIBRATION EVENT DETECTION
// =====================================================

int lastVibrationState = HIGH;

unsigned long lastVibrationEvent = 0;

const unsigned long vibrationDebounceTime = 200;


// =====================================================
// TIMING
// =====================================================

unsigned long lastSensorRead = 0;

unsigned long lastDisplayUpdate = 0;

unsigned long lastLogTime = 0;

unsigned long lastVibrationReset = 0;


// =====================================================
// SYSTEM TIMING
// =====================================================

const unsigned long sensorInterval = 500;

const unsigned long displayInterval = 500;

const unsigned long logInterval = 1000;

const unsigned long vibrationWindow = 10000;


// =====================================================
// SETUP
// =====================================================

void setup() {

  Serial.begin(9600);

  lcd.begin(16, 2);


  // ---------------------------------------------------
  // Configure outputs
  // ---------------------------------------------------

  pinMode(GREEN_LED, OUTPUT);

  pinMode(YELLOW_LED, OUTPUT);

  pinMode(RED_LED, OUTPUT);

  pinMode(BUZZER, OUTPUT);


  // ---------------------------------------------------
  // Configure vibration input
  // ---------------------------------------------------

  pinMode(VIBRATION_SENSOR, INPUT_PULLUP);


  // ---------------------------------------------------
  // Initial output state
  // ---------------------------------------------------

  digitalWrite(GREEN_LED, LOW);

  digitalWrite(YELLOW_LED, LOW);

  digitalWrite(RED_LED, LOW);

  noTone(BUZZER);


  // ---------------------------------------------------
  // Startup display
  // ---------------------------------------------------

  lcd.clear();

  lcd.setCursor(0, 0);

  lcd.print("Equipment");


  lcd.setCursor(0, 1);

  lcd.print("Monitor Starting");


  delay(2000);

  lcd.clear();


  // ---------------------------------------------------
  // Serial logging header
  // ---------------------------------------------------

 
Serial.println("========================================");
Serial.println("Industrial Equipment Health Monitoring System");
Serial.println("Embedded Systems Engineering Prototype");
Serial.println("Author: Ismael Mfumu");
Serial.println("Computer Systems Engineering Project");
Serial.println("========================================");


  Serial.println();

  Serial.println(
    "Time(s),Temperature(C),Vibration,State"
  );


  // ---------------------------------------------------
  // Initialize timers
  // ---------------------------------------------------

  unsigned long currentTime = millis();

  lastSensorRead = currentTime;

  lastDisplayUpdate = currentTime;

  lastLogTime = currentTime;

  lastVibrationReset = currentTime;

  lastVibrationState = digitalRead(VIBRATION_SENSOR);
}


// =====================================================
// MAIN LOOP
// =====================================================

void loop() {

  unsigned long currentTime = millis();


  // ===================================================
  // 1. READ SENSORS
  // ===================================================

  if (currentTime - lastSensorRead >= sensorInterval) {

    readTemperature();

    detectVibration();

    lastSensorRead = currentTime;
  }


  // ===================================================
  // 2. RESET VIBRATION WINDOW
  // ===================================================

  if (currentTime - lastVibrationReset >= vibrationWindow) {

    vibrationCount = 0;

    lastVibrationReset = currentTime;
  }


  // ===================================================
  // 3. EVALUATE EQUIPMENT HEALTH
  // ===================================================

  evaluateEquipmentHealth();


  // ===================================================
  // 4. UPDATE DISPLAY AND OUTPUTS
  // ===================================================

  if (currentTime - lastDisplayUpdate >= displayInterval) {

    updateOutputs();

    lastDisplayUpdate = currentTime;
  }


  // ===================================================
  // 5. LOG DATA
  // ===================================================

  if (currentTime - lastLogTime >= logInterval) {

    logData();

    lastLogTime = currentTime;
  }
}


// =====================================================
// TEMPERATURE ACQUISITION
// =====================================================

void readTemperature() {

  int sensorValue = analogRead(TEMP_SENSOR);


  float voltage =
    sensorValue * (5.0 / 1023.0);


  temperatureC =
    (voltage - 0.5) * 100.0;
}


// =====================================================
// VIBRATION EVENT DETECTION
// =====================================================

void detectVibration() {

  int currentVibrationState =
    digitalRead(VIBRATION_SENSOR);


  // ---------------------------------------------------
  // Detect HIGH → LOW transition
  // ---------------------------------------------------

  if (
    lastVibrationState == HIGH &&
    currentVibrationState == LOW
  ) {

    unsigned long currentTime = millis();


    // -------------------------------------------------
    // Debounce vibration event
    // -------------------------------------------------

    if (
      currentTime - lastVibrationEvent
      >= vibrationDebounceTime
    ) {

      vibrationCount++;

      lastVibrationEvent = currentTime;


      Serial.print("Vibration event detected. Count = ");

      Serial.println(vibrationCount);
    }
  }


  lastVibrationState = currentVibrationState;
}


// =====================================================
// HEALTH ASSESSMENT
// =====================================================

void evaluateEquipmentHealth() {

  // ---------------------------------------------------
  // Sensor fault detection
  // ---------------------------------------------------

  if (
    temperatureC < -40.0 ||
    temperatureC > 125.0
  ) {

    currentState = SENSOR_FAULT;

    return;
  }


  // ---------------------------------------------------
  // Critical temperature
  // ---------------------------------------------------

  if (temperatureC > 60.0) {

    currentState = CRITICAL;

    return;
  }


  // ---------------------------------------------------
  // Critical vibration
  // ---------------------------------------------------

  if (vibrationCount >= 6) {

    currentState = CRITICAL;

    return;
  }


  // ---------------------------------------------------
  // Warning temperature
  // ---------------------------------------------------

  if (temperatureC >= 40.0) {

    currentState = WARNING;

    return;
  }


  // ---------------------------------------------------
  // Warning vibration
  // ---------------------------------------------------

  if (vibrationCount >= 3) {

    currentState = WARNING;

    return;
  }


  // ---------------------------------------------------
  // Otherwise system is normal
  // ---------------------------------------------------

  currentState = NORMAL;
}


// =====================================================
// OUTPUT CONTROL
// =====================================================

void updateOutputs() {

  // ---------------------------------------------------
  // Reset outputs
  // ---------------------------------------------------

  digitalWrite(GREEN_LED, LOW);

  digitalWrite(YELLOW_LED, LOW);

  digitalWrite(RED_LED, LOW);

  noTone(BUZZER);


  // ===================================================
  // NORMAL
  // ===================================================

  if (currentState == NORMAL) {

    digitalWrite(GREEN_LED, HIGH);


    lcd.clear();

    lcd.setCursor(0, 0);

    lcd.print("STATUS: NORMAL");


    lcd.setCursor(0, 1);

    lcd.print("T:");

    lcd.print(temperatureC, 1);

    lcd.print(" V:");

    lcd.print(vibrationCount);
  }


  // ===================================================
  // WARNING
  // ===================================================

  else if (currentState == WARNING) {

    digitalWrite(YELLOW_LED, HIGH);


    lcd.clear();

    lcd.setCursor(0, 0);

    lcd.print("STATUS: WARNING");


    lcd.setCursor(0, 1);

    lcd.print("T:");

    lcd.print(temperatureC, 1);

    lcd.print(" V:");

    lcd.print(vibrationCount);


    tone(BUZZER, 1000);
  }


  // ===================================================
  // CRITICAL
  // ===================================================

  else if (currentState == CRITICAL) {

    digitalWrite(RED_LED, HIGH);


    lcd.clear();

    lcd.setCursor(0, 0);

    lcd.print("STATUS: CRITICAL");


    lcd.setCursor(0, 1);

    lcd.print("T:");

    lcd.print(temperatureC, 1);

    lcd.print(" V:");

    lcd.print(vibrationCount);


    tone(BUZZER, 2000);
  }


  // ===================================================
  // SENSOR FAULT
  // ===================================================

  else if (currentState == SENSOR_FAULT) {

    digitalWrite(RED_LED, HIGH);


    lcd.clear();

    lcd.setCursor(0, 0);

    lcd.print("SENSOR FAULT");


    lcd.setCursor(0, 1);

    lcd.print("CHECK SENSOR");


    tone(BUZZER, 1500);
  }
}


// =====================================================
// DATA LOGGING
// =====================================================

void logData() {

  unsigned long elapsedTime =
    millis() / 1000;


  // ---------------------------------------------------
  // Timestamp
  // ---------------------------------------------------

  Serial.print(elapsedTime);

  Serial.print(",");


  // ---------------------------------------------------
  // Temperature
  // ---------------------------------------------------

  Serial.print(temperatureC, 1);

  Serial.print(",");


  // ---------------------------------------------------
  // Vibration count
  // ---------------------------------------------------

  Serial.print(vibrationCount);

  Serial.print(",");


  // ---------------------------------------------------
  // Equipment state
  // ---------------------------------------------------

  if (currentState == NORMAL) {

    Serial.println("NORMAL");
  }

  else if (currentState == WARNING) {

    Serial.println("WARNING");
  }

  else if (currentState == CRITICAL) {

    Serial.println("CRITICAL");
  }

  else {

    Serial.println("SENSOR_FAULT");
  }
}
