# sesion-11a

## apuntes sesión

## Diagramas de flujo


<details>
<summary><b>Mapa de flujo: experiencia de usuario</b></summary>


```mermaid
%%{init: {'theme':'base','themeVariables':{'fontFamily':'Arial','lineColor':'#2E7D32','primaryTextColor':'#0B3C5D'}}}%%
flowchart TD
    A([Inicio<br/>pantalla apagada]) --> B{"¿Mantiene el botón 1<br/>por 2 segundos?"}
    B -- No --> A
    B -- Sí --> C["La pantalla se enciende<br/>y ve el menú de naves"]


    C --> D["Gira la perilla derecha<br/>para ver las 4 naves"]
    D --> E{"¿Presiona el botón 1<br/>una vez?"}
    E -- No --> D
    E -- Sí --> F["Selecciona la nave<br/>y empieza la partida"]


    F --> G["Ve avanzar el mapa<br/>con obstáculos"]
    G --> H["Gira la perilla izquierda<br/>si quiere más o menos velocidad"]
    H --> I["Mantiene presionado el botón 2<br/>para subir o lo suelta para caer"]
    I --> J{"¿La nave choca con<br/>un obstáculo o el suelo?"}


    J -- No --> G
    J -- Sí --> K["Pierde: el juego se reinicia<br/>y vuelve al menú de naves"]
    K --> C


    C --> L{"¿Mantiene el botón 1<br/>por 2 segundos?"}
    L -- Sí --> M(["Se apaga la pantalla"])
    M --> A
    L -- No --> D


    classDef inicio fill:#0B3C5D,stroke:#2E7D32,stroke-width:2px,color:#FFF9DB;
    classDef decision fill:#FFD60A,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef accion fill:#C8E6C9,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef menu fill:#BFE3F5,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;


    class A,M inicio;
    class B,E,J,L decision;
    class D,F,G,H,I accion;
    class C,K menu;


    linkStyle default stroke:#2E7D32,stroke-width:2px;
```


</details>


<details>
<summary><b>Mapa de flujo: máquina</b></summary>


```mermaid
%%{init: {'theme':'base','themeVariables':{'fontFamily':'Arial','lineColor':'#2E7D32','primaryTextColor':'#0B3C5D'}}}%%
flowchart TD
    A([Alimentación del sistema]) --> B["Inicializar pantalla OLED,<br/>botones y perillas<br/>estado = APAGADO"]
    B --> C{"¿Botón 1 mantenido<br/>por 2 segundos?"}
    C -- No --> C
    C -- Sí --> D["Encender pantalla<br/>estado = MENÚ"]


    D --> E["Leer perilla derecha<br/>Asignar nave 1 de 4 según el rango"]
    E --> F["Mostrar nave elegida<br/>en el menú"]
    F --> G{"¿Botón 1 con<br/>una pulsación?"}
    G -- No --> E
    G -- Sí --> H["Confirmar nave<br/>estado = JUEGO<br/>Posición inicial de la nave"]


    H --> I["Leer perilla izquierda<br/>Ajustar velocidad del mapa"]
    I --> J["Desplazar mapa y obstáculos<br/>en el eje X"]
    J --> K{"¿Botón 2<br/>presionado?"}
    K -- Sí --> L["Subir nave<br/>eje Y"]
    K -- No --> M["Bajar nave por gravedad<br/>eje Y"]
    L --> N
    M --> N["Dibujar nave y mapa<br/>en la pantalla"]


    N --> O{"¿La nave tocó un obstáculo,<br/>el suelo o el techo?"}
    O -- No --> I
    O -- Sí --> P["Registrar derrota<br/>Reiniciar partida"]
    P --> D


    D --> Q{"¿Botón 1 mantenido<br/>por 2 segundos?"}
    Q -- Sí --> R["Apagar pantalla<br/>estado = APAGADO"]
    R --> C
    Q -- No --> E


    classDef inicio fill:#0B3C5D,stroke:#2E7D32,stroke-width:2px,color:#FFF9DB;
    classDef decision fill:#FFD60A,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef proceso fill:#C8E6C9,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef menu fill:#BFE3F5,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;


    class A inicio;
    class C,G,K,O,Q decision;
    class B,E,F,H,I,J,L,M,N proceso;
    class D,P,R menu;


    linkStyle default stroke:#2E7D32,stroke-width:2px;
```


</details>


<details>
<summary><b>Diagrama de flujo: botones</b></summary>


**Botón 1 (seleccionador):** pulsación corta selecciona, pulsación larga (2 segundos) enciende o apaga.


