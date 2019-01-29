/*
============= Sh/\ft Robotica ===============
janeiro/2019
instagram.com/shaftrobotica
facebook.com/shaftrobotica

Codigo referente ao projeto Specchio.
Este programa e do tipo 'codigo aberto' (Open 
Source), mas qualquer alteracao e de 
responsabilidade do usuario.

Domingues, Vitor; Albuquerque, Thiago.
vitordomingues@ymail.com
github.com/vitorshaft/specchio
*/
#include <SoftwareSerial.h>
#include <Servo.h>
#define BTX 4
#define BRX 3

SoftwareSerial bluetooth(BTX,BRX);
Servo j1,j2;
char valor = ' ';

void girar(Servo var,int omega){
  int pos; //= 0;
  for (pos = var.read(); pos < omega; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    var.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = var.read(); pos > omega; pos -= 1) { // goes from 180 degrees to 0 degrees
    var.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  j1.attach(9);
  j2.attach(10,302,544);

}

void loop() {
  if(bluetooth.available()>0){
    valor = bluetooth.read();
    //Serial.println(valor);
    char angulo = valor;// - '0';
    /* valor - '0':  corrige o valor dos numeros
     *  valor: mantem a correspondencia com as letras
     */
    Serial.println(angulo);
    switch(angulo){
      /* via bluetooh os valores são recebidos conforme
       *  ASCII, onde:
       *  - de 0 a 9 corresponde a: 48 a 57
       *  - de a a z corresponde a: 97 a 122
       */
      case 49: girar(j2,20);break;
      case 50: girar(j2,40);break;
      case 51: girar(j2,60);break;
      case 52: girar(j2,80);break;
      case 53: girar(j2,100);break;
      case 54: girar(j2,120);break;
      case 55: girar(j2,140);break;
      case 56: girar(j2,160);break;
      case 57: girar(j2,180);break;
      case 'b': girar(j1,110);break;      //Braço não recebe valores de y porque o switch/case de x nunca se encerra
      case 'c': girar(j1,120);break;
      case 'd': girar(j1,130);break;
      case 'e': girar(j1,140);break;
      case 'f': girar(j1,150);break;
      case 'g': girar(j1,160);break;
      case 'h': girar(j1,170);break;
      case 'i': girar(j1,180);break;
      case 'j': girar(j1,180);break;
      //default: girar(j1,j1.read());break;
    }
//    angulo = angulo*10;
//    if(angulo>180){
//      angulo = 180;
//    }
//    else if(angulo<100){
//      angulo = 100;
    }
//    girar(j1,angulo);
//    girar(j2,angulo);
//    j1.write(angulo);
//    j2.write(angulo);
//  }
  //girar(j2,120);

}
