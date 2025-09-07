#include "InterfazUsuario.hpp"

InterfazUsuario::InterfazUsuario() {
    pacienteActivo = false;
    cirujanoActivo = false;
    tipoActual = 0;
    tipoTypes = {"Apendicectomia", "Transplante de riñon", "Cirugia laser"};
    pressBoton = false;
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
    pacienteShowText.setFont(font);
    pacienteShowText.setCharacterSize(24);
    pacienteShowText.setFillColor(sf::Color::White);
    pacienteShowText.setPosition(110, 145);

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
    cirujanoShowText.setFont(font);
    cirujanoShowText.setCharacterSize(24);
    cirujanoShowText.setFillColor(sf::Color::White);
    cirujanoShowText.setPosition(110, 245);

    //tipo de cirugia
    tipoLabel.setFont(font);
    tipoLabel.setString("Tipo de cirugia: ");
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
    window.draw(pacienteShowText);

    window.draw(cirujanoLabel);
    window.draw(cirujanoBox);
    window.draw(cirujanoShowText);

    window.draw(tipoLabel);
    window.draw(tipoSelector);
    window.draw(startBoton);
    window.draw(textStartBoton);
}

// maybe luego le cambio el nombre porque "manejarEntrada" suena raro
void InterfazUsuario::manejarEntrada(const sf::Event& event) {
    // los clics
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mousePos = {static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)};
        pacienteActivo = pacienteBox.getGlobalBounds().contains(mousePos); //pacientito
        cirujanoActivo = cirujanoBox.getGlobalBounds().contains(mousePos); //cirujanito

        if (startBoton.getGlobalBounds().contains(mousePos)) {
            pressBoton = true;
        }

        if (pacienteActivo) pacienteBox.setOutlineColor(sf::Color::Blue);
        else pacienteBox.setOutlineColor(sf::Color::White);

        if (cirujanoActivo) cirujanoBox.setOutlineColor(sf::Color::Blue);
        else cirujanoBox.setOutlineColor(sf::Color::White);
    }
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128) { //ascii
            if (pacienteActivo) {
                if (event.text.unicode == '\b' && !pacienteText.empty()) {
                    pacienteText.pop_back();
                } else if (event.text.unicode != '\b' && pacienteText.length() < 25) {
                    pacienteText += static_cast<char>(event.text.unicode);
                }
                pacienteShowText.setString(pacienteText);
            } else if (cirujanoActivo) {
                if (event.text.unicode == '\b' && !cirujanoText.empty()) {
                    cirujanoText.pop_back();
                } else if (event.text.unicode != '\b' && cirujanoText.length() < 25) {
                    cirujanoText += static_cast<char>(event.text.unicode);
                }
                cirujanoShowText.setString(cirujanoText);
            }
        }
    }
}

bool InterfazUsuario::getPressBoton() const {
    return this->pressBoton;
}

Cirugia InterfazUsuario::getDatosCirugia() const {
    Cirugia newCirugia;
    newCirugia.setNombreCirujano(this->cirujanoText);
    newCirugia.setNombrePaciente(this->pacienteText);
    newCirugia.setTipoCirugia(this->tipoTypes[this->tipoActual]);
    return newCirugia;
}