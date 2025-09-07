#include "Juego.hpp"

Juego::Juego() {
    window.create(sf::VideoMode(800, 600), "A Contrarreloj c:");
}

void Juego::run() {
    // game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        //window.clear();
        window.clear(sf::Color(173, 216, 230)); // prueba 
        window.display();
    }
}