#include <Arduino.h>
#include <Bounce2.h>

const int pinLed = 5;
const int buttonPinUp = 23;
const int buttonPinDown = 22;

int brilho = 0;

Bounce btn1 = Bounce();
Bounce btn2 = Bounce();

void setup()
{
    Serial.begin(9600);
    pinMode(pinLed, OUTPUT); //inicia
    digitalWrite(pinLed, LOW); 

  btn2.attach(buttonPinDown, INPUT_PULLUP);
  btn2.interval(25);
  btn1.attach(buttonPinUp, INPUT_PULLUP);
  btn1.interval(25);

  Serial.println("Pronto para controlar o brilho. Use os botões.");
}


void loop()
{
  btn1.update();
  btn2.update();

  if (btn1.fell()) {
    if (brilho < 100) {
      brilho += 10;
    }
  }

  if (btn2.fell()) {
    if (brilho > 0) {
      brilho -= 10;
    }
  }

  int brilhoValor = map(brilho, 0, 100, 0, 255);

  analogWrite(pinLed, brilhoValor);

  Serial.print("Intensidade: ");
  Serial.print(brilho);
  Serial.print("%  -> Valor PWM: ");
  Serial.println(brilhoValor);
  
  delay(20); 
}
