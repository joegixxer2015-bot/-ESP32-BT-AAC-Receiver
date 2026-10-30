#include "BluetoothA2DPSink.h"

BluetoothA2DPSink a2dp_sink;

void setup() {
  // เริ่มต้นบลูทูธโดยใช้พิน I2S ค่าเริ่มต้นของไลบรารี
  a2dp_sink.start("JOE_DSP");
}

void loop() {}
