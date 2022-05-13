#include<FirebaseArduino.h>

#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID ""
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
  FirebaseObject sala = Firebase.get(/SALA/);
  String LuzSala = sala.getString("estado");
  if (LuzSala == "LIGADA") {
    digitalWrite(Sala, LOW);
  }
  else if (LuzSala == "DESLIGADA") {
    digitalWrite(Sala, HIGH);
  }

 
}
