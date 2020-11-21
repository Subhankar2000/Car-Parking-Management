#include <Keypad.h>
#include <Wire.h> 

const byte ROWS = 4; 
const byte COLS = 3; 
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; 
byte colPins[COLS] = {8, 7, 6}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
	Wire.begin(8) ;
	Wire.onReceive(receiveEvent);
}

void receiveEvent(int howMany) {
int  i=0 ;
  while (1 < Wire.available()) { 
    stateM[i] = Wire.read(); 
    i=i+1 ;
  }
  
void loop(){
  Wire.requestFrom(8, 1);
  while (Wire.available()) { // slave may send less than requested
    id = Wire.read(); // receive a byte as character
	//    Serial.print(c);         // print the character
	i=i+1;
  char key = keypad.getKey();
  
  if (key){
    if(key == 1 ){
		stateM[0] = id ;
		stateM[1] = '1' ;
		
		Wire.beginTransmission(9) ;
			Wire.write(id) ;   
		Wire.endTransmission() ;
  }
}