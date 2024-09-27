#include <PubSubClient.h>
#include <WiFi.h>
#include <ArduinoJson.h>

#define LED 2
#define LDR A0

const char* ssid = "IFPI_Alunos";

// Configurações do servidor MQTT (ThingBoard)
const char* mqtt_server = "";
const char* mqtt_user = "tenantTB";
const char* mqtt_password = "iotnet";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void setup() {
  WiFi.begin(ssid);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(200);
  }
  Serial.print(WiFi.localIP());

  pinMode(LED, OUTPUT); //COMO A PORTA VAI SE COMPORTAR
  Serial.begin(115200); // inicia a comunicação serial bouds
}

void loop() {
  int sensor = analogRead(LDR); // 0 ~ 1023
  Serial.println(sensor);
  digitalWrite(LED, HIGH); //1 true
  delay(sensor); //milisegundos
  digitalWrite(LED, LOW); //0 false
  delay(sensor); 
}