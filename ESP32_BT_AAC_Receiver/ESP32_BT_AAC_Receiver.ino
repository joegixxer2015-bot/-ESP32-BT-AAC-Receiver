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

  // 1. บังคับเปิดโหมดให้มือถือค้นหาชื่อเจอ (Discoverable) และเปิดรับการเชื่อมต่อ
  a2dp_sink.set_discoverable(true);

  // 2. เอา clean_last_connection() ออก เพื่อไม่ให้ล้างกุญแจจับคู่ทิ้งทุกครั้งที่รีบูต
  // (หากต้องการล้างค่าจริงๆ ค่อยเปิดใช้แค่ครั้งเดียวแล้วปิดกลับ)
  // a2dp_sink.clean_last_connection();

  // 3. เริ่มต้น A2DP Sink โดยเปิด Auto-Reconnect เป็น true เพื่อให้ต่อกลับอัตโนมัติได้
  a2dp_sink.start("JOE_DSP", true); 
  
  Serial.println("Bluetooth JOE_DSP Ready!");
}

void loop() {
  vTaskDelay(pdMS_TO_TICKS(100));
}
