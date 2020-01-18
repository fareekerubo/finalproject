void LCDInit() {
  lcd.init();                      // initialize the lcd
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("farida kerubo");
  lcd.setCursor(-1, 1);
  lcd.print("System Booting!");
  //lcd.setCursor(-3, 2);
  //lcd.print("Please wait...");
}
void LCD_default(){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("rfid system");
  lcd.setCursor(1, 1);
  lcd.print("Place item :");
  lcd.clear();
}
void LCDsendingdata(){
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("");
  
}
