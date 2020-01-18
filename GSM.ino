void readHTTPRequest()
{
 SIM800.println("AT+CSQ"); // Signal quality check
 delay(100);
 ShowSerialData(); // this code is to show the data from gprs shield, in order to easily see the process of how the gprs shield submit a http request, and the following is for this purpose too.
 
 SIM800.println("AT+CGATT?"); //Attach or Detach from GPRS Support
 delay(100);
  ShowSerialData();
  
  SIM800.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");//setting the SAPBR, the connection type is using gprs
  delay(1000);
  ShowSerialData();
 
  SIM800.println("AT+SAPBR=3,1,\"APN\",\"safaricom\"");//setting the APN, Access point name string
  delay(4000);
  ShowSerialData();
  
  SIM800.println("AT+SAPBR=3,1,\"USER\",\"saf\"");
  delay(1000);
  ShowSerialData();
   
  SIM800.println("AT+SAPBR=3,1,\"PWD\",\"data\"");
  delay(1000);
  ShowSerialData();
  
  SIM800.println("AT+SAPBR=1,1");//To open a GPRS context
  delay(1000);
  ShowSerialData();

  

 
  SIM800.println("AT+HTTPINIT"); //init the HTTP request
  delay(2000); 
  ShowSerialData();

  SIM800.println("AT+HTTPPARA = \"CID\",1");
  delay(1000);
  String str(card_buffer);
   String command="AT+HTTPPARA=\"URL\",\"http://lib.co.ke/rfid/api/add-buffer-record/" + str + "/ITEM\"";
   SIM800.println(command);// setting the httppara, the second parameter is the website you want to access
    ShowSerialData();
   delay(1000);
   
   SIM800.println("AT+HTTPACTION=0");//Get session starts
   ShowSerialData();
   delay(5000);
  
  SIM800.println("AT+HTTPREAD");//Read the data of HTTP server
  ShowSerialData();
  delay(1000);
  
  SIM800.println("AT+HTTPTERM");//Terminate HTTP service
  ShowSerialData();
  delay(1000);

  SIM800.println("AT+SAPBR=0,1");
  delay(1000);
  ShowSerialData();
 }


void ShowSerialData()
{
  while(SIM800.available()!=0)
    Serial.write(char (SIM800.read()));
}
