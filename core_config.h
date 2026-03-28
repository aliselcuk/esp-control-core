#pragma once
#include <Arduino.h>
#include "core_platform.h"

#if __has_include("secrets.local.h")
  #include "secrets.local.h"
#endif

#include "secrets.h"

static const char* PROJECT_NAME = "ESP Control Core";

// ============================================================
// NETWORK CONFIG
// ============================================================

static const bool WIFI_ENABLED = true;
static const bool USE_STATIC_IP = false;

static const IPAddress LOCAL_IP(192,168,1,50);
static const IPAddress GATEWAY(192,168,1,1);
static const IPAddress SUBNET(255,255,255,0);
static const IPAddress DNS1(1,1,1,1);
static const IPAddress DNS2(8,8,8,8);

static const uint16_t SERVER_PORT = 80;
static const uint16_t ROUTER_INCOMING_PORT = 808;

static const char* DEVICE_NAME = "esp-control-core";
static const char* DEVICE_PLATFORM = CORE_PLATFORM_NAME;

// ============================================================
// SECURITY
// ============================================================

static const char* SECRET = SECRET_KEY;

// ============================================================
// PUSHOVER
// ============================================================

static const bool PUSH_ENABLED = PUSHOVER_ENABLED;
static const char* PUSH_TOKEN  = PUSHOVER_TOKEN;
static const char* PUSH_USER   = PUSHOVER_USER;
static const char* PUSH_DEVICE = PUSHOVER_DEVICE;
static const char* PUSH_API_URL = "https://api.pushover.net/1/messages.json";