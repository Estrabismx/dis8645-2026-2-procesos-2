# sesion-13b

## apuntes sesión

Hoy revisamos las dos ideas que tenemos para el proyecto 3. con Fan Connect quedaron hartas preguntas, ¿De dónde sacaríamos la música? Las bibliotecas gratuitas se hizo obvio que no eran muy bueenas. También faltaba definir para quién era el dispositivo, cómo sabríamos si a esa persona le iba a gustar lo que le mandaran y cómo mostraríamos el intercambio en Diseño Abierto.

Después de conversar todo eso, decidimos seguir con Nido!! la idea sigue siendo hacer un dispositivo sonoro para niños, con cuentos, música y mensajes grabados por personas cercanas. ahora queremos ver si el contenido podría cambiar según la hora o el momento del día. por ejemplo, que en la tarde aparezca una canción o una fábula y que antes de dormir aparezca un cuento más tranquilo. 

Todavía tenemos que ver qué tendría sentido escuchar en cada momento y si dividirlo por edades, o dejarlo en un rango, etc

Y queda pendiente cambiarle el nombre. muy importante!!

cositas que ya dejamos definidas

### Idea general

El proyecto sería un dispositivo sonoro portátil pensado para acompañar a niños de 3 a 4 años que puedan sentirse solos, asustados o necesitar contención en distintos momentos del día. La idea es que puedan acceder de forma autónoma a cuentos, música y un mensaje grabado por un cuidador mediante botones físicos y una pantalla de apoyo.

El nombre del dispositivo y del proyecto todavía está por definir.

### Usuario y biblioteca

El público objetivo serán niños de 3 a 4 años que necesiten acompañamiento. No vamos a separar la biblioteca en rangos de edad distintos, porque queremos trabajar con un usuario específico y no hacer tres versiones del contenido.

Los cuentos y la música serán audios con licencias que permitan su uso. La biblioteca inicial quedará cerrada con los contenidos que nosotros propongamos y no estará pensada para crecer después de la entrega.

Las grabaciones serán diferentes. Solo el cuidador podrá entregar este contenido y podrá grabar un mensaje nuevo cada día.

La biblioteca se dividirá entre día y noche. Durante el día podrían aparecer cuentos o música para acompañar distintos momentos, mientras que durante la noche se podrían priorizar contenidos más tranquilos o relacionados con la hora de dormir.

Lo que todavía tenemos que figure out es cómo la máquina sabrá en qué momento está. Podría usar la hora de Santiago, un temporizador o una configuración hecha por el cuidador. La división entre día y noche ya está definida, pero falta resolver cómo se implementará.

### Funcionamiento del usuario principal

El dispositivo principal será utilizado por el niño y tendrá tres botones físicos duros.

- Cuentos
- Música
- Grabaciones

La primera presión activará la categoría correspondiente. Si se vuelve a presionar el mismo botón, cambiará el contenido dentro de esa categoría. Por ejemplo, al presionar cuentos se reproducirá un cuento y, al presionar nuevamente el botón, se pasará al siguiente.

Tenemos que evitar que el dispositivo reproduzca siempre el mismo audio. Para eso habrá que definir cómo se recordará el último contenido reproducido y cómo se interpretarán las pulsaciones. Una presión larga o varias presiones muy rápidas podrían contar como una sola, para que el niño no cambie de contenido demasiadas veces sin querer.

La pantalla acompañará esta interacción, pero todavía no hemos definido exactamente qué mostrará. Podría presentar la categoría activa, el personaje relacionado con el contenido, el audio que está sonando o el estado del dispositivo.

### Grabación y control parental

La grabación estará pensada para el cuidador y no para el uso cotidiano del niño. Se guardará un solo mensaje familiar a la vez. Ese mensaje se borrará después de un día o se reemplazará cuando se grabe uno nuevo.

Durante el proceso pensamos en tres alternativas.

#### Primera alternativa

