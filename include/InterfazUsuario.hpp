#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class InterfazUsuario {
private:
    sf::Font font;

    // paciente
    sf::RectangleShape pacienteBox;
    sf::Text pacienteLabel;
    std::string pacienteText; // <-- Aquí se guarda la cadena de texto
    sf::Text pacienteShowText; // <-- Aquí se renderiza la cadena de texto

    // cirujano
    sf::RectangleShape cirujanoBox;
    sf::Text cirujanoLabel;
    std::string cirujanoText; // <-- Aquí se guarda la cadena de texto
    sf::Text cirujanoShowText; // <-- Aquí se renderiza la cadena de texto

    //tipo de cirugia
    sf::Text tipoLabel;
    sf::Text tipoSelector;
    std::vector<std::string> tipoTypes;
    int tipoActual;

    //boton de inicio
    sf::RectangleShape startBoton;
    sf::Text textStartBoton;

    //ESTADO DE LOS CAMPOS
    bool pacienteActivo;
    bool cirujanoActivo;

public:
    InterfazUsuario();
    void config(const sf::Font& juegoFont);
    void draw(sf::RenderWindow& ventana);
    void manejarEntrada(const sf::Event& event);
};