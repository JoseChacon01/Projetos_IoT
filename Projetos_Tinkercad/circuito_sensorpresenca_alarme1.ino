const int pinPIR=2;
const int punBUZ=3;
// variavel PI
#define PI 3.1415 
void setup()
{
  pinMode(pinPIR, INPUT);
  pinMode(punBUZ, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int value, i;
  float frequencia;
  
  value=digitalRead(pinPIR);
  Serial.println(value);

  // tone(punBUZ,262) Pino, frequencia (Dó).
  
  if (value==1){
  for (i=0; i<=180; i++){//"180" esta relacionado com os graus (meio ciclo trigonometrico) de 0° a 180°
    frequencia= 600.0 + sin(i*(PI/180))*1000.0;
    tone(punBUZ,frequencia);
    delay(5);
  }
  }else{
   noTone(punBUZ); //desligar
  }
  
}