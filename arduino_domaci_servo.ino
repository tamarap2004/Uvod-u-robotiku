#include <Servo.h>

Servo servo;
const int potPin = A0;      // Potenciometar na A0
const int buttonPin = 7;    // Taster na digitalnom pinu 7
const int greenLed = 5;     // Zelena LED na pinu 5
const int redLed = 6;       // Crvena LED na pinu 6

bool stopped = false;

void setup() {
  Serial.begin(9600);        // Uključujemo komunikaciju sa Serial Monitorom
  servo.attach(9);
  pinMode(potPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Koristimo internu pull-up otpornost
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);

  digitalWrite(greenLed, HIGH);
  digitalWrite(redLed, LOW);

  Serial.println("Sistem spreman!");
}

void loop() {
  // Čitanje tastera i potenciometra
  int buttonState = digitalRead(buttonPin);
  int potValue = analogRead(potPin);              // Čitamo potenciometar (0-1023)
  int speed = map(potValue, 0, 1023, 91, 180);    // Konvertujemo vrednost (91-180 = napred)

  // Ispis na Serial Monitor
  Serial.print("Potenciometar: ");
  Serial.print(potValue);
  Serial.print(" | Brzina: ");
  Serial.print(speed);
  Serial.print(" | Taster: ");
  Serial.println(buttonState == LOW ? "Pritisnut" : "Otpusten");

  if (buttonState == LOW) {
    // Kada je taster pritisnut - stajanje
    stopped = true;
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    servo.write(90); // Zaustavljanje
    Serial.println("Stanje: ZAUSTAVLJENO");
  } else {
    stopped = false;
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    servo.write(speed);
    Serial.println("Stanje: OKRETANJE");
  }

  delay(200); // Pauza radi preglednijeg ispisa
}
