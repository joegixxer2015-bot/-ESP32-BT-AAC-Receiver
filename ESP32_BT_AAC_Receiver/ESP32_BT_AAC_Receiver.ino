#include "BluetoothA2DPSink.h"

BluetoothA2DPSink a2dp_sink;

void setup() {
  // เริ่มต้นบลูทูธ (รองรับการสตรีมเสียง SBC/AAC อัตโนมัติ)
  a2dp_sink.start("JOE_DSP");
}

void loop() {
  // หน่วงเวลาให้ซีพียูได้พัก ไม่ทำงานหนักเกินไป
  vTaskDelay(pdMS_TO_TICKS(100));
}
