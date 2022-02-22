
## Cel zajęć:
1. Omówienie dzaiłania buzzera i głośnika.
2. Realizacja prostych układów prezentujących działanie omawianych elementów.
3. Realizacja prostego pianina.


## Zadanie:
1. Podłącz Arduino do komputera za pośrednictwem przewodu USB A-B i uruchom program Arduino IDE.
2. Zbuduj prosty układ wg informacji podanych poniżej.
3. Napisz program, symulujący pianino składające się z 8 dzwięków. Dzwięki, jakie należy zagrać będą odczytywane z MPS.

## Sposób podłączenia elementów:
1. Buzzer (Pin sygnałowy PMW):

![Schemat not found](https://github.com/Arillos/Arduino-EKOS-/blob/main/8.%20Buzzer%20i%20g%C5%82o%C5%9Bnik/buzzer.JPG).

2. Głośnik:

![Schemat not found](https://github.com/Arillos/Arduino-EKOS-/blob/main/8.%20Buzzer%20i%20g%C5%82o%C5%9Bnik/glo%C5%9Bnik_schemat.jpg).

## Skrypt - Buzzer:
```c++
const int buzzer = 9;

void setup(){
  pinMode(buzzer, OUTPUT); 
}

void loop(){
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec 
}

```
## Skrypt - głośnik:
** Przykładowe programy grające melodie zostały umieszczone poniżej** :

1. Melodia 1: [link](https://github.com/Arillos/Arduino-EKOS-/blob/main/8.%20Buzzer%20i%20g%C5%82o%C5%9Bnik/glosnik_1.ino).
2. Melodia 2: [link](https://github.com/Arillos/Arduino-EKOS-/blob/main/8.%20Buzzer%20i%20g%C5%82o%C5%9Bnik/glosnik_2.ino).
3. Melodia 3: [link](https://github.com/Arillos/Arduino-EKOS-/blob/main/8.%20Buzzer%20i%20g%C5%82o%C5%9Bnik/glosnik_3.ino).
4. Melodia 4: [link](https://github.com/Arillos/Arduino-EKOS-/blob/main/8.%20Buzzer%20i%20g%C5%82o%C5%9Bnik/glosnik_4.ino).
5. Więcej ciekawych melodi: [link](https://github.com/robsoncouto/arduino-songs).
6. Gama: [link](https://github.com/Arillos/Arduino-EKOS-/blob/main/8.%20Buzzer%20i%20g%C5%82o%C5%9Bnik/gama.ino).




## Rezultat:
Zrealizowany skrypt z **zadania 3** prześlij na: ariel_antonowicz@ekos.edu.pl
