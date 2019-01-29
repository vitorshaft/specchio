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
int servoValue1;
int gyro_x = 0;
int gyro_y = 0;
void setup()
{
Wire.begin();
mpu.initialize();
Serial.begin(9600);
BluetoothSerial.begin(9600);
}
void loop()
{
//mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
mpu.getAcceleration(&x,&y,&z);
gyro_x = map(x, -18000, 18000, 0,9);
gyro_y = map(y, -18000, 18000, 0,9);
//Serial.print(gyro_x);Serial.print(' '); Serial.println(gyro_y);
//BluetoothSerial.print(1);
Serial.println(gyro_x);
switch(gyro_x){
 
case 0: BluetoothSerial.print("0");break;
case 1: BluetoothSerial.print("1");break;
case 2: BluetoothSerial.print("2");break;
case 3: BluetoothSerial.print("3");break;
case 4: BluetoothSerial.print("4");break;
case 5: BluetoothSerial.print("5");break;
case 6: BluetoothSerial.print("6");break;
case 7: BluetoothSerial.print("7");break;
case 8: BluetoothSerial.print("8");break;
case 9: BluetoothSerial.print("9");break;
//default: BluetoothSerial.print("0");//break;      //loop não sai deste switch case para entrar no do gyro_y

//  switch(gyro_y){
  
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
//  default: BluetoothSerial.print("0");break;
}
//Serial.println(x);
//case 10: BluetoothSerial.print("a");break;
//case 11: BluetoothSerial.print("b");break;
//case 12: BluetoothSerial.print("c");break;
//case 13: BluetoothSerial.print("d");break;
//case 14: BluetoothSerial.print("e");break;
//case 15: BluetoothSerial.print("f");break;
//case 16: BluetoothSerial.print("g");break;
//case 17: BluetoothSerial.print("h");break;
//case 18: BluetoothSerial.print("i");break;
//case 19: BluetoothSerial.print("j");break;
//default: BluetoothSerial.print("0");break;
// }
 
delay(100);
}
