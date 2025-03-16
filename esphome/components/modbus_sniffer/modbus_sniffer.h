#pragma once

#include "esphome.h"

class ModbusSniffer : public Component, public UARTDevice {
public:
    ModbusSniffer(UARTComponent *parent) : UARTDevice(parent) {}

    void setup() override {
        // Asennetaan tarvittavat alustuskomennot
    }

    void loop() override {
        // Tässä voidaan lukea Modbus-dataa
        if (this->available()) {
            this->last_modbus_frame = this->read(); // Muokkaa tämän mukaan
        }
    }

    std::string get_data() {
        return this->last_modbus_frame; // Palautetaan viimeisin vastaanotettu Modbus-data
    }

private:
    std::string last_modbus_frame; // Muuttuja, johon tallennetaan viimeisin Modbus-frame
};
