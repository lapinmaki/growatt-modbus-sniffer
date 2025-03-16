#include "modbus_sniffer.h"

namespace esphome {
namespace modbus_sniffer {

class ModbusSniffer : public Component, public UARTDevice {
public:
    // Metodi, joka palauttaa viimeisimmän Modbus-datan
    std::string get_data() {
        return this->last_modbus_frame;  // Esimerkki: palauta viimeisin vastaanotettu Modbus data
    }

private:
    std::string last_modbus_frame;  // Muuttuja, johon tallennetaan viimeisin vastaanotettu Modbus-frame
};

// Nothing additional needed here yet.

}  // namespace modbus_sniffer
}  // namespace esphome
