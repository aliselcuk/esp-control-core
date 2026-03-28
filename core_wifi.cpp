#include "core_wifi.h"
#include "core_config.h"

bool coreWifiConnect(uint32_t timeoutMs) {
  if (!WIFI_ENABLED) return false;

  WiFi.mode(WIFI_STA);

#if defined(ESP8266)
  WiFi.hostname(DEVICE_NAME);
#elif defined(ESP32)
  WiFi.setHostname(DEVICE_NAME);
#endif

  if (USE_STATIC_IP) {
    WiFi.config(LOCAL_IP, GATEWAY, SUBNET, DNS1, DNS2);
  }

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  uint32_t start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < timeoutMs) {
    delay(250);
  }

  return WiFi.status() == WL_CONNECTED;
}

String coreWifiLocalIp() {
  if (WiFi.status() != WL_CONNECTED) return "";
  return WiFi.localIP().toString();
}