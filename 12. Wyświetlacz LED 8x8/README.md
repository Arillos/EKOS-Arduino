## Cel zajęć:
1. Omówienie działania wyświetlacza LED 8x8.
2. Realizacja prostej animacji 8x8.

## Zadanie:
1. Podłącz Arduino do komputera za pośrednictwem przewodu USB A-B i uruchom program Arduino IDE.
2. Zrealizuj układ wykorzystujący wyświetlacz LED 8x8 (sposób podłączenia elementów znajduje się poniżej).
3. Zaprojektuj i zrealizuj dowolną animację na wyświetlaczu LED 8x8.

## Sposób podłączenia wyświetlacza:
  - **( VCC )** zasilanie układu (5V);
  - **( GND )** masa układu (GND).
  - **( DIN )** SPI DATA (PIN 12);
  - **( CS )**  SPI CHIP SELECT (PIN 11);
  - **( CLK )** SPI CLOCK (PIN 10;


## Skrypt - wyświetlacz LED 8x8:
```c++
#include "LedControl.h"

LedControl lc=LedControl(12,10,11,1);  // Pins: DIN,CLK,CS, # of Display connected

unsigned long delayTime=200;  // Delay between Frames

// Put values in arrays
byte invader1a[] =
{
   B00011000,  // First frame of invader #1
   B00111100,
   B01111110,
   B11011011,
   B11111111,
   B00100100,
   B01011010,
   B10100101
};

byte invader1b[] =
{
  B00011000, // Second frame of invader #1
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B01000010
};


void setup()
{
  lc.shutdown(0,false);  // Wake up display
  lc.setIntensity(0,5);  // Set intensity level
  lc.clearDisplay(0);  // Clear Display
}

//  Take values in Arrays and Display them
void sinvader1a()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,invader1a[i]);
  }
}

void sinvader1b()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,invader1b[i]);
  }
}

void loop()
{
// Put #1 frame on both Display
    sinvader1a();
    delay(delayTime);

// Put #2 frame on both Display
    sinvader1b();
    delay(delayTime);
}
```

## Rezultat:
Zrealizowany skrypt z **zadania 3** prześlij na: ariel_antonowicz@ekos.edu.pl
