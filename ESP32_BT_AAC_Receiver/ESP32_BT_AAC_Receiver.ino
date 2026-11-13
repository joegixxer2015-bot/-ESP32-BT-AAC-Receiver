#include "BluetoothA2DPSink.h"

BluetoothA2DPSink a2dp_sink;

void setup() {
  Serial.begin(115200);
  
  // บอกบอร์ดให้ส่งเสียงออกไปที่ขา 26, 25, 22
  i2s_pin_config_t my_pin_config = {
    .bck_io_num = 26,
    .ws_io_num = 25,
    .data_out_num = 22,
    .data_in_num = I2S_PIN_NO_CHANGE
  };
  a2dp_sink.set_pin_config(my_pin_config);

  a2dp_sink.start("JOE_DSP");
}

void loop() {
  vTaskDelay(pdMS_TO_TICKS(100));
}
