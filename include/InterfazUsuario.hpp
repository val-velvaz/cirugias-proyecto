#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Cirugia.hpp"

class InterfazUsuario {
private:
    sf::Font font;


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

    bool pressBoton; //presionar para iniciar

public:
    InterfazUsuario();

    bool getPressBoton() const; //mejor nombre
    Cirugia getDatosCirugia() const;
    void resetBoton();

    void config(const sf::Font& juegoFont);
    void draw(sf::RenderWindow& ventana);
    void manejarEntrada(const sf::Event& event);
};