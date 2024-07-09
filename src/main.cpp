#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "Veljko";
const char* password = "Vladaanja";

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    WiFi.begin(ssid, password);
     while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}

void loop() {
  // put your main code here, to run repeatedly:
  int numNetworks = WiFi.scanNetworks();

    if (numNetworks == 0) {
        Serial.println("No networks found");
    } else {
        Serial.print(numNetworks);
        Serial.println(" networks found");

        for (int i = 0; i < numNetworks; i++) {
            // Print SSID and RSSI (signal strength) for each network found
            Serial.print("Network: ");
            Serial.println(WiFi.SSID(i));
            Serial.print("Signal strength (RSSI): ");
            Serial.println(WiFi.RSSI(i));
            Serial.print("Encryption type: ");
            switch (WiFi.encryptionType(i)) {
                case (WIFI_AUTH_OPEN):
                    Serial.println("Open");
                    break;
                case (WIFI_AUTH_WEP):
                    Serial.println("WEP");
                    break;
                case (WIFI_AUTH_WPA_PSK):
                    Serial.println("WPA-PSK");
                    break;
                case (WIFI_AUTH_WPA2_PSK):
                    Serial.println("WPA2-PSK");
                    break;
                case (WIFI_AUTH_WPA_WPA2_PSK):
                    Serial.println("WPA/WPA2-PSK");
                    break;
                default:
                    Serial.println("Unknown");
                    break;
            }
            Serial.println("-----------------------");
        }
    }

    delay(10000);  // Delay 10 seconds before scanning again
}

