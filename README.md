# ESP32 Bluetooth Control Car

A small car controlled wirelessly over Bluetooth using an ESP32. This project is a hands-on introduction to microcontrollers, wireless communication, and controlling motors.

ESP32 Bluetooth car project overview
(<img width="2000" height="1500" alt="IMG_20261102_172214" src="https://github.com/user-attachments/assets/d7477788-d997-4f9f-9e24-171b5aab93c8" />
)

## Features

- Wireless control over Bluetooth
- ESP32-based control
- Motorized movement in response to commands from a paired device

## Hardware

The exact parts may vary depending on your build. A typical setup includes:

- ESP32 development board
- Robot car chassis and DC motors
- Motor driver module (L298N)
- Battery or other suitable power source (2S li-ion Battery)
- Bluetooth-capable phone or computer (prefer Bluetooth Control Android App)
- Jumper wires and basic mounting hardware

## How it works

A Bluetooth-capable device sends movement commands to the ESP32. The ESP32 processes those commands and signals the motor driver, which powers the car's motors.

## Getting started

1. Assemble the car and connect the motors to the motor driver.
2. Connect the motor driver control pins to the ESP32.
3. Upload the project firmware to the ESP32.
4. Pair your phone or computer with the car over Bluetooth.
5. Send movement commands using the controller.


## Wiring

```text
Bluetooth device  →  ESP32  →  Motor driver  →  DC motors
                         ↑
                    Power source
```
Full connection in above file "Circuit diagram"
