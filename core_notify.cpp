#include "core_notify.h"
#include "core_config.h"
#include "core_http.h"

static String coreUrlEncode(const String& s) {
  String out;
  char buf[4];

  for (size_t i = 0; i < s.length(); i++) {
    char c = s[i];

    if (isalnum((unsigned char)c) || c == '-' || c == '_' || c == '.' || c == '~') {
      out += c;
    } else if (c == ' ') {
      out += '+';
    } else {
      snprintf(buf, sizeof(buf), "%%%02X", (unsigned char)c);
      out += buf;
    }
  }

  return out;
}

bool coreSendPushover(const String& title, const String& message, int priority) {
  if (!PUSH_ENABLED) return false;

  String form =
      "token="   + coreUrlEncode(PUSH_TOKEN) +
      "&user="   + coreUrlEncode(PUSH_USER) +
      "&device=" + coreUrlEncode(PUSH_DEVICE) +
      "&title="  + coreUrlEncode(title) +
      "&message="+ coreUrlEncode(message) +
      "&priority=" + String(priority);

  String response;
  int code = coreHttpPostForm(PUSH_API_URL, form, response, 10000);
  return code > 0 && code < 300;
}