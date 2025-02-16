#define TRIG 2
#define ECHO 3
#define LED 5
#define BUZZER 6

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2; // Convert to cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= 10) { // If object is within 10cm
    digitalWrite(LED, HIGH);
    digitalWrite(BUZZER, HIGH);
  } else {
    digitalWrite(LED, LOW);
    digitalWrite(BUZZER, LOW);
  }
  
  delay(500);
}
