#define LM35 A5
 
void setup(){
  Serial.begin(9600);
}
 
void loop(){
  //Przeliczenie odczytu ADC na temperaturę zgodnie z opisem z kursu
  float temperatura = ((analogRead(LM35) * 5.0) / 1024.0) * 100;

  //Wyslanie przez UART aktualnej temperatury
  Serial.print("Aktualna temperatura: ");
  Serial.print(temperatura);
  Serial.println("*C");

  delay(200);
}
