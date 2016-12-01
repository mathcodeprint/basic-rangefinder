void updateRange() {
  
  if ( showrange == true ) {
       
       int inches = getDistanceInches();
  
       lcd.setCursor(9,0);         // These two lines clear the previous measurement
       lcd.print ("       ");      // otherwise the previous will blend with new.
       lcd.setCursor(0,0);         // Only clear what needs to be to help reduce 
       lcd.print ("Distance: " );  // The amount of display flicker.
       lcd.setCursor(10,0); 
       lcd.print ( inches );       
       lcd.setCursor(12,0);
       lcd.print ( " In. " );       // It is important to have a a string that "covers"
                                    // anything previously displayed
       Serial.print( inches);       
       Serial.print("\t In. \n");

     }
}

void rangingOn() {
  showrange = true;

}

void rangingOff(){
  showrange = false;
  
}

