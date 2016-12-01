

#include <LiquidCrystal_I2C.h>
#include <MenuSystem.h>
#include <Button.h>
#include <Timer.h>

// Globals and Constants

  const int speakerPin =  3;     // Speaker
  const int buttonPin1 = 4;      // Buttons   ( Re-assign to X for prototype only ).
  const int buttonPin2 = 5;
  const int buttonPin3 = 6;
  const int buttonPin4 = 7;
  const int buttonPin5 = 8;
  const int ultrasoundVcc = 9;   // Ultrasonic Sensor, 5V 
  const int ultrasoundEcho = 10; 
  const int ultrasoundTrig = 11; 
  const int ultrasoundGnd = 12;  // Used as GND

  LiquidCrystal_I2C lcd(0x27,16,2);  // Instantiate LCD Objectm, set the LCD address to 0x20
                                     // for a 16 chars and 2 line display 

  Timer t1;

  // States

  char buttonsState;
  //boolean buttonSet = false;
  boolean showrange = false;


void setup() {

  pinMode(speakerPin, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(ultrasoundVcc,OUTPUT);  
  pinMode(ultrasoundTrig, OUTPUT);
  pinMode(ultrasoundEcho,INPUT);
  //pinMode(ultrasoundGnd,INPUT);  
  
  t1.every(1000, updateRange);
  
  initButtons();
  
  lcd.init();
  lcd.backlight(); 
  lcd.clear();

  lcd.setCursor(0, 0);

  initMenu();
  
  Serial.begin(9600);

  //Startup Beeps
  beep(50);
  beep(50);
  beep(50);
}

void loop() {

  //
  // Code in the loop acts as a director for all the
  // functionality of the device.
  //
  
  pollButtons();
  buttonHandler();    

  t1.update();

}



