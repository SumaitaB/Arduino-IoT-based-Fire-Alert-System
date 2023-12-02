#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int gas;
int buzzer = 11;
void setup()
{
 lcd.init();
 lcd.backlight();
 Serial.begin(9600);
 pinMode(buzzer,OUTPUT);
}
void loop()
{
 gas = analogRead(A0);
 Serial.println(gas);
 lcd.setCursor(0,0);

 lcd.print("value = ");
 lcd.print(gas);
 if(gas>750)
 {
 tone(buzzer,400);
 delay(400);
 noTone(buzzer);
 delay(100);
 }
 else
 {
 noTone(buzzer);
 delay(1000);
 }
 delay(500);
 lcd.clear();
}
