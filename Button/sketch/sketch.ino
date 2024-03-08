#include <WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <MQTT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
WiFiClient net;
MQTTClient client;

const char ssid[] = "Wokwi-GUEST";
const char pass[] = "";

void connect(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Menunggu WiFi");
  while(WiFi.status() != WL_CONNECTED){
    lcd.print(".");
    delay(1000);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WiFi Terhubung");

  lcd.setCursor(0,1);
  lcd.print("Menunggu Server");
  while(!client.connect("clientid_subscriber")){
    lcd.print(".");
    delay(1000);
  }
  lcd.setCursor(0,1);
  lcd.print("Server Terhubung");

  client.subscribe("nusabot/panic-button");
}

void subscribe(String &topic, String &data){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Alarm");
  lcd.setCursor(0,1);
  lcd.print("Menyala");

  digitalWrite(32, 1);
}

void setup() {
  pinMode(32, OUTPUT);
  lcd.init();
  lcd.backlight();

  WiFi.begin(ssid, pass);
  client.begin("broker.emqx.io", net);
  client.onMessage(subscribe);

  connect();
}

void loop() {
  client.loop();

  if(!client.connected()){
    connect();
  }
}
