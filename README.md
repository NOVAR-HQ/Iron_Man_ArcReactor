# Arc Reactor NeoPixel Animation

This Arduino project simulates a glowing arc reactor using a ring of NeoPixels. The animation starts with a smooth startup sequence, lighting each LED one by one, then transitions into a slow, layered pulsing effect that fades between cyan, blue, and white — mimicking the iconic glow from Iron Man’s Arc Reactor.



## What You Need

- **Arduino board** (e.g., Uno, Nano, Leonardo, etc.)
- **Adafruit NeoPixel Ring or Strip** (25 LEDs for this project)
- **External Power Supply** (optional but recommended if using many LEDs)
- **220-470 Ohm Resistor** on the data line (recommended)
- **Capacitor** (1000µF, 6.3V+ across power supply, optional)
- **Arduino IDE or VSCode with Arduino extension**



## Wiring Guide

| NeoPixel | Connect to Arduino |
|----------|---------------------|
| **Data In** | Pin 2 (as defined in code) |
| **+5V**     | 5V pin (or external 5V supply) |
| **GND**     | GND pin (common ground) |



## How to Use

1. **Clone or download this project folder**.
2. Make sure the `.ino` file is inside a folder with the same name. Example:
3. Open `arc_reactor.ino` in the Arduino IDE or VSCode with the Arduino extension.
4. Select your board type and serial port.
5. Click Upload to flash the code onto your Arduino.
6. Your arc reactor animation should begin!



## Features

- **Startup Animation**: Each LED lights up sequentially with a soft blue-white glow.
- **Seamless Transition**: Startup ends at the exact same brightness and color as the start of the pulse.
- **Slow Breathing Pulse**: A layered fade between cyan → blue → white, using smooth sine wave interpolation.
- **Optimized for Rings**: Designed to work beautifully on circular NeoPixel ring with 25 LEDS.



## Customization

- Change the `NUMPIXELS` value to match your NeoPixel ring or strip.
- Modify `pulseSpeed` and `delay()` to control the speed and rhythm of the pulse.
- For more effects (like sound reactivity or center-out pulses), feel free to extend the animation logic.



## Inspiration

This project was inspired by the arc reactor from Iron Man, designed to look like a **high-tech energy core** pulsing with life.


