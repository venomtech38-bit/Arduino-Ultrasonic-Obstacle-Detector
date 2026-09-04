/*
  Arduino Ultrasonic Obstacle Detector
  Sensor: HC-SR04
  Board: Arduino UNO

  Wiring:
  HC-SR04 VCC  -> 5V
  HC-SR04 GND  -> GND
  HC-SR04 TRIG -> D9
  HC-SR04 ECHO -> D10

  LED:
  LED + (through 220 ohm resistor) -> D7
  LED - -> GND

  Buzzer:
  Buzzer + -> D8
  Buzzer - -> GND
*/

const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 7;
const int buzzerPin = 8;

long duration;
float distanceCm;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo time
  duration = pulseIn(echoPin, HIGH, 30000);

  // Calculate distance
  if (duration == 0) {
    distanceCm = -1;
  } else {
    distanceCm = duration * 0.0343 / 2.0;
  }

  Serial.print("Distance: ");

  if (distanceCm < 0) {
    Serial.println("Out of range");
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  } 
  else {
    Serial.print(distanceCm);
    Serial.println(" cm");

    // Obstacle detected within 20 cm
    if (distanceCm <= 20) {
      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, 1000);
    } 
    else {
      digitalWrite(ledPin, LOW);
      noTone(buzzerPin);
    }
  }

  delay(100);
}