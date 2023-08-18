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
dest: Puntero al inicio del bloque de memoria de destino donde se copiarán los datos.
src: Puntero al inicio del bloque de memoria de origen desde donde se copiarán los datos.
count: Número de bytes que se copiarán desde el origen al destino.
La razón por la que memmove es útil es que puede manejar situaciones en las que los bloques de memoria de origen y destino se superponen. Esto es crucial para garantizar que los datos se copien correctamente sin corromperlos.
