#include "InterfazUsuario.hpp"

InterfazUsuario::InterfazUsuario() {
    pacienteActivo = false;
    cirujanoActivo = false;
    tipoActual = 0;
    tipoTypes = {"Apendicectomía", "Transplante de riñon", "Cirugía láser"};
}

void InterfazUsuario::config(const sf::Font& juegoFont) {
    font = juegoFont;
    
    // PACIENTE
    //nombre
    pacienteLabel.setFont(font);
    pacienteLabel.setString("Nombre del Paciente: ");
    pacienteLabel.setCharacterSize(24);
    pacienteLabel.setFillColor(sf::Color::White);
    pacienteLabel.setPosition(100, 100);

    //caja de texto (Creo)
    pacienteBox.setSize(sf::Vector2f(400, 40));
    pacienteBox.setFillColor(sf::Color(50, 50, 50));
    pacienteBox.setOutlineColor(sf::Color::White);
    pacienteBox.setOutlineThickness(2); // en px
    pacienteBox.setPosition(100, 140);

    // texto
    pacienteText.setFont(font);

}