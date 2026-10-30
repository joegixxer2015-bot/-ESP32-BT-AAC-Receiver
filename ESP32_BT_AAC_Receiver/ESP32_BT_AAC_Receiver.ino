#include "BluetoothA2DPSink.h"

BluetoothA2DPSink a2dp_sink;

void setup() {
  // เปิดใช้งานโหมดถอดรหัส AAC
  a2dp_sink.set_nfc_active(false); // ปิด NFC ถ้าไม่ได้ใช้
  
  // เริ่มต้นบลูทูธและเปิดใช้งาน AAC Sink
  a2dp_sink.start("JOE_DSP");
}

void loop() {}
