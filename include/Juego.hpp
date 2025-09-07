#pragma once

#include <SFML/Graphics.hpp>
#include <InterfazUsuario.hpp>

enum class JuegoState {
    EXPEDIENTE, //ingreso
    CIRUGIA,// partida
    FINAL // final
};

class Juego {
private:
    sf::RenderWindow window;
    sf::Font juegoFont;
    InterfazUsuario interfaz;

    Cirugia cirugiaActual;
    JuegoState estadoActual; //guardar el estado en el momento q tiene el juego
public:
    Juego();
    void run();
};