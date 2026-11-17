#include "AudioTools.h"
#include "BluetoothA2DPSink.h"

I2SStream i2s;
BluetoothA2DPSink a2dp_sink(i2s);

void setup() {
  Serial.begin(115200);
  
  auto cfg = i2s.defaultConfig();
  cfg.pin_bck = 26;
  cfg.pin_ws = 25;     // LRCK / WS
  cfg.pin_data = 22;   // DATA
  cfg.buffer_size = 1024 * 8; 
  
  // เปิดใช้งาน I2S ฝั่งส่งออก (DevKit ทำหน้าที่เป็น Master จ่าย Clock อัตโนมัติ)
  i2s.begin(cfg);

  // เริ่มต้นบลูทูธพร้อมส่ง config ที่ตั้งพินเข้าไป
  a2dp_sink.start("JOE_DSP", cfg); 
}

void loop() {
  vTaskDelay(pdMS_TO_TICKS(100));
}
