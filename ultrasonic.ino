/*
 * This code was adapted from:
 * 
 * https://www.arduino.cc/en/Tutorial/Ping
 * 
 * created 3 Nov 2008
 * by David A. Mellis
 * modified 30 Aug 2011
 * by Tom Igoe
 *
 */

long getDuration() {
  

  digitalWrite(ultrasoundVcc, HIGH);
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration;
  
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
 
  digitalWrite(ultrasoundTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasoundTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(ultrasoundTrig, LOW);

  // pulseIn Notes from Arduino.cc

  // "The timing of this function has been determined empirically and will
  //  probably show errors in shorter pulses. Works on pulses from 
  //  10 microseconds to 3 minutes in length. Please also note that if the
  //  pin is already high when the function is called, it will wait for the
  //  pin to go LOW and then HIGH before it starts counting. This routine
  //  can be used only if interrupts are activated. Furthermore the highest 
  //  resolution is obtained with short intervals. 
  
  
  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(ultrasoundEcho, HIGH);

  //Serial.print ( "Duration: ");
  //Serial.print ( duration );
  //Serial.print ( "\n" );

  return duration;

}

float microsecondsToInches(long microseconds)
{
// According to Parallax's datasheet for the PING))), there are
// 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
// second). This gives the distance travelled by the ping, outbound
// and return, so we divide by 2 to get the distance of the obstacle.
// See: http://www.parallax.com/dl/docs/prod/acc/28015-PI...

  //Serial.print ( "Inches: ");
  //Serial.println ( microseconds / 73.746 / 2 );  

return microseconds / 73.746 / 2;
}

float microsecondsToCentimeters(long microseconds)
{
// According to Parallax's datasheet for the PING))), there are
// 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
// second). This gives the distance travelled by the ping, outbound
// and return, so we divide by 2 to get the distance of the obstacle.
// See: http://www.parallax.com/dl/docs/prod/acc/28015-PI...

  //Serial.print ( "Centimeters: ");
  //Serial.print ( microseconds / 29 / 2 );
  //Serial.print ( "\n" );

return microseconds / 29 / 2;
}

float getDistanceInches(){
  return microsecondsToInches( getDuration() );
}

float getDistanceCentimeters(){
  return microsecondsToCentimeters( getDuration() );

}

