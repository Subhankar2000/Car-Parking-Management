#include <Adafruit_GFX.h>   
#include <MCUFRIEND_kbv.h> 
#include <Wire.h> 
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define RGB(r, g, b) (((r&0xF8)<<8)|((g&0xFC)<<3)|(b>>3))
#define GREY      RGB(127, 127, 127)
#define DARKGREY  RGB(64, 64, 64)
#define TURQUOISE RGB(150, 5, 90)
#define PINK      RGB(255, 128, 192)
#define OLIVE     RGB(30, 30, 0)
#define DOLIVE    RGB(230, 230, 0)
#define PURPLE    RGB(100, 0, 80)
#define AZURE     RGB(0, 128, 255)
#define ORANGE    RGB(255,128,64)
MCUFRIEND_kbv tft;     						
char stateM[6]={'a','b','c','d','e','f'};
byte defcard[][5]={{0x15,0x28,0x81,0xCE},{0x75,0x7C,0x55,0xCE},{0x75,0x5D,0x5A,0xCE},{0x55,0xBD,0x7B,0xCE},{0x55,0xF4,0x0D,0xCF}} ;
void setup()
{    Serial.begin(9600); 
    Wire.begin(9) ;
    
    tft.reset();
    uint16_t id = tft.readID();
    tft.begin(id);
    tft.setRotation(1);
    tft.fillScreen(PURPLE);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(135,1);
    tft.print("CAR PARKING SYSTEM") ;
    tft.fillRect(7,5,115,5,MAGENTA);
    tft.fillRect(361,5,110,5,MAGENTA);
    tft.fillRect(7,5,5,307,MAGENTA);
    tft.fillRect(468,5,5,307,MAGENTA);
    tft.fillRect(7,310,466,5,MAGENTA);
    tft.setTextSize(1.7);
    tft.setCursor(115,20);
    tft.print("RFID BASED PROJECT , USING TWO ARDUINO UNO") ;
    tft.setTextSize(4);
    tft.setCursor(155,40);
    tft.print("WELCOME") ;
    tft.setTextSize(2);
    tft.setCursor(20,80);
    tft.print("USE YOUR RFID CARD TO SCAN AND MAKE") ;
    tft.setCursor(20,102);
    tft.print("PAYMENT FOR PARKING , THEN SEE EMPTY") ;
    tft.setCursor(20,124);
    tft.print("SLOTS AND PARK YOUR CAR SAFELY !") ;
    tft.setCursor(220,148);
    tft.setTextSize(3);
    tft.setTextColor(MAGENTA);
    tft.print("OR") ;
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20,180);    
    tft.print("IF YOU HAVE YOUR CAR INSIDE, SIMPLY") ;
    tft.setCursor(20,200);
    tft.print("SCAN THE CARD AGAIN, FOR RECORDS") ;
    tft.setCursor(20,220);
    tft.print("AND THEN TAKE YOUR CAR OUTSIDE ") ;
    tft.setTextSize(5);
    tft.setTextColor(MAGENTA);
    tft.setCursor(17,253);
    tft.print(" * SCAN CARD *") ;
//    Wire.onReceive(receiveEvent) ;

Wire.onReceive(receiveEvent);

}
/*void receiveEvent(char Bytes){
  int i=0 ;
  Wire.requestFrom(9, 6);
  while (Wire.available()) { // slave may send less than requested
    stateM[i] = Wire.read(); // receive a byte as character
//    Serial.print(c);         // print the character
i=i+1;
  }
}*/

