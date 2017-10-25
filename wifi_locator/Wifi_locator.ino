#include <ESP8266WiFi.h>
#include "WifiLocator.h"

#include "conf.h"

WifiLocator locator;

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println("\nReset");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.println();
  Serial.printf("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  while(!locator.updateLocation()){
    Serial.println("updateLocation failed. retry"); 
    delay(5000);
  }

  Serial.print("location: ");
  Serial.print(locator.getLat());
  Serial.print(",");
  Serial.println(locator.getLon());

  Serial.print("range: ");
  Serial.println(locator.getRange());
}

void loop() {
}





