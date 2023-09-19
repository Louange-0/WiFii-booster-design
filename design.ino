#include <Servo.h>
#include <ESP8266WiFi.h>

Servo antennaMotor;

void setup() {
  antennaMotor.attach(9);
  Serial.begin(115200);
  connectToWiFi();
}

void loop() {
  int signalStrength = readWifiSignalStrength();
  int desiredPosition = map(signalStrength, -100, -40, 0, 180); // Adjust the signal strength range as needed
  antennaMotor.write(desiredPosition);
  delay(1000);
}

int readWifiSignalStrength() {
  long rssi = WiFi.RSSI(); // Read Wi-Fi signal strength in dBm
  Serial.print("Signal Strength (dBm): ");
  Serial.println(rssi);
  return rssi;
}

void connectToWiFi() {
  // Replace with your Wi-Fi credentials
  const char* ssid = "RCA-WiFii";
  const char* password = "@rca@2023";

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected to WiFi");
}
