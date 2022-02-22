## Informacje wstępne:

Przed przystąpieniem do zajęć warto zapoznać się z informacjami zawartymi w źródłach:
- sklep Botland: [rezystancyjny czujnik światła](https://botland.com.pl/czujniki-swiatla-i-koloru/16560-czujnik-swiatla-ldr-rezystancyjny-dla-arduino-okystar.html);
- kurs Forbot: [fotorezystor](https://forbot.pl/blog/leksykon/fotorezystor);
- kurs Forbot [kontaktron](https://forbot.pl/blog/kurs-arduino-ii-przerwania-kontaktron-czujnik-pir-id16792).

## Cel zajęć:
1. Omówienie działania kontaktronu oraz fotorezystoru.
2. Realizacja algorytmu "Inteligente oświetlenie".

## Zadanie:
1. Podłącz Arduino do komputera za pośrednictwem przewodu USB A-B i uruchom program Arduino IDE.
2. Zrealizuj układ wykorzystujący rezystancyjny czujnik światła oraz kontaktron (sposób podłączenia elementów znajduje się poniżej).
3. Zaprojektuj i zrealizuj układ inteligentnego oświetlenia (stopień świecenia diody (PWM) uzależnij od jasności w pomieszczeniu).

## Sposób podłączenia elementów:
1. Kontaktron:
  - **( PIN 1 )** wyjście cyfrowe (np. PIN 2);
  - **( PIN 2 )** masa układu (GND).
  
2. Serwomechanizm:
  - **( A0 )** oznacza wyjście analogowe (np. A5);
  - **( D0 )** oznacza wyjście cyfrowe (np. 3);
  - **( VCC )** oznacza zasilanie VCC 5V;
  - **( GND )** oznacza masę układu (GND).


## Skrypt - kontaktron:
```c++
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
```

## Skrypt - rezystancyjny czujnik światła:

```c++
void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  
  Serial.println(digitalRead(3));
  Serial.println(analogRead(A5));
  delay(1000);
}
```

## Rezultat:
Zrealizowany skrypt z **zadania 3** prześlij na: ariel_antonowicz@ekos.edu.pl
