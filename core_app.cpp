#include <Arduino.h>

#include "core_app.h"
#include "core_config.h"
#include "core_wifi.h"
#include "core_remote.h"
#include "core_notify.h"
#include "core_ui.h"

ESPWebServerType server(SERVER_PORT);

static String gLocalIp;
static String gPublicIp;
static String gLocalUrl;
static String gRemoteUrl;

static bool coreCheckSecret() {
  if (!server.hasArg("key")) return false;
  return server.arg("key") == SECRET;
}

static void handleRoot() {
  String html = coreHtmlHeader("ESP Control Core");
  html += coreHtmlStatusCard("Device", DEVICE_NAME);
  html += coreHtmlStatusCard("Platform", DEVICE_PLATFORM);
  html += coreHtmlStatusCard("Local IP", gLocalIp);
  html += coreHtmlStatusCard("Public IP", gPublicIp);
  html += coreHtmlStatusCard("Local URL", gLocalUrl);
  html += coreHtmlStatusCard("Remote URL", gRemoteUrl);
  html += coreHtmlFooter();
  server.send(200, "text/html", html);
}

static void handlePing() {
  server.send(200, "text/plain", "OK");
}

static void handleProtected() {
  if (!coreCheckSecret()) {
    server.send(403, "text/plain", "FORBIDDEN");
    return;
  }
  server.send(200, "text/plain", "AUTHORIZED");
}

void coreInit() {
  Serial.begin(115200);
  delay(200);

  bool ok = coreWifiConnect();
  gLocalIp = coreWifiLocalIp();

  if (ok) {
    gPublicIp = coreGetPublicIp();
    gLocalUrl = coreBuildLocalUrl(gLocalIp, SERVER_PORT);
    gRemoteUrl = coreBuildRemoteUrl(gPublicIp, ROUTER_INCOMING_PORT);

    String msg = "Device: " + String(DEVICE_NAME) + "\nPlatform: " + String(DEVICE_PLATFORM) + "\nLocal: " + gLocalUrl + "\nRemote: " + gRemoteUrl;

    coreNotifyUser("ESP Online", msg);
  }

  server.on("/", handleRoot);
  server.on("/ping", handlePing);
  server.on("/protected", handleProtected);

  server.begin();

  Serial.println("Ready");
  Serial.println(gLocalUrl);
  Serial.println(gRemoteUrl);
}

void coreLoop() {
  server.handleClient();
}

ESPWebServerType& coreServer() {
  return server;
}