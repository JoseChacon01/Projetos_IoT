
const int pinA=8;
const int pinB=9;
const int pinC=12;
const int pinD=11;
const int pinE= 10;
const int pinF=7;
const int pinG=6;
const int pinPonto=13;

const int pinBotaoA=2;
const int pinBotaoB=3;
const int pinBotaoC=4; 


void setup(){
  pinMode(pinBotaoA, INPUT); 
  pinMode(pinBotaoB, INPUT);
  pinMode(pinBotaoC, INPUT);
  
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
  
  if (digitalRead(pinBotaoA)== 0 && digitalRead(pinBotaoB)== 0 && digitalRead(pinBotaoC)== 0 ){  //0
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  }
  
  if (digitalRead(pinBotaoA)== 0 && digitalRead(pinBotaoB)== 0 && digitalRead(pinBotaoC)== 1 ){ //1
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, LOW);
  }
  
  if (digitalRead(pinBotaoA)== 0 && digitalRead(pinBotaoB)== 1 && digitalRead(pinBotaoC)== 0 ){ //2
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  }
  
  if (digitalRead(pinBotaoA)== 0 && digitalRead(pinBotaoB)== 1 && digitalRead(pinBotaoC)== 1 ){ //3
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  }
  
  if (digitalRead(pinBotaoA)== 1 && digitalRead(pinBotaoB)== 0 && digitalRead(pinBotaoC)== 0 ){ //4
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  }
  
  if (digitalRead(pinBotaoA)== 1 && digitalRead(pinBotaoB)== 0 && digitalRead(pinBotaoC)== 1 ){ //5
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  }
  
  if (digitalRead(pinBotaoA)== 1 && digitalRead(pinBotaoB)== 1 && digitalRead(pinBotaoC)== 0 ){ //6
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  }
  
  
  if (digitalRead(pinBotaoA)== 1 && digitalRead(pinBotaoB)== 1 && digitalRead(pinBotaoC)== 1 ){ //7
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, LOW);
  }
  

}



























































