#include "core_remote.h"
#include "core_http.h"

String coreGetPublicIp() {
  String ip = coreHttpGet("https://api.ipify.org");
  ip.trim();
  return ip;
}

String coreBuildLocalUrl(const String& localIp, uint16_t port) {
  if (localIp.isEmpty()) return "";
  return "http://" + localIp + ":" + String(port);
}

String coreBuildRemoteUrl(const String& publicIp, uint16_t externalPort) {
  if (publicIp.isEmpty()) return "";
  return "http://" + publicIp + ":" + String(externalPort);
}