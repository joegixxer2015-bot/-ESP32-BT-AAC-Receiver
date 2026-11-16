#include "AudioTools.h"
#include "BluetoothA2DPSink.h"

I2SStream i2s;
BluetoothA2DPSink a2dp_sink(i2s);

void setup() {
  Serial.begin(115200);
  
  // ตั้งค่าขา I2S สำหรับบอร์ด DevKit V1 (BCK=26, WS/LRCK=25, DATA=22)
  auto cfg = i2s.defaultConfig();
  cfg.pin_bck = 26;
  cfg.pin_ws = 25;     // LRCK / WS
  cfg.pin_data = 22;   // DATA
  i2s.begin(cfg);

  // เริ่มต้นบลูทูธ
  a2dp_sink.start("JOE_DSP");
  
  // ตั้งค่าระดับเสียงเริ่มต้นเป็นสูงสุด (ป้องกันเสียงออกเป็น 0)
  a2dp_sink.set_volume(100);
}

void loop() {
  // หน่วงเวลาเพื่อแบ่งทรัพยากร CPU ให้ระบบบลูทูธทำงานได้อย่างเสถียร
  vTaskDelay(pdMS_TO_TICKS(100));
}
