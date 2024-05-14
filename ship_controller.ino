#include <Servo.h>

#include <SoftwareSerial.h>
#include <Servo.h>

// CONEXIONES PARA EL BLUETOOTH.
int bluetoothTx = 2;
int bluetoothRx = 3;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

// MOTOR 1.
int Motor1A = 5;
int Motor1B = 6;

// MOTOR 2.
int Motor2A = 9;
int Motor2B = 10;

void setup() {
  bluetooth.begin(115200);
  bluetooth.print("$$$");
  delay(100);
  bluetooth.println("U,9600,N");
  bluetooth.begin(9600);

  pinMode(Motor1A, OUTPUT);
  pinMode(Motor1B, OUTPUT);
  pinMode(Motor2A, OUTPUT);
  pinMode(Motor2B, OUTPUT);

  digitalWrite(Motor1A, LOW);
  digitalWrite(Motor1B, LOW);
  digitalWrite(Motor2A, LOW);
  digitalWrite(Motor2B, LOW);
}

void loop() {
  if (bluetooth.available()) {
    char toSend = (char)bluetooth.read();
    if (toSend == 'A') {
      digitalWrite(Motor1B, HIGH);
    } 
    else {
      digitalWrite(Motor1B, LOW);
    }
    if (toSend == 'B') {
      digitalWrite(Motor2B, HIGH);
    } 
    else {
      digitalWrite(Motor2B, LOW);
  
    }
}
}
  

