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

    sf::Texture bisturiTexture;
    sf::Texture pinzasTexture;
    sf::Texture alicateTexture;
    sf::Texture tijerasTexture;

    sf::Sprite bisturiSprite;
    sf::Sprite pinzasSprite;
    sf::Sprite alicateSprite;
    sf::Sprite tijerasSprite;

    bool isBisturiDragged;
    bool isPinzaDragged;
    bool isTijerasDragged;
    bool isAlicateDragged;
    
public:
    Juego();
    void run();
};