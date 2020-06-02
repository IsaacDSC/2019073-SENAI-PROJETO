#include <ESP8266WiFi.h>


const int pin = 13;

struct WIFI {
  WIFI(String ssid, String pwd) {
    Serial.begin(115200);
    //taixa de tranferencia
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid,pwd);
    Serial.println();
    Serial.print("Conectando ao roteador WiFi");
    while(WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
    }
    Serial.println("OK!");
    Serial.print("Endereco IP: ");
    Serial.println(WiFi.localIP());
  }
  void definiIP(IPAddress IP,IPAddress MSK,IPAddress GW) {
    WiFi.config(IP,GW,MSK);
    Serial.println("Endereco IP: "+WiFi.localIP().toString());
  }
  String obterIP() {
    return WiFi.localIP().toString();
  }
  void HTTP(int porta) {
    WiFiServer servidor(porta);
    servidor.begin();
    while(true) {
      WiFiClient cliente = servidor.available();
      if(!cliente)
        continue;
      String requisicao = cliente.readStringUntil('\r');
      Serial.println(requisicao); 
      cliente.flush();
      cliente.println("HTTP/1.1 200 OK");
      cliente.println("Access-Control-Allow-Origin: *");
      cliente.println("Servidor de pé!");
      
    }
  }
};
