int s1;
int s2;
int s3;
int s4;
int s5;

int black = 1;
int white = 0; 
const int ENA = 10;
const int IN1 = 3;
const int IN2 = 4;
const int ENB = 9;
const int IN3 = 5;
const int IN4 = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(9600);

  delay(100);
}

void loop() {

  s1 = digitalRead(A0);
  s2 = digitalRead(A1);
  s3 = digitalRead(A2);
  s4 = digitalRead(A3);
  s5 = digitalRead(A4);

  Serial.print(s1);
  Serial.print(" ");
  Serial.print(s2);
  Serial.print(" ");
  Serial.print(s3);
  Serial.print(" ");
  Serial.print(s4);
  Serial.print(" ");
  Serial.print(s5);
  Serial.println(" ");

  black = 1;
  white = 0;

  //forward
  if (
    ((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 0) && (s5 == 0)) ||
    ((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0)) ||
    ((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 0)) ||
    ((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0)) ||
    ((s1 == 0) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0)) ||
    ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 0)) ||
    ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  )
  {
    forward();
    Serial.print ("forward");
  }

  //left
  else if (
    ((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1)) ||
    ((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1)) ||
    ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1)) ||
    ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 1)) ||
    ((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1)) ||
    ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 0)) ||
    ((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 0)) ||
    ((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  )
  {
    left();
    Serial.print ("left");
  }
  else if (
    ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0)) ||
    ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0)) ||
    ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0)) ||
    ((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0)) ||
    ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 1)) ||
    ((s1 == 0) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0)) ||
    ((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0)) ||
    ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1))
  )
  {
    right();
    Serial.print ("right");
  }
  else if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    motor_stop();
    Serial.print ("stop");
  }
  else
  {
    forward();
    Serial.print ("forward");
  }
}
void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 60);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 60);

}

void right()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 40);
}

void left()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 40);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

void motor_stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}
