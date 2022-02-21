void setup() {
  Serial.begin(9600);  // Uruchomienie komunikacji
}

void loop() {

  if (Serial.available() > 0)                             // Jeżeli Arduino odebrało dane to ..
  {       
      Serial.println(Serial.readStringUntil('\n'));       // Odczytaj wszystkie znaki do momentu wystąpienia znaku nowej lini
  }
}
