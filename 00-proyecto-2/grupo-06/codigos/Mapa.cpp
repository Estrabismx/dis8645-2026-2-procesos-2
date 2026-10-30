#include "mapa.h"
#include "mapa_imagen.h"
#include <cstring>

Mapa::Mapa()
    : desplazamientoX(0),
      intervaloMs(INTERVALO_INICIAL_MS),
      ultimoPasoMs(0)
{
}

void Mapa::iniciar()
{
    desplazamientoX = 0;
    ultimoPasoMs = to_ms_since_boot(get_absolute_time());
}

void Mapa::reiniciar()
{
    iniciar();
}

void Mapa::setIntervaloMs(uint32_t ms)
{
    if (ms == 0)
    {
        ms = 1; // evita dividir por cero
    }
    intervaloMs = ms;
}

bool Mapa::actualizar()
{
    uint32_t ahora = to_ms_since_boot(get_absolute_time());

    // cuántos pixeles tocaba avanzar desde la última vez
    uint32_t pasos = (ahora - ultimoPasoMs) / intervaloMs;

    if (pasos == 0)
    {
        return false;
    }

    // el % hace que al pasar del pixel 599 vuelva al 0 (bucle infinito)
    desplazamientoX = (desplazamientoX + (int)pasos) % ANCHO_TOTAL;

    // avanzamos la referencia solo lo que "gastamos", para no perder tiempo sobrante
    ultimoPasoMs += pasos * intervaloMs;
    return true;
}

int Mapa::desplazamiento() const
{
    return desplazamientoX;
}

bool Mapa::pixelEncendido(int xPantalla, int y) const
{
    // fuera de la pantalla no hay nada que choque
    if (xPantalla < 0 || xPantalla >= ANCHO || y < 0 || y >= ALTO)
    {
        return false;
    }

    int col = (desplazamientoX + xPantalla) % ANCHO_TOTAL;
    return mapa_completo[y * BYTES_POR_FILA + col / 8] & (0x80 >> (col % 8));
}

void Mapa::dibujar(uint8_t* buffer) const
{
    memset(buffer, 0, BYTES_BUFFER);

    // recorremos cada columna de la pantalla (0 a 127)
    for (int sx = 0; sx < ANCHO; sx++)
    {
        // columna correspondiente dentro de la imagen larga (con vuelta al inicio)
        int col = (desplazamientoX + sx) % ANCHO_TOTAL;

        int byteColumna = col / 8;          // qué byte de la fila
        uint8_t mascara = 0x80 >> (col % 8); // qué bit (el más alto es el de la izquierda)

        for (int y = 0; y < ALTO; y++)
        {
            if (mapa_completo[y * BYTES_POR_FILA + byteColumna] & mascara)
            {
                // la imagen viene por filas; la OLED pide por páginas de 8 px verticales
                buffer[(y / 8) * ANCHO + sx] |= (1 << (y % 8));
            }
        }
    }
}