La primera opción era usar una perilla encoder. La perilla tendría un valor mínimo y máximo que representarían no y sí. Si el dispositivo no está realizando otra acción, después de 15 segundos volvería automáticamente al valor por defecto, no.

Para activar la grabación habría que mover la perilla hasta sí y mantenerla presionada durante cinco segundos. En la pantalla aparecería una cuenta regresiva.

- mantener apretado 1
- mantener apretado 2
- mantener apretado 3
- mantener apretado 4
- mantener apretado 5
- grabando

Al dejar de presionar terminaría la grabación y aparecería durante diez segundos el mensaje “mensaje guardado”. También habíamos pensado que, si se vuelve a presionar, se podría borrar el mensaje anterior.

Esta opción nos permitía usar una interacción completamente física, pero se sentía un poco enredada para el cuidador.

#### Segunda alternativa

La segunda opción era usar la pantalla touch con lápiz como control parental. Además de la interfaz general, habría un ícono presionable en una esquina de la pantalla. Al mantenerlo presionado durante cinco segundos se abriría una pantalla de clave.

Si no existiera una clave, se podría crear. Si ya existiera, también se podría cambiar. Después de ingresar la clave aparecería una pantalla exclusiva para grabar.

La idea era que solo ese botón o sector de la pantalla fuera touch, para que el niño no pudiera entrar por accidente. Tenemos que revisar si se puede dejar solo una parte de la pantalla como touch y si funcionaría correctamente usando lápiz.

#### Tercera alternativa

La tercera alternativa es la que elegimos. Una parte del producto se separará del dispositivo principal y tendrá el micrófono y la función de grabar. Esta pieza se conectará mediante conectores JST y, al hacer el attach, aparecerá la pantalla de grabación.

El cuidador presionará para comenzar a grabar y soltará para terminar. Al dejar de presionar aparecerá el mensaje “mensaje guardado”. Si ocurre algún problema, aparecerá un mensaje de error.

El módulo de grabación tendrá un LED que se encenderá mientras está grabando y se apagará al terminar. El parlante y los botones de cuentos, música y grabaciones quedarán en el dispositivo principal, que será utilizado por el niño.

La parte desmontable funcionará como una restricción física. Así el niño no podrá acceder fácilmente a la grabación ni borrar por accidente los mensajes de sus cuidadores.

### Componentes y almacenamiento

Para grabar necesitamos un micrófono barato y funcional, sin agregar una complejidad innecesaria. La idea es buscar un modelo básico y compatible con la raspi. Dependiendo del modelo elegido, habrá que confirmar si funciona por USB o mediante una entrada analógica por ADC.

Para guardar los audios y las grabaciones agregaremos un lector SD y una tarjeta SD. Los cuentos y la música de la biblioteca inicial se almacenarían ahí, junto con el mensaje diario del cuidador.

También se mantiene como referencia el amplificador PAM8403 y el parlante. Antes de cerrar completamente el sistema tenemos que probar la cadena de audio con la raspi y verificar que la reproducción funcione correctamente.

### Carcasa

La carcasa debe contemplar el dispositivo principal y la pieza desmontable de grabación. También debe dejar espacio para la pantalla, el parlante, el lector SD, la tarjeta, la batería, los conectores JST y la ventilación.

Los botones serán duros y fáciles de distinguir. No usaremos botones de goma porque los niños se las comen. La parte desmontable debe poder separarse sin dejar conexiones expuestas ni piezas fáciles de sacar.

### Pendientes reales

- Definir el nombre final del proyecto y del dispositivo.
- Definir el modelo y la función exacta de la pantalla.
- Buscar los cuentos y canciones con licencias compatibles.
- Resolver cómo la máquina reconocerá si es de día o de noche.
- Buscar y probar un modelo de micrófono.
- Definir cómo se evitarán las pulsaciones accidentales.
- Resolver el apagado seguro para no dañar la tarjeta SD.
- Definir las medidas finales de la carcasa y del módulo desmontable.


## encargos

## lectura
