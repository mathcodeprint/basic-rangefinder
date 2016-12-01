/*
 * This code was adapted from :
 * 
 * lcd_nav.ino - Example code using the menu system library
 *
 * This example shows using the menu system with a 16x2 LCD display
 * (controled over serial).
 *
 * Copyright (c) 2015 arduino-menusystem
 * Licensed under the MIT license (see LICENSE)
 */


// Menu variables
MenuSystem ms;
Menu mm("Rangefinder");
MenuItem mm_mi1("Start");
MenuItem mm_mi2("Stop");

String currentMenuSelection = "";

// Menu callback function
// In this example all menu items use the same callback.
void on_start_selected(MenuItem* p_menu_item)
{
  lcd.setCursor(0,1);
  lcd.print(">Start<   Stop ");                // The menu name and what is displayed
  //Serial.println (p_menu_item->get_name());  // should be abstracted for easier menu customization

  rangingOn();                                 // Even though this is not a direct function of menuing
                                               // it is called here for simplicity.
}

void on_stop_selected(MenuItem* p_menu_item)
{
  lcd.setCursor(0,1);
  lcd.print(" Start   >Stop<");
  //Serial.println (p_menu_item->get_name());
  
  rangingOff();
}

void initMenu()
{
  mm.add_item(&mm_mi1, &on_start_selected);  // Add the first item to the Main Menu
  mm.add_item(&mm_mi2, &on_stop_selected);   // Add the seconf item to the Main Menu
  ms.set_root_menu(&mm);                     // Set the main menu as the top level ( root )
  displayMenu();
}

void displayMenu() {
  lcd.clear();
    // Display the menu
  Menu const* cp_menu = ms.get_current_menu();  
  
  lcd.setCursor(0,0);             // Set the LCD to Cursor to 1st Line at 1st Column.
  lcd.print(cp_menu->get_name()); // Print the current Menu at the cursor.
  
  lcd.setCursor(0,1);             //Set the LCD Cursor to 2nd Line at 1st Column. 

  currentMenuSelection = cp_menu->get_selected()->get_name();
  if ( currentMenuSelection == "Start") 
  lcd.print(">Start<   Stop ");  // Print the selected menu item at the cursor

  if ( currentMenuSelection == "Stop") 
  lcd.print(" Start   >Stop<");
  
}

void buttonHandler() {

  if(buttonsState) {
    switch (buttonsState) {
     case 'l': // Previuos item
      ms.prev();
      displayMenu();
      buttonsState = '\0';   // After processing the button press clear the state, otherwise it is 
      break;                 // as if the button is held down.
    case 'r': // Next item
      ms.next();
      displayMenu();
      buttonsState = '\0';
      break;
    case 'd': // Select pressed
      ms.select();
      displayMenu();
      buttonsState = '\0';
      break;
    default:
      break;
      buttonsState = '\0';
      break;
    }
  }
}
