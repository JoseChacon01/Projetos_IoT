//Visor
const int pinA=8;
const int pinB=9;
const int pinC=12;
const int pinD=11;
const int pinE= 10;
const int pinF=7;
const int pinG=6;
const int pinPonto=13;

//Botão
const int pinBotaoB=3;
const int pinBotaoC=4; 

//Led
const int pinLedB=2;
const int pinLedC=5; 


void setup(){
  pinMode(pinBotaoB, INPUT);
  pinMode(pinBotaoC, INPUT);
  
  pinMode(pinLedB,OUTPUT);
  pinMode(pinLedC,OUTPUT);

  
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
  
  if (digitalRead(pinBotaoB)== 0 && digitalRead(pinBotaoC)== 0 ){  //0
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, LOW);
    
    digitalWrite(pinLedB, LOW);
    digitalWrite(pinLedC, LOW);
  }
  
  if (digitalRead(pinBotaoB)== 1 && digitalRead(pinBotaoC)== 0 ){ //1-0
 
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH); //0
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, LOW);
   
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, LOW); 
    delay(500);
  //-------
  
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH); //1
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, LOW);
  
   
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, LOW); 
    delay(500);
  //----------
  
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);//2
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
   
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, LOW); 
    delay(500);
  //----------
  
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);//3
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
   
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, LOW); 
    delay(500);
  //---------------
  
     digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);//4
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
   
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, LOW); 
    delay(500);
  //----------------
  
     digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);//5
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
   
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, LOW); 
    delay(500);
  //-------------------
  
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);//6
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
    
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, LOW); 
    delay(500);
  //----------------
  
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);//7
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, LOW);
  
   
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, LOW); 
    delay(500);
    //--------------------
    
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);//8
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
    
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, LOW); 
    delay(500);
    //-------------------
    
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);//9
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
    
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, LOW); 
    delay(500);
  
  }
  
  
  
  
  
  
  
  if (digitalRead(pinBotaoB)== 0 && digitalRead(pinBotaoC)== 1 ){ //1
 
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH); //9
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
   
    digitalWrite(pinLedB, LOW);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
  //-------
  
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);//8
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
   
    digitalWrite(pinLedB, LOW);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
  //----------
  
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);//7
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, LOW);
  
   
    digitalWrite(pinLedB, LOW);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
  //----------
  
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);//6
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
    
    digitalWrite(pinLedB, LOW);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
  //---------------
  
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);//5
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
   
    digitalWrite(pinLedB, LOW);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
  //----------------
  
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);//4
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
   
    digitalWrite(pinLedB, LOW);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
  //-------------------
    
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);//3
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
   
    digitalWrite(pinLedB, LOW);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
  //----------------
  
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);//2
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
   
    digitalWrite(pinLedB, LOW);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
    //--------------------
    
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH); //1
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, LOW);
  
   
    digitalWrite(pinLedB, LOW);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
    //-------------------
    
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH); //0
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, LOW);
   
    digitalWrite(pinLedB, LOW);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
  
  }
  
  
  
  if (digitalRead(pinBotaoB)== 1 && digitalRead(pinBotaoC)== 1 ){ //1
 
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH); //9
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
   
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
  //-------
  
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);//8
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
   
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
  //----------
  
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);//7
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, LOW);
  
   
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
  //----------
  
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);//6
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
    
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
  //---------------
  
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);//5
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
   
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
  //----------------
  
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);//4
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
   
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
  //-------------------
    
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);//3
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
  
   
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
  //----------------
  
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);//2
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, HIGH);
   
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
    //--------------------
    
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH); //1
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, LOW);
  
   
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
    //-------------------
    
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH); //0
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinPonto, HIGH);
    digitalWrite(pinG, LOW);
   
    digitalWrite(pinLedB, HIGH);
    digitalWrite(pinLedC, HIGH); 
    delay(500);
  
  }
  
}



























































