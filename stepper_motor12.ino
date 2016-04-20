int clck = 11;
int cntl = 12;
int relay = 13;
int button = 6;
int button2 = 7;
int led = 4;
boolean buttonState = LOW;
void setup() {

  pinMode(clck, OUTPUT);
  pinMode(cntl, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  pinMode(button2, INPUT);

}

void loop()
{
  if (debounceButton(buttonState) == HIGH && buttonState == LOW)
  {
    digitalWrite(led, HIGH);
    for ( int i = 0; i <= 35; i++)
    {

      for (int i = 0; i <= 23; i++)
      {
        digitalWrite (clck, HIGH);
        delay(15);
        digitalWrite(clck, LOW);
        delay(15);

      }
      digitalWrite(relay, HIGH);
      delay(20);
      digitalWrite(relay, LOW);
      delay(20);
      break;
    }
    delay(2000);

   digitalWrite(led, LOW);
  }
}
boolean debounceButton(boolean state)
{
  boolean stateNow = digitalRead(button);
  if (state != stateNow)
  {
    delay (10);
    stateNow = digitalRead(button);
  }
  return stateNow;

}

void NextRotation()
{
  if (debounceButton1(buttonState) == HIGH && buttonState == LOW)
  {

    for ( int i = 0; i <= 35; i++)
    {

      for (int i = 0; i <= 23; i++)
      {
        digitalWrite (clck, HIGH);
        delay(15);
        digitalWrite(clck, LOW);
        delay(15);

      }
      digitalWrite(relay, HIGH);
      delay(20);
      digitalWrite(relay, LOW);
      delay(20);
      break;
    }
    delay(1000);
  }
}
boolean debounceButton1(boolean state)
{

  boolean statenow = digitalRead(button2);
  if (state != statenow)
  {
    delay (10);
    statenow = digitalRead(button2);
  }
  return statenow;
}

