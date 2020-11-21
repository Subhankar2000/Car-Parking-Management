#include <LiquidCrystal.h>    
#include<SPI.h>               
#include<MFRC522.h>
#include<Wire.h>           
#define RSTPIN 9              
#define SSPIN 10              

MFRC522 rc(SSPIN, RSTPIN);           
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
int readsuccess;
byte defcard[][5]={{0x15,0x28,0x81,0xCE},{0x75,0x7C,0x55,0xCE},{0x75,0x5D,0x5A,0xCE},{0x55,0xBD,0x7B,0xCE},{0x55,0xF4,0x0D,0xCF}} ;
byte readcard[4];
int N=5;

char stateM[6] ;
char flag1 = '0' ;
char flag2 = '0' ;
char flag3 = '0' ;
char flag4 = '0' ;
char flag5 = '0' ;

void setup() {  
  Serial.begin(9600);
  Wire.begin();
  SPI.begin();
  rc.PCD_Init();
  rc.PCD_DumpVersionToSerial();
  
  lcd.begin(16, 2);

}



void loop() {
    
  lcd.print("Wave Card");
  lcd.setCursor(0,1) ;
  lcd.print("To Continue ....");
  int i=0 ; 
  readsuccess = getid();

  if(readsuccess){
    int match=0;
    for(int j=0;j<N;j++)
    {
     
        if(defcard[j][1] == readcard[1] )
       { match++ ; 
        i = j+1 ;
        break ; }
        
     
    } 
    if(match){
      
    if ( i  == 1 ){
      id = '1' ;
    
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("1. 1 Hrs   2. 3 Hrs");
      lcd.setCursor(0, 1);
      lcd.print("3. 5 Hrs   4. 10 Hrs");
      i = 0 ;
    
	Wire.beginTransmission(8) ;
      Wire.write(id) ;   
    Wire.endTransmission() ;

    delay(20000) ;
	
    setup() ;
  }   
}
  }
}
    
/*---- RFID PART , PROCESSING AND SENDING STATE VALUES -----*/
/*--------- END OF LOOP -----------*/
/*--------- FUNCTION TO SCAN RFID CARDS ----------*/
}
int getid(){  
  if(!rc.PICC_IsNewCardPresent()){
    return 0;
  }
  if(!rc.PICC_ReadCardSerial()){
    return 0;
  }
 
  
  //Serial.println("THE UID OF THE SCANNED CARD IS:");
  
  for(int i=0;i<4;i++){
    readcard[i]=rc.uid.uidByte[i]; 
    //Serial.print(readcard[i],HEX); 
  }
   //Serial.println("");
   //Serial.println("Now Comparing with stored cards");
   rc.PICC_HaltA();
  
  return 1;
}

