#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Замените на свои данные Wi-Fi
const char* ssid = "Nepike";
const char* password = "123453119670";

ESP8266WebServer server(80);
IPAddress localIp;

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT); // Установка GPIO-2 как выход
  digitalWrite(2, HIGH); // Выключаем светодиод
  
  // Подключение к Wi-Fi
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("connecting Wi-Fi...");
  }
  
  Serial.println("connected Wi-Fi!");
  localIp = WiFi.localIP(); // Получаем IP-адрес устройства
  Serial.print("IP: ");
  Serial.println(localIp);

  // Обработка запроса
  server.on("/lumos", HTTP_GET, handle_lumos);
  server.on("/nox", HTTP_GET, handle_nox);
  
  server.begin();
}

void loop() {
  server.handleClient();
}

void handle_lumos() {
  digitalWrite(2, LOW); // Включаем светодиод
  String response = "LED on! IP: " + localIp.toString(); // Формируем сообщение для отправки
  server.send(200, "text/plain", response); // Отправляем ответ
}

void handle_nox() {
  digitalWrite(2, HIGH); // Выключаем светодиод
  String response = "LED off! IP: " + localIp.toString(); // Формируем сообщение для отправки
  server.send(200, "text/plain", response); // Отправляем ответ
}
