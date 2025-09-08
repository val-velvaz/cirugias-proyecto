#include "Juego.hpp"

Juego::Juego() {
    window.create(sf::VideoMode(800, 600), "A Contrarreloj c:");
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

    tituloInforme.setFont(juegoFont);
    tituloInforme.setString("INFORME DE CIRUGIA");
    tituloInforme.setCharacterSize(40);
    tituloInforme.setFillColor(sf::Color::White);
    tituloInforme.setPosition(150, 50);

    textPaciente.setFont(juegoFont);
    textPaciente.setString("Paciente: ");
    textPaciente.setCharacterSize(30);
    textPaciente.setFillColor(sf::Color::White);
    textPaciente.setPosition(150, 20);
    
    textDiagnostico.setFont(juegoFont);
    textDiagnostico.setCharacterSize(24);
    textDiagnostico.setFillColor(sf::Color::White);
    textDiagnostico.setPosition(50, 50);

    textInstrumento.setFont(juegoFont);
    textInstrumento.setCharacterSize(24);
    textInstrumento.setFillColor(sf::Color::Red);
    textInstrumento.setPosition(50, 80);

    areaEsteril.setSize(sf::Vector2f(200, 200));
    areaEsteril.setFillColor(sf::Color(0, 255, 0, 100));
    areaEsteril.setPosition(300, 200);

    bisturiSprite.setTexture(bisturiTexture);
    bisturiSprite.setPosition(100, 400);
    alicateSprite.setTexture(alicateTexture);
    alicateSprite.setPosition(250, 400);
    pinzasSprite.setTexture(pinzasTexture);
    pinzasSprite.setPosition(400, 400);
    tijerasSprite.setTexture(tijerasTexture);
    tijerasSprite.setPosition(550, 400);

    textResultado.setFont(juegoFont);
    textResultado.setCharacterSize(30);
    textResultado.setFillColor(sf::Color::Yellow);
    textResultado.setPosition(50, 400);

    interfaz.config(juegoFont);
    estadoActual = JuegoState::EXPEDIENTE;

    // AÑADIDO: Inicializar las banderas de arrastre
    isBisturiDragged = false;
    isPinzaDragged = false;
    isTijerasDragged = false;
    isAlicateDragged = false;
}

