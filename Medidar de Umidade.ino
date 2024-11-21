#include <WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include <DHT.h>  // Biblioteca DHT

// Configurações de rede Wi-Fi
#define REDE_WIFI "Wokwi-GUEST"
#define SENHA_WIFI ""

// Configurações do Adafruit IO
#define SERVIDOR_AIO "io.adafruit.com"
#define PORTA_AIO 1883 // Porta padrão MQTT
#define USUARIO_AIO "FelipeMen"
#define CHAVE_AIO ""

// Configuração do sensor DHT22
#define PINO_DHT 4  // Pino ao qual o DHT22 está conectado (ajuste conforme necessário)
#define TIPO_DHT DHT22 // Tipo do sensor

// Conexão ao broker MQTT
WiFiClient cliente;
Adafruit_MQTT_Client mqtt(&cliente, SERVIDOR_AIO, PORTA_AIO, USUARIO_AIO, CHAVE_AIO);

// Feed do Adafruit IO para umidade do ar
Adafruit_MQTT_Publish feedUmidade = Adafruit_MQTT_Publish(&mqtt, USUARIO_AIO "/feeds/humidity");

// Instanciando o sensor DHT
DHT dht(PINO_DHT, TIPO_DHT);

void setup() {
  Serial.begin(115200);

  // Conectar ao Wi-Fi
  Serial.print("Conectando-se à rede Wi-Fi");
  WiFi.begin(REDE_WIFI, SENHA_WIFI);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado ao Wi-Fi!");

  // Conectar ao broker MQTT
  conectarMQTT();

  // Inicializar o sensor DHT
  dht.begin();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    reconectarWiFi();
  }
  
  if (!mqtt.connected()) {
    conectarMQTT();
  }

  mqtt.processPackets(10000);

  // Leitura do sensor DHT22 (umidade do ar)
  float umidade = dht.readHumidity(); // Leitura da umidade
  if (isnan(umidade)) {
    Serial.println("Falha ao ler o sensor DHT");
  } else {
    Serial.print("Umidade do Solo: ");
    Serial.print(umidade);
    Serial.println("%");

    // Publicar no Adafruit IO
    if (!feedUmidade.publish(umidade)) {
      Serial.println("Falha ao publicar no Adafruit IO");
    } else {
      Serial.println("Dados publicados com sucesso!");
    }
  }

  delay(1000); // Envia dados a cada 10 segundos
}

void conectarMQTT() {
  Serial.print("Conectando-se ao Adafruit IO...");
  while (mqtt.connect() != 0) {
    Serial.print(".");
    delay(5000);
  }
  Serial.println("\nConectado ao Adafruit IO!");
}

void reconectarWiFi() {
  Serial.println("Reconectando ao Wi-Fi...");
  WiFi.disconnect();
  WiFi.begin(REDE_WIFI, SENHA_WIFI);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nReconectado ao Wi-Fi!");
}
