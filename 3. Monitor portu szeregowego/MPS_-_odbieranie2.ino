
String odebraneDane = ""; // Deklaracja zmiennej typu String o nazwie odebraneDane

void setup() {
  Serial.begin(9600);     // Uruchomienie komunikacji
}

void loop() {

  if (Serial.available() > 0)                                         // Jeżeli Arduino odebrało dane to ..
  {       
      odebraneDane = Serial.readStringUntil('\n');                    // Odczytaj wszystkie znaki do momentu wystąpienia znaku nowej lini i zapisz je w zmiennej odebraneDane
      Serial.println("Odebrane dane to: " + odebraneDane + ".");        // Wyświetl komunikat w MPS 
  }
}
