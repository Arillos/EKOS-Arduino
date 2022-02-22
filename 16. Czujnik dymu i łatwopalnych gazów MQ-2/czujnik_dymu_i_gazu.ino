int wartoscAnalog = 0;
byte wartoscZmapowana = 0;        
char info[96];  

void setup() {
  Serial.begin(9600); 
  pinMode(2, INPUT);
} 
void loop() {
  wartoscAnalog = analogRead(A5);
  wartoscZmapowana = map(wartoscAnalog, 0, 1023, 0, 100);

  Serial.println(wartoscAnalog);
  Serial.println(wartoscZmapowana);
  
  if (wartoscZmapowana > 20) {
    Serial.print(info);
    Serial.println(digitalRead(2));
    Serial.println(F(" UWAGA! WYKRYTO GAZ LUB DYM "));
    }
  else {
    Serial.println(info);
    Serial.println(digitalRead(2));
    }
  delay(1000);
}
