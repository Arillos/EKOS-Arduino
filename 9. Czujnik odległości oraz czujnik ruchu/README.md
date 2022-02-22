## Informacje wstępne:

Przed przystąpieniem do zajęć warto zapoznać się z informacjami zawartymi w źródłach:
- kurs Forbot: [czujnik ruchu PIR](https://forbot.pl/blog/kurs-arduino-ii-przerwania-kontaktron-czujnik-pir-id16792);
- kurs Forbot: [czujnik odległości](https://forbot.pl/blog/kurs-arduino-czujnik-odleglosci-hc-sr04-funkcje-id4290).

## Cel zajęć:
1. Omówienie działania czujnika ruchu i odległości.
2. Wprowadzenie do funkcji.
3. Realizacja prostych układów prezentujących działanie omawianych elementów.
4. Realizacja algorytmu symulującego czujnik parkowania.

## Zadanie:
1. Podłącz Arduino do komputera za pośrednictwem przewodu USB A-B i uruchom program Arduino IDE.
2. Zbuduj prosty układ wg informacji podanych poniżej.
3. Napisz program, symulujący czujnik parkowania składający się z 3 diod, głośnika i czujnika odległości.

## Sposób podłączenia elementów:
1. Czujnik ruchu PIR:
  - **( VCC )** oznacza zasilanie VCC 5V;
  - **( OUT )** oznacza sygnał cyfrowy (np. PIN 2);
  - **( GND )** oznacza masę układu (GND).

2. Ultradźwiękowy czujnik odległości:
  - **( VCC )** oznacza zasilanie VCC 5V;
  - **( TRIG )** oznacza sygnał cyfrowy (np. PIN 12);
  - **( ECHO )** oznacza sygnał PWM (np. PIN 11);
  - **( GND )** oznacza masę układu (GND).

## Skrypt - czujnik ruchu:

```c++

int pirPin = 2;                     // PIR PIN
int pirStat = 0;                    // PIR STATUS
void setup() {

 pinMode(pirPin, INPUT);     
 Serial.begin(9600);
}
void loop(){
 pirStat = digitalRead(pirPin); 
 if (pirStat == HIGH) {            // if motion detected

   Serial.println("Wykryto ruch");
 } 
 else {
   Serial.println("Nie wykryto ruch");
 }
 delay(1000);
} 
```

## Skrypt - czujnik odległości:

```c++
#define trigPin 12
#define echoPin 11

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); //Pin, do którego podłączymy trig jako wyjście
  pinMode(echoPin, INPUT); //a echo, jako wejście
}

void loop() {  
  
  int jakDaleko = zmierzOdleglosc();
  Serial.println(jakDaleko);
  delay(100);
} 

int zmierzOdleglosc() {
  long czas, dystans;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  czas = pulseIn(echoPin, HIGH);
  dystans = czas / 58;

  return dystans;
}

```


## Rezultat:
Zrealizowany skrypt z **zadania 3** prześlij na: ariel_antonowicz@ekos.edu.pl
