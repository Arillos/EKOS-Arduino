## Informacje wstępne:

Przed przystąpieniem do zajęć warto zapoznać się z informacjami zawartymi w kursie Forbot odnośnie [komunikacji z komputerem](https://forbot.pl/blog/kurs-arduino-uart-komunikacja-z-komputerem-pc-zmienne-id3836).

## Cel zajęć:
1. Omówienie protokołu UART.
1. Omówienie roli debugowania w programowaniu.
2. Definicja **zmiennej**.
3. Wyświetlanie informacji o stanie programu w MPS (Monitorze Portu Szeregowego).
4. Odbieranie informacji z MPS.
5. Omówienie instrukcji warunkowych.

## Zadanie:
1. Podłącz Arduino do komputera za pośrednictwem przewodu USB A-B i uruchom program Arduino IDE.
2. Omów z nauczycielem rolę zmiennych w programowaniu oraz ich typy.
3. Zweryfikuj, wgraj i omów z nauczycielem działanie programu [Monitor Portu Szeregowego - wysyłanie]().
4. Zweryfikuj, wgraj i omów z nauczycielm działanie programu [Monitor Portu Szeregowego - obieranie sposób 1]().
5. Zweryfikuj, wgraj i omów z nauczycielm działanie programu [Monitor Portu Szeregowego - obieranie sposób 2]().
6. Zweryfikuj, wgraj i omów z nauczycielem działanie programu [Instrukcje Warunkowe]().
7. **Zmodyfikuj program z punktu 6. w taki sposób aby weryfikować login i hasło**.

> **Uruchomienie MPS: W programie Arduino IDE: Narzędzia / Monitor Portu Szeregowego Shift + Ctrl + M**

## Rodzaje zmiennych:
```c++
boolean logika = false;                   // boolean - wartość prawda (true) lub fałsz (false)
  
int liczba = 30000;                       // int - liczby całkowite z zakresu -32,768 do 32,767 (w Arduino Uno)
long duzaLiczba = 2000000;                // long - liczby całkowite z zakresu -2,147,483,648 do 2,147,483,647

float liczbaZmiennoprzecinkowa = 6.28;    // float - liczby rzeczywiste zajmujące w pamięci 4 bajty.

char znak = 'a';                          // char - przechowuje jeden znak
String zdanie = "EKOS WITA!";             // String - ciąg znaków

```
## Kod programu (MPS - wysyłanie):
```c++
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

```
## Kod programu (MPS - odbieranie):
### Sposób 1 (bez zmiennych):
```c++

void setup() {
  Serial.begin(9600);  // Uruchomienie komunikacji
}

void loop() {

  if (Serial.available() > 0)                             // Jeżeli Arduino odebrało dane to ..
  {       
      Serial.println(Serial.readStringUntil('\n'));       // Odczytaj wszystkie znaki do momentu wystąpienia znaku nowej lini
  }
}

```

### Sposób 2 (ze zmienną):
```c++
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
```

## Kod programu (instrukcje warunkowe):
```c++
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
```
### Dodatkowe informację o instrukcjach warunkowych, które warto wiedzieć:
```c++
  // && - AND (oba warunki muszą zostać spełnione aby wykonać instrukcję)
  if (password == alarm_password) && (wiek >= 12)     
  {
    // kod programu
  }

  // || - OR (tylko jeden z warunków musi zostać spełniony aby wykonać instrukcję
  if (password == alarm_password) || (wiek >= 12)      
  {
    // kod programu
  }
  
  // ===== Operatory:
  //      ==    równe
  //      !=    różne
  //      >     większe od
  //      >=    większe i równe od
  //      <     mniejsze od
  //      <=    mniejsze i równe od
  
  

```
## Rezultat:
Zrealizowany skrypt z **zadania 7** prześlij na: ariel_antonowicz@ekos.edu.pl
