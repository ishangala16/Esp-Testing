#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"

int a=0;
// Set your access point network credentials
const char* ssid = "Sarbhar";
const char* password = "123456789";

AsyncWebServer server(80);

String readCoords() {
  a +=1 ;
  return String(a);
}



void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.println(".");
  
  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  
  
 
  
  // Start server
  server.begin();
}
 
void loop(){
    server.on("/coords", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain",readCoords().c_str());
  });
    delay(1000);

  
}
