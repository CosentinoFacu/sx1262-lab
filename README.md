# sx1262-lab
A modular ESP32 firmware to control, test, and characterize the Semtech SX1262 LoRa transceiver using a serial command interface. Designed for learning and low-level experimentation.

## Summary
SX1262-Lab is an educational and experimental firmware for ESP32-based SX1262 LoRa modules. Instead of focusing on end-user LoRa applications, the project provides an interactive command interface that allows developers to configure, inspect, and experiment with the radio step by step. The goal is to understand how the SX1262 works internally, from high-level RadioLib functions down to low-level SPI commands defined in the Semtech datasheet.