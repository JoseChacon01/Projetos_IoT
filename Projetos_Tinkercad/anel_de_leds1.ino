#include <Adafruit_NeoPixel.h>

#define numLeds   24    // Anel de leds com 24 leds
#define pinNumber 2     // Pino do arduino 
const int botao = 3;
int aux;
int k=0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numLeds, pinNumber, NEO_GRB + NEO_KHZ800);

int leds1[8]={0,3,6, 9,12,15,18,21};
int leds2[8]={1,4,7,10,13,16,19,22};
int leds3[8]={2,5,8,11,14,17,20,23};

int tempo = 110;

void setup(){
  Serial.begin(9600);
  pixels.begin();
  pinMode(botao, INPUT);
}

void loop() {
  
  uint32_t color1;
  uint32_t color2;
  uint16_t led;
  
  
  
   if (digitalRead(botao)== 1){ 
    aux = 1 - aux;
    delay(200);
  }
  
  if(aux == 1){    //FORMA 1
  
    while (k<3){
   for(int x=0; x<=7; x++){
     pixels.setPixelColor(leds3[x], pixels.Color(0, 0, 0));
     pixels.setPixelColor(leds1[x], pixels.Color(0, 0, 255)); // Pixel número "0" - Cores (Red = 0, Green = 0, Blue = 255)
     pixels.show();
   }
   delay(tempo);
   
   for(int x=0; x<=7; x++){
     pixels.setPixelColor(leds1[x], pixels.Color(0, 0, 0));
     pixels.setPixelColor(leds2[x], pixels.Color(0, 0, 255)); // Pixel número "0" - Cores (Red = 0, Green = 0, Blue = 255)
     pixels.show();
   }
   delay(tempo);

   for(int x=0; x<=7; x++){
     pixels.setPixelColor(leds2[x], pixels.Color(0, 0, 0));
     pixels.setPixelColor(leds3[x], pixels.Color(0, 0, 255)); // Pixel número "0" - Cores (Red = 0, Green = 0, Blue = 255)
     pixels.show();
   }
   delay(tempo);
    pixels.clear();
      k++;
    }
    
    k=0;
    //FORMA 2
    while (k<3){
     for (led=0; led<24; led++){
          color1 = pixels.Color (0, (255/24)*(led+1), (255/24)*(24-(led+1)));

      if (led>2){ 
    	  pixels.setPixelColor(led-3, 0);  
    }
   	      pixels.setPixelColor(led, color1);
          pixels.show(); 
          delay(110);
  }
     pixels.clear();
    
   k++;
 }
    
    k=0;
    
    //FORMA 3= 2
    while (k<3){
     for (led=0; led<24; led++){
          color2 = pixels.Color ((255/24)*(led+1), 0, (255/24)*(24-(led+1)));

      if (led>5){ 
    	  pixels.setPixelColor(led-6, 0);  
     }
   	      pixels.setPixelColor(led, color2);
          pixels.show(); 
          delay(110);
   }
     pixels.clear();
       k++;
  }
    
    k=0;
 }
    else{
      for(int x=0; x<=7; x++){
     pixels.setPixelColor(leds3[x], pixels.Color(0, 0, 0));
     pixels.setPixelColor(leds1[x], pixels.Color(0, 0, 0)); // Pixel número "0" - Cores (Red = 0, Green = 0, Blue = 255)
     pixels.show();
   }
   delay(tempo);
   
   for(int x=0; x<=7; x++){
     pixels.setPixelColor(leds1[x], pixels.Color(0, 0, 0));
     pixels.setPixelColor(leds2[x], pixels.Color(0, 0, 0)); // Pixel número "0" - Cores (Red = 0, Green = 0, Blue = 255)
     pixels.show();
   }
   delay(tempo);

   for(int x=0; x<=7; x++){
     pixels.setPixelColor(leds2[x], pixels.Color(0, 0, 0));
     pixels.setPixelColor(leds3[x], pixels.Color(0, 0, 0)); // Pixel número "0" - Cores (Red = 0, Green = 0, Blue = 255)
     pixels.show();
   }
   delay(tempo);
  }
 }   
   
