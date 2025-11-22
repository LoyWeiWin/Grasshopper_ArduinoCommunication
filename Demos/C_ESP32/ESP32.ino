/**
 * ESP32 <-> Grasshopper UDP
 * Buzzer control: "1" = 3 beeps, "0" = silent
 */

#include <WiFi.h>
#include <WiFiUdp.h>

// ---------- USER CONFIG ----------
const char* WIFI_SSID     = "NOKIA-1994";
const char* WIFI_PASSWORD = "27a7a29afc";

const uint16_t ESP32_LISTEN_PORT = 8888;   // ESP32 listens here
// ---------------------------------

WiFiUDP udp;

// ---------- Buzzer ----------
#define BUZZER_PIN 23   // choose your GPIO
// --------------------------------

void beepSequence() {
  for (int i = 0; i < 3; i++) {
    tone(BUZZER_PIN, 2000);  // 2 kHz beep
    delay(200);              // beep duration
    noTone(BUZZER_PIN);
    delay(800);              // gap before next beep
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);
  noTone(BUZZER_PIN);

  // WiFi connect
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.printf("Connecting to %s", WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.printf("\nWiFi connected. IP: %s\n", WiFi.localIP().toString().c_str());

  // UDP start
  if (udp.begin(ESP32_LISTEN_PORT)) {
    Serial.printf("UDP listening on %u\n", ESP32_LISTEN_PORT);
  }
}

void loop() {
  int pktLen = udp.parsePacket();
  if (pktLen > 0) {
    char buf[16];
    int n = udp.read(buf, sizeof(buf) - 1);
    buf[n] = '\0';
    String msg(buf);
    msg.trim();

    if (msg == "1") {
      Serial.println("Trigger beep sequence");
      beepSequence();
    } else if (msg == "0") {
      Serial.println("No sound");
      noTone(BUZZER_PIN); // ensure silence
    } else {
      Serial.printf("Unknown: %s\n", msg.c_str());
    }
  }
}
