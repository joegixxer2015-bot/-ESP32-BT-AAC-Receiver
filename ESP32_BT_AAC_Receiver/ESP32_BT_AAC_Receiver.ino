#include "BluetoothA2DPSink.h"

BluetoothA2DPSink a2dp_sink;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting Bluetooth...");
  
  // เริ่มต้นบลูทูธชื่อ JOE_DSP แบบมาตรฐาน
  a2dp_sink.start("JOE_DSP");
  Serial.println("Bluetooth Started Successfully!");
}

void loop() {
  // หน่วงเวลาให้ Task อื่นๆ ในระบบทำงานได้อย่างราบรื่น
  vTaskDelay(pdMS_TO_TICKS(100));
}
