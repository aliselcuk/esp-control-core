#include "core_http.h"
#include "core_platform.h"

#if defined(ESP8266)
  #include <ESP8266HTTPClient.h>
  #include <WiFiClientSecureBearSSL.h>
#elif defined(ESP32)
  #include <HTTPClient.h>
  #include <WiFiClientSecure.h>
#endif

String coreHttpGet(const String& url, uint32_t timeoutMs) {
#if defined(ESP8266)
  std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);
  client->setInsecure();

  HTTPClient http;
  http.setTimeout(timeoutMs);

  if (!http.begin(*client, url)) return "";
  int code = http.GET();
  String body = (code > 0) ? http.getString() : "";
  http.end();
  return body;

#elif defined(ESP32)
  WiFiClientSecure client;
  client.setInsecure();

  HTTPClient http;
  http.setTimeout(timeoutMs);

  if (!http.begin(client, url)) return "";
  int code = http.GET();
  String body = (code > 0) ? http.getString() : "";
  http.end();
  return body;
#endif
}

int coreHttpPostForm(const String& url, const String& formData, String& response, uint32_t timeoutMs) {
#if defined(ESP8266)
  std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);
  client->setInsecure();

  HTTPClient http;
  http.setTimeout(timeoutMs);

  if (!http.begin(*client, url)) return -999;
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int code = http.POST(formData);
  response = (code > 0) ? http.getString() : "";
  http.end();
  return code;

#elif defined(ESP32)
  WiFiClientSecure client;
  client.setInsecure();

  HTTPClient http;
  http.setTimeout(timeoutMs);

  if (!http.begin(client, url)) return -999;
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int code = http.POST(formData);
  response = (code > 0) ? http.getString() : "";
  http.end();
  return code;
#endif
}