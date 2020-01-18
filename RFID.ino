void RFIDInit() {
  //Creates an Instance of RFID Object called rfid and initializes it
  pinMode(RFID_SS, OUTPUT);
  digitalWrite(RFID_SS, LOW);
  rfid.PCD_Init();
  rfid.PCD_SetAntennaGain(rfid.RxGain_max);
}
void CommsInit() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  SPI.begin();
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}
void ReadUID() {
  RFIDInit();
 
  // Getting ready for Reading Tags/Cards
  if ( !rfid.PICC_IsNewCardPresent()) {
    return 0; //If a new Access Card is placed to RFID reader continue
  }
  if ( !rfid.PICC_ReadCardSerial()) {
    return 0; //Since a Tag is placed, get Serial and continue
  }
  // Assuming Tags have 4 byte UID, others may have 7 (Reminder)
  Serial.print(F("Scanned Access Tag Unique ID: "));
  for (int i = 0; i < 4; i++) {
    readCard[i] = rfid.uid.uidByte[i];
    // Operation on lower byte to enable ID in a nibble rather than a byte
    byte lowerByte = (readCard[i] & 0x0F);
    int lowerInt = (int) lowerByte; //converting byte into int
    char lowerChar[1];
    itoa(lowerInt, lowerChar, 16);
    byte upperByte = (readCard[i] >> 4);
    int upperInt = (int) upperByte;
    // Operation on upper byte to enable ID in a nibble rather than a byte
    char upperChar[1];
    itoa(upperInt, upperChar, 16);
    int j = i * 2;
    int k = j + 1;
    // Storing UID in char array (card_buffer)
    card_buffer[k] = lowerChar[0];
    card_buffer[j] = upperChar[0];
  }
    Serial.print("card buffer");
    Serial.println(card_buffer);
  rfid.PICC_HaltA(); // Stop reading
  return 1;
}
