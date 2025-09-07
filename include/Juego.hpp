#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "InterfazUsuario.hpp"
#include "Cirugia.hpp"

enum class JuegoState {
    EXPEDIENTE, //ingreso
    CIRUGIA,// partida
    FINAL, // final
    INFORME 
};

class Juego {
private:
    sf::RenderWindow window;
    sf::Font juegoFont;
    InterfazUsuario interfaz;

    Cirugia cirugiaActual;
    JuegoState estadoActual; //guardar el estado en el momento q tiene el juego

    // cirujano
    sf::Text tituloInforme;
    sf::Text textPaciente;
    sf::Text textCirujano;
    sf::Text textTipoCirugia;
    sf::Text textResultado;
    sf::Text ResetBoton;
    sf::Text textDiagnostico;
    sf::Text textInstrumento;

    sf::RectangleShape areaEsteril;

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
    std::string  getInstrumentoName(Instrumento instrumento);
    Juego();
    void run();
};