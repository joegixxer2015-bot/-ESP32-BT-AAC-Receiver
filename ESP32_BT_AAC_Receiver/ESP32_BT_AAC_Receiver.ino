#include "BluetoothA2DPSink.h"

BluetoothA2DPSink a2dp_sink;

void setup() {
  // เริ่มต้นบลูทูธ (รองรับการสตรีมเสียง SBC/AAC อัตโนมัติ)[span_1](start_span)[span_1](end_span)
  a2dp_sink.start("JOE_DSP");[span_2](start_span)[span_2](end_span)
}

void loop() {
  // เพิ่มบรรทัดหน่วงเวลานี้เข้าไป เพื่อไม่ให้ซีพียูทำงานหนักเกินไปตอนสตรีมเสียง
  vTaskDelay(pdMS_TO_TICKS(100)); 
}
