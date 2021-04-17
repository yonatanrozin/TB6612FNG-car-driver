#define AI1 12 
#define AI2 11
#define BI1 10
#define BI2 9
#define pwmA A7
#define pwmB A6
#define stdby 4

int dataIn;
void setup() {
  Serial.begin(9600);
  pinMode(AI1, OUTPUT);
  pinMode(AI2, OUTPUT);
  pinMode(BI1, OUTPUT);
  pinMode(BI2, OUTPUT);
  pinMode(stdby, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(pwmA, OUTPUT);
  
  analogWrite(pwmA, 255);
  analogWrite(pwmB, 255);
  digitalWrite(stdby, HIGH);

}

void loop() {
  if (Serial.available() > 0) {
    dataIn = Serial.read();
    driveCar(dataIn);
    Serial.println(dataIn);
  }
}

void driveCar(int dirNum) {
  if (dirNum == 48 || dirNum == 0) {
    carStop();
  } else if (dirNum == 49 || dirNum == 1) {
    carForward();
  } else if (dirNum == 50 || dirNum == 2) {
    carBack();
  } else if (dirNum == 51 || dirNum == 3) {
    carLeft();
  } else if (dirNum == 52 || dirNum == 4) {
    carRight();
  } else carStop();
}

void carBack() {
  digitalWrite(AI1, HIGH);
  digitalWrite(AI2, LOW);
  digitalWrite(BI1, HIGH);
  digitalWrite(BI2, LOW);
}

void carForward() {
  digitalWrite(AI1, LOW);
  digitalWrite(AI2, HIGH);
  digitalWrite(BI1, LOW);
  digitalWrite(BI2, HIGH);
}

void carRight() {
  digitalWrite(AI1, HIGH);
  digitalWrite(AI2, LOW);
  digitalWrite(BI1, LOW);
  digitalWrite(BI2, HIGH);
}

void carLeft() {
  digitalWrite(AI1, LOW);
  digitalWrite(AI2, HIGH);
  digitalWrite(BI1, HIGH);
  digitalWrite(BI2, LOW);
}

void carStop() {
  digitalWrite(AI1, LOW);
  digitalWrite(AI2, LOW);
  digitalWrite(BI1, LOW);
  digitalWrite(BI2, LOW);
}
