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
                //arrastrar y soltar creo
                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                    // creo q seria mejor hacer una funcion en vez de todos estos ifs
                    if (bisturiSprite.getGlobalBounds().contains(mousePos)) {
                        isBisturiDragged = true;
                    }
                    if (tijerasSprite.getGlobalBounds().contains(mousePos)) {
                        isTijerasDragged = true;
                    }
                    if (alicateSprite.getGlobalBounds().contains(mousePos)) {
                        isAlicateDragged = true;
                    }
                    if (pinzasSprite.getGlobalBounds().contains(mousePos)) {
                        isPinzaDragged = true;
                    }
                }
            }
            if (event.type == sf::Event::MouseMoved) {
                if (isBisturiDragged) {
                    bisturiSprite.setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
                }
                if (isTijerasDragged) {
                    tijerasSprite.setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
                }
                if (isAlicateDragged) {
                    alicateSprite.setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
                }
                if (isPinzaDragged) {
                    pinzasSprite.setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
                }
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    isBisturiDragged = false;
                    isTijerasDragged = false;
                    isAlicateDragged = false;
                    isPinzaDragged = false;
                }
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