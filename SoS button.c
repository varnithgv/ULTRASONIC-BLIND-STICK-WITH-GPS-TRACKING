
#include <ESP8266WiFi.h>
#include <ESP8266IFTTT.h>
const char* IFTTT_WEBHOOK_NAME="SOS";
const char* IFTTT_KEY="diI7DFErHhMNXrURrg5yno";
const char* ssid = "project";
const char* password = "1234567890";
#define wakePin 16


void setup() {
    Serial.begin(115200);
    Serial.println("Button Pressed");
    Serial.println("");
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
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());  
  IFTTT.trigger(IFTTT_WEBHOOK_NAME, IFTTT_KEY,"https://drive.google.com/open?id=1OqhTDTHLiQihJx4qXjcUdY3tycT5Nhjw","","");
  delay(1000);
  
  ESP.deepSleep(wakePin);
}

void loop() {      
}