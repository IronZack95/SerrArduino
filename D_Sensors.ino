
//------------------------------------- FUNZIONI -----------------------------------

void Lettura_Sensori(){
      // Read photocell
      light  = analogRead(LIGHTPIN);
      light_percentuale = (int)abs(light-MAXLIGHT)*(100./MAXLIGHT);
      return;
  }
