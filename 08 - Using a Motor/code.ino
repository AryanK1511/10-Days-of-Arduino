const int switchPin = 2;
const int ledPin = 7;
const int motorPin = 8;
int switchState  = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  switchState = digitalRead(switchPin);

  if (switchState == HIGH) {
    digitalWrite(motorPin, HIGH);
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(motorPin, LOW);
    digitalWrite(ledPin, LOW);
  }
}