#pragma once

#include <SFML/Graphics.hpp>
#include <InterfazUsuario.hpp>
#include <iostream>
#include <string>

enum class JuegoState {
    EXPEDIENTE,
    CIRUGIA,
    FINAL,
    INFORME
};


class Juego {
private:
    sf::RenderWindow window;
    sf::Font juegoFont;
    InterfazUsuario interfaz;

    Cirugia cirugiaActual;
    JuegoState estadoActual;

    // Textos del informe final
    sf::Text tituloInforme;
    sf::Text textPaciente;
    sf::Text textCirujano;
    sf::Text textTipoCirugia;
    sf::Text textResultado;
    sf::Text ResetBoton;
    sf::Text textDiagnostico;
    sf::Text textInstrumento;

    // Zona de colision
    sf::RectangleShape areaEsteril;

    // Texturas
    sf::Texture bisturiTexture;
    sf::Texture pinzasTexture;
    sf::Texture alicateTexture;
    sf::Texture tijerasTexture;

    // Sprites
    sf::Sprite bisturiSprite;
    sf::Sprite pinzasSprite;
    sf::Sprite alicateSprite;
    sf::Sprite tijerasSprite;

    // Flags para arrastrar y soltar
    bool isBisturiDragged;
    bool isPinzaDragged;
    bool isTijerasDragged;
    bool isAlicateDragged;

public:
    std::string getInstrumentoName(Instrumento instrumento);
    Juego();
    void run();
};