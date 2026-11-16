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

  // ปิด AAC เพื่อบังคับให้ iPhone ใช้ SBC (แก้ปัญหาเสียงสะดุกกระตุก)
  a2dp_sink.set_is_aac_supported(false);

  // เริ่มต้นบลูทูธ (ชื่ออุปกรณ์ที่มือถือจะค้นหา)
  a2dp_sink.start("JOE_DSP");
}

void loop() {
  // หน่วงเวลาเพื่อแบ่งทรัพยากร CPU ให้ระบบบลูทูธทำงานได้อย่างเสถียร
  vTaskDelay(pdMS_TO_TICKS(100));
}
