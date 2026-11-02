# Arduino State-Latch Toggle Controller

A foundational embedded systems project built using an ELEGOO UNO R3 to explore digital input/output handling, tactile switch debouncing, and custom C++ state-latch logic.

##  Overview
This project reads digital input from a physical push button and toggles an active LED output with each press. Instead of relying on simple momentary high/low states, the firmware manages state transitions cleanly in C++ to ensure reliable switching.

---

## Hardware & Circuitry
* **Microcontroller:** ELEGOO UNO R3 (ATmega328P)
* **Components:** 
  * Tactile push-button switch
  * LED (with proper orientation/polarity)
  * 220-ohm current-limiting series resistor
* **Circuit Configuration:** Breadboard layout wired with digital input pull configuration and proper active-low/high signal routing.

<img width="438" height="286" alt="image" src="https://github.com/user-attachments/assets/9e3b9dbf-f160-4904-b32c-c00b328c46bd" />


---

## Firmware & Logic (C++)
The core logic tracks button state changes and flips an internal boolean state flag only upon a complete press-and-release transition. 

```cpp
#define ButtonA 2
#define redLED 4
#define ON 0
#define OFF 1
void setup()
{
  Serial.begin(9600);
  pinMode(ButtonA, INPUT_PULLUP);
  pinMode(redLED, OUTPUT);
  digitalWrite(redLED, LOW);
}

int LED_ON = OFF;

void loop()
{
  int ButtonA_INPUT = digitalRead(ButtonA);
  //Serial.println(ButtonA_INPUT);

  if ((ButtonA_INPUT == ON) && (LED_ON == OFF)) // Checks if you have pressed the button
  {
    while (ButtonA_INPUT == ON) // Waits for your finger to lift off the button to proceed
    {
      delay(1);
      ButtonA_INPUT = digitalRead(ButtonA);
    }
    while (ButtonA_INPUT == OFF) // While the button isn't being pressed, it will keep the LED ON.
    {
      delay(10);
      digitalWrite(redLED, HIGH);
      LED_ON = ON;
      ButtonA_INPUT = digitalRead(ButtonA);
    }
  }
  if ((ButtonA_INPUT == ON) && (LED_ON == ON))
  {
    while (ButtonA_INPUT == ON) // Waits for your finger to lift off the button to proceed
    {
      delay(1);
      ButtonA_INPUT = digitalRead(ButtonA);
    }
    while (ButtonA_INPUT == OFF) // While the button isn't being pressed, it will keep the LED OFF.
    {
      delay(10);
      digitalWrite(redLED, LOW);
      LED_ON = OFF;
      ButtonA_INPUT = digitalRead(ButtonA);
    }
  }
}
