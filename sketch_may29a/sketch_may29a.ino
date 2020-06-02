#include "Esp8266.h"


void setup() {
  WIFI esp8266 = WIFI("HOME(R&I)","33264672i");
  IPAddress ip(192,168,1,51);
  IPAddress msk(255,255,255,0);
  IPAddress gw(192,168,1,1);
  esp8266.definiIP(ip,msk,gw);
  esp8266.HTTP(80);

  pinMode(pin,OUTPUT);
  digitalWrite(pin, HIGH);
  WiFiServer server(80);

  
}

void loop() {
flot celsius = myTMP

}
