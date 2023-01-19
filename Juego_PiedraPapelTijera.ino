#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

//Se asignan los servos
int PINSERVO3 = 8;
int PINSERVO2 = 7;
int PINSERVO1 = 6;
int PULSOMIN = 1000;
int PULSOMAX = 2000;

//Se asignan los valores del sensor ultrasónico
int TRIG = 10;
int ECO = 9;
int LED = 13;
int DURACION;
int DISTANCIA;

int buzzer = 4;
int opcion;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  servo1.attach(PINSERVO1, PULSOMIN, PULSOMAX);
  servo2.attach(PINSERVO2, PULSOMIN, PULSOMAX);
  servo3.attach(PINSERVO3, PULSOMIN, PULSOMAX);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.println(DISTANCIA);
  delay(200);
  if(DISTANCIA <= 20 && DISTANCIA > 0){
    opcion = random(1,4);
    //digitalWrite(LED, HIGH);
    //delay(DISTANCIA * 10);
    //digitalWrite(LED, LOW);
    Serial.println("La opcion es " + opcion);
    if (opcion == 1){
      Serial.println("Piedra");
      servo1.write(180);
      tone(buzzer, 523.25);
      delay(500);
      noTone(buzzer);
      servo1.write(0);
    } else if (opcion == 2){
        Serial.println("Papel");
        servo2.write(180);
        tone(buzzer,659.26); 
        delay(500);
        noTone(buzzer);
        servo2.write(0);
    } else if (opcion == 3){
      Serial.println("Tijera");
      servo3.write(180);
      tone(buzzer,783.99);
      delay(500);
      noTone(buzzer);
      servo3.write(0);
    }
    delay(1000);
  }
}
