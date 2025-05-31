// Motor A (belakang kiri)
const int motorPin1  = 5;  
const int motorPin2  = 6;  
// Motor B (belakang kanan)  
const int motorPin3  = 10; 
const int motorPin4  = 9;  

// Front Motors (L293D #2)
// Motor C (depan kiri)
const int motorPin5  = 3;  
const int motorPin6  = 2;  
// Motor D (depan kanan)
const int motorPin7  = 11; 
const int motorPin8  = 12; 

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(motorPin5, OUTPUT);
  pinMode(motorPin6, OUTPUT);
  pinMode(motorPin7, OUTPUT);
  pinMode(motorPin8, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  kekiri();

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
