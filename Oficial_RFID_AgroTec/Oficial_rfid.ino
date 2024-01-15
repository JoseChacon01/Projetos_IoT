#include <BluetoothSerial.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 5    // Pino Slave Select (SS) do módulo RFID
#define RST_PIN 14   // Pino Reset do módulo RFID
#define LED_PIN 13   // Pino da LED
#define BUZZER_PIN 4 // Pino do buzzer
#define ACTIVE_LED_PIN 15 // Pino da LED que indica o circuito ativo
#define BUTTON_PIN 16        // Pino do botão

MFRC522 mfrc522(SS_PIN, RST_PIN);
BluetoothSerial SerialBT;

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Endereço I2C do display e tamanho das linhas e colunas

int tagCount = 0;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("AgroTec_RFID");

  lcd.backlight();// Liga LCD
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(ACTIVE_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(ACTIVE_LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Wire.begin();  // Inicializa a comunicação I2C
  lcd.begin(16, 2);  // Inicializa o display LCD

  SPI.begin();
  mfrc522.PCD_Init();

  lcd.print("Tags Lidas:");
  Serial.println("Pronto para se conectar via Bluetooth e ler tags RFID");
}

void loop() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    // Se o botão está pressionado, liga a LED indicando que o circuito está inativo
    digitalWrite(ACTIVE_LED_PIN, LOW);
    
    // Reseta a contagem de tags
    tagCount = 0;

    // Desliga o leitor RFID, a LED e o buzzer
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    mfrc522.PCD_StopCrypto1();
  } else {
    // Se o botão não está pressionado, liga a LED indicando que o circuito está ativo
    digitalWrite(ACTIVE_LED_PIN, HIGH);
    
    // Execute o código RFID
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      tagCount++;
      
      String tagValue = "";
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        tagValue += String(mfrc522.uid.uidByte[i], HEX);
      }

      Serial.print("Tag RFID lida: ");
      Serial.println(tagValue);
      Serial.println(tagCount);

      SerialBT.print("RFID Tag: ");
      SerialBT.println(tagValue);

      // Limpa o display antes de atualizar o número de tags lidas
      lcd.clear();

      // Atualiza o display com o número de tags lidas
      lcd.setCursor(0, 0);
      lcd.print("Tags Lidas:");

      lcd.setCursor(0, 1);
      lcd.print(tagCount);

      digitalWrite(LED_PIN, HIGH);   // Acende a LED quando uma tag é lida
      digitalWrite(BUZZER_PIN, HIGH); // Ativa o buzzer

      // Aguarde um pouco para evitar a leitura contínua da mesma tag
      delay(1000);

      digitalWrite(LED_PIN, LOW);    // Desliga a LED após o atraso
      digitalWrite(BUZZER_PIN, LOW);  // Desativa o buzzer após o atraso
    }
  }
}
