// The two control pins tell the H-bridge which direction to spin the motor in
const int controlPin1 = 2;
const int controlPin2 = 3;

// When the enable Pin receives 5V, it turns the motor on
const int enablePin = 9;

// This is the switch that will control direction
const int directionSwitchPin = 4;

// This is the switch that will control whether the motor is ON or OFF
const int onOffStateSwitchPin = 5;

// This is the variable current supplied by the potentiometer
const int potPin = A0;

// Variables to hold values from inputs
int onOffState = 0;
int previousOnOffState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;
int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffStateSwitchPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
}

void loop() {
  onOffState = digitalRead(onOffStateSwitchPin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin) / 4;

  if (onOffState != previousOnOffState) {
    if (onOffState == HIGH) {
      motorEnabled = !motorEnabled;
    }
  }

  if (directionSwitchState != previousDirectionSwitchState) {
    if (directionSwitchState == HIGH) {
      motorDirection = !motorDirection;
    }
  }

  if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  } else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  if (motorEnabled == 1) {
    analogWrite(enablePin, motorSpeed);
  } else {
    analogWrite(enablePin, 0);
  }

  previousDirectionSwitchState = directionSwitchState;
  previousOnOffState = onOffState;
}
