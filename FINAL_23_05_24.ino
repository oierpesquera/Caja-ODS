// Práctica encender y apagar un LED a través de botón pulsador


#include "Wire.h"
#include "LiquidCrystal_I2C.h"
#include "Arduino.h"
#include "SoftwareSerial.h"

const int LED = 13;
const int BOTON = 7;

int val;
int ZumbadorPin = 11;  // definimos el pin al que conectaremos el zumbador.
/*definimos cada una de las frecuencias de las notas musicales.
c, d, e... son las notas en notación inglesa.
Cuando van acompañadas de la letra S significa que esa nota es sostenido.
Cuando van acompañadas de la letra H significa que esa nota está en una
octava superior (High).
*/

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX

int c = 261;
int d = 294;
int e = 329;
int f = 349;
int g = 391;
int gS = 415;
int a = 440;
int aS = 455;
int b = 466;
int cH = 523;
int cSH = 554;
int dH = 587;
int dSH = 622;
int eH = 659;
int fH = 698;
int fSH = 740;
int gH = 783;
int gSH = 830;
int aH = 880;

// this declares each of our buttons and their pins
int input7Pin = 7;
int input6Pin = 6;
int input5Pin = 5;
int input4Pin = 4;
int buttonPins[16] = { 19, 18, 17, 16, 15, 14, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13 };  // Pins a los que se conectan los botones

LiquidCrystal_I2C LCD(0x27, 16, 2);

void setup() {
  
  mySoftwareSerial.begin(9600); // Iniciando la comunicación SoftwareSerial
  Serial.begin(115200); // Iniciando la comunicación serial "normal" para el Monitor Serial
  // while(! Serial);
  //Serial.begin(57600);  // this begins the serial connection with a baud rate of 57600

  // LCD
  LCD.init();
  LCD.backlight();

  LCD.setCursor(1, 0);
  LCD.print("01. ESPERANDO.");
  // LCD.print("ODS 1");

  //LCD.setCursor(8, 1);
  //LCD.print("FIN DE LA POBREZA");

  pinMode(ZumbadorPin, OUTPUT);  // definimos la variable ZumbadorPin como una salida.

  for (int i = 0; i < 18; i++) {           // repetir 16 veces (para cada botón)
    pinMode(buttonPins[i], INPUT_PULLUP);  // Los botones se usan con resistencias internas PULLUP
    // Serial.println(i);
    //Serial.flush();   //lo manda a la pantalla
  }

  // pinMode(input7Pin, INPUT);
  //pinMode(input6Pin, INPUT);
  //pinMode(input5Pin, INPUT);
  //pinMode(input4Pin, INPUT);  // these lines declare each of the buttons as an input
}


void loop() {
 
  // checkPush (6);
  // checkPush (5);
  // checkPush (4); // each of these lines calls our checkPush function with a different pin number
  
  //for (int i = 0; i < 18; i++) {              // repetir 18 veces (para cada botón)
  for (int i = 7; i < 8; i++) {              // repetir 18 veces (para cada botón)
    //Serial.println(i);
    //Serial.flush();   //lo manda a la pantalla
    
    
    checkPush (i);


   /* if (digitalRead(buttonPins[i]) == LOW) {  // cuando no se presiona un botón
      Serial.println("No presiona botón");
      Serial.flush();   //lo manda a la pantalla
      
      LCD.init();
      LCD.backlight();
      LCD.setCursor(1, 0);
      LCD.print(F("No presiona botón"));
      
      //LCD.init();
      //LCD.backlight();
      //LCD.setCursor(1, 0);
      //LCD.print(buttonPins[i]);
    }


    else{
        
        Serial.println("Se presiona");
        Serial.flush();   //lo manda a la pantalla
        
        LCD.init();
        LCD.backlight();
        LCD.setCursor(1, 0);
        LCD.print("Se presiona");

        LCD.init();
        LCD.backlight();
        LCD.setCursor(1, 0);
        LCD.print(i);
        Serial.println(i);
      }*/
  
      delay(200);
}
}//

