/*Lee la entrada analogica A0, mapea el resultado al rango de 0 a 255 
y utiliza el resutado para poner la anchura del pulso PWM.
 Tambien se escribe en el monitor serie el valor binario de A0 y
 el valor mapeado para la señal PWM.
 De esta manera controlamos la luminosidad del led verde
 de la placa Edubasica
 
 El circuito:
 * potenciometro conectado a la entrada analogica A0.
   Terminal central del potenciometro a pin A0.
   Resto de terminales del potenciometro a +5V y masa
 * Circuito de LED verde conectado a D3-PWM.
 */

// pines usados:
const int analogInPin = A0;  // Entrada analogica A0 del potenciometro
const int analogOutPin = 3; // Salida PWM

int potValor = 0;        // valor de lectura del potenciometro
int outputValor = 0;     // valor de salida de la señal PWM 

void setup() {
  // inicializacion del monitor serie a 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // lee el valor de la entrada analogica:
  potValor = analogRead(analogInPin);            
  // mapea el rango para la señal de salida PWM:
  outputValor = map(potValor, 0, 1023, 0, 255);  
  // asigna el valor cambiado a pin 3 PWM:
  analogWrite(analogOutPin, outputValor);           

  // escribe el resultado en el monitor serie:
  Serial.print("Potenciometro = " );                       
  Serial.print(potValor);      
  Serial.print("\t PWM = ");      
  Serial.println(outputValor);   

  // espera 1 segundo cada bucle para una visualizacion aceptable
  // conviene tener un valor aunque sea pequeño (10ms)
  // por el proceso de conversion de A/D
  delay(10);                     
}
