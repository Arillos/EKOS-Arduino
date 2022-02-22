
## Cel zajęć:
1. Omówienie działania cyfrowego czujnika dźwięku.
2. Realizacja "klaskacza".

## Zadanie:
1. Podłącz Arduino do komputera za pośrednictwem przewodu USB A-B i uruchom program Arduino IDE.
2. Zrealizuj układ wykorzystujący cyfrowy czujnik dzwięku (sposób podłączenia elementów znajduje się poniżej).

## Sposób podłączenia cyfrowego czujnika dzwięku:

  - **( VCC )** oznacza zasilanie VCC 5V;
  - **( OUT )** oznacza sygnał cyfrowy (np. PIN 2);
  - **( GND )** oznacza masę układu (GND).

## Skrypt - klaskacz:
```c++
#define sensorPin 2

// Variable to store the time when last event happened
unsigned long lastEvent = 0;

void setup() {
  pinMode(sensorPin, INPUT);  // Set sensor pin as an INPUT
  Serial.begin(9600);
}

void loop() {
  // Read Sound sensor
  int sensorData = digitalRead(sensorPin);

  // If pin goes LOW, sound is detected
  if (sensorData == LOW) {
    
    // If 25ms have passed since last LOW state, it means that
    // the clap is detected and not due to any spurious sounds
    if (millis() - lastEvent > 25) {
      Serial.println("Clap detected!");
    }
    
    // Remember when last event happened
    lastEvent = millis();
  }
}
```

