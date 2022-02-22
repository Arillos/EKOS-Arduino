## Informacje wstępne:

Przed przystąpieniem do zajęć warto zapoznać się z informacjami zawartymi w źródłach:
- kurs Forbot: [wyświetlacze LCD](https://forbot.pl/blog/kurs-arduino-wyswietlacz-tekstowy-lcd-id4263);
- kurs Forbot: [serwomechanizmy](https://forbot.pl/blog/kurs-arduino-silniki-pwm-serwomechanizm-zewnetrzne-biblioteki-id3913).

## Cel zajęć:
1. Omówienie dzaiłania podstawowych elementów wykonawczych.
2. Omówienie zasady działania PWM.
3. Omówienie i przedstawienie działania wyświetlacza LCD.
4. Omówienie i przedstawienie działania serwomechanizmów.
5. Realizacja prostego układu symulujące pracę szlabanu.

## Zadanie:
1. Podłącz Arduino do komputera za pośrednictwem przewodu USB A-B i uruchom program Arduino IDE.
2. Omów z nauczycielem zasadę działania PWM.
3. Omów z nauczycielem zasadę działania podstawowych elementów wykonawczych.
4. Zbuduj prosty układ wg informacji podanych poniżej.
5. Napisz program, który będzie symulatorem szlabanu. Wykorzystaj następujące elementy:
- przycisk: umożliwiający otwarcie szlabanu;
- dioda LED czerwona + rezystor: sygnalizuje zamknięty szlaban (zakaz przejazdu);
- dioda LED zielona + rezystor: sygnalizuje otwarty szlaban (możliwość przejazdu);
- wyświetlacz LCD: sygnalizuje informacje o aktualnym etapie algorytmu (np. szlaban zamknięty, szlaban otwarty, otwieranie szlabanu, zakmykanie szlabanu, szlaban zamknie sie za 5 sekund).

## Sposób podłączenia elementów:
1. Wyświetlacz LCD (z konwerterem I2C):
  - **( VCC )** oznacza zasilanie VCC 5V;
  - **( SDA )** oznacza sygnał danych I2C (PIN A4);
  - **( SCL )** oznacza sygnał zegarowy I2C (PIN A5);
  - **( GND )** oznacza masę układu (GND).
2. Serwomechanizm:
  - **( CZERWONY )** oznacza zasilanie VCC 5V;
  - **( POMARAŃCZOWY )** oznacza PIN sygnałowy osbsługujący PWM (np. ~3);
  - **( BRĄZOWY )** oznacza masę układu (GND).


## Skrypt - LCD:
### Weryfikacja adresu urządzenia:
```c++
 #include <Wire.h>
  
void setup()
{
  Wire.begin();
   Serial.begin(9600);
  while (!Serial);             // Leonardo: wait for serial monitor
  Serial.println("\nI2C Scanner");
}
 
 void loop()
{
  byte error, address;
  int nDevices;
 
  Serial.println("Scanning...");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
 
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
 
  delay(5000);           // wait 5 seconds for next scan
}
```

### Wyświetlanie tekstu na wyświetlaczu (po zweryfikowaniu adresu):
```c++
 
#include <LiquidCrystal_I2C.h>  
#include <OneWire.h>
LiquidCrystal_I2C lcd(0x3F, 20, 4);  // Ustawienie adresu ukladu na wskazany z poprzedniego programu np. 0x3F
void setup()  
{
  lcd.init();                       // Inicjalizacja LCD 
  
  lcd.backlight();                  // zalaczenie podwietlenia 
  lcd.setCursor(0,0);               // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna)
  lcd.print("Hello EKOS!");
  delay(500);
  lcd.setCursor(0,1);               
  lcd.print("INFORMATYKA JEST ..");
  lcd.setCursor(0,2);               
  lcd.print("SUPER! :)");
  lcd.setCursor(0,3);               
  lcd.print("....... :) >>");
}
void loop() 
{

}
```
## Skrypt - serwomechanizm:

```c++

#include <Servo.h> //Biblioteka odpowiedzialna za serwa
 
Servo serwomechanizm;  //Tworzymy obiekt, dzięki któremu możemy odwołać się do serwa 
int pozycja = 0; //Aktualna pozycja serwa 0-180
int zmiana = 6; //Co ile ma się zmieniać pozycja serwa?
 
void setup() 
{ 
  serwomechanizm.attach(3);  //Serwomechanizm podłączony do pinu 9
} 
 
void loop() 
{  
  if (pozycja < 180) { //Jeśli pozycja mieści się w zakresie
    serwomechanizm.write(pozycja); //Wykonaj ruch
  } else { //Jeśli nie, to powrót na początek
    pozycja = 0;
  }    
  
  pozycja = pozycja + zmiana; //Zwiększenie aktualnej pozycji serwa
  delay(200); //Opóźnienie dla lepszego efektu                        
}
```

## Rezultat:
Zrealizowany skrypt z **zadania 5** prześlij na: ariel_antonowicz@ekos.edu.pl
