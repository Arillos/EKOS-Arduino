String good_password = "tajne1234";       // Deklaracja zmiennej typu String o nazwie good_password
String alarm_password = "admin1234";      // Deklaracja zmiennej typu String o nazwie alarm_password
String password = "";                     // Deklaracja zmiennej typu String o nazwie password
    
void setup() {
  Serial.begin(9600);                     // Uruchomienie komunikacji
}

void loop() {

  if (Serial.available() > 0)                                         // Jeżeli Arduino odebrało dane to ..
  {       
      password = Serial.readStringUntil('\n');                        // Odczytaj wszystkie znaki do momentu wystąpienia znaku nowej lini i zapisz je w zmiennej password

      if (password == alarm_password)                                             // Jeżeli w zmiennej password jest to samo co w zmiennej alarm_password to ...
      {
        Serial.println("Wpisano hasło alarmowe! Dzwonię na 112");      
        // Kod wykonujący algorytm alarmowy
      }

      else if (password == good_password)                                         // W przeciwnym wypadku jeśli w zmiennej password jest to samo co w zmiennej good_password to ...
      {
        Serial.println("Wpisano prawidłowe hasło - zalogowano pomyślnie");         
        // Kod wykonujący algorytm 
           
      }
      else                                                                        // Jeśli żaden z powyższych warunków nie został spełniony to ..
      {
        Serial.println("Wpisano nie prawidłowe hasło");
        // Kod, który przykładowo zlicza liczbę nieprawidłowych prób

      }
      delay(1000);
  }
}
