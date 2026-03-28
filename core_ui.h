#pragma once
#include <Arduino.h>

String coreHtmlHeader(const String& title);
String coreHtmlFooter();
String coreHtmlStatusCard(const String& label, const String& value);