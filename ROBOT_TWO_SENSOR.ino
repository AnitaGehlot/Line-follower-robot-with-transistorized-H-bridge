#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 3, 2, 1, 0);
void setup()
{
   lcd.begin(16, 2);
  //start serial connection
 // Serial.begin(9600);
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  //read the pushbutton value into a variable
  int SEN1 = digitalRead(5);
  int SEN2 = digitalRead(6);
  //print out the value of the pushbutton
  //Serial.println(sensorVal);

  // Keep in mind the pullup means the pushbutton's
  // logic is inverted. It goes HIGH when it's open,
  // and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if ((SEN1 == LOW)&&(SEN2 == HIGH))
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    lcd.setCursor(0, 1);
    lcd.print("MOTION LEFT");
    delay(20);
    lcd.clear();
  } 
   if ((SEN1 == HIGH)&&(SEN2 == LOW))
  {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11, LOW);
    lcd.setCursor(0, 1);
    lcd.print("MOTION RIGHT");
    delay(20);
    lcd.clear();
  }
  
  else 
  {
     digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    lcd.setCursor(0, 1);
    lcd.print("MOTION FORWARD");
    delay(20);
    lcd.clear();
  }
}
