# Growatt Modbus Sniffer for ESPHome

This ESPHome external component listens to Modbus RTU traffic (e.g., Growatt inverter communication) and displays the raw hex data on a web dashboard.

### Features
- Sniffs Modbus RTU traffic (RS485) via UART.
- Displays hex data on ESPHome web server and Home Assistant.
- Easy to integrate into any ESPHome project.

### Usage

Add this to your `external_components` in YAML:

```yaml
external_components:
  - source: github://yourusername/growatt-modbus-sniffer
