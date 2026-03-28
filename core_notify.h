#pragma once
#include <Arduino.h>

bool coreNotify(const String& message, const String& prefix = "", int priority = 0);
bool coreNotifyPushover(const String& title, const String& message, int priority = 0);