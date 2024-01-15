#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 14    // Configurar o pino RST do leitor RFID
#define SS_PIN 5    // Configurar o pino SS do leitor RFID
#define LED_PIN 13   // Pino do LED (ou qualquer pino desejado)

MFRC522 rfid(SS_PIN, RST_PIN);  // Criar um objeto MFRC522

void setup() {
  Serial.begin(9600);  // Iniciar a comunicação serial
  SPI.begin();         // Iniciar a SPI bus
  rfid.PCD_Init();     // Iniciar o leitor RFID

  pinMode(LED_PIN, OUTPUT);  // Configurar o pino do LED como saída
  digitalWrite(LED_PIN, LOW);  // Desligar o LED no início
}

void loop() {
  // Verificar se há cartões presentes
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Ler o UID do cartão RFID
    Serial.print("Cartão UID: ");
    dump_byte_array(rfid.uid.uidByte, rfid.uid.size);
    Serial.println();

    digitalWrite(LED_PIN, HIGH);  // Ligar o LED quando um cartão é detectado
    delay(3000);  // Esperar 1 segundo antes de desligar o LED
    digitalWrite(LED_PIN, LOW);  // Desligar o LED
  }
  
  rfid.PICC_HaltA();  // Parar a comunicação com o cartão
  rfid.PCD_StopCrypto1();  // Parar a criptografia
}

// Função para imprimir o UID do cartão RFID
void dump_byte_array(byte* buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}
