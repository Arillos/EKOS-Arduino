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
