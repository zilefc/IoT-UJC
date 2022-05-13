#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>

#define FIREBASE_HOST "ujc2022-34589-default-rtdb.europe-west1.firebasedatabase.app"
#define FIREBASE_AUTH "0O7bt2ZSUhU4LrmEu0UcEx51C8UDMnxFJGM9VhXc"
#define WIFI_SSID "Elite way 2"
#define WIFI_PASSWORD ""

const int Sala = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(Sala, OUTPUT);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  if (Firebase.failed())
  {
    Serial.print(Firebase.error());
  }
  else {
    Serial.print("Firebase Connected");
  }

  Firebase.setInt("S1", 0);
}
void loop()
{
  FirebaseObject sala = Firebase.get("/SALA/");
  String LuzSala = sala.getString("estado");
  if (LuzSala == "LIGADA") {
    digitalWrite(Sala, LOW);
  }
  else if (LuzSala == "DESLIGADA") {
    digitalWrite(Sala, HIGH);
  }

 
}
