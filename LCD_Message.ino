#include <Wire.h>                     // i2C 통신을 위한 라이브러리
#include <LiquidCrystal_I2C.h>        // LCD 2004 I2C용 라이브러리
LiquidCrystal_I2C lcd(0x27,20,4);     //  0x3F or 0x27


void setup()
{
  lcd.init();                      // LCD 초기화
  lcd.backlight();                // 백라이트 켜기
  lcd.setCursor(0,0);             // 1번째, 1라인
  lcd.print("Your emotion is");
  lcd.setCursor(0,2);             // 3번째, 3라인
  lcd.print("Happy");

  delay(3000);
}

void loop() 
{

}
