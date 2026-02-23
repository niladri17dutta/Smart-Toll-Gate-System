#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define TRIG 9
#define ECHO 8
#define SERVO_PIN 6
#define DIST_LIMIT 50       // Distance threshold (cm)
#define MAX_DISTANCE 400    // Ignore unrealistic readings

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo gate;

int count = 0;

bool vehicleDetected = false;
bool gateOpen = false;

unsigned long gateOpenTime = 0;
const unsigned long gateDuration = 5000;  // Gate stays open for 5 seconds

void setup() {
  Serial.begin(9600);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  lcd.init();
  lcd.backlight();

  gate.attach(SERVO_PIN);
  gate.write(0);  // Gate closed

  lcd.setCursor(0, 0);
  lcd.print("Toll Gate Ready");
  delay(1000);
  lcd.clear();
}

// --------------------------------------------------

void loop() {

  long distance = getDistance();

  // Ignore invalid readings
  if (distance <= 0 || distance > MAX_DISTANCE) {
    return;
  }

  // Display distance
  lcd.setCursor(0, 0);
  lcd.print("Dist:");
  lcd.print(distance);
  lcd.print("cm   ");

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // -------- Vehicle Entry Detection --------
  if (distance < DIST_LIMIT && !vehicleDetected) {
    vehicleDetected = true;
    openGate();
  }

  // -------- Reset Detection When Vehicle Leaves --------
  if (distance >= DIST_LIMIT && vehicleDetected && !gateOpen) {
    vehicleDetected = false;
  }

  // -------- Auto Close Gate (Non-Blocking) --------
  if (gateOpen && millis() - gateOpenTime >= gateDuration) {
    closeGate();
  }

  // Display vehicle count
  lcd.setCursor(0, 1);
  lcd.print("Count:");
  lcd.print(count);
  lcd.print("     ");
}

long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000);
  long distance = duration * 0.034 / 2;

  return distance;
}

void openGate() {
  gate.write(90);  // Open gate
  gateOpen = true;
  gateOpenTime = millis();

  count++;

  lcd.setCursor(0, 1);
  lcd.print("Vehicle Passed");
  Serial.println("Gate Opened");
}

void closeGate() {
  gate.write(0);   // Close gate
  gateOpen = false;

  Serial.println("Gate Closed");
}