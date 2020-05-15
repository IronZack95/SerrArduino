void Serial_Out(byte t, byte u, int v, int l , int p){

        // Print to Serial

        //System Time
        Serial.print("Raw data: ");
        Serial.print(dt.year);   Serial.print("-");
        Serial.print(dt.month);  Serial.print("-");
        Serial.print(dt.day);    Serial.print(" ");
        Serial.print(dt.hour);   Serial.print(":");
        Serial.print(dt.minute); Serial.print(":");
        Serial.print(dt.second); Serial.println("");
        
        Serial.println("Sample OK: ");
        
        Serial.print("Temperatura: "); Serial.print((int)t); Serial.println(" *C, ");
        Serial.print("Velocità Motore: "); Serial.print((int)v); Serial.println(" %, "); 
        
        Serial.print("Luce: "); Serial.print((int)l); Serial.println(" %, ");
        Serial.print("Servo: "); Serial.print((int)p); Serial.println(" gradi, ");

        Serial.print("Umidità: "); Serial.print((int)u); Serial.println(" %");

  }

  
void LCD_Out(byte t, byte u, int v, int l){
  
        // Print a message to the LCD.       
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Temp:");   lcd.print((int)t);
        lcd.setCursor(8, 0);
        lcd.print("Umid:");   lcd.print((int)u); //lcd.print("%");
        lcd.setCursor(0, 1);
        lcd.print("Luce:");   lcd.print((int)l); //lcd.print("%");
        lcd.setCursor(8, 1);
        lcd.print("Velo:"); lcd.print((int)v); //lcd.print("%");
        
        return;
}

void LCD_Menu();
