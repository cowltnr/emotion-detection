int RED = 7;
int GREEN = 6;
int BLUE = 5;
  
void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);  
}
  
void loop()
{
  analogWrite(RED, 0);   // RED ON
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 255);  
  delay(1000);
 
  analogWrite(RED, 255);
  analogWrite(GREEN, 0); // GREEN ON
  analogWrite(BLUE, 255);  
  delay(1000);
 
  analogWrite(RED, 255);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 0);   // BLUE ON
  delay(1000);
}