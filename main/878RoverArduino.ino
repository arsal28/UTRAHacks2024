const int analogIpt1 = A0; // infrared input left side
const int speed = 255; 

// Motor A pins
const int enableA = 11;
const int IN1 = 9;
const int IN2 = 8;

// Motor B pins
const int enableB = 10;
const int IN3 = 7;
const int IN4 = 6;

void setup() {
  // Initialize pin mode
  pinMode(analogIpt1, INPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Turn off motors - Initial state
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);

  Serial.begin(9600);
}

int changeVal;


void controlDir(){
  analogWrite(enableA, speed);
  analogWrite(enableB, speed);


  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(2000);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(2000);
}

void loop() {
  changeVal = map(analogRead(analogIpt1), 0, 1023, 0, 100);
  Serial.print("Detected value: "+ changeVal);

  analogWrite(enableA, speed);
  analogWrite(enableB, speed);

  analogWrite(IN1, 180);
  analogWrite(IN2, 0);
  analogWrite(IN3, 180);
  analogWrite(IN4, 0);

  delay(3000);

  analogWrite(IN1, 0);
  analogWrite(IN2, 180);
  analogWrite(IN3, 0);
  analogWrite(IN4, 180);

  delay(3000);

}