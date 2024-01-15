// Example code using MQTT to publish and subscribe data

#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>

// Replace the next variables with your SSID/Password combination
const char* ssid = "wIFRN-IoT";
const char* password = "deviceiotifrn";

const char* mqtt_server = "10.44.1.35";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;

const int ledPin = ; //escolher pino para LED de saída

void setup() {
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  pinMode(ledPin, OUTPUT);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
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

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp; //string que recebe os valores das mensagens recebidas
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // Feel free to add more if statements to control more GPIOs with MQTT

  // If a message is received on the topic teste/led, you check if the message is either "on" or "off". 
  // Changes the output state according to the message
  if (String(topic) == "  ") { //inserir nome do tópico que recebe o comando para o LED

    //Completar IF-ELSE abaixo de acordo com as mensagens recebidas e ação no pino do led
    if(messageTemp == " "){
      Serial.println("LED LIGADO");
      digitalWrite(ledPin, );
    }
    else if(messageTemp == " "){
      Serial.println("LED DESLIGADO");
      digitalWrite(ledPin, );
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
      client.subscribe(" "); //Subscrever no tópico correto
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
  if (now - lastMsg > 5000) {
    lastMsg = now;

  float ldr_value = ;  // Inserir função para leitura do LDR, na porta analógica correta
  char luzString[8];
    dtostrf(ldr_value, 1, 2, tempString);
    Serial.print("Leitura LDR: ");
    Serial.println(luzString);
    client.publish(" ", luz); //Inserir nome do tópico onde o valor do LDR será publicado
    
} 
}
