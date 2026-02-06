/*
  Project Title : Smart Transformer Condition Monitoring and Self-Balancing System
  Controller    : ESP32
  Description   :
    - Monitors transformer temperature and load current
    - Detects abnormal operating conditions
    - Activates relay for protection / load balancing
    - Designed for smart grid and power system research
*/

#include <OneWire.h>
#include <DallasTemperature.h>

// ---------------- PIN DEFINITIONS ----------------
#define TEMP_PIN      4      // DS18B20 data pin
#define CURRENT_PIN   34     // ACS712 analog output
#define RELAY_PIN     26     // Relay control

// ---------------- SYSTEM LIMITS ------------------
#define TEMP_LIMIT    70.0   // °C (safe transformer limit)
#define CURRENT_LIMIT 5.0    // Amps (example threshold)

// ---------------- SENSOR SETUP -------------------
OneWire oneWire(TEMP_PIN);
DallasTemperature tempSensor(&oneWire);

// ------------------------------------------------
void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Relay OFF initially

  tempSensor.begin();

  Serial.println("==============================================");
  Serial.println(" Smart Transformer Condition Monitoring System ");
  Serial.println("==============================================");

  if (tempSensor.getDeviceCount() == 0) {
    Serial.println("Temperature sensor not detected!");
    while (1);
  }

  Serial.println("System Initialized Successfully");
}

// ------------------------------------------------
void loop() {
  // -------- TEMPERATURE READING --------
  tempSensor.requestTemperatures();
  float temperature = tempSensor.getTempCByIndex(0);

  // -------- CURRENT READING ------------
  int rawADC = analogRead(CURRENT_PIN);
  float voltage = (rawADC / 4095.0) * 3.3;
  float current = (voltage - 1.65) / 0.066; // ACS712 30A model

  // -------- DISPLAY DATA ---------------
  Serial.println("----------------------------------");
  Serial.print("Transformer Temperature : ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Load Current             : ");
  Serial.print(current);
  Serial.println(" A");

  // -------- CONDITION MONITORING -------
  if (temperature > TEMP_LIMIT || abs(current) > CURRENT_LIMIT) {
    Serial.println("ABNORMAL CONDITION DETECTED!");
    Serial.println("Activating Protection / Load Balancing");
    digitalWrite(RELAY_PIN, HIGH);  // Cut / shift load
  } else {
    Serial.println("Transformer Operating Normally");
    digitalWrite(RELAY_PIN, LOW);   // Normal operation
  }

  delay(2000);
}

