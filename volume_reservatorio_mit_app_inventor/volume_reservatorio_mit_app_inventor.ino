#include <WiFi.h>
#include <PubSubClient.h>


int PinTrigger = 32;
int PinEcho = 33;
float TempoEcho = 0;
const float VelocidadeSom_mpors = 340;        // em metros por segundo
const float VelocidadeSom_mporus = 0.000340;  // em metros por microsegundo

//Leds e rele
const int ledRele = 2;
const int verdePin = 4;
const int amarelaPin = 5;
const int vermelhaPin = 16;
const int rele = 23;

// Define as distâncias de ativação para cada LED
const int distanciaMin = 5;
const int distanciaMax = 10;
float distancia;


// Informações do Wi-Fi
const char *ssid = "wIFRN-IoT";
const char *password = "deviceiotifrn";

// Informações do servidor MQTT
const char *mqtt_server = "10.44.1.35";
const int mqtt_port = 1883;
//const char *mqtt_user = "SEU_USUARIO_MQTT";
//const char *mqtt_password = "SUA_SENHA_MQTT";

WiFiClient espClient;
PubSubClient client(espClient);

long lastMsg = 0;

// Funçao para enviar o pulso de trigger
void DisparaPulsoUltrassonico() {
  digitalWrite(PinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(PinTrigger, LOW);
}


// Função para calcular a distancia em metros
float CalculaDistancia(float tempo_us) {
  return ((tempo_us * VelocidadeSom_mporus) / 2);
}

void setup() {
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  // Configura pino de Trigger como saída e inicializa com nível baixo
  pinMode(PinTrigger, OUTPUT);
  digitalWrite(PinTrigger, LOW);
  pinMode(PinEcho, INPUT);  // configura pino ECHO como entrada

  //Config leds e rele
  pinMode(verdePin, OUTPUT);
  pinMode(amarelaPin, OUTPUT);
  pinMode(vermelhaPin, OUTPUT);
  pinMode(ledRele, OUTPUT);
  pinMode(rele, OUTPUT);
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char *topic, byte *message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;

  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  if (String(topic) == "bomba/reservatorio") {
    Serial.print("Changing output to ");
    if (messageTemp == "on") {
      Serial.println("on");
      digitalWrite(ledRele, HIGH); 
      digitalWrite(rele, HIGH);
       // Publica a mensagem no tópico "situacao/bomba"
      client.publish("situacao/bomba", "Ligada");
    } else if (messageTemp == "off") {
      Serial.println("off");
      digitalWrite(rele, LOW);
      digitalWrite(ledRele, LOW);
      // Publica a mensagem no tópico "situacao/bomba"
      client.publish("situacao/bomba", "Desligada");
    }
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("bomba/reservatorio");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;

    DisparaPulsoUltrassonico();
    // Mede o tempo de duração do sinal no pino de leitura(us)
    TempoEcho = pulseIn(PinEcho, HIGH);

    distancia = (CalculaDistancia(TempoEcho) * 100);
    float volume = 100*(30-distancia)/30;
    Serial.println("Distancia em metros: ");
    Serial.println(CalculaDistancia(TempoEcho));
    Serial.println("Distancia em centimetros: ");
    Serial.println(distancia);


    if (distancia < distanciaMin) {
      digitalWrite(verdePin, HIGH);
      digitalWrite(amarelaPin, LOW);
      digitalWrite(vermelhaPin, LOW);
    } else if (distancia >= distanciaMin && distancia <= distanciaMax) {
      digitalWrite(verdePin, LOW);
      digitalWrite(amarelaPin, HIGH);
      digitalWrite(vermelhaPin, LOW);
    } else if (distancia > distanciaMax){
      digitalWrite(verdePin, LOW);
      digitalWrite(amarelaPin, LOW);
      digitalWrite(vermelhaPin, HIGH);
    }


    char tempString[8];
    dtostrf(volume, 1, 2, tempString);
    Serial.print("Volume: ");
    Serial.println(tempString);
    client.publish("volume/reservatorio", tempString);
  }
}