#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); // This indicates that the LCD has 16 columns and 2 rows
  pinMode(switchPin, INPUT);
  lcd.print("Ask the");
  lcd.setCursor(0, 1); // These are the coordinates of the first column on the second line // setCursor(coulmn, row)
  lcd.print("Crystal Ball");
}

void loop() {
  switchState = digitalRead(switchPin);
  Serial.println(switchState);

  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = random(8);
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("The ball says:");
  lcd.setCursor(0, 1);

  switch(reply) {
    case 0:
    lcd.print("King");
    break;
    case 1:
    lcd.print("James");
    break;
    case 2:
    lcd.print("Fail");
    break;
    case 3:
    lcd.print("Rich");
    break;
    case 4:
    lcd.print("God");
    break;
    case 5:
    lcd.print("Best");
    break;
    case 6:
    lcd.print("Worst");
    break;
    case 7:
    lcd.print("Amazing");
    break;
  }

  prevSwitchState = switchState;
}
