#include<LiquidCrystal.h>
LiquidCrystal lcd (8,9,10,11,12,13);

const int pinFotoRes=A1;

int leituraSensor;
int leituraLUZ;

const int PinSensor=A0;
const int PinRele=4;
const int pinLvermelho=5;
const int PinLamarelo=6;
const int PinLverde=7;
void setup() {
  
lcd.begin(16,2); 
 
 //Sensor
 pinMode(PinSensor, INPUT);
 //Atuador
 pinMode(PinRele, OUTPUT);
 //Foto Resistor
  pinMode(pinFotoRes, INPUT);
 //LEDs
 pinMode(pinLvermelho, OUTPUT); 
 pinMode(PinLamarelo, OUTPUT); 
 pinMode(PinLverde, OUTPUT);
  
  Serial.begin(9600);
}
void loop() {
  
  int seco=80; //aciona
  int ideal=750; //Desliga
 leituraSensor = analogRead(PinSensor);
  
  int noite=650;
 leituraLUZ=analogRead(pinFotoRes);
  
  // o sistema de irrigação só funcionara durante o dia.
  if(leituraLUZ > noite ){
 digitalWrite(pinLvermelho, LOW); 
 digitalWrite(PinLamarelo, LOW); 
 digitalWrite(PinLverde, LOW); 
 digitalWrite(PinRele, LOW);
 analogWrite(PinSensor, LOW);
  }else{
  
 if (leituraSensor <= seco) {
 //No estado seco
 digitalWrite(pinLvermelho, HIGH); 
 digitalWrite(PinLamarelo, LOW); 
 digitalWrite(PinLverde, LOW); 
 digitalWrite(PinRele, HIGH);
   
 lcd.setCursor(3,0); 
  lcd.print("Solo seco:");
  delay(2000);
  lcd.clear(); //apaga 
   
  lcd.setCursor(1,0); 
  lcd.print("Bomba acionada.");
  delay(2000);
  lcd.clear(); 
   
 } else if (leituraSensor > seco && leituraSensor < ideal) {
 //No estado de atuação
 digitalWrite(pinLvermelho, LOW); 
 digitalWrite(PinLamarelo, HIGH); 
 digitalWrite(PinLverde, LOW); 
 digitalWrite(PinRele, HIGH);
  
 lcd.setCursor(1,0); 
  lcd.print("Solo umidecido:");
  delay(2000);
  lcd.clear(); 
  
  lcd.setCursor(4,0); 
  lcd.print("Bomba em");
  lcd.setCursor(4,1); 
  lcd.print("Atuacao.");
  delay(2000);
  lcd.clear();
   
 } else if (leituraSensor >= ideal) { 
 //No estado ideal, desliga a bomba
 digitalWrite(pinLvermelho, LOW); 
 digitalWrite(PinLamarelo, LOW); 
 digitalWrite(PinLverde, HIGH); 
 digitalWrite(PinRele, LOW);
   
  lcd.setCursor(3,0);
  lcd.print("Solo umido:");
  delay(2000);
  lcd.clear(); 
  
  lcd.setCursor(0,0); 
  lcd.print("Bomba desligada.");
  delay(2000);
  lcd.clear();
 }
  }
  
 Serial.println(analogRead (PinSensor));
}

