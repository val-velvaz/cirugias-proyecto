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
    pacienteText.setCharacterSize(24);
    pacienteText.setFillColor(sf::Color::White);
    pacienteText.setPosition(110, 145);

    //CIRUJANO
    //nombre
    cirujanoLabel.setFont(font);
    cirujanoLabel.setString("Nombre del Cirujano: ");
    cirujanoLabel.setCharacterSize(24);
    cirujanoLabel.setFillColor(sf::Color::White);
    cirujanoLabel.setPosition(100, 200);

    //caja de texto
    cirujanoBox.setSize(sf::Vector2f(400, 40));
    cirujanoBox.setFillColor(sf::Color(50, 50, 50));
    cirujanoBox.setOutlineColor(sf::Color::White);
    cirujanoBox.setOutlineThickness(2);
    cirujanoBox.setPosition(100, 240);

    //texto
    cirujanoText.setFont(font);
    cirujanoText.setCharacterSize(24);
    cirujanoText.setFillColor(sf::Color::White);
    cirujanoText.setPosition(110, 245);

    //tipo de cirugia
    tipoLabel.setFont(font);
    tipoLabel.setString("Tipo de cirugía: ");
    tipoLabel.setCharacterSize(24);
    tipoLabel.setFillColor(sf::Color::White);
    tipoLabel.setPosition(100, 300);

    tipoSelector.setFont(font);
    tipoSelector.setString(tipoTypes[tipoActual]);
    tipoSelector.setCharacterSize(24);
    tipoSelector.setFillColor(sf::Color::White);
    tipoSelector.setPosition(100, 340);

    //BOTONCITOS
    startBoton.setSize(sf::Vector2f(200, 50));
    startBoton.setFillColor(sf::Color::Green);
    startBoton.setPosition(300, 450);

    textStartBoton.setFont(font);
    textStartBoton.setString("Iniciar cirugia:");
    textStartBoton.setCharacterSize(24);
    textStartBoton.setFillColor(sf::Color::White);
    textStartBoton.setPosition(310, 460);
}

void InterfazUsuario::draw(sf::RenderWindow& window) {
    window.draw(pacienteLabel);
    window.draw(pacienteBox);
    window.draw(pacienteText);

    window.draw(cirujanoLabel);
    window.draw(cirujanoBox);
    window.draw(cirujanoShowText); // es la misma q pacienteText nada mas se me fue el show

    window.draw(tipoLabel);
    window.draw(tipoSelector);
    window.draw(startBoton);
    window.draw(textStartBoton);
}