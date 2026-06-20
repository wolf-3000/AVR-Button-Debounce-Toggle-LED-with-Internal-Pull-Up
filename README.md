# AVR Button Debounce — Toggle LED with Internal Pull-Up

A minimal bare-metal AVR example that toggles an LED with a **pushbutton** using **software debounce** and **millis()** timing. No external resistor needed — the internal pull-up on the input pin is used.

> Target: ATmega328P (Arduino Uno/Nano) @ 16 MHz

---

## What it does

- Press the button connected to **PD3** (Arduino digital pin **3**) to toggle the LED on **PD4** (pin **4**).
- **50 ms software debounce** prevents flickering from mechanical contact bounce.
- Detects the **falling edge** (press-down), so holding the button does not toggle repeatedly.

---

## Wiring

No external resistor needed — the code enables the **internal pull-up** on PD3.

```
PD3 (pin 3) ──────┬─── Button ───┬─── GND
                   │              │
PD4 (pin 4) ───[220 Ω]───►|─── GND
```

- One side of the button to **PD3**, the other side to **GND**.
- LED anode (long leg) to **PD4** via 220 Ω, cathode to **GND**.

---
## Picture
<img width="1280" height="1280" alt="picture_" src="https://github.com/user-attachments/assets/5653b0a9-8076-40fb-a14b-a8d844d5617a" />


---

## How it works (brief)

| Part | What it does |
|------|-------------|
| Internal pull-up (`PORTD |= (1 << PD3)`) | Keeps PD3 **HIGH** when button is open; goes **LOW** when pressed |
| `millis()` debounce | Only samples the button every **50 ms** to ignore contact bounce |
| Falling edge check (`prevReading && !currentReading`) | Toggles LED only on **press-down**, not on release or hold |

---



## License

MIT
