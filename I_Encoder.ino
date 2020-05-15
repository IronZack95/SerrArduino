// Interrupt routine runs if CLK goes from HIGH to LOW
void isr ()  {
    delay(4);  // delay for Debouncing
    if (digitalRead(PinCLK))
      rotationdirection= digitalRead(PinDT);
    else
      rotationdirection= !digitalRead(PinDT);
    TurnDetected = true;

    Serial.println("Interrupt");
  }

void Detect(){
   // Runs if rotation was detected
    if (TurnDetected)  {
      PrevPosition = RotaryPosition; // Save previous position in variable
      if (rotationdirection) {
        RotaryPosition=RotaryPosition-1;} // decrase Position by 1
      else {
        RotaryPosition=RotaryPosition+1;} // increase Position by 1
      
      
      Serial.println("");
      Serial.print("RotaryPosition: "); Serial.println(RotaryPosition);
      Serial.println("");

      
      TurnDetected = false;  // do NOT repeat IF loop until new rotation detected
    }
  }
