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
  
  // เพิ่มขนาด Buffer ให้ใหญ่ขึ้น (จากค่าเริ่มต้น ช่วยซับแรงกระแทกตอน iPhone ส่งข้อมูล)
  cfg.buffer_size = 1024 * 8; 
  i2s.begin(cfg);

  // เริ่มต้นบลูทูธ
  a2dp_sink.start("JOE_DSP");
}

void loop() {
  vTaskDelay(pdMS_TO_TICKS(100));
}
