#pragma once
#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"
#include "esphome/components/text_sensor/text_sensor.h"

namespace esphome {
namespace modbus_sniffer {

class ModbusSniffer : public Component, public uart::UARTDevice {
 public:
  ModbusSniffer(uart::UARTComponent *parent) : uart::UARTDevice(parent) {}

  void set_text_sensor(text_sensor::TextSensor *sensor) { sensor_ = sensor; }

  void loop() override {
    while (this->available()) {
      uint8_t byte;
      this->read_byte(&byte);
      buffer_ += byte_to_hex(byte) + " ";
      if (byte == 0x0D || byte == 0x0A || buffer_.length() > 50) {
        if (sensor_ != nullptr) {
          sensor_->publish_state(buffer_);
        }
        buffer_.clear();
      }
    }
  }

 protected:
  std::string buffer_;
  text_sensor::TextSensor *sensor_{nullptr};

  std::string byte_to_hex(uint8_t byte) {
    char hex[5];
    sprintf(hex, "%02X", byte);
    return std::string(hex);
  }
};

}  // namespace modbus_sniffer
}  // namespace esphome
