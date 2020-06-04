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
      String req = cliente.readStringUntil('\r');
      Serial.println(req);
      req.replace("GET /","");
      req.replace(" HTTP/1.1","");


    
      //Analisando a requisicao recebida para decidir se liga ou desliga a lampada
  if (req.indexOf("on") != -1)
  {
    digitalWrite(pin, LOW);
  }
  else if (req.indexOf("off") != -1)
  {
    digitalWrite(pin, HIGH);
  }

      

      
      
      /*
       * int pino;
      int acao;
      if(requisicao.length()==4) {
        pino = requisicao.substring(0,2).toInt();
        acao = requisicao.substring(3,4).toInt();
      }
      else if(requisicao.length()==3) {
        pino = requisicao.substring(0,1).toInt();
        acao = requisicao.substring(2,3).toInt();
      }
      Serial.println("Pino: "+String(pino));
      Serial.println("Acao: "+String(acao));
      digitalWrite(pino,acao);*/
    }
  }
};
