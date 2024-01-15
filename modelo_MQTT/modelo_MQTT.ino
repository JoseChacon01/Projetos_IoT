#include <WiFi.h>
#include <PubSubClient.h>
#include "dht.h"

#define DHT11_PIN 19
#define LED_PIN 2

// Crendenciais Wifi
const char* ssid = "wIFRN-IoT";
const char* password = "deviceiotifrn";

// Dados MQTT
const char* mqttServer = "10.44.1.35";
const char* mqttClientId = "ifrn/esp32/pedro-chacon";

#define HUMIDITY_TOPIC 0
#define TEMPERATURE_TOPIC 1
#define LED_TOPIC 2
const char* mqttTopics[] = { "esp32/humidity03", "esp32/temperature03", "esp32/output03" };

WiFiClient espClient;
PubSubClient client(espClient);
dht DHT;

long lastMsg = 0;
char msg[50];
int value = 0;

float temperature = 0;
float humidity = 0;

void setup() {
  Serial.begin(115200);

  // Inicia Wifi
  setupWifi();

  // Inicia cliente MQTT
  client.setServer(mqttServer, 1883);
  client.setCallback(callback);

  // Substituir por função
  pinMode(LED_PIN, OUTPUT);
}

void setupWifi() {
  delay(10);

  Serial.println();
  Serial.print("Conectando na rede ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Intensidade do sinal: ");
  Serial.println(WiFi.RSSI());
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Chegou uma mensagem no tópico: ");
  Serial.print(topic);
  Serial.print("Payload: ");

  String topicName = String(topic);
  String messageTemp;

  // Monta uma string com os bytes recebidos
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  if (topicName == mqttTopics[LED_TOPIC]) {
    Serial.println("Mesagem para o LED: ");
    if (messageTemp == "on") {
      Serial.print("Led Ligado");
      digitalWrite(LED_PIN, HIGH);
    } 
    else if (messageTemp == "off") {
      Serial.print("Led desligado");
      digitalWrite(LED_PIN, LOW);
    }
    Serial.println();
  }
}

void reconnect() {
  // Espera até reconectar
  while (!client.connected()) {
    Serial.print("Carregando conexão MQTT...");
    // Tenta conectar
    if (client.connect(mqttClientId)) {
      Serial.println("conectado");
      // Se inscreve novamente
      client.subscribe(mqttTopics[LED_TOPIC]);
    } 
    else {
      Serial.print("falha, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5s");
      // Espera 5s antes de tentar denovo
      delay(5000);
    }
  }
}
void loop() {
  // Verifica a conexão
  if (!client.connected()) {
    reconnect();
  }

  // Verifica e executa a callback do MQTT
  client.loop();

  // Delay não blocante de 5s
  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
    Serial.println("5s");
    
    DHT.read11(DHT11_PIN);
    humidity = DHT.humidity;
    temperature = DHT.temperature;

    char humString[8];
    dtostrf(humidity, 1, 2, humString);
    client.publish(mqttTopics[0], humString);

    char tempString[8];
    dtostrf(temperature, 1, 2, tempString);
    client.publish(mqttTopics[1], tempString);

    Serial.println(humidity);
    Serial.println(temperature);
    Serial.println();
    
  }
}
