int wartosc = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);  // Dioda LED
}


void loop()
{
  
  wartosc = analogRead(A0);
  Serial.println(wartosc);
 
  if (wartosc >= 600) 
  {
    digitalWrite(13, HIGH);
  }
  // W przeciwnym razie
  else
  {
    digitalWrite(13, LOW);
   }
}
