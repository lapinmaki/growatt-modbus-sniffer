import esphome.config_validation as cv
from esphome.components import uart, text_sensor
from esphome.const import CONF_ID

import esphome.codegen as cg

# Define custom constants
CONF_TEXT_SENSOR = "text_sensor"

# Create a namespace for modbus_sniffer
modbus_sniffer_ns = cg.esphome_ns.namespace("modbus_sniffer")

# Define ModbusSniffer class
ModbusSniffer = modbus_sniffer_ns.class_("ModbusSniffer", cg.Component, uart.UARTDevice)

# Define the schema for the modbus_sniffer component
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(ModbusSniffer),
    cv.Required("uart_id"): cv.use_id(uart.UARTComponent),
    cv.Required(CONF_TEXT_SENSOR): cv.use_id(text_sensor.TextSensor),
}).extend(cv.COMPONENT_SCHEMA)

# Function to define the logic for the component
async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID], config["uart_id"])
    await cg.register_component(var, config)
    await uart.register_uart_device(var, config["uart_id"])
    text_sensor_ = await cg.get_variable(config[CONF_TEXT_SENSOR])
    cg.add(var.set_text_sensor(text_sensor_))
