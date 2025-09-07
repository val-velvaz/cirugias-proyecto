#include "Juego.hpp" //pendiente: cambiarlo por game

Juego::Juego() {
    window.create(sf::VideoMode(800, 600), "A Contrarreloj c:");
    // agregar la fuente
    if (!juegoFont.loadFromFile("arial.ttf")) {
        window.close();
    }
    if (!bisturiTexture.loadFromFile("assets/textures/bisturi.png") ||
        !alicateTexture.loadFromFile("assets/textures/alicate.png") ||
        !pinzasTexture.loadFromFile("assets/textures/pinzas.png") ||
        !tijerasTexture.loadFromFile("assets/textures/tijeras.png")
        ) {
            window.close();
        } 
    
    bisturiSprite.setTexture(bisturiTexture);
    bisturiSprite.setPosition(150, 400);
    alicateSprite.setTexture(alicateTexture);
    alicateSprite.setPosition(250, 400);
    pinzasSprite.setTexture(pinzasTexture);
    pinzasSprite.setPosition(350, 400);
    tijerasSprite.setTexture(tijerasTexture);
    tijerasSprite.setPosition(450, 400);

    interfaz.config(juegoFont);
    estadoActual = JuegoState::EXPEDIENTE;
}

void Juego::run() {
    // game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (estadoActual == JuegoState::EXPEDIENTE) {
                interfaz.manejarEntrada(event);

                if(interfaz.getPressBoton()) {
                    estadoActual = JuegoState::CIRUGIA;
                    cirugiaActual = interfaz.getDatosCirugia();
                    interfaz.resetBoton();
                }
            } else if (estadoActual == JuegoState::CIRUGIA) {

            }

        }
        window.clear(sf::Color::Black); 
        if(estadoActual == JuegoState::EXPEDIENTE) {
        interfaz.draw(window);
        } else if (estadoActual == JuegoState::CIRUGIA) {
            window.draw(bisturiSprite);
            window.draw(pinzasSprite);
            window.draw(tijerasSprite);
            window.draw(alicateSprite);
        }
        window.display();
    }
}