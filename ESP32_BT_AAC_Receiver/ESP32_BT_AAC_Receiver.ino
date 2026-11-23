#include "AudioTools.h"
#include "BluetoothA2DPSink.h"

I2SStream i2s;
BluetoothA2DPSink a2dp_sink(i2s);

void setup() {
  Serial.begin(115200);
  delay(500);

  auto cfg = i2s.defaultConfig(TX_MODE);
  cfg.sample_rate = 44100;
  cfg.channels = 2;
  cfg.bits_per_sample = 16;
  cfg.is_master = true;
  cfg.pin_bck = 26;
  cfg.pin_ws = 25;     // LRCK / WS
  cfg.pin_data = 22;   // DATA
  cfg.buffer_count = 8;
  cfg.buffer_size = 512;
  i2s.begin(cfg);

  // เริ่มต้น A2DP Sink โดยเปิด Auto-Reconnect เป็น true
  a2dp_sink.start("JOE_DSP", true);

  Serial.println("Bluetooth JOE_DSP Ready!");
}

void loop() {
  vTaskDelay(pdMS_TO_TICKS(100));
}
