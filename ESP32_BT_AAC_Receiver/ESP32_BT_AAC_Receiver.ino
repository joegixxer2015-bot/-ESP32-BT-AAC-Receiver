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

  // ตั้งโหมดให้ค้นหาชื่อเจอด้วยชื่อเมธอดที่ตรงกับคลาส BluetoothA2DPSink
  a2dp_sink.set_discoverability(ESP_BT_SCAN_MODE_DISCOVERABLE);

  // คอมเมนต์ clean_last_connection() เพื่อไม่ให้ลบลิงก์จับคู่ทุกครั้งที่เปิดบอร์ด
  // a2dp_sink.clean_last_connection();

  a2dp_sink.start("JOE_DSP", true);

  Serial.println("Bluetooth JOE_DSP Ready!");
}

void loop() {
  vTaskDelay(pdMS_TO_TICKS(100));
}
