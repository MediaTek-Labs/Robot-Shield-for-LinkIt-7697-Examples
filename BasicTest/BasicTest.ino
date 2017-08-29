// Demonstrate all the basics funtionalities
// Servo @ pin 2/3/4/5/7/8/9/11/15/16
// motor @ pin 10/12/13/17
// battary voltage @ pin 14

#include <Servo.h>

#define BATVOL_PIN 14  // Analog input pin

Servo myservo2;  // servo on pin 2
Servo myservo3;  // servo on pin 3
Servo myservo4;  // servo on pin 4
Servo myservo5;  // servo on pin 5
Servo myservo7;  // servo on pin 7
Servo myservo8;  // servo on pin 8
Servo myservo9;  // servo on pin 9
Servo myservo11; // servo on pin 11
Servo myservo15; // servo on pin 15
Servo myservo16; // servo on pin 16

float adcValue;
float voltage;

void setup() {

  Serial.begin(115200);
  
  pinMode(BatteryVolPin, INPUT);

  // set motor pins
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(17, OUTPUT);

  // attach servo pins
  myservo2.attach(2);  
  myservo3.attach(3);  
  myservo4.attach(4);  
  myservo5.attach(5);  
  myservo7.attach(7);  
  myservo8.attach(8);  
  myservo9.attach(9);  
  myservo11.attach(11);
  myservo15.attach(15);
  myservo16.attach(16);
}


void loop() {

  // all servo to 90 degree
  Serial.println("Servo Test = 90");
  myservo2.write(90);
  myservo3.write(90);
  myservo4.write(90);
  myservo5.write(90);
  myservo7.write(90);
  myservo8.write(90);
  myservo9.write(90);
  myservo11.write(90);
  myservo15.write(90);
  myservo16.write(90);  
  delay(1000); 

  // all servo to 0 degree
  Serial.println("Servo Test = 0");
  myservo2.write(0);
  myservo3.write(0);
  myservo4.write(0);
  myservo5.write(0);
  myservo7.write(0);
  myservo8.write(0);
  myservo9.write(0);
  myservo11.write(0);
  myservo15.write(0);
  myservo16.write(0);  
  delay(1000); 

  // moto test
  Serial.println("Motor Test : P10 Lo , P12 Hi , P13 Lo , P17 Hi");
  digitalWrite(10, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(17, HIGH);
  delay(500);                       

  Serial.println("Motor Test : P10 Hi , P12 Lo , P13 Hi , P17 Lo");
  digitalWrite(10, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(17, LOW);
  delay(500);                       

  Serial.println("Motor Test : STOP");
  digitalWrite(10, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(17, LOW);

  // measure the voltage of the battary
  // read ADC value, LinkIt 7697's ADC range is 0~2.5V (0~4095)
  adcValue = analogRead(BATVOL_PIN); 
  Serial.println(adcValue);  
  
  // voltage = ((R1+R2)/R2)*adcValue*2.5/4096
  voltage = adcValue*0.0018315;
  Serial.println(voltage);

  delay(500);  
}