void receiveEvent(int howMany) {
int  i=0 ;
  while (1 < Wire.available()) { // loop through all but the last
    stateM[i] = Wire.read(); // receive byte as a character
    i=i+1 ;
  }
//  int x = Wire.read();    // receive byte as an integer
//  Serial.println(x);         // print the integer
}
void loop(){
  /*
  
  }*/
int i=0 ;
  Wire.requestFrom(9, 6);
  while (Wire.available()) { // slave may send less than requested
    stateM[i] = Wire.read(); // receive a byte as character
//    Serial.print(c);         // print the character
i=i+1;
  }
  
    if( stateM[0] == '1' && stateM[1] =='0' )
  {
    tft.fillRect(20,33,444,275,PURPLE);
    tft.setTextColor(WHITE);
    tft.setCursor(20,40);
    tft.setTextSize(2);
    tft.print("CARD HOLDER DETAILS :") ;
    tft.setCursor(40,70);
    tft.print("ID : ") ;
    for(int j=0;j<4;j++)
    tft.print(defcard[0][j],HEX);
    tft.setTextSize(1);
    tft.setCursor(40,93);
    tft.print("PRIVILEDGED : YES | SLOT : 1") ;
    tft.setTextSize(2);
    tft.setCursor(40,108);
    tft.print("NAME : Mr. SUBHANKAR KARMAKAR") ;
    tft.setCursor(40,132);
    tft.setTextColor(MAGENTA);
    tft.print("YOU HAVE A RESERVED SLOT") ;
    tft.setTextColor(WHITE);
    tft.setCursor(40,154);
    tft.print("PARK YOUR CAR AT SLOT 1") ;
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20,184);
    tft.print("PARKING SPACE OVERVIEW :") ;

    tft.fillRect(65,210,65,60,MAGENTA);
    tft.fillRect(70,215,55,50,GREEN);
    tft.setTextColor(BLACK) ;
    tft.setCursor(87,225);
    tft.setTextSize(4);
    tft.print("1") ;
    
    tft.fillRect(  160,210,65,60,MAGENTA);
    
    tft.fillRect( 165,215,55,50,RED);
    tft.setTextColor(WHITE) ;
    tft.setCursor(182,225);
    tft.setTextSize(4);
    tft.print("2") ;
    
    tft.fillRect(255,210,65,60,MAGENTA);
    
    tft.fillRect(260,215,55,50,RED);
    tft.setTextColor(WHITE) ;
    tft.setCursor(277,225);
    tft.setTextSize(4);
    tft.print("3") ;
    
    tft.fillRect(345,210,65,60,MAGENTA);
    
    tft.fillRect(350,215,55,50,RED);
    tft.setTextColor(WHITE) ;
    tft.setCursor(369,225);
    tft.setTextSize(4);
    tft.print("4") ;
    
    tft.setTextColor(WHITE) ;
    tft.setCursor(20,287);
    tft.setTextSize(2);
    tft.print("GREEN : ALLOWED  ");
    tft.setTextColor(MAGENTA);
    tft.print("|");
    tft.setTextColor(WHITE) ;
    tft.print("  RED : NOT ALLOWED") ;
    delay(10000) ;
   stateM[0] = 'a' ;
    stateM[1] = 'b' ;
    stateM[2] = 'c' ;
    stateM[3] = 'd' ;
    stateM[4] = 'e' ;
    stateM[5] = 'f' ;
    setup() ;
  }else if( stateM[0] == '1' && stateM[1] == '1' ){
 tft.fillRect(20,33,444,275,PURPLE);
    tft.setTextColor(WHITE);
    tft.setCursor(20,40);
    tft.setTextSize(2);
    tft.print("CARD HOLDER DETAILS :") ;
    tft.setCursor(40,70);
    tft.print("ID : ") ;
    for(int j=0;j<4;j++)
    tft.print(defcard[0][j],HEX);
    tft.setTextSize(1);
    tft.setCursor(40,93);
    tft.print("PRIVILEDGED : YES | SLOT : 1") ;
    tft.setTextSize(2);
    tft.setCursor(40,108);
    tft.print("NAME : Mr. SUBHANKAR KARMAKAR") ;
    tft.setTextSize(6);
    tft.setCursor(25,140);
    tft.setTextColor(MAGENTA);
    tft.print("WELCOME BACK") ;
    tft.setTextSize(3);
    tft.setCursor(130,200);
    tft.setTextColor(WHITE);
    tft.print("YOU CAN NOW") ;
    tft.setCursor(113,240);
    tft.print("TAKE YOUR CAR") ;
    tft.setTextSize(2);
    tft.setCursor(180,280);
    tft.setTextColor(MAGENTA);
    tft.print("THANK YOU !") ;
    stateM[0] = 'a' ;
    stateM[1] = 'b' ;
    stateM[2] = 'c' ;
    stateM[3] = 'd' ;
    stateM[4] = 'e' ;
    stateM[5] = 'f' ;
    delay(10000) ;
    setup() ;}
  else if( stateM[0] == '2' && stateM[1] == '0')
  {
   tft.fillRect(20,33,444,275,PURPLE);
    tft.setTextColor(WHITE);
    tft.setCursor(20,40);
    tft.setTextSize(2);
    tft.print("CARD HOLDER DETAILS :") ;
    tft.setCursor(40,70);
    tft.print("ID : ") ;
    for(int j=0;j<4;j++)
    tft.print(defcard[1][j],HEX);
    tft.setTextSize(1);
    tft.setCursor(40,93);
    tft.print("PRIVILEDGED : NO | SLOT : ANY GREEN") ;
    tft.setTextSize(2);
    tft.setCursor(40,108);
    tft.print("NAME : Miss. Megha Deoghoria") ;
    tft.setCursor(40,132);
    tft.setTextColor(MAGENTA);
    tft.print("YOU CAN PARK YOUR CAR ") ;
    tft.setTextColor(WHITE);
    tft.setCursor(40,154);
    tft.print("AT GREEN AVAILABLE SLOTS") ;
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20,184);
    tft.print("PARKING SPACE OVERVIEW :") ;
    
    tft.fillRect(65,210,65,60,MAGENTA);
    
    tft.fillRect(70,215,55,50,RED);
    tft.setTextColor(WHITE) ;
   tft.setCursor(87,225);
    tft.setTextSize(4);
    tft.print("1") ;
    
    tft.fillRect(  160,210,65,60,MAGENTA);
    if(stateM[3] == '1'){
    tft.fillRect( 165,215,55,50,RED);
    tft.setTextColor(WHITE) ;
    tft.setCursor(182,225);
    tft.setTextSize(4);
    tft.print("2") ;}
    else{
      tft.fillRect( 165,215,55,50,GREEN);
    tft.setTextColor(BLACK) ;
    tft.setCursor(182,225);
    tft.setTextSize(4);
    tft.print("2") ;
    }
    
    tft.fillRect(255,210,65,60,MAGENTA);
    if(stateM[4] == '1'){
    tft.fillRect(260,215,55,50,RED);
    tft.setTextColor(WHITE) ;
    tft.setCursor(277,225);
    tft.setTextSize(4);
    tft.print("3") ;}
    else{
     tft.fillRect(260,215,55,50,GREEN);
    tft.setTextColor(BLACK) ;
    tft.setCursor(277,225);
    tft.setTextSize(4);
    tft.print("3") ;
    }
   tft.fillRect(345,210,65,60,MAGENTA);
    if(stateM[5] == '1'){
   tft.fillRect(350,215,55,50,RED);
    tft.setTextColor(WHITE) ;
    tft.setCursor(369,225);
    tft.setTextSize(4);
    tft.print("4") ;}
    else{
      tft.fillRect(350,215,55,50,GREEN);
    tft.setTextColor(BLACK) ;
    tft.setCursor(369,225);
    tft.setTextSize(4);
    tft.print("4") ;
    }
    
    tft.setTextColor(WHITE) ;
    tft.setCursor(20,287);
    tft.setTextSize(2);
    tft.print("GREEN : ALLOWED  ");
    tft.setTextColor(MAGENTA);
    tft.print("|");
    tft.setTextColor(WHITE) ;
    tft.print("  RED : NOT ALLOWED") ;
    delay(10000) ;
    stateM[0] = 'a' ;
    stateM[1] = 'b' ;
    stateM[2] = 'c' ;
    stateM[3] = 'd' ;
    stateM[4] = 'e' ;
    stateM[5] = 'f' ;
    setup() ;
  }
  else if( stateM[0] == '2' && stateM[1] == '1' ){
    tft.fillRect(20,33,444,275,PURPLE);
    tft.setTextColor(WHITE);
    tft.setCursor(20,40);
    tft.setTextSize(2);
    tft.print("CARD HOLDER DETAILS :") ;
    tft.setCursor(40,70);
    tft.print("ID : ") ;
    for(int j=0;j<4;j++)
    tft.print(defcard[1][j],HEX);
    tft.setTextSize(1);
    tft.setCursor(40,93);
    tft.print("PRIVILEDGED : NO | SLOT : ANY GREEN") ;
    tft.setTextSize(2);
    tft.setCursor(40,108);
    tft.print("NAME : Miss. Megha Deoghoria") ;
    tft.setTextSize(6);
    tft.setCursor(25,140);
    tft.setTextColor(MAGENTA);
    tft.print("WELCOME BACK") ;
    tft.setTextSize(3);
    tft.setCursor(130,200);
    tft.setTextColor(WHITE);
    tft.print("YOU CAN NOW") ;
    tft.setCursor(113,240);
    tft.print("TAKE YOUR CAR") ;
    tft.setTextSize(2);
    tft.setCursor(180,280);
    tft.setTextColor(MAGENTA);
    tft.print("THANK YOU !") ;
    stateM[0] = 'a' ;
    stateM[1] = 'b' ;
    stateM[2] = 'c' ;
    stateM[3] = 'd' ;
    stateM[4] = 'e' ;
    stateM[5] = 'f' ;
    delay(10000) ;
    setup() ;
  }
  else if(stateM[0] == '3' && stateM[1] =='0' )
  {
   tft.fillRect(20,33,444,275,PURPLE);
    tft.setTextColor(WHITE);
    tft.setCursor(20,40);
    tft.setTextSize(2);
    tft.print("CARD HOLDER DETAILS :") ;
    tft.setCursor(40,70);
    tft.print("ID : ") ;
    for(int j=0;j<4;j++)
    tft.print(defcard[2][j],HEX);
    tft.setTextSize(1);
    tft.setCursor(40,93);
    tft.print("PRIVILEDGED : NO | SLOT : ANY GREEN") ;
    tft.setTextSize(2);
    tft.setCursor(40,108);
    tft.print("NAME : Miss. Divya Suman") ;
    tft.setCursor(40,132);
    tft.setTextColor(MAGENTA);
    tft.print("YOU CAN PARK YOUR CAR ") ;
    tft.setTextColor(WHITE);
    tft.setCursor(40,154);
    tft.print("AT GREEN AVAILABLE SLOTS") ;
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20,184);
    tft.print("PARKING SPACE OVERVIEW :") ;
    tft.fillRect(65,210,65,60,MAGENTA);
    
    tft.fillRect(70,215,55,50,RED);
    tft.setTextColor(WHITE) ;
   tft.setCursor(87,225);
    tft.setTextSize(4);
    tft.print("1") ;
    
    tft.fillRect(  160,210,65,60,MAGENTA);
    if(stateM[3] == '1'){
    tft.fillRect( 165,215,55,50,RED);
    tft.setTextColor(WHITE) ;
    tft.setCursor(182,225);
    tft.setTextSize(4);
    tft.print("2") ;}
    else{
      tft.fillRect( 165,215,55,50,GREEN);
    tft.setTextColor(BLACK) ;
    tft.setCursor(182,225);
    tft.setTextSize(4);
    tft.print("2") ;
    }
    
    tft.fillRect(255,210,65,60,MAGENTA);
    if(stateM[4] == '1'){
    tft.fillRect(260,215,55,50,RED);
    tft.setTextColor(WHITE) ;
    tft.setCursor(277,225);
    tft.setTextSize(4);
    tft.print("3") ;}
    else{
     tft.fillRect(260,215,55,50,GREEN);
    tft.setTextColor(BLACK) ;
    tft.setCursor(277,225);
    tft.setTextSize(4);
    tft.print("3") ;
    }
   tft.fillRect(345,210,65,60,MAGENTA);
    if(stateM[5] == '1'){
   tft.fillRect(350,215,55,50,RED);
    tft.setTextColor(WHITE) ;
    tft.setCursor(369,225);
    tft.setTextSize(4);
    tft.print("4") ;}
    else{
      tft.fillRect(350,215,55,50,GREEN);
    tft.setTextColor(BLACK) ;
    tft.setCursor(369,225);
    tft.setTextSize(4);
    tft.print("4") ;
    }
    
    tft.setTextColor(WHITE) ;
    tft.setCursor(20,287);
    tft.setTextSize(2);
    tft.print("GREEN : ALLOWED  ");
    tft.setTextColor(MAGENTA);
    tft.print("|");
    tft.setTextColor(WHITE) ;
    tft.print("  RED : NOT ALLOWED") ;
    delay(10000) ;
    stateM[0] = 'a' ;
    stateM[1] = 'b' ;
    stateM[2] = 'c' ;
    stateM[3] = 'd' ;
    stateM[4] = 'e' ;
    stateM[5] = 'f' ;
    setup() ; 
  }else if(stateM[0] == '3' && stateM[1] == '1' ){
    tft.fillRect(20,33,444,275,PURPLE);
    tft.setTextColor(WHITE);
    tft.setCursor(20,40);
    tft.setTextSize(2);
    tft.print("CARD HOLDER DETAILS :") ;
    tft.setCursor(40,70);
    tft.print("ID : ") ;
    for(int j=0;j<4;j++)
    tft.print(defcard[2][j],HEX);
    tft.setTextSize(1);
    tft.setCursor(40,93);
    tft.print("PRIVILEDGED : NO | SLOT : ANY GREEN") ;
    tft.setTextSize(2);
    tft.setCursor(40,108);
    tft.print("NAME : Miss. Divya Suman") ;
    tft.setTextSize(6);
    tft.setCursor(25,140);
    tft.setTextColor(MAGENTA);
    tft.print("WELCOME BACK") ;
    tft.setTextSize(3);
    tft.setCursor(130,200);
    tft.setTextColor(WHITE);
    tft.print("YOU CAN NOW") ;
    tft.setCursor(113,240);
    tft.print("TAKE YOUR CAR") ;
    tft.setTextSize(2);
    tft.setCursor(180,280);
    tft.setTextColor(MAGENTA);
    tft.print("THANK YOU !") ;
    stateM[0] = 'a' ;
    stateM[1] = 'b' ;
    stateM[2] = 'c' ;
    stateM[3] = 'd' ;
    stateM[4] = 'e' ;
    stateM[5] = 'f' ;
    delay(10000) ;
    setup() ;
  }else if(stateM[0] == '4' && stateM[1] == '0'){
    tft.fillRect(20,33,444,275,PURPLE);
    tft.setTextColor(WHITE);
    tft.setCursor(20,40);
    tft.setTextSize(2);
    tft.print("CARD HOLDER DETAILS :") ;
    tft.setCursor(40,70);
    tft.print("ID : ") ;
    for(int j=0;j<4;j++)
    tft.print(defcard[3][j],HEX);
    tft.setTextSize(1);
    tft.setCursor(40,93);
    tft.print("PRIVILEDGED : NO | SLOT : ANY GREEN") ;
    tft.setTextSize(2);
    tft.setCursor(40,108);
    tft.print("NAME : Miss. Snehil Srivastava") ;
    tft.setCursor(40,132);
    tft.setTextColor(MAGENTA);
    tft.print("YOU CAN PARK YOUR CAR ") ;
    tft.setTextColor(WHITE);
    tft.setCursor(40,154);
    tft.print("AT GREEN AVAILABLE SLOTS") ;
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20,184);
    tft.print("PARKING SPACE OVERVIEW :") ;
    tft.fillRect(65,210,65,60,MAGENTA);
    
    tft.fillRect(70,215,55,50,RED);
    tft.setTextColor(WHITE) ;
   tft.setCursor(87,225);
    tft.setTextSize(4);
    tft.print("1") ;
    
    tft.fillRect(  160,210,65,60,MAGENTA);
    if(stateM[3] == '1'){
    tft.fillRect( 165,215,55,50,RED);
    tft.setTextColor(WHITE) ;
    tft.setCursor(182,225);
    tft.setTextSize(4);
    tft.print("2") ;}
    else{
      tft.fillRect( 165,215,55,50,GREEN);
    tft.setTextColor(BLACK) ;
    tft.setCursor(182,225);
    tft.setTextSize(4);
    tft.print("2") ;
    }
    
    tft.fillRect(255,210,65,60,MAGENTA);
    if(stateM[4] == '1'){
    tft.fillRect(260,215,55,50,RED);
    tft.setTextColor(WHITE) ;
    tft.setCursor(277,225);
    tft.setTextSize(4);
    tft.print("3") ;}
    else{
     tft.fillRect(260,215,55,50,GREEN);
    tft.setTextColor(BLACK) ;
    tft.setCursor(277,225);
    tft.setTextSize(4);
    tft.print("3") ;
    }
   tft.fillRect(345,210,65,60,MAGENTA);
    if(stateM[5] == '1'){
   tft.fillRect(350,215,55,50,RED);
    tft.setTextColor(WHITE) ;
    tft.setCursor(369,225);
    tft.setTextSize(4);
    tft.print("4") ;}
    else{
      tft.fillRect(350,215,55,50,GREEN);
    tft.setTextColor(BLACK) ;
    tft.setCursor(369,225);
    tft.setTextSize(4);
    tft.print("4") ;
    }
    tft.setTextColor(WHITE) ;
    tft.setCursor(20,287);
    tft.setTextSize(2);
    tft.print("GREEN : ALLOWED  ");
    tft.setTextColor(MAGENTA);
    tft.print("|");
    tft.setTextColor(WHITE) ;
    tft.print("  RED : NOT ALLOWED") ;
    delay(10000) ;
    stateM[0] = 'a' ;
    stateM[1] = 'b' ;
    stateM[2] = 'c' ;
    stateM[3] = 'd' ;
    stateM[4] = 'e' ;
    stateM[5] = 'f' ;
    setup() ;
  }else if(stateM[0] == '4' && stateM[1] == '1'){
    tft.fillRect(20,33,444,275,PURPLE);
    tft.setTextColor(WHITE);
    tft.setCursor(20,40);
    tft.setTextSize(2);
    tft.print("CARD HOLDER DETAILS :") ;
    tft.setCursor(40,70);
    tft.print("ID : ") ;
    for(int j=0;j<4;j++)
    tft.print(defcard[3][j],HEX);
    tft.setTextSize(1);
    tft.setCursor(40,93);
    tft.print("PRIVILEDGED : NO | SLOT : ANY GREEN") ;
    tft.setTextSize(2);
    tft.setCursor(40,108);
    tft.print("NAME : Miss. Snehil Srivastava") ;
    tft.setTextSize(6);
    tft.setCursor(25,140);
    tft.setTextColor(MAGENTA);
    tft.print("WELCOME BACK") ;
    tft.setTextSize(3);
    tft.setCursor(130,200);
    tft.setTextColor(WHITE);
    tft.print("YOU CAN NOW") ;
    tft.setCursor(113,240);
    tft.print("TAKE YOUR CAR") ;
    tft.setTextSize(2);
    tft.setCursor(180,280);
    tft.setTextColor(MAGENTA);
    tft.print("THANK YOU !") ;
    stateM[0] = 'a' ;
    stateM[1] = 'b' ;
    stateM[2] = 'c' ;
    stateM[3] = 'd' ;
    stateM[4] = 'e' ;
    stateM[5] = 'f' ;
    delay(10000) ;
    setup() ;
  }
  else if(stateM[0] == '5' && stateM[1] == '0'){
    tft.fillRect(20,33,444,275,PURPLE);
    tft.setTextColor(WHITE);
    tft.setCursor(20,40);
    tft.setTextSize(2);
    tft.print("CARD HOLDER DETAILS :") ;
    tft.setCursor(40,70);
    tft.print("ID : ") ;
    for(int j=0;j<2;j++)
      tft.print(defcard[4][j],HEX);

      tft.print("0D");
      tft.print(defcard[4][3],HEX);
      tft.setTextSize(1);
    tft.setCursor(40,93);
    tft.print("PRIVILEDGED : NO | SLOT : ANY GREEN") ;
    tft.setTextSize(2);
    tft.setCursor(40,108);
    tft.print("NAME : Mr. Sourik Prakash Kabi") ;
    tft.setCursor(40,132);
    tft.setTextColor(MAGENTA);
    tft.print("YOU CAN PARK YOUR CAR ") ;
    tft.setTextColor(WHITE);
    tft.setCursor(40,154);
    tft.print("AT GREEN AVAILABLE SLOTS") ;
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20,184);
    tft.print("PARKING SPACE OVERVIEW :") ;
    
    tft.fillRect(65,210,65,60,MAGENTA);
    
    tft.fillRect(70,215,55,50,RED);
    tft.setTextColor(WHITE) ;
   tft.setCursor(87,225);
    tft.setTextSize(4);
    tft.print("1") ;
    
    tft.fillRect(  160,210,65,60,MAGENTA);
    if(stateM[3] == '1'){
    tft.fillRect( 165,215,55,50,RED);
    tft.setTextColor(WHITE) ;
    tft.setCursor(182,225);
    tft.setTextSize(4);
    tft.print("2") ;}
    else{
      tft.fillRect( 165,215,55,50,GREEN);
    tft.setTextColor(BLACK) ;
    tft.setCursor(182,225);
    tft.setTextSize(4);
    tft.print("2") ;
    }
    
    tft.fillRect(255,210,65,60,MAGENTA);
    if(stateM[4] == '1'){
    tft.fillRect(260,215,55,50,RED);
    tft.setTextColor(WHITE) ;
    tft.setCursor(277,225);
    tft.setTextSize(4);
    tft.print("3") ;}
    else{
     tft.fillRect(260,215,55,50,GREEN);
    tft.setTextColor(BLACK) ;
    tft.setCursor(277,225);
    tft.setTextSize(4);
    tft.print("3") ;
    }
   tft.fillRect(345,210,65,60,MAGENTA);
    if(stateM[5] == '1'){
   tft.fillRect(350,215,55,50,RED);
    tft.setTextColor(WHITE) ;
    tft.setCursor(369,225);
    tft.setTextSize(4);
    tft.print("4") ;}
    else{
      tft.fillRect(350,215,55,50,GREEN);
    tft.setTextColor(BLACK) ;
    tft.setCursor(369,225);
    tft.setTextSize(4);
    tft.print("4") ;
    }tft.setTextColor(WHITE) ;
    tft.setCursor(20,287);
    tft.setTextSize(2);
    tft.print("GREEN : ALLOWED  ");
    tft.setTextColor(MAGENTA);
    tft.print("|");
    tft.setTextColor(WHITE) ;
    tft.print("  RED : NOT ALLOWED") ;
    delay(10000) ;
    stateM[0] = 'a' ;
    stateM[1] = 'b' ;
    stateM[2] = 'c' ;
    stateM[3] = 'd' ;
    stateM[4] = 'e' ;
    stateM[5] = 'f' ;
    setup() ;
  }else if(stateM[0] == '5' && stateM[1] == '1'){
    tft.fillRect(20,33,444,275,PURPLE);
    tft.setTextColor(WHITE);
    tft.setCursor(20,40);
    tft.setTextSize(2);
    tft.print("CARD HOLDER DETAILS :") ;
    tft.setCursor(40,70);
    tft.print("ID : ") ;
    for(int j=0;j<2;j++)
      tft.print(defcard[4][j],HEX);

      tft.print("0D");
      tft.print(defcard[4][3],HEX);
      
    tft.setTextSize(1);
    tft.setCursor(40,93);
    tft.print("PRIVILEDGED : NO | SLOT : ANY GREEN") ;
    tft.setTextSize(2);
    tft.setCursor(40,108);
    tft.print("NAME : Mr. Sourik Prakash Kabi") ;
    tft.setTextSize(6);
    tft.setCursor(25,140);
    tft.setTextColor(MAGENTA);
    tft.print("WELCOME BACK") ;
    tft.setTextSize(3);
    tft.setCursor(130,200);
    tft.setTextColor(WHITE);
    tft.print("YOU CAN NOW") ;
    tft.setCursor(113,240);
    tft.print("TAKE YOUR CAR") ;
    tft.setTextSize(2);
    tft.setCursor(180,280);
    tft.setTextColor(MAGENTA);
    tft.print("THANK YOU !") ;
    stateM[0] = 'a' ;
    stateM[1] = 'b' ;
    stateM[2] = 'c' ;
    stateM[3] = 'd' ;
    stateM[4] = 'e' ;
    stateM[5] = 'f' ;
    delay(10000) ;
    setup() ;
  }else if(stateM[0] == '9'){
    tft.fillRect(20,33,444,275,PURPLE);
    tft.setTextColor(WHITE) ;
    tft.setTextSize(6);
    tft.setCursor(30,70);
    tft.print("PARKING FULL");
    tft.setTextSize(4);
    tft.setCursor(40,135);
    tft.print("COME BACK LATER !");
    tft.setTextColor(MAGENTA) ;
    tft.setTextSize(5);
    tft.setCursor(70,250);
    tft.print(" THANK YOU");
    delay(10000) ;
    stateM[0] = 'a' ;
    stateM[1] = 'b' ;
    stateM[2] = 'c' ;
    stateM[3] = 'd' ;
    stateM[4] = 'e' ;
    stateM[5] = 'f' ;
    setup() ;
  }else if(stateM[0] == '8'){
    tft.fillRect(20,33,444,275,PURPLE);
    tft.setTextSize(4);
    tft.setCursor(30,70);
    tft.print("THIS RFID CARD IS");
    tft.setTextSize(4);
    tft.setCursor(64,120);
    tft.print("NOT SUPPORTED !");
    delay(10000) ;
    stateM[0] = 'a' ;
    stateM[1] = 'b' ;
    stateM[2] = 'c' ;
    stateM[3] = 'd' ;
    stateM[4] = 'e' ;
    stateM[5] = 'f' ;
    setup() ;
  }
}
