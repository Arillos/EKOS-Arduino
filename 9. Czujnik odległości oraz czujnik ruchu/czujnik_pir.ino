
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
