# sesion-13b

## apuntes sesión


Brainstorming
que sí queremos 
tinder de sonido
acercarse para escucharlo
transmite por bluetooth 
máquina que se le pueda enviar sonido 
interactivo - pulsar 
mínimo 2 personas (si no hay alguien en el lugar b desde el a no podras enviar señales) dentro de parámetros preestablecidos 
cámara
alimentación
parlante mediano 
sonido se fusiona entre a y b 
ambos dispositivos tendrán características propias

que no queremos  
alarma de auto
alarma de incendios
un despertador
madera
no hay memoria
detector de metales 
parlante pequeño
Radio.
Máquina de arcade.
maquina de pago 



podría ser
cartón
plástico

Texto descriptivo
La propuesta consiste en dos objetos individuales, cada uno con un micrófono, que permiten la interacción entre dos personas. Cada una puede grabar o capturar un sonido propio, ya sean palabras, voces o sonidos realizados con el cuerpo. Luego, pueden experimentar modificando la velocidad de sus sonidos, reproduciéndolos de forma rápida, normal o lenta.
Una vez que ambas personas hayan experimentado con sus sonidos, estos se fusionan dentro de la máquina, generando una nueva composición sonora que se transforma visualmente mediante figuras de Lissajous. Estas formas cambian dependiendo de las frecuencias y de la relación entre ambos sonidos, creando una figura única que representa el encuentro de las dos personas.
La idea es que cada persona aporte un sonido distinto y que, al juntarse, se genere algo nuevo que ninguna podría producir por separado. Todo sucede en tiempo real, sin almacenar los sonidos, convirtiendo la interacción en una experiencia física, visual y sonora.
Lo que puede hacer nuestro proyecto es medir las frecuencias y jugar con los tiempos, por ejemplo que las figuras de Lissajous duren más en el tiempo. Tener claro cuales son los parámetros específicamente, los valores lo podemos cambiar rápido pero los parámetros no, esto para lo de diseño abierto.
Bom
# BOM 

| Cantidad | Componente | Descripción |
|---:|---|---|
| 1 | Raspberry Pi Pico | Microcontrolador principal |
| 1 | Micrófono MAX4466 | Captura y amplificación de sonido. [Ver producto](https://afel.cl/products/modulo-microfono-amplificador-max4466?_pos=1&_sid=604d93d7d&_ss=r) |
| 4 | Potenciómetros | Control de parámetros |
| 2 | Botones | Activación y control de funciones |
| 1 | Láser | Emisión de luz láser |

Diagrama de flujo

Captura el sonido que la persona realiza frente al micrófono
Transforma (debemos verlo) darle características al sonido como frecuencia y amplitud
Encuentro fusión de las señales con sus características ya establecidas que ambas generan una nueva composición visual y sonora
Reproducción se transmite la señal y visualizamos como estas conversan

inicio → dos personas → definir características de frecuencia y amplitud → perturban el micrófono → visualizar las figuras creadas desde lo hablado

## encargos

## lectura