void checkPush(int pinNumber)  // this function expects an integer value when it is called
{
  int buttonPushed = digitalRead(pinNumber);  // this reads the state of a button based on its pin number
 
  LCD.init();
  LCD.backlight();
  LCD.setCursor(1, 0);
  LCD.print(F("Botón__"));
  LCD.print(pinNumber);
  LCD.init();
  LCD.backlight();
  LCD.setCursor(1, 0);
  LCD.print("Estado");
  LCD.print(buttonPushed);


  ////////////////////////////////////////
  //ESTADO DEL BOTON PULSADO / NO PULSADO

  //PULSADO
  if (buttonPushed == HIGH) {         
    // when a button is pressed

    LCD.init();
    LCD.backlight();
    LCD.setCursor(1, 0);
    LCD.print("PULSADO");
    LCD.print(buttonPushed);

    LCD.init();
    LCD.backlight();
    LCD.setCursor(1, 0);
    LCD.print("Estado");
    LCD.print(buttonPushed);

    //ENCIENDE EL LED
    digitalWrite(LED, HIGH);  //ENCIENDE EL LED

    //LED
    LCD.noDisplay();
    delay(1000);
    LCD.display();
    delay(1000);

    LCD.init();
    LCD.backlight();
    LCD.setCursor(1, 0);
    LCD.print("PULSADO");
    Serial.println(buttonPushed);
    
    ////////////////////////////////////////
    //TONO STAR WARS
    tone(10, 600);
    delay(100);
    noTone(10);

    tone(ZumbadorPin, a, 500);
    delay(500 + 50);
    tone(ZumbadorPin, a, 500);
    delay(500 + 50);
    tone(ZumbadorPin, a, 500);
    delay(500 + 50);
    tone(ZumbadorPin, f, 350);
    delay(350 + 50);
    tone(ZumbadorPin, cH, 150);
    delay(150 + 50);

    tone(ZumbadorPin, a, 500);
    delay(500 + 50);
    tone(ZumbadorPin, f, 350);
    delay(350 + 50);
    tone(ZumbadorPin, cH, 150);
    delay(150 + 50);
    tone(ZumbadorPin, a, 1000);
    delay(1000 + 50);

    tone(ZumbadorPin, eH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, eH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, eH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, fH, 350);
    delay(350 + 50);
    tone(ZumbadorPin, cH, 150);
    delay(150 + 50);

    tone(ZumbadorPin, gS, 500);
    delay(500 + 50);
    tone(ZumbadorPin, f, 350);
    delay(350 + 50);
    tone(ZumbadorPin, cH, 150);
    delay(150 + 50);
    tone(ZumbadorPin, a, 1000);
    delay(1000 + 50);

    tone(ZumbadorPin, aH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, a, 350);
    delay(350 + 50);
    tone(ZumbadorPin, a, 150);
    delay(150 + 50);
    tone(ZumbadorPin, aH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, gSH, 250);
    delay(250 + 50);
    tone(ZumbadorPin, gH, 250);
    delay(250 + 50);

    tone(ZumbadorPin, fSH, 125);
    delay(125 + 50);
    tone(ZumbadorPin, fH, 125);
    delay(125 + 50);
    tone(ZumbadorPin, fSH, 250);
    delay(250 + 50);
    delay(250);
    tone(ZumbadorPin, aS, 250);
    delay(250 + 50);
    tone(ZumbadorPin, dSH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, dH, 250);
    delay(250 + 50);
    tone(ZumbadorPin, cSH, 250);
    delay(250 + 50);

    // virtuosismo :)))

    tone(ZumbadorPin, cH, 125);
    delay(125 + 50);
    tone(ZumbadorPin, b, 125);
    delay(125 + 50);
    tone(ZumbadorPin, cH, 250);
    delay(250 + 50);
    delay(250);
    tone(ZumbadorPin, f, 125);
    delay(125 + 50);
    tone(ZumbadorPin, gS, 500);
    delay(500 + 50);
    tone(ZumbadorPin, f, 375);
    delay(375 + 50);
    tone(ZumbadorPin, a, 125);
    delay(125 + 50);

    tone(ZumbadorPin, cH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, a, 375);
    delay(375 + 50);
    tone(ZumbadorPin, cH, 125);
    delay(125 + 50);
    tone(ZumbadorPin, eH, 1000);
    delay(1000 + 50);


    tone(ZumbadorPin, aH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, a, 350);
    delay(350 + 50);
    tone(ZumbadorPin, a, 150);
    delay(150 + 50);
    tone(ZumbadorPin, aH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, gSH, 250);
    delay(250 + 50);
    tone(ZumbadorPin, gH, 250);
    delay(250 + 50);

    tone(ZumbadorPin, fSH, 125);
    delay(125 + 50);
    tone(ZumbadorPin, fH, 125);
    delay(125 + 50);
    tone(ZumbadorPin, fSH, 250);
    delay(250 + 50);
    delay(250);
    tone(ZumbadorPin, aS, 250);
    delay(250 + 50);
    tone(ZumbadorPin, dSH, 500);
    delay(500 + 50);
    tone(ZumbadorPin, dH, 250);
    delay(250 + 50);
    tone(ZumbadorPin, cSH, 250);
    delay(250 + 50);


    tone(ZumbadorPin, cH, 125);
    delay(125 + 50);
    tone(ZumbadorPin, b, 125);
    delay(125 + 50);
    tone(ZumbadorPin, cH, 250);
    delay(250 + 50);
    delay(250);
    tone(ZumbadorPin, f, 250);
    delay(250 + 50);
    tone(ZumbadorPin, gS, 500);
    delay(500 + 50);
    tone(ZumbadorPin, f, 375);
    delay(375 + 50);
    tone(ZumbadorPin, cH, 125);
    delay(125 + 50);

    tone(ZumbadorPin, a, 500);
    delay(500 + 50);
    tone(ZumbadorPin, f, 375);
    delay(375 + 50);
    tone(ZumbadorPin, c, 125);
    delay(125 + 50);
    tone(ZumbadorPin, a, 1000);
    delay(1000 + 50);

    delay(2000);  // dos segundos para volver a empezar.
  }
  
  else {                  
    //NO PULSADO
    digitalWrite(LED, LOW);
    tone(10, 200);
    delay(100);
    noTone(10);
    
    LCD.init();
    LCD.backlight();
    LCD.setCursor(1, 0);
    LCD.print("NO PULSADO");
    Serial.println(buttonPushed);
  }
}