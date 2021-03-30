#include <Arduino.h>
#include <WiFi.h>
#include <esp8266-google-home-notifier.h>

const char *ssid = "<REPLASE_YOUR_WIFI_SSID>";
const char *password = "<REPLASE_YOUR_WIFI_PASSWORD>";
const char displayName[] = "<REPLASE_YOUR_GOOGLE_HOME_SPEAKER_NAME>";

GoogleHomeNotifier ghn;

void setup()
{
  Serial.begin(115200);
  Serial.println("");
  Serial.print("connecting to Wi-Fi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); //Print the local IP

  Serial.println("connecting to Google Home...");
  if (ghn.device(displayName, "en") != true)
  {
    Serial.println(ghn.getLastError());
    return;
  }
  Serial.print("found Google Home(");
  Serial.print(ghn.getIPAddress());
  Serial.print(":");
  Serial.print(ghn.getPort());
  Serial.println(")");

  if (ghn.notify("Hello, World!") != true)
  {
    Serial.println(ghn.getLastError());
    return;
  }
  Serial.println("Done.");
}

void loop()
{
  // put your main code here, to run repeatedly:
}