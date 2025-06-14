#include <Servo.h>
#include <Ps3Controller.h>

// Motor A (Back Left)

#define motorPin1 5  // Pin 14 of L293
#define motorPin2 6  // Pin 10 of L293
// Motor B (Back Right)  
#define motorPin3 10 // Pin  7 of L293
#define motorPin4 9  // Pin  2 of L293

// Front Motors (L293D #2)
// Motor C (Front Left)
#define motorPin5 3  // Pin 14 of L293
#define motorPin6 2 // Pin 10 of L293
// Motor D (Front Right)
#define motorPin7 11 // Pin  7 of L293
#define motorPin8 12 // Pin  2 of L293


//Lifter
#define lift1 8
#define lift2 13
// Servo 1 A0
// Servo 2 A1

Servo myservo1;

void setup() {
  //Motor
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(motorPin5, OUTPUT);
  pinMode(motorPin6, OUTPUT);
  pinMode(motorPin7, OUTPUT);
  pinMode(motorPin8, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  
  //Servo
  myservo1.attach(A0);
  myservo1.write(0);
  
  //Lifter
  pinMode(lift1, OUTPUT);
  pinMode(lift2, OUTPUT);

  Serial.begin(115200);
  Ps3.begin("01:02:03:04:05:06");
  Serial.println("Ready.");
}

void loop() {

  if (Ps3.isConnected()){
  
    String cmd = Serial.readString();
    if (Ps3.data.button.up){
    	maju();
    } else if (Ps3.data.button.down){
    	mundur();
    } else if (Ps3.data.button.left){
    	kekiri();
    } else if (Ps3.data.button.right){
    	kekanan();
    } else{
    	berhenti();  
    }
    
    if (Ps3.data.button.triangle){
    	servo1_putar();
    } else if(Ps3.data.button.cross){
    	keatas();
    } else if(Ps3.data.button.circle){
    	servo1_putarbalik();
    } else if(Ps3.data.button.square){
    	kebawah();
    }
  }
  delay(200);
}


void maju() {
  Serial.println("Maju");
  digitalWrite(motorPin1, HIGH);  // maju
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);  // maju
  digitalWrite(motorPin4, LOW);
  

  digitalWrite(motorPin5, HIGH);  // maju
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, HIGH);  // maju
  digitalWrite(motorPin8, LOW);
}

void mundur() {
  Serial.println("Mundur");

  digitalWrite(motorPin1, LOW);   // mundur
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);   // mundur
  digitalWrite(motorPin4, HIGH);
  

  digitalWrite(motorPin5, LOW);   // mundur
  digitalWrite(motorPin6, HIGH);
  digitalWrite(motorPin7, LOW);   // mundur
  digitalWrite(motorPin8, HIGH);
}

void kekiri() {
  Serial.println("Kiri");

  digitalWrite(motorPin1, LOW);   // belakang kiri diam
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);  // belakang kanan maju
  digitalWrite(motorPin4, LOW);
  
  digitalWrite(motorPin5, LOW);   // sama
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, HIGH);  // sama
  digitalWrite(motorPin8, LOW);
}

void kekanan() {
  Serial.println("kanan");
  digitalWrite(motorPin1, HIGH);  // belakang kiri maju
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);   // belakang kanan diam
  digitalWrite(motorPin4, LOW);
  
  digitalWrite(motorPin5, HIGH);  // sama
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, LOW);   // sama
  digitalWrite(motorPin8, LOW);
}

void berhenti() {
  Serial.println("Stop");
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin5, LOW);
  digitalWrite(motorPin6, LOW);
  digitalWrite(motorPin7, LOW);
  digitalWrite(motorPin8, LOW);
}

void servo1_putar(){
  for (int i =0; i <=180; i++){
  	myservo1.write(i);
  }
}

void servo1_putarbalik(){
  for (int i =180; i >= 0; i--){
  	myservo1.write(i);
  }
}

void keatas(){
  digitalWrite(A4, HIGH);
  digitalWrite(A5, LOW);
}

void kebawah(){
  digitalWrite(A4, LOW);
  digitalWrite(A5, HIGH);
}
