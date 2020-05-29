/*
void Detect_Reciver(){
  
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  
  
  
  return;
}



void translateIR() // takes action based on IR code received

// describing Remote IR codes 

{

  switch(results.value)

  {
  case 0xFFA25D: Serial.println(F("POWER")); break;
  case 0xFFE21D: Serial.println(F("FUNC/STOP")); break;
  case 0xFF629D: Serial.println(F("VOL+")); break;
  case 0xFF22DD: Serial.println(F("FAST BACK"));    break;
  case 0xFF02FD: Serial.println(F("PAUSE"));    break;
  case 0xFFC23D: Serial.println(F("FAST FORWARD"));   break;
  case 0xFFE01F: Serial.println(F("DOWN"));    break;
  case 0xFFA857: Serial.println(F("VOL-"));    break;
  case 0xFF906F: Serial.println(F("UP"));    break;
  case 0xFF9867: Serial.println(F("EQ"));    break;
  case 0xFFB04F: Serial.println(F("ST/REPT"));    break;
  case 0xFF6897: Serial.println(F("0"));    break;
  case 0xFF30CF: Serial.println(F("1"));    break;
  case 0xFF18E7: Serial.println(F("2"));    break;
  case 0xFF7A85: Serial.println(F("3"));    break;
  case 0xFF10EF: Serial.println(F("4"));    break;
  case 0xFF38C7: Serial.println(F("5"));    break;
  case 0xFF5AA5: Serial.println(F("6"));    break;
  case 0xFF42BD: Serial.println(F("7"));    break;
  case 0xFF4AB5: Serial.println(F("8"));    break;
  case 0xFF52AD: Serial.println(F("9"));    break;
  case 0xFFFFFFFF: Serial.println(F(" REPEAT"));break;  

  default: 
    Serial.println(F(" other button   "));

  }// End Case

} //END translateIR
*/
