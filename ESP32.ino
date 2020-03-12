// carregar biblioteca Wi-Fi 
#include <WiFi.h>

//credenciais da rede a ser usada
const char* ssid     = "";
const char* password = "";

// porta do servidor
WiFiServer server(80);

String header;

//definicao de variaveis
String output25State = "off";
String output26State = "off";

// atribuir variaveis aos pinoss
const int output25 = 25;
const int output26 = 26;

void setup() {
  Serial.begin(115200);
  // Inicializa as variaveis 
  pinMode(output25, OUTPUT);
  pinMode(output26, OUTPUT);
  
   // Conecta a rede Wi-Fi com o SSID e Senha
  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // IP Local e inicio do servidor web
  Serial.println("");
  Serial.println("WiFi conectado.");
  Serial.println("IP: ");
  Serial.println(WiFi.localIP());
  server.begin();
}