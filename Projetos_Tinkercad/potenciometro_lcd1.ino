#include<LiquidCrystal.h> // biblioteca c++

LiquidCrystal lcd (12,13,7,6,1,4); //pinos utilizados
//TODA FUNÇÃO IRA INICIAR COM lcd (OBJETO QUE CRIAMOS).

void setup(){
lcd.begin(16,2); //16,2 -> refere-se ao tamanho do dislay
}

void loop(){
  //Aparece a primeira msg, some e aparece a outra.
  
  lcd.setCursor(2,0); // o nome deve aparecer apartir da coluna 2 e linha 0
  lcd.print("curso arduino");
  delay(1000);
  lcd.clear(); //apaga a frase
  
  lcd.setCursor(4,0); 
  lcd.print("Robotica");
  delay(1000);
  lcd.clear(); //apaga a frase 
  
  
 /* //Frase "correndo" para esquerda, tbm podemos colocar para direita
  lcd.setCursor(0,1); //por padrão fica na linha de cima, com esse comando a palavra fica na linha de baixo
  lcd.print("curso arduino");
  while (1>0){
  lcd.scrollDisplayLeft();
  delay(100);  
  }*/

}