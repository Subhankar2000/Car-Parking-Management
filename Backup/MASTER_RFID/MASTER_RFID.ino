#include <LiquidCrystal.h>
#include<SPI.h>
#include<MFRC522.h>

#define RSTPIN 9
#define SSPIN 10
MFRC522 rc(SSPIN, RSTPIN);


volatile int Val;

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int readsuccess;

byte readcard[4];
byte sendcard;

void setup() {
  
  Serial.begin(9600);

  SPI.begin();
  rc.PCD_Init();
  rc.PCD_DumpVersionToSerial();
  lcd.begin(16, 2);

  lcd.print("Scan RFID Card");
  Serial.println("Scan RFID Card : ");
}

void loop() {
  readsuccess = getid();
}

int getid(){  
  if(!rc.PICC_IsNewCardPresent()){
    return 0;
  }
  if(!rc.PICC_ReadCardSerial()){
    return 0;
  }
 
  lcd.setCursor(0, 1);
  Serial.println("THE UID IS :");
  lcd.print("UID : ");
  for(int i=0;i<4;i++){
    readcard[i]=rc.uid.uidByte[i];
    sendcard=rc.uid.uidByte[i];
 Serial.write(sendcard);
    
    Serial.print(readcard[i],HEX);
     lcd.print(readcard[i],HEX); 
     
    
  }
  rc.PICC_HaltA();
  
}
