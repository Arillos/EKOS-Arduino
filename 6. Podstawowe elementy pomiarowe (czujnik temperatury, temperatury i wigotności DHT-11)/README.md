## Informacje wstępne:

Przed przystąpieniem do zajęć warto zapoznać się z informacjami zawartymi w następujących źródłach:
- Akademia Nettigo: [czujnik temperatury (sonda) DS18B20](http://akademia.nettigo.pl/ds18b20/);
- Kurs Forbot: [cyfrowy czujnik temperatury i wilgotności DHT-11](https://forbot.pl/blog/kurs-arduino-ii-cyfrowy-czujnik-wilgotnosci-dht11-id18417);
- Kurs Forbot: [termometr analogowy LM35](https://forbot.pl/blog/kurs-arduino-ii-termometry-analogowe-lm35-i-cyfrowe-ds18b20-id18414).

## Cel zajęć:
1. Omówienie podstawowych elementów pomiarowych.
2. Omówienie zjawiska występowania błędów pomiarowych oraz sposoby ich niwelowania.
3. Zbudowanie trzech prostych układów i implementacja skryptów odczytujących temperaturę i wilgotność względną RH.

## Zadanie:
1. Podłącz Arduino do komputera za pośrednictwem przewodu USB A-B i uruchom program Arduino IDE.
2. Omów z nauczycielem zasadę działania cyfrowych i analogowych czujników temperatury.
3. Zbuduj prosty układ wg informacji podanych poniżej.
4. Napisz program, który naprzemiennie odczytuje temperaturę ze wszystkich czujników. Oblicz średnią z 12 pomiarów i określ różnicę między czujnikami.

## Sposób podłączenia elementów:
1. Czujnik DHT-11:
  - **( + )** oznacza zasilanie VCC 5V;
  - **( OUT )** oznacza CYFROWY PIN sygnałowy (np. PIN 2);
  - **( - )** oznacza masę układu (GND).
2. Czujnik LM35:
  - **( VCC )** oznacza zasilanie VCC 5V;
  - **( OUT )** oznacza ANALOGOWY PIN sygnałowy (np. PIN A5);
  - **( GND )** oznacza masę układu (GND).
3. Czujnik DS18B20 (sonda wodoodporna):
  - **( CZERWONY )** oznacza zasilanie VCC 5V;
  - **( ŻÓLTY )** oznacza CYFROWY PIN sygnałowy (np. PIN 2);
  - **( CZARNY )** oznacza masę układu (GND).
  
  **UWAGA** W przypadku czujnika DS18B20 przewód czerwony oraz żólty trzeba połączyć rezystorem 4.7k Ohm. Wizualizacja podłączenia została przedstawiona poniżej:
  


## Skrypt - czujnik temperatury DHT-11:
```c++
#include "DHT.h"
#define DHT11_PIN 2
DHT dht;

void setup()
{
  Serial.begin(9600);
  dht.setup(DHT11_PIN);
}

void loop()
{
  //Pobranie informacji o wilgotnosci
  int wilgotnosc = dht.getHumidity();
  Serial.print(wilgotnosc);
  Serial.print("%RH | ");
  
  //Pobranie informacji o temperaturze
  int temperatura = dht.getTemperature();
  Serial.print(temperatura);
  Serial.println("*C");

  delay(1000); //Odczekanie wymaganego czasu
}
```
## Skrypt - czujnik temperatury LM35:
```c++
#define LM35 A5
 
void setup(){
  Serial.begin(9600);
}
 
void loop(){
  //Przeliczenie odczytu ADC na temperaturę zgodnie z opisem z kursu
  float temperatura = ((analogRead(LM35) * 5.0) / 1024.0) * 100;

  //Wyslanie przez UART aktualnej temperatury
  Serial.print("Aktualna temperatura: ");
  Serial.print(temperatura);
  Serial.println("*C");

  delay(200);
}
```
## Skrypt - czujnik temperatury DS18B20:
### Program odczytujący adres termometru:
```c++
#include <OneWire.h>

// Numer pinu cyfrowego do którego podłaczyłęś czujniki
const byte ONEWIRE_PIN = 2;

OneWire onewire(ONEWIRE_PIN);

void setup()
{
  while(!Serial);
  Serial.begin(9600);
}

void loop()
{
  byte address[8];

  onewire.reset_search();
  while(onewire.search(address))
  {
    if (address[0] != 0x28)
      continue;

    if (OneWire::crc8(address, 7) != address[7])
    {
      Serial.println(F("Błędny adres, sprawdz polaczenia"));
      break;
    }

    for (byte i=0; i<8; i++)
    {
      Serial.print(F("0x"));
      Serial.print(address[i], HEX);

      if (i < 7)
        Serial.print(F(", "));
    }
    Serial.println();
  }

  while(1);
}
```
### Program odczytujący temperaturę z czujnika:
```c++
#include <OneWire.h>
#include <DS18B20.h>

// Numer pinu do którego podłaczasz czujnik
#define ONEWIRE_PIN 2

// Adres czujnika
byte address[8] = {0x28, 0xFF, 0x64, 0x1E, 0x87, 0x76, 0xE1, 0xD8}; // tu wklej swój adres!

OneWire onewire(ONEWIRE_PIN);
DS18B20 sensors(&onewire);

void setup() {
  while(!Serial);
  Serial.begin(9600);

  sensors.begin();
  sensors.request(address);
}

void loop() {
  if (sensors.available())
  {
    float temperature = sensors.readTemperature(address);

    Serial.print(temperature);
    Serial.println(F(" 'C"));

    sensors.request(address);
  }

  // tu umieść resztę twojego programu
  // Będzie działał bez blokowania
}
```

## Rezultat:
Zrealizowany skrypt z **zadania 4** prześlij na: ariel_antonowicz@ekos.edu.pl
