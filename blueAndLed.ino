#include <SoftwareSerial.h>
char rec;
SoftwareSerial bt(2,3);

void setup(){
  pinMode(13,OUTPUT);
  bt.begin(9600);
  bt.println("Conectado");
  }
void loop(){
  if(bt.available()){
    rec=bt.read();
    switch(rec){
      case '0':
        digitalWrite(13,LOW);
        delay(500);
        bt.println("Led 13 off");
        break;
      case '1':
        digitalWrite(13,HIGH);
        delay(500);
        bt.println("Led 13 on");
        break;
        default:
        delay(500);
        bt.print(rec);
        bt.println("no es una orden valida");
    }
  }
}
