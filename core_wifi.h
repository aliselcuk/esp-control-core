#pragma once
#include <Arduino.h>
#include "core_platform.h"

bool coreWifiConnect(uint32_t timeoutMs = 20000);
String coreWifiLocalIp();