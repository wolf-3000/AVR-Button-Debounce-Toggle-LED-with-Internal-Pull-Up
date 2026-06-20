# AVR-Button-Debounce-LED-Toggle

## Overview

This bare-metal AVR sketch toggles an LED with a pushbutton using **software debounce** and **millis()** timing. The internal pull-up on the input pin means no external resistor is needed.

- Press the button to toggle the LED on/off
- **50 ms debounce** via `millis()` — samples the button at fixed intervals to ignore contact bounce
- **Falling-edge detection** — only toggles on press-down, not on hold or release

## Hardware

| Component | Notes |
|-----------|-------|
| Arduino Nano / Uno | ATmega328P @ 16 MHz |
| LED | Any standard LED |
| 220 Ω resistor | Current limiter for LED |
| Pushbutton | Tactile or any momentary switch |

## Pinout / Wiring

| Arduino Pin | Connected To | Purpose |
|-------------|--------------|---------|
| 3 (PD3) | Button → GND | Input with internal pull-up |
| 4 (PD4) | LED anode → 220 Ω → GND | Output to LED |

> No external resistor on the button — `PORTD |= (1 << PD3)` enables the internal pull-up, keeping `PD3` HIGH when open and LOW when pressed.

## Build Photos

<img width="1280" height="1280" alt="picture_" src="https://github.com/user-attachments/assets/82b5c185-03e6-4b97-925d-5c6b8b3a35c0" />


## How It Works

- `DDRD &= ~(1 << PD3)` sets `PD3` as an **input**; `PORTD |= (1 << PD3)` enables the **internal pull-up**.
- The loop reads `millis()` and only samples the button every **50 ms** (`debounceInterval`), filtering out mechanical bounce.
- `PIND & (1 << PD3)` reads the current pin state; `prevReading && !currentReading` detects the **falling edge** (button press).
- On falling edge, `ledState` is flipped and written to `PD4`.
- Holding the button does not re-toggle — the next press must begin from a released state.
