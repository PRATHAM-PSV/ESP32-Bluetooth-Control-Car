#include "BluetoothSerial.h"
#include <ESP32Servo.h>



// Check if Bluetooth is properly enabled
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to enable it
#endif

BluetoothSerial SerialBT;

// Define L298N Control Pins
const int IN1 = 12;
const int IN2 = 13;
const int IN3 = 14;
const int IN4 = 27;

Servo steeringServo;

void setup() {
  Serial.begin(115200);
  
  
  // Set all motor control pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  
  // Start with motors off
  stopCar();

  // Attach Servo to Pin 21 and center it
  steeringServo.attach(21);
  steeringServo.write(90);
  
  // Initialize Bluetooth with the device name
  SerialBT.begin("ESP32_Robot_Car");
  Serial.println("The robot is ready to pair via Bluetooth!");
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();
    Serial.print("Received Command: ");
    Serial.println(command);
    
    // Process commands received from the mobile app
    switch (command) {
      case 'U': lightson();     break;
      case 'u': lightsoff();    break;
      case 'Y': buzzeron();     break;

    // Motors Configuration
      case 'F': moveForward();  break;
      case 'B': moveBackward(); break;
      case 'L': turnLeft();     break;
      case 'R': turnRight();    break;
      case 'S': stopCar();      break;

    // servo configuration 
      case 'X': servoLeft();    break;
      case 'x': servoCenter();  break;
      case 'W': servoRight();   break;
      case 'w': servoback();    break;
    }
  }
  delay(20);
}

// Direction Control Functions
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}             

void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void lightson() {
  digitalWrite(2,HIGH);
}

void lightsoff() {
  digitalWrite(2,LOW);
}

void buzzeron(){
  digitalWrite(4,HIGH);
  delay(2000);
  digitalWrite(4,LOW);
}

// Servo Control Functions
void servoLeft() {
  steeringServo.write(0);
}

void servoCenter() {
  steeringServo.write(90);
}

void servoRight() {
  steeringServo.write(180);
}

void servoback(){
  steeringServo.write(160);
}