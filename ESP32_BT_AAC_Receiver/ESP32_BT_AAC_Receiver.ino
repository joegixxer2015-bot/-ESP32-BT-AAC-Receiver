#include "AudioTools.h"
#include "BluetoothA2DPSink.h"

I2SStream i2s;
BluetoothA2DPSink a2dp_sink(i2s);

void setup() {
  Serial.begin(115200);
  delay(500);

  auto cfg = i2s.defaultConfig();
  cfg.pin_bck = 26;
  cfg.pin_ws = 25;     // LRCK / WS
  cfg.pin_data = 22;   // DATA
  i2s.begin(cfg);

  // ไม่เรียก set_discoverability เพราะค่าคงที่ ESP_BT_SCAN_MODE_DISCOVERABLE ไม่มีในชุดนี้
  // เอา clean_last_connection() ออก เพื่อไม่ให้ลบลิงก์จับคู่ทุกครั้งที่รีบูต
  // a2dp_sink.clean_last_connection();

  // เริ่มต้น A2DP Sink โดยเปิด Auto-Reconnect เป็น true
  a2dp_sink.start("JOE_DSP", true);

  Serial.println("Bluetooth JOE_DSP Ready!");
}

void loop() {
  vTaskDelay(pdMS_TO_TICKS(100));
}
