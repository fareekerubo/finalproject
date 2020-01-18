#include <SoftwareSerial.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <MFRC522.h>
#include <SPI.h>
#define Password_Lenght 7

SoftwareSerial SIM800(7,6); // RX, TX


char Data[Password_Lenght]; // 6 is the number of chars it can hold + the null char = 7
char Master[Password_Lenght] = "345678"; 
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;

#define RFID_SS 10
#define RFID_RST 9
int x;

byte readCard[7];
char card_buffer[10];
void CommsInit();
void LCDInit();
void RFIDInit();
void  LCD_default();
int y;

LiquidCrystal_I2C lcd(0x3F, 16, 2);
MFRC522 rfid(RFID_SS, RFID_RST);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {A0, A1, A2, A3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//Create an object of keypad
//Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
Keypad customKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup(){
  CommsInit();
  RFIDInit();
  LCDInit();
  SIM800.begin(9600);
    Serial.begin(9600);
    
}

void loop() {
  //char key = keypad.getKey();// Read the key
  customKey = customKeypad.getKey();
  if (customKey=='1'){
    y=1;
      }
  if (customKey == '2'){
    y=2;
  }
  if (y == 1){
    LCD_default();
    //Serial.println("reading");
    delay(2000);
    ReadUID();
    Serial.println(card_buffer);
    readHTTPRequest();
    
//    readHTTPRequest();
     if (customKey == '2'){
    y=2;
  }
    
    
    //Serial.println("exiting");
 }
  if (y ==2){
    Serial.println("pass");
     createpassword();
     //readHTTPRequest()
     Serial.println("done");
      if (customKey=='1'){
    y=1;
      }
  }
  
  //y = 0;
  }
  
  
  
