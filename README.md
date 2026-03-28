# ⚡ ESP Control Core

A lightweight, reusable control framework for ESP8266 and ESP32 devices.

Designed for real-world embedded projects with Wi-Fi control, HTTP interface, remote access (via port forwarding), and optional push notifications.

Built to be simple, modular, and actually reusable across projects.

---

## ✨ Features

* ESP8266 & ESP32 support (single codebase)
* Built-in Wi-Fi connection handling
* HTTP server (web interface ready)
* Secret key protection for endpoints
* Public IP detection
* Remote URL generation (port forwarding friendly)
* Pushover notifications (optional)
* Minimal HTML helpers
* Clean modular architecture

---

## 🧠 Philosophy

This is not a heavy framework.

* No overengineering
* No hidden magic
* No unnecessary abstraction

Just a clean, reusable base you can copy into real projects.

---

## 📁 Project Structure

```id="struct1"
.
├── esp-control-core.ino
├── core_platform.h
├── core_config.h
├── core_app.h
├── core_app.cpp
├── core_wifi.h
├── core_wifi.cpp
├── core_http.h
├── core_http.cpp
├── core_remote.h
├── core_remote.cpp
├── core_notify.h
├── core_notify.cpp
├── core_ui.h
├── core_ui.cpp
├── secrets.h
├── secrets.local.h (ignored)
└── .gitignore
```

---

## ⚡ Quick Start

1. Clone the repository

2. Open in Arduino IDE

3. Create your local secrets file:

```id="cmd1"
secrets.local.h
```

4. Fill in your credentials:

```cpp id="code1"
#pragma once

#define WIFI_SSID        "your_wifi"
#define WIFI_PASSWORD    "your_password"

#define SECRET_KEY       "your_secret_key"

#define PUSHOVER_ENABLED true
#define PUSHOVER_TOKEN   "your_token"
#define PUSHOVER_USER    "your_user"
#define PUSHOVER_DEVICE  "your_device"
```

5. Upload to ESP8266 or ESP32

6. Open Serial Monitor → get device IP

7. Open in browser:

```id="url1"
http://<DEVICE_IP>
```

---

## 🌐 Web Endpoints

| Endpoint     | Description              |
| ------------ | ------------------------ |
| `/`          | Status page              |
| `/ping`      | Health check             |
| `/protected` | Requires `key` parameter |

Example:

```id="ex1"
http://<IP>/protected?key=YOUR_SECRET
```

---

## 🔐 Secrets Configuration

Sensitive data is not stored in the repository.

### How it works

* `secrets.h` → default values (safe)
* `secrets.local.h` → your real credentials (ignored by git)

### Notes

* Never commit `secrets.local.h`
* This keeps your repo clean and secure

---

## 🌍 Remote Access

This framework supports remote control via router port forwarding.

Example:

* Local:

  ```
  http://192.168.1.50:80
  ```

* Remote:

  ```
  http://<PUBLIC_IP>:808
  ```

The device can automatically:

* Detect public IP
* Build remote URL
* Send it via Pushover

---

## 📡 Pushover Integration

Optional notification on boot:

* Device name
* Local URL
* Remote URL

Example message:

```
Device: esp-control-core
Platform: ESP8266
Local: http://192.168.1.50:80
Remote: http://x.x.x.x:808
```

---

## 🔧 Platform Support

| Platform | Supported |
| -------- | --------- |
| ESP8266  | ✅         |
| ESP32    | ✅         |

Handled internally via `core_platform.h`.

---

## 🚀 Usage in Projects

Typical usage pattern:

```cpp id="usage1"
void setup() {
  coreInit();
}

void loop() {
  coreLoop();
}
```

Add your own routes:

```cpp id="usage2"
coreServer().on("/my-endpoint", myHandler);
```

---

## 💡 Example Use Cases

* Remote switches
* Audio trigger systems
* IoT dashboards
* Alert systems
* Embedded web control panels

---

## ⚠️ Notes

* Do not power ESP via USB and external 5V at the same time
* Ensure stable Wi-Fi signal
* Public IP requires internet access

---

## 📜 License

MIT

---

## 🙌 Credits

Built for real-world usage, not just demos.

