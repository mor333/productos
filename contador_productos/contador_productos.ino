int distancia = 45;
int productos = 0;

long tiempoproducto = 3000;
long tiempo = 0;
long tiempoanterior = 0;
long productoquieto = 0 ;
long distancia;
const int pinBuzzer = 9;
const int Trigger = 2;
const int Echo = 3;
int verde = 5;
int rojo = 6; 

long leerdistancia(){
  long t;
  long d;

  digitalWrite (Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

t= pulseIn(Echo,HIGH);
d=t/59;

Serial.print("Distancia; ");
Serial.print(d);
Serial.println();
delay(100);

return d;
}

void setup() {
  Serial.begin(9600);
  pinMode(Trigger,OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger,LOW);
 
}
 
void loop() {

distancia=leerdistancia();  

if (distancia >45){
  Serial.println("distancia mayor a 45cm");
}


  if (distancia < 45 && tiempo-tiempoanterior == tiempoproducto){
    productos =+ 1;
    digitalWrite (verde, HIGH);
    tone(pinBuzzer, 440);
    //cuando detecto un producto, tiempoanterior =tiempo
   }

  else { 
    if(tiempo-tiempoanterior > tiempoproducto) {
      frenarCinta();
      while(pulsador ==low){
      digitalWrite (rojo, HIGH);
      tone(pinBuzzer, 440);
    }
    iniciarCinta();
    tiempoanterior= tiempo;

}
  }
}