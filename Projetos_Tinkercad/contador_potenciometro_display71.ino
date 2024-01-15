const int pinA=2, pinB=3, pinC=4, pinD=5;
const int pinE=6, pinF=7, pinG=8, pinDP=9;
const int pinPOTEN=A0;
int valor;
  
void setup()
{            // Poderia declarar todos os pinos como OUTPUT da forma tradicional, foi feito dessa forma para facilitar.
  for (int i=2; i<=9; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(pinPOTEN, INPUT);
  Serial.begin(9600);
}

void loop()
{
  valor = analogRead(pinPOTEN);
  valor= map(valor, 0, 1023, 0, 5);
 // Serial.println(valor);  -> os valores do potenciometro vão aparecer na tela
  
  switch(valor){
  case 0:  
       //ZERO
       digitalWrite (pinA, HIGH);  // PODE TROCAR HIGH=1 E LOW=3.
       digitalWrite (pinB, HIGH);
       digitalWrite (pinC, HIGH);
       digitalWrite (pinD, HIGH);
       digitalWrite (pinE, HIGH);
       digitalWrite (pinF, HIGH);
       digitalWrite (pinG, LOW);
       digitalWrite (pinDP, HIGH); //PONTO.
  break;
    
  case 1:  
       //UM
       digitalWrite (pinA, LOW);
       digitalWrite (pinB, HIGH);
       digitalWrite (pinC, HIGH);
       digitalWrite (pinD, LOW);
       digitalWrite (pinE, LOW);
       digitalWrite (pinF, LOW);
       digitalWrite (pinG, LOW);
       digitalWrite (pinDP, HIGH); //PONTO.
  break;  
    
  case 2:
       //DOIS
       digitalWrite (pinA, HIGH);
       digitalWrite (pinB, HIGH);
       digitalWrite (pinC, LOW);
       digitalWrite (pinD, HIGH);
       digitalWrite (pinE, HIGH);
       digitalWrite (pinF, LOW);
       digitalWrite (pinG, HIGH);
       digitalWrite (pinDP, HIGH); //PONTO.
  break;  
    
  case 3:
       //TRÊS
       digitalWrite (pinA, HIGH);
       digitalWrite (pinB, HIGH);
       digitalWrite (pinC, HIGH);
       digitalWrite (pinD, HIGH);
       digitalWrite (pinE, LOW);
       digitalWrite (pinF, LOW);
       digitalWrite (pinG, HIGH);
       digitalWrite (pinDP, HIGH); //PONTO.
  break;
    
  case 4:
       //QUATRO
       digitalWrite (pinA, LOW);
       digitalWrite (pinB, HIGH);
       digitalWrite (pinC, HIGH);
       digitalWrite (pinD, LOW);
       digitalWrite (pinE, LOW);
       digitalWrite (pinF, HIGH);
       digitalWrite (pinG, HIGH);
       digitalWrite (pinDP, HIGH); //PONTO.
  break;
    
  case 5:
       //CINCO
       digitalWrite (pinA, HIGH);
       digitalWrite (pinB, LOW);
       digitalWrite (pinC, HIGH);
       digitalWrite (pinD, HIGH);
       digitalWrite (pinE, LOW);
       digitalWrite (pinF, HIGH);
       digitalWrite (pinG, HIGH);
       digitalWrite (pinDP, HIGH); //PONTO.
  break;
  }


}