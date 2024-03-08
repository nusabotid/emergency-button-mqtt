#include <WiFi.h>
#include <MQTT.h>

const char ssid[] = "Wokwi-GUEST";
const char pass[] = "";

WiFiClient net;
MQTTClient client;

void connect(){
  Serial.print("Menghubungkan ke WiFi");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(1000);
  }
  Serial.println("");
  Serial.println("Terhubung ke WiFi");

  Serial.print("Menghubungkan ke Server");
  while(!client.connect("clientid_publisher")){
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Terhubung ke Server");
}

void setup() {
  pinMode(32, INPUT_PULLUP);
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  client.begin("broker.emqx.io", net);

  connect();
}

void loop() {
  bool button = digitalRead(32);
  delay(10);

  if(!client.connected()){
    connect();
  }

  if(button == 0){
    client.publish("nusabot/panic-button", String(button));
  }
}