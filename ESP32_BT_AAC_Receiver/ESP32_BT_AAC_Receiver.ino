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
  
  // ตัดบรรทัดขยาย Buffer ทิ้ง ปล่อยให้ใช้ค่าเริ่มต้นของระบบเพื่อความเสถียร
  i2s.begin(cfg);

  // ล้างประวัติการเชื่อมต่อเก่า และเปิดโหมดค้นหาบลูทูธทันที
  a2dp_sink.clean_last_connection();
  a2dp_sink.start("JOE_DSP", false); 
}

void loop() {
  vTaskDelay(pdMS_TO_TICKS(100));
}
