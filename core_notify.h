#pragma once
#include <Arduino.h>

bool coreNotifyUser(const String& title, const String& message, int priority = 0);
bool coreNotifyPushover(const String& title, const String& message, int priority = 0);