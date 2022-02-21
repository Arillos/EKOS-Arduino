void setup()
{
  pinMode(13, OUTPUT);  // Dioda LED
  pinMode(6, INPUT);  // Przycisk z fizycznym rezystorem podciągającym
}


void loop()
{
  // Jeśli na pinie 6 jest stan wysoki HIGH (logiczne 1) to ...
  if (digitalRead(6) == 1)  
  {
    digitalWrite(13, HIGH);
  }
  // W przeciwnym razie
  else
  {
    digitalWrite(13, LOW);
   }
}
