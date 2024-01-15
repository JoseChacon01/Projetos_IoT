#include <Servo.h> 

#define pinServoVertCima 2
#define pinServoHorizBaixo 3

#define pinSensor_Su_E A0
#define pinSensor_Su_D A2
#define pinSensor_In_E A1
#define pinSensor_In_D A3

Servo servoCima;
Servo servoBaixo;

void setup()
{
  pinMode(pinSensor_Su_E, INPUT); //Entrada de dados
  pinMode(pinSensor_Su_D, INPUT);
  pinMode(pinSensor_In_E, INPUT);
  pinMode(pinSensor_In_D, INPUT);
  
  servoCima.attach(pinServoVertCima); //O método attach do Servo é usado para indicar qual entrada do Arduino será usada.
  servoBaixo.attach(pinServoHorizBaixo);
  
  Serial.begin(9600);
  
  //posição inicial
  servoCima.write(90);
  servoBaixo.write(90);
}

void loop()
{
  int modoNoturno = 180;
  
   Serial.print("Sensor Superior Esquerdo: ");
   Serial.println(analogRead (pinSensor_Su_E));
   Serial.print("Sensor Superior Direito:  ");
   Serial.println(analogRead (pinSensor_Su_D));
   Serial.print("Sensor Inferior Esquerdo: ");
   Serial.println(analogRead (pinSensor_In_E));
   Serial.print("Sensor Inferior Direito:  ");
   Serial.println(analogRead (pinSensor_In_D));
   Serial.println("=============================");
  delay(1000);
  
  
 // compara_Sens_Horiz
  int valorLEsq= analogRead(pinSensor_Su_E)+ analogRead(pinSensor_In_E);
  int valorLDir= analogRead(pinSensor_Su_D)+ analogRead(pinSensor_In_D);
  
  //  compara_Sens_Vert
  int valorLSup= analogRead(pinSensor_Su_E)+ analogRead(pinSensor_Su_D);
  int valorLInf= analogRead(pinSensor_In_E)+ analogRead(pinSensor_In_D);
  
  //TESTE C. AQUI
  if (valorLSup > valorLInf && valorLSup > valorLEsq && valorLSup > valorLDir) {
    servoCima.write(60); 
  } else if (valorLInf > valorLSup && valorLInf > valorLEsq && valorLInf > valorLDir) {
    servoCima.write(120);
  } else if (valorLEsq > valorLDir && valorLEsq > valorLSup && valorLEsq > valorLInf) {
    servoBaixo.write(60); 
  } else if (valorLDir > valorLEsq && valorLDir > valorLSup && valorLDir > valorLInf ) {
    servoBaixo.write(120);
  }else if (modoNoturno > valorLDir && modoNoturno > valorLEsq && modoNoturno > valorLSup && modoNoturno > valorLInf ) {
    servoCima.write(90);
  	servoBaixo.write(90);
  }
  
  //FIM
  
  }          
      