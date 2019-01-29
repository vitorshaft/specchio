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
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
MPU6050 mpu;
//int16_t ax, ay, az;
int16_t x, y, z;
int16_t gx, gy, gz;
#include <SoftwareSerial.h>
#define BT_SERIAL_TX 2
#define BT_SERIAL_RX 3
SoftwareSerial BluetoothSerial(BT_SERIAL_TX, BT_SERIAL_RX);

//int servoValue1;
int gyro_x;
int gyro_x_ant;
int gyro_y;
int gyro_y_ant;
char cX;
char cY;

void setup(){
Wire.begin();
mpu.initialize();
Serial.begin(9600);
BluetoothSerial.begin(9600);
}
void loop(){
//mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
mpu.getAcceleration(&x,&y,&z);
gyro_x = map(x, -17000, 17000, 0,9);
gyro_y = map(y, -17000, 17000, 0,9);
//Serial.print(gyro_x);Serial.print(' '); Serial.println(gyro_y);
//BluetoothSerial.print(1);
Serial.println(gyro_x);

if(gyro_x != gyro_x_ant){
  cX = gyro_x+'0';
  BluetoothSerial.write(cX);
  gyro_x_ant = gyro_x;
  Serial.print("Valor X: ");
  Serial.println(cX);
}
delay(50);
if(gyro_y != gyro_y_ant){
  if(gyro_y == 0){
    BluetoothSerial.print("0");
  }
  else if(gyro_y == 1){
    BluetoothSerial.print("b");
  }
  else if(gyro_y == 2){
    BluetoothSerial.print("c");
  }
  else if(gyro_y == 3){
    BluetoothSerial.print("d");
  }
  else if(gyro_y == 4){
    BluetoothSerial.print("e");
  }
  else if(gyro_y == 5){
    BluetoothSerial.print("f");
  }
  else if(gyro_y == 6){
    BluetoothSerial.print("g");
  }
  else if(gyro_y == 7){
    BluetoothSerial.print("h");
  }
  else if(gyro_y == 8){
    BluetoothSerial.print("i");
  }
  else if(gyro_y == 9){
    BluetoothSerial.print("j");
  }
//switch(gyro_y){
//  
//  case 0: BluetoothSerial.print("0");break;
//  case 1: BluetoothSerial.print("b");break;
//  case 2: BluetoothSerial.print("c");break;
//  case 3: BluetoothSerial.print("d");break;
//  case 4: BluetoothSerial.print("e");break;
//  case 5: BluetoothSerial.print("f");break;
//  case 6: BluetoothSerial.print("g");break;
//  case 7: BluetoothSerial.print("h");break;
//  case 8: BluetoothSerial.print("i");break;
//  case 9: BluetoothSerial.print("j");break;
////  default: BluetoothSerial.print("0");break;
//  }
gyro_y_ant = gyro_y;
}

delay(100);
}
