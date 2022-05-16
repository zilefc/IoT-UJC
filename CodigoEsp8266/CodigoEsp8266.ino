#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>

#define FIREBASE_HOST "ujc2022-cd76a-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "OGbq8ZfaeJT2uE9aZRvc6AKys1h3qynaJbHMTdbx"
#define WIFI_SSID "TME Education"
#define WIFI_PASSWORD "mz123456mpz"

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
    Firebase.setInt("S1", 0);
  }

  
}
void loop()
{
  Firebase.setInt("S1", 0);
  
  FirebaseObject casa = Firebase.get("/SALA/");
  String LuzSala = casa.getString("estado");
  if (LuzSala == "LIGADA") {
    digitalWrite(Sala, LOW);
  }
  else if (LuzSala == "DESLIGADA") {
    digitalWrite(Sala, HIGH);
  }
}
