#pragma once

#include <SFML/Graphics.hpp>
#include <InterfazUsuario.hpp>

class Juego {
private:
    sf::RenderWindow window;
    sf::Font juegoFont;
    InterfazUsuario interfaz;

public:
    Juego();
    void run();
};