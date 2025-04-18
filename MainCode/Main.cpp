// C++ code
//
int Ultrasonic = 0;

int Force = 0;

int unnamed = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

int counter;

int counter2;

void setup()
{
  pinMode(A4, INPUT);
  pinMode(3, INPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A5, INPUT);
  pinMode(6, INPUT);
  pinMode(1, INPUT);
  pinMode(4, INPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  Force = analogRead(A4);
  Ultrasonic = 0.01723 * readUltrasonicDistance(10, 11);
  if (Force > 400 && (Ultrasonic <= 40 && digitalRead(3) == 0)) {
    delay(1000); // Wait for 1000 millisecond(s)
    for (counter = 0; counter < 10; ++counter) {
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(5, HIGH);
      delay(300); // Wait for 300 millisecond(s)
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
      digitalWrite(5, LOW);
      delay(300); // Wait for 300 millisecond(s)
    }
  }
  Force = analogRead(A5);
  Ultrasonic = 0.01723 * readUltrasonicDistance(13, 12);
  if (Force > 400 && (Ultrasonic <= 40 && digitalRead(6) == 0)) {
    delay(1000); // Wait for 1000 millisecond(s)
    for (counter2 = 0; counter2 < 10; ++counter2) {
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(5, HIGH);
      delay(300); // Wait for 300 millisecond(s)
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
      digitalWrite(5, LOW);
      delay(300); // Wait for 300 millisecond(s)
    }
  }
  if (digitalRead(1) == 1 && (digitalRead(4) == 1 && digitalRead(6) == 1)) {
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(2, HIGH);
  }
  if (digitalRead(1) == 0 && (digitalRead(4) == 1 && digitalRead(6) == 1)) {
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(2, LOW);
  }
}
