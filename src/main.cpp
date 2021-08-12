#include <Arduino.h>
#include "ESP8266WiFi.h"
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>


const char* ssid = "Ambu";
const char* password = "LANCE001";
ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
// connecting to WiFi
  Serial.println("Connecting to Wifi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
     delay(500);
  }  
  Serial.println("WiFi connection Successful");

// HTTP send request as number
  HTTPClient http;
  http.begin("192.168.4.1//456789");
  int httpCodeOn = http.GET(); //Send the request
  http.end();

  server.begin();

}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println("Connection: close");
    client.println();

    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");

  }

}