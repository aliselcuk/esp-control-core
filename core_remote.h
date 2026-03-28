#pragma once
#include <Arduino.h>

String coreGetPublicIp();
String coreBuildLocalUrl(const String& localIp, uint16_t port);
String coreBuildRemoteUrl(const String& publicIp, uint16_t externalPort);