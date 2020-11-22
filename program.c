#include <SoftwareSerial.h>
SoftwareSerial mySerial(11,10);
#include <LiquidCrystal.h>
//SoftwareSerial Sim800l(10,11);
int m=0;int t=0;int a=0;int count;
const int rs = 12, en = 13, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int i=0; char txt[16]="----------------"; char notice[16]="----------------";
int r=0;
boolean process=true;
char msg;
String s="";
//char txt;
void setup()
{
   count=0;
  r=0;
lcd.begin(16,2);
lcd.setCursor(0,0);
  Serial.begin(9600);
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  delay(1000);
   // lcd.scrollDisplayLeft();
   //lcd.clear();
 //  mySerial.print("AT\r");
   //mySerial.print("ATE0\r");
//gsm_init();
  //mySerial.print("AT+CMGF=1r"); // set SMS mode to text
  mySerial.print("AT+CMGF=1\r");  // set SMS mode to text

  delay(100);
  //mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  //mySerial.print("AT+CNMI=2,2,0,0,0r");

  mySerial.print("AT+CNMI=2,2,0,0,0\r"); // AT Command to receive a live SMS
  delay(100);
  //Serial.println("Ready");
    lcd.print("GSM Initilizing...");
  delay(1000);
  gsm_init();
  lcd.setCursor(0,0);
  lcd.print("Wireless Notice");
  lcd.setCursor(0,1);
  lcd.print("    Board      ");
  delay(2000);
  lcd.clear();
  lcd.print("Circuit Digest");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("System Ready");
  delay(500);
  delay(1000);
  
}

void loop() 
{
  


  while(mySerial.available()>0)
  {
     


    msg=mySerial.read();
    Serial.print(msg);
       if(msg=='#'){
      i=i+1;
      m=m+1;
      }
      if(m==1){
        if(msg=='#'){
          count=1;
          lcd.clear();
          }else{
      lcd.print(msg);
        t=t+1;
        if(t==16){
          lcd.setCursor(0,1);
          }
        }
        }
        if(m==2){
          m=0;
          t=0;
          r=1;
}
    

    }


 }
void gsm_init()
{
  lcd.clear();
  lcd.print("Finding Module..");
  delay(1000);
  

  lcd.clear();
  lcd.print("Module Connected..");
  delay(1000);
  lcd.clear();
  lcd.print("Disabling ECHO");
    delay(2000);

  boolean echo_flag=1;
      Serial.print("ATE0\n");



  lcd.clear();
  lcd.print("Echo OFF");
  delay(2000);
  lcd.clear();
  lcd.print("Finding Network..");
    delay(2000);

  boolean net_flag=1;
     
  lcd.clear();
  lcd.print("Network Found..");
  delay(2000);
  lcd.clear();
}
