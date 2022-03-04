## Informacje wstępne:

Przed przystąpieniem do zajęć warto zapoznać się z informacjami zawartymi w kursie Forbot odnośnie:
- [podstaw programowania wejść i wyjść](https://forbot.pl/blog/kurs-arduino-podstawy-programowania-porty-io-id3648);
- [przetwornikach ADC](https://forbot.pl/blog/kurs-arduino-pomiar-napiecia-przetwornik-adc-id3819).

## Cel zajęć:
1. Omówienie układu wejść i wyjść Arduino.
2. Omówienie zasady działania przycisków.
3. Omówienie roli rezystorów podciągająych *pull up* oraz *pull down*.
4. Zbudowanie prostego układu składającego się z diody LED, dwóch przycisków oraz potencjometra.
5. Implementacja prostego programu wykorzystującego wiedzę z układów wejść i wyjść.

## Zadanie:
1. Podłącz Arduino do komputera za pośrednictwem przewodu USB A-B i uruchom program Arduino IDE.
2. Omów z nauczycielem zasadę działania przycisków i rezystorów podciągających.
3. Zbuduj prosty [schemat przedstawiony poniżej](https://github.com/Arillos/Arduino-EKOS-/blob/main/4.%20Uk%C5%82ady%20wej%C5%9Bcia%2C%20wyj%C5%9Bcia%20(diody%20LED%2C%20przyciski%20oraz%20potencjometry)/uk%C5%82ady%20we-wy.JPG).
4. Zweryfikuj, wgraj i omów z nauczycielem działanie programu [przycisk z wbudowanym rezystorem podciągającym](https://github.com/Arillos/Arduino-EKOS-/blob/main/4.%20Uk%C5%82ady%20wej%C5%9Bcia%2C%20wyj%C5%9Bcia%20(diody%20LED%2C%20przyciski%20oraz%20potencjometry)/przycisk_z_pullup.ino).
5. Zweryfikuj, wgraj i omów z nauczycielem działanie programu [przycisk z fizycznym rezystorem podciągającym](https://github.com/Arillos/Arduino-EKOS-/blob/main/4.%20Uk%C5%82ady%20wej%C5%9Bcia%2C%20wyj%C5%9Bcia%20(diody%20LED%2C%20przyciski%20oraz%20potencjometry)/przycisk_bez_pullup.ino).
6. Zweryfikuj, wgraj i omów z nauczycielem działanie programu wykorzystującego [potencjometr](https://github.com/Arillos/Arduino-EKOS-/blob/main/4.%20Uk%C5%82ady%20wej%C5%9Bcia%2C%20wyj%C5%9Bcia%20(diody%20LED%2C%20przyciski%20oraz%20potencjometry)/potencjometr.ino).
7. Zrealizuj algorytm, który na podstawie informacji o stanie dwóch przycisków i wartości odczytanej z potencjometra będzie działał w sposób następujący:
- w przypadku gdy żaden z przycisków nie jest naciśnięty i wartość odczytana z potencjometra jest mniejsza od 500: dida LED się nie świeci;
- w przypadku gdy żaden z przycisków nie jest naciśnięty i wartość odczytana z potencjometra jest większa lub równa 500: dioda LED świeci się w sposób ciągły;
- w przypadku gdy jeden z przycisków jest wciśnięty i wartość odczytana z potencjometra jest mniejsza od 500: dida LED mruga z częstotliwością 2 sekund;
- w przypadku gdy jeden z przycisków jest wciśnięty i wartość odczytana z potencjometra jest większa lub równa 500: dida LED mruga z częstotliwością 3 sekund;
- w przypadku gdy oba przyciski są wciśnięte (dowolna wartość odczytana z potencjometru) wyświetl w MPS komunikat *"Znalazłeś easter ega!"*.

## Schemat połączenia:

![Schemat not found](https://github.com/Arillos/Arduino-EKOS-/blob/main/4.%20Uk%C5%82ady%20wej%C5%9Bcia%2C%20wyj%C5%9Bcia%20(diody%20LED%2C%20przyciski%20oraz%20potencjometry)/uk%C5%82ady%20we-wy.JPG)

## Przycisk z wbudowanym rezystorem podciągającym:
```c++
void setup()
{
  pinMode(13, OUTPUT);  // Dioda LED
  pinMode(6, INPUT_PULLUP);  // Przycisk z fizycznym rezystorem podciągającym
}


void loop()
{
  // Jeśli na pinie 6 jest stan wysoki HIGH (logiczne 1) to ...
  if (digitalRead(6) == 1)  
  {
    digitalWrite(13, HIGH);
  }
  // W przeciwnym razie
  else
  {
    digitalWrite(13, LOW);
   }
}

```
## Przycisk z fizycznym rezystorem podciągającym:
```c++
void setup()
{
  pinMode(13, OUTPUT);  // Dioda LED
  pinMode(6, INPUT);  // Przycisk z fizycznym rezystorem podciągającym
}


void loop()
{
  // Jeśli na pinie 6 jest stan wysoki HIGH (logiczne 1) to ...
  if (digitalRead(6) == 1)  
  {
    digitalWrite(13, HIGH);
  }
  // W przeciwnym razie
  else
  {
    digitalWrite(13, LOW);
   }
}

```
## Potencjometr:

```c++

int wartosc = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);  // Dioda LED
}


void loop()
{
  
  wartosc = analogRead(A0);
  Serial.println(wartosc);
 
  if (wartosc >= 600) 
  {
    digitalWrite(13, HIGH);
  }
  // W przeciwnym razie
  else
  {
    digitalWrite(13, LOW);
   }
}

```

## Rezultat:
Zrealizowany skrypt z **zadania 7** prześlij na: ariel_antonowicz@ekos.edu.pl
