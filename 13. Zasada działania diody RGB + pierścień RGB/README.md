## Informacje wstępne:

Przed przystąpieniem do zajęć warto zapoznać się z informacjami zawartymi w źródłach:
- kurs Forbot: [NeoPixel](https://forbot.pl/blog/kurs-arduino-ii-diody-rgb-tradycyjne-oraz-ws2812-id15495).

## Cel zajęć:
1. Omówienie działania diody RGB.
2. Realizacja autorskich wizualizacji świetlnych.

## Zadanie:
1. Podłącz Arduino do komputera za pośrednictwem przewodu USB A-B i uruchom program Arduino IDE.
2. Zrealizuj układ wykorzystujący pierścień LED RGB (sposób podłączenia elementów znajduje się poniżej).
3. Zaprojektuj i zrealizuj własny algorytm wykorzystujący pierścień LED RGB.

## Sposób podłączenia pierścienia LED RGB:

  - **( VCC )** oznacza zasilanie VCC 5V;
  - **( IN )** oznacza sygnał wejściowy (np. PIN 2);
  - **( GND )** oznacza masę układu (GND).

![Schemat not found](https://github.com/Arillos/Arduino-EKOS-/blob/main/13.%20Zasada%20dzia%C5%82ania%20diody%20RGB%20%2B%20pier%C5%9Bcie%C5%84%20RGB/neopixel.JPG)


## Skrypt - pierścień LED RGB:
```c++
 #include <Adafruit_NeoPixel.h>

#define PIN 2	 // input pin Neopixel is attached to

#define NUMPIXELS      16 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; // timing delay in milliseconds

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setup() {
  // Initialize the NeoPixel library.
  pixels.begin();
}

void loop() {
  setColor();

  for (int i=0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));

    // This sends the updated pixel color to the hardware.
    pixels.show();

    // Delay for a period of time (in milliseconds).
    delay(delayval);
  }
}

// setColor()
// picks random values to set for RGB
void setColor(){
  redColor = random(0, 255);
  greenColor = random(0,255);
  blueColor = random(0, 255);
}
```

## Rezultat:
Zrealizowany skrypt z **zadania 2** prześlij na: ariel_antonowicz@ekos.edu.pl
