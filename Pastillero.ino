#include<Keypad.h>
#include<Servo.h>
#include <LiquidCrystal_I2C.h> // Debe descargar la Libreria que controla el I2C
#include<Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);
Servo servoc;
const byte filas = 4;
const byte columnas = 4;
byte pinsFilas[filas] = {39, 41, 43, 45};
byte pinsColumnas[columnas] = {47, 49, 51, 53};

char teclas[filas][columnas] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

Keypad teclado = Keypad(makeKeymap(teclas), pinsFilas, pinsColumnas, filas, columnas);
char tecla;
int tiempo = 0;
int tiempo1;
int tiempo2;
int tiempo3;
int tiempo4;
int numero;
int i=10000;
int tiempo1n;
int tiempo2n;
int tiempo3n;
int tiempo4n;
int minutos=59;
int segundos=55;
int horas=23;
int dia=06;
int mes=05;
int anio=2019;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
 
  servoc.attach(52);
  Serial.begin(9600);
}

void mover_servo() {    
      // Reloj
// Control Servo
    for(int t = 0; t <= 8640000; t=t+1000){
      horas++;
       if(horas>=24)
      {
      horas=0;
      minutos=0;
      segundos=0;
      dia++;
      }
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Hora:");
  lcd.print(" ");
  if(horas<10)lcd.print("0");
  lcd.print(horas);
  lcd.print(":");
  if(minutos<10)lcd.print("0");
  lcd.print(minutos);
  lcd.print(":");
  if(segundos<10)lcd.print("0");
  lcd.print(segundos);
  delay (1000);

      if(t == tiempo1n){
      //servoc.write(180);
      //delay(1000);
      //servoc.write(0);
      tiempo1n = tiempo1n + tiempo1;
      Serial.print("Tiempo1 es: ");
      Serial.println(tiempo1n);
      }
      
      if(t == tiempo2n){
      //servoc.write(180);
      //delay(1000);
      //servoc.write(0);
      tiempo2n = tiempo2n + tiempo2;
      Serial.print("Tiempo2 es: ");
      Serial.println(tiempo2n);
      }
      
      if(t == tiempo3n){
      //servoc.write(180);
      //delay(1000);
      //servoc.write(0);
      tiempo3n = tiempo3n + tiempo3;
      Serial.print("Tiempo3 es: ");
      Serial.println(tiempo3n);
      }
      
      if(t == tiempo4n){
      //servoc.write(180);
      //delay(1000);
      //servoc.write(0);
      tiempo4n = tiempo4n + tiempo4;
      Serial.print("Tiempo4 es: ");
      Serial.println(tiempo4n);
      }
      delay(1000);
    }
}


void loop() {
    tecla = teclado.getKey();
    if((tecla != NO_KEY)&&(tecla != 'A')&&(tecla != 'B')&&(tecla != 'C')&&(tecla != 'D')&&(tecla != '*')&&(tecla != '#')) {
      if(i != 1){
      numero = (tecla - 48)*i;
      tiempo = tiempo + numero;
      i = i/10;
      Serial.println(tiempo);
    }
    }
    if(tecla == 'A'){
      tiempo1=tiempo;
      i=10000;
      tiempo=0;     
    }
    
    if(tecla == 'B'){
      tiempo2=tiempo;
      i=10000;
      tiempo=0;
    }
    
    if(tecla == 'C'){
      tiempo3=tiempo;
      i=10000;
      tiempo=0;
    }
    
    if(tecla == 'D'){
      tiempo4=tiempo;
      i=10000;
      tiempo=0;
    }
    
    if(tecla == '#'){
      Serial.print("El tiempo 1 es: ");
      Serial.println(tiempo1);
      Serial.print("El tiempo 2 es: ");
      Serial.println(tiempo2);
      Serial.print("El tiempo 3 es: ");
      Serial.println(tiempo3);
      Serial.print("El tiempo 4 es: ");
      Serial.println(tiempo4);      
    }

    if(tecla == '*'){
      tiempo1n=tiempo1;
      tiempo2n=tiempo2;
      tiempo3n=tiempo3;
      tiempo4n=tiempo4;
      mover_servo();
    }
