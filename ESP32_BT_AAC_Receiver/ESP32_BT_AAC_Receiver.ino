#include "BluetoothA2DPSink.h"
BluetoothA2DPSink a2dp_sink;

static const i2s_pin_config_t my_pin_config = {
  .bck_io_num = 4,
  .ws_io_num = 5,
  .data_out_num = 6,
  .data_in_num = I2S_PIN_NO_CHANGE
};

void setup() {
  a2dp_sink.set_pin_config(my_pin_config);
  a2dp_sink.start("JOE_DSP");
}

void loop() {}
