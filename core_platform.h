#pragma once

// ============================================================
// PLATFORM DETECTION
// ============================================================

#if defined(ESP8266)
  #include <ESP8266WiFi.h>
  #include <ESP8266WebServer.h>
  using ESPWebServerType = ESP8266WebServer;
  #define CORE_PLATFORM_NAME "ESP8266"

#elif defined(ESP32)
  #include <WiFi.h>
  #include <WebServer.h>
  using ESPWebServerType = WebServer;
  #define CORE_PLATFORM_NAME "ESP32"

#else
  #error Unsupported platform. Only ESP8266 and ESP32 are supported.
#endif