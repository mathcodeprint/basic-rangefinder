void beep(unsigned char delayms){

  analogWrite(speakerPin, 40);// 
  delay(delayms);             // Duration of Tone
  analogWrite(speakerPin, 0); // 0 turns it off  
  delay(delayms);             // wait for a delayms ms   

}  


