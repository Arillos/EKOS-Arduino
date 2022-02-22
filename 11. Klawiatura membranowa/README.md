## Informacje wstępne:

Przed przystąpieniem do zajęć warto zapoznać się z informacjami zawartymi w źródłach:
- kurs Forbot: [klawiatura membranowa](https://forbot.pl/blog/kurs-arduino-ii-klawiatura-wlasny-system-alarmowy-id18341).


## Cel zajęć:
1. Omówienie dzaiłania klawiatury membranowej.
2. Omówienie instrukcji switch().
3. Realizacja centralki alarmowej.

## Zadanie:
1. Podłącz Arduino do komputera za pośrednictwem przewodu USB A-B i uruchom program Arduino IDE.
2. Zrealizuj układ wykorzystujący klawiaturę membranową (sposób podłączenia elementów znajduje się poniżej).
3. Zaprojektuj i zrealizuj centralkę antywłamaniową (dodaj wyświetlacz LCD, 2 diody i buzzer). 

## Sposób podłączenia klawiatury membranowej:

![Schemat not found](https://github.com/Arillos/Arduino-EKOS-/blob/main/11.%20Klawiatura%20membranowa/klawiatura_schemat.JPG)


## Skrypt - klawiatura membranowa:
```c++
#include "Keypad.h"

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3' , 'A'},
  {'4','5','6' , 'B'},
  {'7','8','9' , 'C'},
  {'*','0','#' , 'D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5};  //Piny, do których podłączamy wyprowadzenia od rzędów
byte colPins[COLS] = {6, 7, 8 , 9}; //Piny, do których kolumn wyprowadzenia od rzędów

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
 Serial.begin(9600);
}
  
void loop(){
 char key = keypad.getKey();
  
  if (key){
    Serial.print(key);
    Serial.print(", ");
  }

  if(key == '1')
  {
    Serial.println("Wpisano 1");
  } 
}
```


## Rezultat:
Zrealizowany skrypt z **zadania 3** prześlij na: ariel_antonowicz@ekos.edu.pl
