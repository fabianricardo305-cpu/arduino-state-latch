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
