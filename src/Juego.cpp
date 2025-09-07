#include "Juego.hpp" //pendiente: cambiarlo por game

Juego::Juego() {
    window.create(sf::VideoMode(800, 600), "A Contrarreloj c:");
    // agregar la fuente
    if (!juegoFont.loadFromFile("arial.ttf")) {
        window.close();
    }
    interfaz.config(juegoFont);
}

void Juego::run() {
    // game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            interfaz.manejarEntrada(event);
        }
        //window.clear();
        window.clear(sf::Color(sf::Color::Black)); // prueba 
        interfaz.draw(window);
        window.display();
    }
}