bool ledState = false;
bool prevReading = true;
uint32_t lastDebounceTime = 0;
const uint8_t debounceInterval = 50;

void setup() {

  DDRD &= ~(1 << PD3);
  DDRD |= (1 << PD4);
  PORTD |= (1 << PD3);
}

void loop() {
  uint32_t now = millis();

  if (now - lastDebounceTime >= debounceInterval){
    lastDebounceTime = now;
    
    bool currentReading = PIND & (1 << PD3);

    if (prevReading && !currentReading){
      ledState = !ledState;
    }
    prevReading = currentReading;
    if (ledState) PORTD |= (1 << PD4);
    else PORTD &= ~(1 << PD4);
  }
}
