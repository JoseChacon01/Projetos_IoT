const int linhas[4] = {11, 10, 9, 8};//portas linhas
const int colunas[4] = {7, 6, 5, 4};//portas colunas

char senha[3]={'1', '5', '9'};//Atv. senha-> Asenha correta
char digitado[3];//Atv. senha -> Variavel, usuario vai digitar

char matrix[4][4] = {   //matriz de caracteres do controle
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
int i, j, k=0; // i= linha   j=colona k= contador que vai auxiliar na "Atv. senha" 
int valor;

void setup(){
  for (i=0; i<4; i++){          // PODERIA DECLARAR DA FORMA TRADICIONAL!!
    pinMode(linhas[i], OUTPUT); //Declareando os pinos (11, 10, 9, 8) das linhas-> "Energizadas".
    pinMode(colunas[i], INPUT); //Declareando os pinos (7, 6, 5, 4) das colunas.-> "ira verificar"
  }                                                                                // VEJA O EXMP. EM RASCUNHO (DEZENHO)!!
  Serial.begin(9600);
  Serial.println("Digite a senha corretamente!");

}

void loop(){
  
  while (k<3){ //IICIO -> Em quanto k for menor que 3, tudo isso sera executado -> Atv. senha
  for (i=0; i<4; i++){	//Energizando todas as linhas
    digitalWrite(linhas[i], HIGH); //*
    
    for (j=0; j<4; j++){ //verificando (ler) todas as colunas
        valor=digitalRead(colunas[j]);// A variavel "valor" vai receber o valor lido, que pode ser 0 ou 1 (0- botão não foi precionado e 1-botão foi precionado)
      
      if (valor == 1){ 
         Serial.println(matrix[i][j]);// Após ser identificado a posição do i do 1, sera impresso o valor correspondente da matrix
         digitado[k] = matrix[i][j];
        
        k++; // Atv. senha-> repete esse bloco 3x
        delay(200);
      }
    }
     digitalWrite(linhas[i], LOW); // Depois que ja identificou o pino que foi precionado, precisa desligar a linha que foi ligada antes*
  }
   }// fim do while  
  k=0;
  for (i=0; i<3; i++){
    if (senha[i] == digitado[i]){
      k++;
    }
  }
 
  if (k == 3){
    Serial.println("Autorizado(a)!");
    while(1){
    }
  }else{
     Serial.println("Senha incorreta, tente novamente!");
    k=0; 
  }
   
} 





