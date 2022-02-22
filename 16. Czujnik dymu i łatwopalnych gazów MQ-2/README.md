
## Cel zajęć:
1. Omówienie działania czujnika dymu i łatwopalnych gazów MQ-2.
2. Realizacja prostego czujnika wykrającego dym lub gaz.

## Zadanie:
1. Podłącz Arduino do komputera za pośrednictwem przewodu USB A-B i uruchom program Arduino IDE.
2. Zrealizuj układ wykorzystujący czujnik (sposób podłączenia elementów znajduje się poniżej).

## Sposób podłączenia cyfrowego czujnika dzwięku:
  - **( A0 )** oznacza wyjście analogowe (np. A5);
  - **( D0 )** oznacza wyjście cyfrowe (np. 2);
  - **( VCC )** oznacza zasilanie VCC 5V;
  - **( GND )** oznacza masę układu (GND).
  

## Skrypt - czujnik dymu i gazów łatwopalnych MQ-2:

/*
Progi detekcji: 

200ppm - 5000ppm LPG, propan
300 ppm - 5000 ppm butanu
5000 ppm - 20000 ppm metanu
300ppm - 5000ppm H2
100 ppm -2000 ppm alkoholu
 */
int wartoscAnalog = 0;
byte wartoscZmapowana = 0;        
char info[96];  

void setup() {
  Serial.begin(9600); 
  pinMode(2, INPUT);
} 
void loop() {
  wartoscAnalog = analogRead(A5);
  wartoscZmapowana = map(wartoscAnalog, 0, 1023, 0, 100);

  Serial.println(wartoscAnalog);
  Serial.println(wartoscZmapowana);
  
  if (wartoscZmapowana > 20) {
    Serial.print(info);
    Serial.println(digitalRead(2));
    Serial.println(" UWAGA! WYKRYTO GAZ LUB DYM ");
    }
  else {
    Serial.println(info);
    Serial.println(digitalRead(2));
    }
  delay(1000);
}
```

