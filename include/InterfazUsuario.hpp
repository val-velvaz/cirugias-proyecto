#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class InterfazUsuario {
private:
    sf::Font fuente;

    // paciente
    sf::RectangleShape pacienteBox;
    sf::Text pacienteLabel;
    std::string pacienteText;
    sf::Text pacienteShowText;

    // cirujano
    sf::RectangleShape cirujanoBox;
    sf::Text cirujanoLabel;
    std::string cirujanoText;
    sf::Text cirujanoShowText;

    //tipo de cirugia
    sf::RectangleShape tipoBox;
    sf::Text tipoLabel;
    std::vector<std::string> tipoTypes;
    int tipoActual;

    //boton de inicio
    bool pacienteActivo;
    bool cirujanoActivo;
    
public:
    InterfazUsuario();
    void config(const sf::Font& fuenteJuego);
    void draw(sf::RenderWindow& ventana);
    void manejarEntrada(const sf::Event& event);
};