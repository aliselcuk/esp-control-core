#include "core_ui.h"

String coreHtmlHeader(const String& title) {
  String s;
  s += "<!doctype html><html><head><meta name='viewport' content='width=device-width,initial-scale=1'>";
  s += "<title>" + title + "</title>";
  s += "<style>";
  s += "body{font-family:Arial,sans-serif;max-width:720px;margin:20px auto;padding:0 12px}";
  s += ".card{border:1px solid #ddd;border-radius:12px;padding:14px;margin-bottom:14px}";
  s += "button,input,select{font-size:16px;padding:10px;border-radius:10px}";
  s += "</style></head><body>";
  s += "<h2>" + title + "</h2>";
  return s;
}

String coreHtmlFooter() {
  return "</body></html>";
}

String coreHtmlStatusCard(const String& label, const String& value) {
  return "<div class='card'><b>" + label + ":</b> " + value + "</div>";
}