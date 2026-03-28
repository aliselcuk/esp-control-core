#pragma once
#include <Arduino.h>

String coreHttpGet(const String& url, uint32_t timeoutMs = 10000);
int coreHttpPostForm(const String& url, const String& formData, String& response, uint32_t timeoutMs = 10000);