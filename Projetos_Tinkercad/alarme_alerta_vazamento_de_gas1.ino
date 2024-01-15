// pinGas -> Conecta em pino analogico pq vai ler informações

const int pinGas=A0;
const int punBUZ=3;
const int ledVerm=4;

void setup()
{
  pinMode(pinGas, INPUT);
  pinMode(punBUZ, OUTPUT);
  pinMode(ledVerm, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //Ler a informação -> Na leitura analogica os valores variam entre 0 a 1023
  int valor, i; 
  float frequencia;
  
  valor= analogRead(pinGas);
  valor= map(valor, 0, 1023, 0, 10); // Ao inves do valor variar de 0 a 1023, ele ira variar de 0 a 10
  Serial.println(valor);
  
  if (valor>=5){
     for (i=0; i<=180; i++){//"180" esta relacionado com os graus (meio ciclo trigonometrico) de 0° a 180°
     frequencia= 600.0 + sin(i*(PI/180))*1000.0;
     tone(punBUZ,frequencia);
     delay(5); 
  }
    digitalWrite(ledVerm, HIGH);// LIGAR LED
  }else{
   noTone(punBUZ); //desligar BUZZ
   digitalWrite(ledVerm, LOW);//desligar LED
  }
}