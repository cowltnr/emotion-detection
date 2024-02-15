#include <Wire.h>
#include <LiquidCrystal_I2C.h>

String receivedData = ""; // 수신된 데이터를 저장할 변수
LiquidCrystal_I2C lcd(0x27,20,4); // LCD 2004 I2C용 라이브러리
int RED = 7;
int GREEN = 6;
int BLUE = 5;

void setup() {
  pinMode(8, OUTPUT); // 신호등
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
  pinMode(RED, OUTPUT);   // LED 무드등
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  
  lcd.init();         // LCD 초기화
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) { // 시리얼 버퍼에 데이터가 있는지 확인
    String receivedData = ""; // 수신된 데이터를 저장할 문자열
    while (Serial.available() > 0) { // 시리얼 버퍼에 데이터가 있는 동안 반복
      char receivedChar = Serial.read(); // 바이트 읽기
      receivedData += receivedChar; // 읽은 바이트를 문자열에 추가

      if (receivedData.length() > 0) {
    Serial.print("값:");
    Serial.println(receivedData);
  }

  // 신호등 제어
  if (receivedData == "Happy") {
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    delay(3000); // 3초후 다음 코드 실행
  } else if (receivedData == "Neutral") {
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    delay(3000); // 3초후 다음 코드 실행
  } else if (receivedData == "Disgusted" || receivedData == "Surprised") {
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    delay(3000); // 3초후 다음 코드 실행
  } else if (receivedData == "Angry" || receivedData == "Sad" || receivedData == "Fearful") {
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    delay(3000); // 3초후 다음 코드 실행
  }

  // LCD 메시지 표시 후 딜레이
  lcd.backlight();
  lcd.setCursor(0,0); // 첫 번째 줄, 첫 번째 열
  lcd.print("Your emotion is");
  lcd.setCursor(0,2); // 세 번째 줄, 첫 번째 열
  lcd.print(receivedData); // 받은 감정 메시지 출력
  delay(100); // 3초후 다음 코드 실행

  // LED 무드등 제어
  
    //// happy
  if (receivedData == "Happy") {
    analogWrite(RED, 207);  
    analogWrite(GREEN, 226);
    analogWrite(BLUE, 241);  
    delay(3000);
    } // 3초후 다음 코드 실행

    //// Neutural
  else if (receivedData == "Neutral") {
    analogWrite(RED, 153);  
    analogWrite(GREEN, 202);
    analogWrite(BLUE, 235);  
    delay(3000); // 3초후 다음 코드 실행
  }
  

    //// Disgusted
  else if (receivedData == "Disgusted") {
    analogWrite(RED, 245);   // RED ON
    analogWrite(GREEN, 130);
    analogWrite(BLUE, 37);  
    delay(3000); // 3초후 다음 코드 실행
  }
    
    //// Surprised
  else if (receivedData == "Surprised") {
    analogWrite(RED, 253);   // RED ON
    analogWrite(GREEN, 225);
    analogWrite(BLUE, 79);  
    delay(3000); // 3초후 다음 코드 실행
  }  
    
    //// Angry
  else if (receivedData == "Angry") {
    analogWrite(RED, 253);   // RED ON
    analogWrite(GREEN, 225);
    analogWrite(BLUE, 79);  
    delay(3000); // 3초후 다음 코드 실행
  }  

    //// Sad
  else if (receivedData == "Sad") {
    analogWrite(RED, 245);   // RED ON
    analogWrite(GREEN, 130);
    analogWrite(BLUE,37);  
    delay(3000); // 3초후 다음 코드 실행
  }
    
    //// Fearful
  else if (receivedData == "Fearful") {
    analogWrite(RED, 255);   // RED ON
    analogWrite(GREEN, 214);
    analogWrite(BLUE, 172);  
    delay(3000); // 3초후 다음 코드 실행
  }
}

    }
    // UTF-8로 인코딩된 문자열 출력
    Serial.println(receivedData);
  }
  // 수신된 데이터 출력
  