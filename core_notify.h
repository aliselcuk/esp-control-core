#pragma once
#include <Arduino.h>

bool coreSendPushover(const String& title, const String& message, int priority = 0);