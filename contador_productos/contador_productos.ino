int distancia = 45;
int productos = 0;

long tiempoproducto = 3000;
long tiempo = 0;
long tiempoanterior = 0;
long productoquieto = 0 ;

const int pinBuzzer = 9;
const int Trigger = 2;
const int Echo = 3;
int verde = 5;
int rojo = 6; 


void setup() {
  Serial.begin(9600);
  pinMode(Trigger,OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger,LOW);
 
}
 
void loop() {
  long t;
  long d;

  digitalWrite (Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

t= pulseIn(Echo,HIGH);
d=t/59;
if (d >45){
  Serial.println("distancia mayor a 45cm");
}

Serial.print("Distancia; ");
Serial.print(d);
Serial.println();
delay(100);

  if (distancia < 45 && tiempo-tiempoanterior == tiempoproducto){
    productos =+ 1;
    digitalWrite (verde, HIGH);
    tone(pinBuzzer, 440);
    delay(1000);
   }

  else { if(distancia < 45 && tiempo-tiempoanterior == productoquieto) {
    digitalWrite (rojo, HIGH);
    tone(pinBuzzer, 440);
    delay(10000);
}
  }
}