
const int pinA=8;
const int pinB=9;
const int pinC=12;
const int pinD=11;
const int pinE= 10;
const int pinF=7;
const int pinG=6;
const int pinPonto=13;

const int ledVerm=3;
const int ledAzul=5;
const int ledAmarelo=2; 



void setup(){
  pinMode(ledVerm, OUTPUT); 
  pinMode(ledAzul, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  
  pinMode(pinA, OUTPUT); 
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinPonto, OUTPUT);
}

void loop(){ 
  
 
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
   
    digitalWrite(ledVerm, LOW);
    digitalWrite(ledAzul, LOW); 
    digitalWrite(ledAmarelo, LOW); 
    delay(500);
  //-------
  
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, LOW);
  
    digitalWrite(ledVerm, LOW);
    digitalWrite(ledAzul, LOW); 
    digitalWrite(ledAmarelo, HIGH); 
    delay(500);
  //----------
  
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
    digitalWrite(ledVerm, LOW);
    digitalWrite(ledAzul, HIGH); 
    digitalWrite(ledAmarelo, LOW); 
    delay(500);
  //----------
  
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
    digitalWrite(ledVerm, LOW);
    digitalWrite(ledAzul, HIGH); 
    digitalWrite(ledAmarelo, HIGH); 
    delay(500);
  //---------------
  
     digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
    digitalWrite(ledVerm, HIGH);
    digitalWrite(ledAzul, LOW); 
    digitalWrite(ledAmarelo, LOW); 
    delay(500);
  //----------------
  
     digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
    digitalWrite(ledVerm, HIGH);
    digitalWrite(ledAzul, LOW); 
    digitalWrite(ledAmarelo, HIGH); 
    delay(500);
  //-------------------
  
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
    digitalWrite(ledVerm, HIGH);
    digitalWrite(ledAzul, HIGH); 
    digitalWrite(ledAmarelo, LOW); 
    delay(500);
  //----------------
  
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, LOW);
  
    digitalWrite(ledVerm, HIGH);
    digitalWrite(ledAzul, HIGH); 
    digitalWrite(ledAmarelo, HIGH); 
    delay(500);
  
} 

































