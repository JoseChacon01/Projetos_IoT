double calculovazao;
volatile int contador;
float fluxoAcumulado = 0;
float metroCubico = 0;
double contaAgua = 0;
double valorPorM3 = 0;

const int sensorFluxo = 2;

void setup(){
pinMode (sensorFluxo, INPUT);
attachInterrupt(0,Vazao, RISING); //Como funciona a interrupção: A cada segundo o contador recebe valores de acordo com o giro do sensor, com isso, ele recebe quantos giros forem realizados por segundo atravez do metodo "Vazao", toda ves que o giro for de LOW para HIGH. Dando "exclusividade" para o sensorFluxo
Serial.begin(9600);

}

void loop(){
contador = 0;
interrupts();
delay(1000);
noInterrupts();

calculovazao = (contador * 2.25);  //"2.25" É a quantidade de ml consumidas em um giro do sensor --> "contador" vai guardar a quantidade de giros do sensor
fluxoAcumulado =  fluxoAcumulado + (calculovazao / 1000); //mls/1000 = valor em litros
metroCubico = fluxoAcumulado / 1000; // litros/1000 = valor em M3

if (metroCubico >= 0 && metroCubico <= 10999){
  contaAgua = 46.71;
}

if (metroCubico >= 11000 && metroCubico <= 15999){
  valorPorM3 = 5.21;
  contaAgua = metroCubico * valorPorM3;
}

if (metroCubico >= 16000 && metroCubico <= 20999){
  valorPorM3 = 6.16;
  contaAgua = metroCubico * valorPorM3;
}

if (metroCubico >= 21000 && metroCubico <= 30999){
  valorPorM3 = 6.94;
  contaAgua = metroCubico * valorPorM3;
}

if (metroCubico >= 31000 && metroCubico <= 50999){
  valorPorM3 = 7.99;
  contaAgua = metroCubico * valorPorM3;
}

if (metroCubico >= 51000 && metroCubico <= 100000){
  valorPorM3 = 10.34;
  contaAgua = metroCubico * valorPorM3;
}

if (metroCubico > 100000){
  valorPorM3 = 11.75;
  contaAgua = metroCubico * valorPorM3;
}


calculovazao = calculovazao * 60;   // "ml por minuto"
calculovazao= calculovazao / 1000; // vazão "momentania" de "Litros por minuto"


//================================

Serial.print("Litros por minuto: ");
Serial.println(calculovazao);

Serial.print("Gasto Total em Litros: ");
Serial.println(fluxoAcumulado);

Serial.print("Metros Cubicos totais: ");
Serial.println(metroCubico);

Serial.print("R$: ");
Serial.println(contaAgua);

Serial.println(" ================== ");
Serial.println(" ");

}

void Vazao(){
contador ++;
}