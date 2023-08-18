
#include "mbed.h"
#include <iostream>
#include <string.h>


//Definimos el período de tiempo en el que se cambiará el color 
//de los LEDs RGB. En este caso, se establece en 50 milisegundos (ms)
#define BLINKING_RATE     50ms


//Creamos un objeto UnbufferedSerial llamado serial para la comunicación
//serial utilizando los pines USBTX y USBRX de la placa
//La velocidad de transmisión se establece en 9600 baudios*
UnbufferedSerial serial(USBTX, USBRX, 9600);


//Creamos objetos PwmOut para controlar los LEDs RGB conectados a los pines
//LED1, LED2 y LED3 de la placa
//con estos objetos podremos controlar la intensidad de los colores rojo,
//verde y azul mediante modulación por ancho de pulso (PWM)*
PwmOut ledR(LED1);
PwmOut ledG(LED2);
PwmOut ledB(LED3);


//Definimos una función setRGBColor que toma tres valores flotantes del 0 al 1
//para establecer la intensidad de los colores rojo, verde y azul en los LEDs RGB
void setRGBColor(float red, float green, float blue) {
    ledR = red;
    ledG = green;
    ledB = blue;
}

int main() {
    while(true) {
        //Declaramos un arreglo de caracteres de longitud 8 para recibir los 6 digitos del
        //codigo hexadecimal y el cero al final de la cadena y el # al inicio de la cadena
        //Tambien mostramos el mensaje al usuario y leemos la cadena, 
        //"%s" indica que se leerá una cadena de caracteres
        char input[8]; 
        printf("Introduce el valor hexadecimal de color (RRGGBB): ");
        scanf("%s", input);


        // Eliminamos "#"" del inicio si está presente
        if (input[0] == '#') {
            // Mover todos los caracteres un lugar a la izquierda
            //explicación detallada de la función memmove en el "Read me"
            memmove(input, input + 1, 7);  
        }
  

        //declara una variable colorValue para almacenar el valor hexadecimal
        //convertido en un número sin signo, la función sscanf se explica en el "Read me"
        unsigned int colorValue;
        sscanf(input, "%x", &colorValue);


        //Se explica en el readme
        float red = (1-(float)((colorValue >> 16) & 0xFF) / 255.0f);
        float green = (1-(float)((colorValue >> 8) & 0xFF) / 255.0f);
        float blue = (1-(float)(colorValue & 0xFF) / 255.0f);

        setRGBColor(red, green, blue);
    }
}