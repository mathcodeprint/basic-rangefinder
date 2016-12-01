

Button button1(buttonPin1); // Connect the Select Button to Pin 4 and GND
Button button2(buttonPin2); // Connect the Up Button to Pin 5 and GND
Button button3(buttonPin3); // Connect the Down Button to Pin 6 and GND
Button button4(buttonPin4); // Connect the Left Button to Pin 7 and GND
Button button5(buttonPin5); // Connect the Right Button to Pin 8 and GND

void initButtons() {
  button1.begin();
  button2.begin();
  button3.begin();
  button4.begin();
  button5.begin();
}

void pollButtons() {

  // The initial release of code only uses three of the five buttons.

  // RIGHT
  if (button3.pressed()) {
    buttonsState = 'r';
    Serial.println("Right/Next"); 
    beep(40);   
  }

  // SELECT
  if (button4.pressed()) {
    buttonsState = 'd';
    Serial.println("Select");
    beep(40);
  }

  // LEFT
  if (button5.pressed()) {
    buttonsState = 'l';
    Serial.println("Left/Previous");
    beep(40);

  }  
}

