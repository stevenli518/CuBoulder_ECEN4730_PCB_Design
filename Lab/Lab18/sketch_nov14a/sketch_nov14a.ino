void setup() { 
  DDRB = B00111111; 
  pinMode(7, OUTPUT); 
  digitalWrite(7, LOW); 
} 
void loop() { 
  PORTB = B00111101; 
  delayMicroseconds(4); 
  PORTB = B00000001; 
  delay(1); 
 
  digitalWrite(7, HIGH); 
  delayMicroseconds(400); 
  digitalWrite(7, LOW); 
  delay(10); 
} 
