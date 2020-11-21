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

  pinMode( A0 , INPUT ) ;
  pinMode( A1 , INPUT ) ; 
  pinMode( A2 , INPUT ) ;
  pinMode( A3 , INPUT ) ;


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
      //Serial.println("CARD AUTHORISED");
    if ( i  == 1 ){
      stateM[0] = '1' ;
    if( digitalRead(A0) == HIGH )
      flag1 = '1' ;
    else if ( digitalRead(A0) == LOW )
      flag1 = '0' ;
      
      stateM[1] = flag1 ;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("S.Karmakar");
      lcd.setCursor(0, 1);
      lcd.print("ID : ");
      for(int j=0;j<4;j++)
      lcd.print(defcard[0][j],HEX);
      i = 0 ;
    
    if( digitalRead(A0) == HIGH )
      stateM[2] = '1' ;
    else if( digitalRead(A0) == LOW )
      stateM[2] = '0' ;
  
    if( digitalRead(A1) == HIGH )
      stateM[3] = '1' ;
    else if( digitalRead(A1) == LOW )
      stateM[3] = '0' ;
  
    if( digitalRead(A2) == HIGH )
      stateM[4] = '1' ;
    else if( digitalRead(A2) == LOW )
      stateM[4] = '0' ;
  
    if( digitalRead(A3) == HIGH )
      stateM[5] = '1' ;
    else if( digitalRead(A3) == LOW )
      stateM[5] = '0' ;
    
    
   Wire.beginTransmission(9) ;
    for(int w=0 ; w<6 ; w++){
      Wire.write(stateM[w]) ;
     
    }
    
    
    Wire.endTransmission() ;

    delay(15000) ;
    setup() ;
  }   
    
    else if ( i  == 2 ){
      stateM[0] = '2' ;
    
    if( flag2 == '0' ){
      if( digitalRead(A1) == HIGH && digitalRead(A2) == HIGH && digitalRead(A3) == HIGH){
      lcd.clear();
      lcd.print("Parking Full");
      lcd.setCursor(0,1) ;
      lcd.print("Come Back Later");
      delay(15000) ;
      setup() ;
	    }
      else{
	    stateM[1] = flag2 ;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("M.Deogharia");
      lcd.setCursor(0, 1);
      lcd.print("ID : ");
      for(int j=0;j<4;j++)
      lcd.print(defcard[1][j],HEX);
      
      i = 0 ;
      if( digitalRead(A0) == HIGH )
      stateM[2] = '1' ;
      else if( digitalRead(A0) == LOW )
      stateM[2] = '0' ;
  
      if( digitalRead(A1) == HIGH )
      stateM[3] = '1' ;
      else if( digitalRead(A1) == LOW )
      stateM[3] = '0' ;
  
      if( digitalRead(A2) == HIGH )
      stateM[4] = '1' ;
      else if( digitalRead(A2) == LOW )
      stateM[4] = '0' ;
  
      if( digitalRead(A3) == HIGH )
      stateM[5] = '1' ;
      else if( digitalRead(A3) == LOW )
      stateM[5] = '0' ;
    
      flag2 = '1' ;
      
     Wire.beginTransmission(9) ;
    for(int w=0 ; w<7 ; w++)
    Wire.write(stateM[w]);
      Wire.endTransmission() ;
      
      delay(15000) ;
      setup() ;
      }	
    }
    else if(flag2 == '1' ){
      stateM[0] = '2' ;
      stateM[1] = flag2 ;
      flag2 = '0' ;
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("M.Deogharia");
      lcd.setCursor(0, 1);
      lcd.print("ID : ");
      for(int j=0;j<4;j++)
      lcd.print(defcard[1][j],HEX);
      
      i = 0 ;
      Wire.beginTransmission(9) ;
      for(int w=0 ; w<7 ; w++)
    Wire.write(stateM[w]);
      Wire.endTransmission() ;
      delay(15000) ;
      setup() ;
    }
   }
    
    
    else if ( i  == 3 ){
      stateM[0] = '3' ;
    
    if( flag3 == '0' ){
      if(  digitalRead(A1) == HIGH && digitalRead(A2) == HIGH && digitalRead(A3) == HIGH){
      lcd.clear();
      lcd.print("Parking Space Full");
      lcd.setCursor(0,1) ;
      lcd.print("Come Back Later");
      delay(15000) ;
      setup() ;
	    }
	    else{
	    stateM[1] = flag3 ;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("D.Suman");
      lcd.setCursor(0, 1);
      lcd.print("ID : ");
      for(int j=0;j<4;j++)
      lcd.print(defcard[2][j],HEX);
      
      i = 0 ;
    
      if( digitalRead(A0) == HIGH )
      stateM[2] = '1' ;
      else if( digitalRead(A0) == LOW )
      stateM[2] = '0' ;
  
      if( digitalRead(A1) == HIGH )
      stateM[3] = '1' ;
      else if( digitalRead(A1) == LOW )
      stateM[3] = '0' ;
  
      if( digitalRead(A2) == HIGH )
      stateM[4] = '1' ;
      else if( digitalRead(A2) == LOW )
      stateM[4] = '0' ;
  
      if( digitalRead(A3) == HIGH )
      stateM[5] = '1' ;
      else if( digitalRead(A3) == LOW )
      stateM[5] = '0' ;
      
      flag3 = '1' ;
      Wire.beginTransmission(9) ;
      for(int w=0 ; w<7 ; w++)
      Wire.write(stateM[w]) ;
    
      Wire.endTransmission() ;
      delay(15000) ;
      setup() ;
    }
  }
    else if(flag3 == '1' ){
      stateM[0] = '3' ;
      stateM[1] = flag3 ;
      flag3 = '0' ;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("D.Suman");
      lcd.setCursor(0, 1);
      lcd.print("ID : ");
      for(int j=0;j<4;j++)
      lcd.print(defcard[2][j],HEX);
      
      i = 0 ;
      
      Wire.beginTransmission(9) ;
      for(int w=0 ; w<7 ; w++)
    Wire.write(stateM[w]);
    
      Wire.endTransmission() ;
      delay(15000) ;
      setup() ;
    }
	 }
    else if ( i  == 4 ){
      stateM[0] = '4' ;
    
    if( flag4 == '0' ){
      if(  digitalRead(A1) == HIGH && digitalRead(A2) == HIGH && digitalRead(A3) == HIGH){
      lcd.clear();
      lcd.print("Parking Space Full");
      lcd.setCursor(0,1) ;
      lcd.print("Come Back Later");
      delay(15000) ;
      setup() ;
	    }
    else{
	  stateM[1] = flag4 ;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("S.Srivastava");
    lcd.setCursor(0, 1);
    lcd.print("ID : ");
      for(int j=0;j<4;j++)
      lcd.print(defcard[3][j],HEX);
      
      i = 0 ;
    if( digitalRead(A0) == HIGH )
    stateM[2] = '1' ;
    else if( digitalRead(A0) == LOW )
    stateM[2] = '0' ;
  
    if( digitalRead(A1) == HIGH )
    stateM[3] = '1' ;
    else if( digitalRead(A1) == LOW )
    stateM[3] = '0' ;
  
    if( digitalRead(A2) == HIGH )
    stateM[4] = '1' ;
    else if( digitalRead(A2) == LOW )
    stateM[4] = '0' ;
  
    if( digitalRead(A3) == HIGH )
    stateM[5] = '1' ;
    else if( digitalRead(A3) == LOW )
    stateM[5] = '0' ;
      flag4 = '1' ;
    Wire.beginTransmission(9) ;
      for(int w=0 ; w<7 ; w++)
      Wire.write(stateM[w]) ;
    
      Wire.endTransmission() ;
      delay(15000) ;
      setup() ;
   }	
  }
    else if(flag4 == '1' ){
      stateM[0] = '4' ;
      stateM[1] = flag4 ;
      flag4 = '0' ;
      lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("S.Srivastava");
    lcd.setCursor(0, 1);
    lcd.print("ID : ");
      for(int j=0;j<4;j++)
      lcd.print(defcard[3][j],HEX);
      
      i = 0 ;
      Wire.beginTransmission(9) ;
      for(int w=0 ; w<7 ; w++)
    Wire.write(stateM[w]);
      Wire.endTransmission() ;
      delay(15000) ;
      setup() ;
    }  
		 }
    else if ( i  == 5 ){
      stateM[0] = '5' ;
    
    if( flag5 == '0' ){
      if(  digitalRead(A1) == HIGH && digitalRead(A2) == HIGH && digitalRead(A3) == HIGH){
      lcd.clear();
      lcd.print("Parking Space Full");
      lcd.setCursor(0,1) ;
      lcd.print("Come Back Later");
      delay(15000) ;
      setup() ;
      }
    else{
    stateM[1] = flag5 ;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("S.P.Kabi");
    lcd.setCursor(0, 1);
    lcd.print("ID : ");
      for(int j=0;j<2;j++)
      lcd.print(defcard[4][j],HEX);

      lcd.print("0D");
      lcd.print(defcard[4][3],HEX);
      
      i = 0 ;
    if( digitalRead(A0) == HIGH )
    stateM[2] = '1' ;
    else if( digitalRead(A0) == LOW )
    stateM[2] = '0' ;
  
    if( digitalRead(A1) == HIGH )
    stateM[3] = '1' ;
    else if( digitalRead(A1) == LOW )
    stateM[3] = '0' ;
  
    if( digitalRead(A2) == HIGH )
    stateM[4] = '1' ;
    else if( digitalRead(A2) == LOW )
    stateM[4] = '0' ;
  
    if( digitalRead(A3) == HIGH )
    stateM[5] = '1' ;
    else if( digitalRead(A3) == LOW )
    stateM[5] = '0' ;
      flag5 = '1' ;
    Wire.beginTransmission(9) ;
      for(int w=0 ; w<7 ; w++)
      Wire.write(stateM[w]) ;
    
      Wire.endTransmission() ;
      delay(15000) ;
      setup() ;
   }  
  }
    else if(flag5 == '1' ){
      stateM[0] = '5' ;
      stateM[1] = '1' ;
      flag5 = '0' ;
      lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("S.P.Kabi");
    lcd.setCursor(0, 1);
    lcd.print("ID : ");
      for(int j=0;j<2;j++)
      lcd.print(defcard[4][j],HEX);

      lcd.print("0D");
      lcd.print(defcard[4][3],HEX);
      
      i = 0 ;
      Wire.beginTransmission(9) ;
      
      for(int w=0 ; w<7 ; w++)
    Wire.write(stateM[w]);
      Wire.endTransmission() ;
      delay(15000) ;
      setup() ;
    }  
     }
    }
  else if(!match){
   
   lcd.clear() ;
   lcd.print("This RFID Card") ;
   lcd.setCursor(0,1) ;
   lcd.print("is not supported !") ;
   delay(10000) ;
   setup() ;}

    lcd.clear() ;
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