```mermaid
%%{init: {'theme':'base','themeVariables':{'fontFamily':'Arial','lineColor':'#2E7D32','primaryTextColor':'#0B3C5D'}}}%%
flowchart TD
    A([Ciclo principal llama a update]) --> B{"¿La persona está<br/>presionando el botón?"}


    B -- Sí --> C{"¿Ya estaba presionado<br/>en el ciclo anterior?"}
    C -- No --> D["Anota la hora de inicio<br/>Estado: estaSiendoPresionado"]
    C -- Sí --> E{"¿Pasaron 2 segundos<br/>desde el inicio?"}
    E -- No --> F["Sigue esperando<br/>Estado: estaSiendoPresionado"]
    E -- Sí --> G["Avisa: PULSACIÓN LARGA<br/>Significa: ENCENDER o APAGAR"]
    G --> H["Marca la pulsación como usada<br/>para no repetir el aviso"]


    B -- No --> I{"¿Estaba presionado<br/>en el ciclo anterior?"}
    I -- Sí --> J{"¿La pulsación ya fue<br/>usada como larga?"}
    J -- No --> K["Avisa: PULSACIÓN CORTA<br/>Significa: SELECCIONAR nave"]
    J -- Sí --> L["No avisa nada más"]
    K --> M["Estado: noPresionado"]
    L --> M
    I -- No --> M


    D --> A
    F --> A
    H --> A
    M --> A


    classDef inicio fill:#0B3C5D,stroke:#2E7D32,stroke-width:2px,color:#FFF9DB;
    classDef decision fill:#FFD60A,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef proceso fill:#C8E6C9,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef aviso fill:#BFE3F5,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;


    class A inicio;
    class B,C,E,I,J decision;
    class D,F,H,L,M proceso;
    class G,K aviso;


    linkStyle default stroke:#2E7D32,stroke-width:2px;
```


**Botón 2 (volador):** mientras se mantiene presionado la nave sube; al soltarlo, cae.


```mermaid
%%{init: {'theme':'base','themeVariables':{'fontFamily':'Arial','lineColor':'#2E7D32','primaryTextColor':'#0B3C5D'}}}%%
flowchart TD
    A([Ciclo principal llama a update]) --> B{"¿La persona está<br/>presionando el botón?"}


    B -- Sí --> C["Estado: estaSiendoPresionado"]
    C --> D(["La nave SUBE<br/>mientras siga presionado"])


    B -- No --> E{"¿Estaba presionado<br/>en el ciclo anterior?"}
    E -- Sí --> F["Estado: soltado"]
    F --> G["Estado: noPresionado"]
    E -- No --> G
    G --> H(["La nave CAE<br/>por gravedad"])


    D --> A
    H --> A


    classDef inicio fill:#0B3C5D,stroke:#2E7D32,stroke-width:2px,color:#FFF9DB;
    classDef decision fill:#FFD60A,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef proceso fill:#C8E6C9,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef aviso fill:#BFE3F5,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;


    class A inicio;
    class B,E decision;
    class C,F,G proceso;
    class D,H aviso;


    linkStyle default stroke:#2E7D32,stroke-width:2px;
```


</details>


<details>
<summary><b>Diagrama de flujo: perillas</b></summary>


**Perilla izquierda (velocidad del mapa):**


```mermaid
%%{init: {'theme':'base','themeVariables':{'fontFamily':'Arial','lineColor':'#2E7D32','primaryTextColor':'#0B3C5D'}}}%%
flowchart TD
    A([Ciclo principal llama a update]) --> B["Leer valor analógico<br/>de la perilla<br/>0 a 65535"]
    B --> C["Convertir el valor<br/>a velocidad del mapa<br/>mínima a máxima"]
    C --> D{"¿La velocidad cambió<br/>respecto al ciclo anterior?"}
    D -- Sí --> E(["Avisa: nueva velocidad<br/>El mapa avanza más rápido o más lento"])
    D -- No --> F(["No avisa nada nuevo"])
    E --> A
    F --> A


    classDef inicio fill:#0B3C5D,stroke:#2E7D32,stroke-width:2px,color:#FFF9DB;
    classDef decision fill:#FFD60A,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef proceso fill:#C8E6C9,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef aviso fill:#BFE3F5,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;


    class A inicio;
    class D decision;
    class B,C proceso;
    class E,F aviso;


    linkStyle default stroke:#2E7D32,stroke-width:2px;
```


**Perilla derecha (selección de nave):**


```mermaid
%%{init: {'theme':'base','themeVariables':{'fontFamily':'Arial','lineColor':'#2E7D32','primaryTextColor':'#0B3C5D'}}}%%
flowchart TD
    A([Ciclo principal llama a update]) --> B["Leer valor analógico<br/>de la perilla<br/>0 a 65535"]
    B --> C["Dividir el recorrido<br/>en 4 rangos iguales"]
    C --> D{"¿En qué rango<br/>está la perilla?"}
    D -- Rango 1 --> E1["Nave 1"]
    D -- Rango 2 --> E2["Nave 2"]
    D -- Rango 3 --> E3["Nave 3"]
    D -- Rango 4 --> E4["Nave 4"]
    E1 --> F{"¿Cambió la nave<br/>respecto al ciclo anterior?"}
    E2 --> F
    E3 --> F
    E4 --> F
    F -- Sí --> G(["Avisa: nueva nave<br/>Se actualiza el menú"])
    F -- No --> H(["No avisa nada nuevo"])
    G --> A
    H --> A


    classDef inicio fill:#0B3C5D,stroke:#2E7D32,stroke-width:2px,color:#FFF9DB;
    classDef decision fill:#FFD60A,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef proceso fill:#C8E6C9,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef aviso fill:#BFE3F5,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;


    class A inicio;
    class D,F decision;
    class B,C,E1,E2,E3,E4 proceso;
    class G,H aviso;


    linkStyle default stroke:#2E7D32,stroke-width:2px;
```


</details>


## encargos

## lectura
