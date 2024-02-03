#include <Servo.h>

Servo ymyservo1; // utwórz obiekt serwa dla pierwszego silniczka
Servo zmyservo2; // utwórz obiekt serwa dla drugiego silniczka
Servo xmyservo2; // utwórz obiekt serwa dla drugiego silniczka
Servo cmyservo2; // utwórz obiekt serwa dla drugiego silniczka
int angle = 0; // zmienna przechowująca kąt serw

void setup() {
ymyservo1.attach(9); // podłącz pierwsze serwo do pinu 9
zmyservo2.attach(3); // podłącz drugie serwo do pinu 3
xmyservo2.attach(6); // podłącz drugie serwo do pinu 3
//cmyservo2.attach(5); // podłącz drugie serwo do pinu 3
}

void loop() {
for (angle = 0; angle <= 170; angle += 1) { // zmieniaj kąt od 0 do 180 stopni
ymyservo1.write(angle); // ustaw kąt pierwszego serwa
delay(30); // czekaj chwilę
}

for (angle = 40; angle <= 170; angle += 1) { // zmieniaj kąt od 0 do 180 stopni
xmyservo2.write(angle); // ustaw kąt pierwszego serwa
delay(30); // czekaj chwilę
}

for (angle = 170; angle >= 40; angle -= 1) { // zmieniaj kąt od 0 do 180 stopni
xmyservo2.write(angle); // ustaw kąt pierwszego serwa
delay(30); // czekaj chwilę
}


for (angle = 170; angle >= 0; angle -= 1) { // zmieniaj kąt od 180 do 0 stopni
ymyservo1.write(angle - 40); // ustaw kąt pierwszego serwa
delay(30); // czekaj chwilę
}

for (angle = 100; angle >= 30; angle -= 1) { // zmieniaj kąt od 0 do 180 stopni
zmyservo2.write(angle); // ustaw kąt drugiego serwa
delay(30); // czekaj chwilę
}

for (angle = 0; angle <= 170; angle += 1) { // zmieniaj kąt od 0 do 180 stopni
ymyservo1.write(angle); // ustaw kąt pierwszego serwa
delay(30); // czekaj chwilę
}

for (angle = 170; angle >= 0; angle -= 1) { // zmieniaj kąt od 180 do 0 stopni
ymyservo1.write(angle - 40); // ustaw kąt pierwszego serwa
delay(30); // czekaj chwilę
}

for (angle = 30; angle <= 100; angle += 1) { // zmieniaj kąt od 0 do 180 stopni
zmyservo2.write(angle); // ustaw kąt drugiego serwa
delay(30); // czekaj chwilę
}


}