void Juego::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                std::cout << "la ventana ha sido cerrada" << std::endl;
                window.close();
            }
            if (estadoActual == JuegoState::EXPEDIENTE) {
                interfaz.manejarEntrada(event);
                if(interfaz.getPressBoton()) {
                    estadoActual = JuegoState::CIRUGIA;
                    cirugiaActual = interfaz.getDatosCirugia();
                    interfaz.resetBoton();
                    textDiagnostico.setString("Diagnostico: " + cirugiaActual.getDiagnostico());
                    textInstrumento.setString("Instrumento: " + getInstrumentoName(cirugiaActual.getInstrumentoNeeded()));
                    std::cout << "DATOS DE LA CIRUGIA" << std::endl;
                    std::cout << "Paciente: " << cirugiaActual.getNombrePaciente() << std::endl;
                    std::cout << "Cirujano: " << cirugiaActual.getNombreCirujano() << std::endl;
                    std::cout << "Tipo de cirugia: " << cirugiaActual.getTipoCirugia() << std::endl;
                    std::cout << "Diagnostico: " << cirugiaActual.getDiagnostico() << std::endl;
                    std::cout << "Instrumento necesario: " << getInstrumentoName(cirugiaActual.getInstrumentoNeeded()) << std::endl;
                }
            } else if (estadoActual == JuegoState::CIRUGIA) {
                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                    if (bisturiSprite.getGlobalBounds().contains(mousePos)) {
                        isBisturiDragged = true;
                        std::cout << "Bisturi tomado" << std::endl;
                    }
                    else if (tijerasSprite.getGlobalBounds().contains(mousePos)) {
                        isTijerasDragged = true;
                        std::cout << "Tijeras tomadas" << std::endl;
                    }
                    else if (alicateSprite.getGlobalBounds().contains(mousePos)) {
                        isAlicateDragged = true;
                        std::cout << "Alicate tomado" << std::endl;
                    }
                    else if (pinzasSprite.getGlobalBounds().contains(mousePos)) {
                        isPinzaDragged = true;
                        std::cout << "Pinza tomada" << std::endl;
                    }
                }
                if (event.type == sf::Event::MouseMoved) {
                    if (isBisturiDragged) {
                        bisturiSprite.setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
                    }
                    else if (isTijerasDragged) {
                        tijerasSprite.setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
                    }
                    else if (isAlicateDragged) {
                        alicateSprite.setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
                    }
                    else if (isPinzaDragged) {
                        pinzasSprite.setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
                    }
                }
                if (event.type == sf::Event::MouseButtonReleased) {
                    if(event.mouseButton.button == sf::Mouse::Left) {
                        if (isBisturiDragged) {
                            if (bisturiSprite.getGlobalBounds().intersects(areaEsteril.getGlobalBounds())) {
                                std::cout << "Bisturi soltado" << std::endl;
                                estadoActual = JuegoState::INFORME;
                            } else {
                                textResultado.setString("Instrumento incorrecto. Se necesita un " + getInstrumentoName(cirugiaActual.getInstrumentoNeeded()));
                                estadoActual = JuegoState::INFORME;
                            }
                        } else if (isTijerasDragged) {
                            if (tijerasSprite.getGlobalBounds().intersects(areaEsteril.getGlobalBounds())) {
                                std::cout << "tijeras soltadas" << std::endl;
                                estadoActual = JuegoState::INFORME;
                            } else {
                                textResultado.setString("Instrumento incorrecto. Se necesita un " + getInstrumentoName(cirugiaActual.getInstrumentoNeeded()));
                                estadoActual = JuegoState::INFORME;
                            }
                        } else if (isAlicateDragged) {
                            if (alicateSprite.getGlobalBounds().intersects(areaEsteril.getGlobalBounds())) {
                                std::cout << "alicate soltado" << std::endl;
                                estadoActual = JuegoState::INFORME;
                            } else { 
                                textResultado.setString("Instrumento incorrecto. Se necesita un " + getInstrumentoName(cirugiaActual.getInstrumentoNeeded()));
                                estadoActual = JuegoState::INFORME;
                            }
                        } else if (isPinzaDragged) {
                            if (pinzasSprite.getGlobalBounds().intersects(areaEsteril.getGlobalBounds())) {
                                std::cout << "pinza soltadoa" << std::endl;
                                estadoActual = JuegoState::INFORME;
                            } else {
                                textResultado.setString("Instrumento incorrecto. Se necesita un " + getInstrumentoName(cirugiaActual.getInstrumentoNeeded()));
                                estadoActual = JuegoState::INFORME;
                            }
                        }
                        isBisturiDragged = false;
                        isTijerasDragged = false;
                        isAlicateDragged = false;
                        isPinzaDragged = false;
                    }
                }
            }
        }
        window.clear(sf::Color::Black); 
        if(estadoActual == JuegoState::EXPEDIENTE) {
            interfaz.draw(window);
        } else if (estadoActual == JuegoState::CIRUGIA) {
            window.draw(textDiagnostico);
            window.draw(textInstrumento);
            window.draw(areaEsteril);
            window.draw(bisturiSprite);
            window.draw(pinzasSprite);
            window.draw(tijerasSprite);
            window.draw(alicateSprite);
        } else if (estadoActual == JuegoState::INFORME) {
            window.draw(textResultado);
            std::cout << "estado INFORME" << std::endl;
            // Agrega aquí los otros textos del informe que quieras mostrar
        }
        window.display();
    }
}

std::string Juego::getInstrumentoName(Instrumento instrumento) {
    switch (instrumento) {
        case Instrumento::BISTURI: return "Bisturi";
        case Instrumento::ALICATE: return "Alicate";
        case Instrumento::TIJERAS: return "Tijeras";
        case Instrumento::PINZAS: return "Pinzas";
        case Instrumento::NINGUNO: return "ninguno";
    }
    return "desconocido";
}