const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 5000;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i <=4; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - previousTime > interval) {
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led ++;
    if (led == 4) {}
  }

  switchState = digitalRead(switchPin);
  Serial.println("State " + String(switchState));

  if (switchState != prevSwitchState) {
    for (int x = 2; x <= 4; x ++) {
      digitalWrite(x, LOW);
    }

    led = 2;
    previousTime = currentTime;
  }

  prevSwitchState = switchState;
}
