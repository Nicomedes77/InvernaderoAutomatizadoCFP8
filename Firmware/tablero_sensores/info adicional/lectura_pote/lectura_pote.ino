const int analogPin = A0;
int value;      //variable que almacena la lectura analógica raw
int position;   //posicion del potenciometro en tanto por ciento
 
void setup() {
}
 
void loop() {
   value = analogRead(analogPin);          // realizar la lectura analógica raw
   position = map(value, 0, 1023, 0, 100);  // convertir a porcentaje
 
   //...hacer lo que se quiera, con el valor de posición medido
 
   delay(1000);
}
