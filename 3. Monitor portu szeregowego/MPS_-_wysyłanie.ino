void setup() {
  Serial.begin(9600);  // Uruchomienie komunikacji
  Serial.print("Dzień dobry EKOS!");    // Wyświetlenie w MPS: Dzień dobry EKOS!   (bez znaku nowej lini)
  Serial.print("\n");                   // Dodanie znaku nowej lini
  delay(1000);                          // Odczekaj 1 sekundę
  Serial.println("Dobranoc EKOS!");     // Wyświetlenie w MPS: Dobranoc EKOS! (wraz ze znakiem nowej lini) 
  delay(1000);                          // Odczekaj 1 sekundę
}

void loop() {
  
  Serial.println("Tekst powtarzający się co sekundę :) ");     // Wyświetlenie w MPS: Tekst potwarzający się co sekundę :)
  delay(1000);                                                 // Odczekaj 1 sekundę
  
}
