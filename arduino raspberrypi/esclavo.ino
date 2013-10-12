#include <Wire.h>

byte pinLed = 13;

void setup(){
  pinMode(pinLed,OUTPUT);
  
  Wire.begin(8);
  Wire.onReceive(evento);
  
  Serial.begin(9600);
  
  digitalWrite(pinLed,LOW);
}//setup

void loop(){}//loop

void evento(int cuantos){
  int recibo = Wire.read();
  
  Serial.print("Evento registrado: ");
  Serial.println( recibo );
  
  Serial.print("Cuantos: ");
  Serial.println( cuantos);
  
  digitalWrite(pinLed,recibo);  
}//evento