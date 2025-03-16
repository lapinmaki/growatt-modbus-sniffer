#include "modbus_sniffer.h"

namespace esphome {
namespace custom_components {

  // Liitetään ModbusSniffer C++-koodiin
  static ModbusSniffer *modbus_sniffer = nullptr;

  void setup() {
    modbus_sniffer = new ModbusSniffer(id(modbus_uart));
    App.register_component(modbus_sniffer);
  }

  void loop() {
    if (modbus_sniffer != nullptr) {
        modbus_sniffer->loop();  // Luetaan Modbus-data
    }
  }

}  // namespace custom_components
}  // namespace esphome
