const int pinBLED=3; 
const int pinLED=4; 
const int pinRele=5; 
const int pinBLAMP=6; 



void setup(){
  pinMode(pinBLED, INPUT); // AFIRMANDO QUE O PINHO 3 VAI LER A INFORMAÇÃO (ENTRADA)
  pinMode(pinLED, OUTPUT); //AFIRMANDO QUE O PINHO 4 VAI TER A "SAIDA DE INFORMAÇÃO"
  pinMode(pinRele, OUTPUT);
  pinMode(pinBLAMP, INPUT);

}

void loop(){ 
  
  if (digitalRead(pinBLED)== 1 && digitalRead(pinBLAMP)== 0 ){ 
    digitalWrite(pinLED, HIGH);
    digitalWrite(pinRele, LOW);
    delay(200);
  }
  
  if (digitalRead(pinBLED)== 0 && digitalRead(pinBLAMP)== 1 ){ 
    digitalWrite(pinLED, LOW);
    digitalWrite(pinRele, HIGH);
    delay(200);
  }

}