![](./resources/official_armmbed_example_badge.png)
# Blinky Mbed OS example

# **¿Que son 9600 baudios?**
Los baudios son una unidad de medida que se utiliza para expresar la velocidad de transmisión de datos en una comunicación serie. Un baudio representa la cantidad de cambios de estado (como transiciones de señal eléctrica) por segundo en una línea de comunicación.
En el contexto de la comunicación serie, los baudios se utilizan para indicar la velocidad a la que se transmiten los datos entre dispositivos. Un valor de 9600 baudios significa que hay 9600 cambios de estado por segundo en la línea de comunicación.
Cuando se utiliza un valor de 9600 baudios, se están transmitiendo 9600 bits por segundo en la línea. Esto no necesariamente significa que cada bit se represente por un cambio de estado; en la comunicación serial, se utilizan protocolos que pueden incluir bits de inicio, bits de datos y bits de parada, junto con posiblemente bits de paridad.
En resumen, en el contexto de la comunicación serie, 9600 baudios indican la velocidad a la que los datos se transmiten y reciben entre dispositivos. Cuanto mayor sea el valor de baudios, mayor será la velocidad de transmisión de datos.

# **¿Qué es modulación por ancho de pulso (PWM)?**
La Modulación por Ancho de Pulso (PWM, por sus siglas en inglés: Pulse Width Modulation) es una técnica utilizada en electrónica y control para controlar la cantidad de energía entregada a un dispositivo. Esta técnica es particularmente útil para controlar la velocidad de motores, la intensidad de la luz en LEDs, el volumen de altavoces y muchas otras aplicaciones en las que se necesita variar la potencia suministrada.
La idea central detrás de PWM es modificar la duración relativa de un pulso de señal periódica (normalmente una onda cuadrada) mientras se mantiene constante la frecuencia de esta señal. En otras palabras, se altera el ancho del pulso, de ahí el nombre "Modulación por Ancho de Pulso".
El principio básico es que, si mantienes la frecuencia constante y varías la duración de los pulsos, puedes simular una señal analógica (continua) controlando la cantidad de tiempo durante la cual la señal está en estado alto (encendido) en comparación con el tiempo total del ciclo. Esto se realiza a menudo a una frecuencia lo suficientemente alta como para que el ojo humano no perciba el parpadeo en caso de controlar LEDs o la mayoría de los dispositivos electrónicos.
En términos de aplicaciones prácticas, la PWM se usa ampliamente en sistemas embebidos y controladores para ajustar dispositivos a diferentes niveles de rendimiento o intensidad. Por ejemplo:
Control de Motor: Al variar el ancho de los pulsos aplicados a un motor, se puede ajustar su velocidad y dirección.
Control de Luminosidad en LEDs: Se puede ajustar el brillo de un LED variando la duración de los pulsos de encendido y apagado.
Control de Servomotores: Los servomotores se controlan con PWM para ajustar su posición en grados.
Control de Voltaje en Dispositivos: Al alternar rápidamente entre un estado de alta tensión y un estado de baja tensión, se puede controlar el nivel de voltaje medio entregado a un dispositivo.
En resumen, PWM es una técnica esencial en electrónica y control que permite ajustar el nivel de energía entregado a un dispositivo al variar el ancho de los pulsos en una señal periódica.

# **Función memmove**
La función memmove es una función de la biblioteca estándar de C/C++ que se utiliza para copiar bloques de memoria de un lugar a otro, incluso si los bloques de memoria se superponen. Es útil cuando necesitas mover datos dentro de un bloque de memoria sin preocuparte por conflictos de superposición.
Aquí está la sintaxis básica de memmove:
```c++
void* memmove(void* dest, const void* src, size_t count);
```
1. dest: Puntero al inicio del bloque de memoria de destino donde se copiarán los datos.
2. src: Puntero al inicio del bloque de memoria de origen desde donde se copiarán los datos.
3. count: Número de bytes que se copiarán desde el origen al destino.

La razón por la que memmove es útil es que puede manejar situaciones en las que los bloques de memoria de origen y destino se superponen. Esto es crucial para garantizar que los datos se copien correctamente sin corromperlos.

# **Función sscanf**
```c++
sscanf(input, "%x", &colorValue);
```
La función sscanf es una función de la biblioteca estándar de C/C++ que se utiliza para analizar (leer y convertir) datos desde una cadena de caracteres según un formato especificado. En este caso, se está utilizando para convertir una cadena hexadecimal en un valor numérico.

Vamos a analizar cada parte de la llamada a sscanf:
1. input: Es el primer argumento de la función sscanf. Es la cadena de caracteres que se va a analizar.
2. "%x": Es el segundo argumento de sscanf. Es una cadena de formato que indica cómo se espera que esté estructurado el valor en la cadena input. En este caso, %x especifica que se espera un número hexadecimal.
3. &colorValue: Es el tercer argumento de sscanf. Es un puntero a la variable en la que se almacenará el valor analizado. El operador & se utiliza para obtener la dirección de memoria de la variable colorValue, ya que sscanf necesita saber dónde almacenar el valor convertido.

# **Extraer valores RGB**
```c++
float red = (1-(float)((colorValue >> 16) & 0xFF) / 255.0f);
```
1. `colorValue`: Es el valor numérico que se obtiene después de convertir el valor hexadecimal ingresado por el usuario.
2. `colorValue` >> 16: Esto realiza un desplazamiento a la derecha de 16 bits en el valor de colorValue. Básicamente, se desplaza el valor 16 bits hacia la derecha, lo que descarta los bits menos significativos y deja solo los 8 bits más significativos del componente rojo.
3. `& 0xFF`: Esto realiza una operación AND bit a bit entre el resultado del desplazamiento (colorValue >> 16) y 0xFF. 0xFF es un número binario que tiene todos los bits en 1 en los 8 bits más bajos y todos los bits en 0 en los 24 bits superiores. La operación AND con 0xFF permite extraer los 8 bits más bajos del componente rojo.
4. `(float)((colorValue >> 16) & 0xFF)`: Este paso convierte el valor resultante de la operación AND a un número de punto flotante (float). Ahora tenemos un valor decimal entre 0 y 255 que representa el componente rojo.
5.`(1 - (float)((colorValue >> 16) & 0xFF) / 255.0f)`: Aquí estamos ajustando la intensidad del componente rojo. Como el valor original va de 0 a 255 (donde 0 es completamente apagado y 255 es completamente encendido), restamos este valor del 1 para invertirlo (mayor valor -> menor valor). Luego, dividimos por 255.0 para normalizarlo en el rango de 0 a 1, que es lo que espera la función setRGBColor.

Entonces, la línea completa está calculando la intensidad del componente rojo en función del valor hexadecimal ingresado por el usuario, de manera que sea compatible con la función setRGBColor, que espera valores entre 0 y 1.

