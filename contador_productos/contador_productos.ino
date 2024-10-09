const int pinBuzzer = 9;
const int Trigger = 2;
const int Echo = 3;
void setup() {
  Serial.begin(9600);
  pinMode(Trigger,OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger,LOW);
 
}

void loop() {
  long t;
  long d;

  digitalWrite(Trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger,LOW);

t= pulseIn(Echo,HIGH);
d=t/59;
if (d >30){
  Serial.println("distancia mayor a 30cm");
}
Serial.print("Distancia; ");
Serial.print(d);
Serial.println();
delay(100);

}
