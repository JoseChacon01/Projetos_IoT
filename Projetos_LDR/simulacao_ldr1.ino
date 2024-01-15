const int pinFotr=A0;
const int pinREL=2;
void setup()
{
  pinMode(pinFotr, INPUT);
  pinMode(pinREL, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  float valor;
  valor = analogRead(pinFotr);
  valor = valor*(10.0/1023.0); //-> vaz com que a variação seja de 0 a 10 e nao de 0 a 1023 que o valor ¨padrão"
  Serial.println(valor);
  
  if(valor>=3.0){ 
    digitalWrite(pinREL, HIGH);
    }
  else{ 
    digitalWrite(pinREL, LOW);
    }   		           
}