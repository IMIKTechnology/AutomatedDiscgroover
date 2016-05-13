int clck = 11;
int cntl = 12;
int relay = 4;
int button = 5;  
int button2 = 6   ;
int relay2 = 8;

boolean buttonState = LOW;
void setup() {

  pinMode(clck, OUTPUT);
  pinMode(cntl, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(button, INPUT);
  pinMode(button2, INPUT);

}

void loop()
{
  NextRotation();
  if (debounceButton(buttonState) == HIGH && buttonState == LOW) // if we press the button means if it high following the next steps//
  {
    digitalWrite(relay2, HIGH);   // this for single phase motor turnning on//
    for ( int i = 0; i <= 35; i++) // this for 36 steps to complete the one cycle//
    {

      for (int i = 0; i <= 117; i++) // this for given pulse to the stepper motor. 24 pulses for 10 degree//
      {
        digitalWrite (clck, HIGH);
        delay(15);
        digitalWrite(clck, LOW);
        delay(15);

      }
      digitalWrite(relay, HIGH); // this code for energising pressure valve//
      delay(20);
      digitalWrite(relay, LOW);
      delay(20);
     delay(1500);
    }
     // after completing 10degree it takes this delay//

   digitalWrite(relay2, LOW);
  }

  
}
boolean debounceButton(boolean buttonState)  // debounce button code // // state is we give low in the starting //
{
  boolean stateNow = digitalRead(button);     // read the state of the button pressing //
  if (buttonState!= stateNow) // if it high means it is set in the buttonState//
  {
    delay (10); // waiting for 10 second for debouncing//
    stateNow = digitalRead(button); // again it check the value of button state//
  }
  return stateNow; 

}

void NextRotation() // this program for switch 2//
{
  if (debounceButton1(buttonState) == HIGH && buttonState == LOW) 
  {
     digitalWrite(relay2, HIGH); 
     for (int i=0; i<=56; i++)
     
  {
    digitalWrite (clck, HIGH);
    delay(10);
    digitalWrite(clck,LOW);
    delay(10);
  }
    
    for ( int i = 0; i <= 35; i++)
    {

      for (int i = 0; i <= 117; i++)
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
          delay(1500);
    
  }
    digitalWrite(relay2, LOW);
  }

}
boolean debounceButton1(boolean buttonState)
{

  boolean statenow = digitalRead(button2);
  if (buttonState != statenow)
  {
    delay (10);
    statenow = digitalRead(button2);
  }
  return statenow;
}

