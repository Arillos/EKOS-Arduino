void setup() {
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(2) == LOW)
  {
    Serial.println("Wszystko dobrze");    
  }
  else
  {
    Serial.println("Ktoś chce się włamać!");
  }
  delay(1000);

}
