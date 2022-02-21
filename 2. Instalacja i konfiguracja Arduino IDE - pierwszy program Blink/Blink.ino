
// W funkcji SETUP umieszczamy wszystkie informacje początkowe
// niezbędne do uruchomienia programu np. czy dany PIN w Arduino
// (np. PIN 2) ma być traktowany jako WEJŚCIE (INPUT), czy WYJŚCIE
// (OUTPUT).

void setup()
{
  // Informujemy Arduino, że PIN 2 będzie wysyłać sygnał
  pinMode(2, OUTPUT);
}

// W funkcji LOOP znajduje się cały algorytm. Każda instrukcja
// wykonywana jest krok po kroku (linijka po linijce).

void loop()
{
  // Wysyłamy na PIN 2 stan WYSOKI (logiczne 1 - HIGH)  
  digitalWrite(2, LOW);
  //Odczekujemy 1 sekundę (1000 milisekund)
  delay(1000);
  // Wysyłamy na PIN 2 stan NISKI (logiczne 0 - LOW)
  digitalWrite(2, HIGH);
  //Odczekujemy 1 sekundę (1000 milisekund)
  delay(1000);  
}
