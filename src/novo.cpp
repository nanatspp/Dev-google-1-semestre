#include <Arduino.h>
#include <Bounce2.h>


#define pinLed 5
#define pinBotao 23

bool estadoAnteriorBotao = 0;
bool estadoBotao = 0; 
bool estadoLed = 0;

Bounce btn = Bounce();


void setup() {
 Serial.begin(9600);

 btn.attach(23,  INPUT_PULLUP ); //pinMode
}

void loop() {
 btn.update(); //digitalRead

// Serial.println(btn.fell());
//pressionado - Retorna true quando o botão for pressionado

//Serial.println(btn.read());
// Lê e retorna a leitura

//Serial.println(btn.rose());
// Retorna true quando o botão for solto

//Serial.println(btn.changed());
// Retorna true quando existe uma alteração

//Serial.println(btn.currentDuration());
// Retorna o tempo do estado atual do botão

Serial.println(btn.previousDuration());
// Retorna o tempo do estado anterior do botão
 delay(1000);
}