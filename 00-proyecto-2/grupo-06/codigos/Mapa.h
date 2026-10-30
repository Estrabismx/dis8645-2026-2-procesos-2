#ifndef MAPA_H
#define MAPA_H

#include <cstdint>
#include "pico/stdlib.h"

// Clase que muestra el mapa (una imagen de 600x64 px) avanzando de corrido
// hacia la izquierda. Al llegar al final vuelve al principio sin corte.
//
// La pantalla es una "ventana" de 128 px que se desliza por la imagen larga.
class Mapa
{
  public:
    static const int ANCHO = 128;                  // ancho de la pantalla
    static const int ALTO = 64;
    static const int ANCHO_TOTAL = 600;            // ancho de la imagen completa
    static const int BYTES_POR_FILA = ANCHO_TOTAL / 8;  // 75 bytes por fila de la imagen
    static const int BYTES_BUFFER = ANCHO * (ALTO / 8); // 1024 bytes (formato SSD1306)

    // constructor
    Mapa();

    // deja el mapa en el inicio; se llama al empezar el juego
    void iniciar();

    // avanza el mapa según el tiempo que pasó; se llama en CADA vuelta del loop.
    // devuelve true si el mapa se movió (o sea, hay que redibujar)
    bool actualizar();

    // cuántos milisegundos tarda el mapa en avanzar 1 px.
    // la velocidad real la decide la clase Perilla (otro grupo); aquí
    // solo se recibe el número ya calculado
    void setIntervaloMs(uint32_t ms);

    // vuelve al inicio del mapa (por ejemplo, al reiniciar tras un choque)
    void reiniciar();

    // dibuja la ventana actual del mapa dentro del framebuffer de la OLED SSD1306
    // (formato por páginas: 128 x 8 páginas = 1024 bytes)
    void dibujar(uint8_t* buffer) const;

    // posición actual de la ventana dentro de la imagen larga (0 a 599)
    int desplazamiento() const;

    // true si el pixel de la PANTALLA (x de 0 a 127, y de 0 a 63) está encendido
    // en el mapa; sirve para detectar choques con los planetas
    bool pixelEncendido(int xPantalla, int y) const;

  private:
    int desplazamientoX;     // dónde empieza la ventana dentro de los 600 px
    uint32_t intervaloMs;    // ms por cada pixel que avanza
    uint32_t ultimoPasoMs;   // referencia de tiempo del último avance

    static const uint32_t INTERVALO_INICIAL_MS = 30;
};

#endif