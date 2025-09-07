// src/main.cpp
#include <SFML/Graphics.hpp>
#include <iostream> 

#include "Cirugia.cpp"
#include "InterfazUsuario.hpp"
#include "Juego.hpp"

int main() {
    // probar Cirugia
    Cirugia m_Cirugia;
    m_Cirugia.setNombrePaciente("Paciente X");
    m_Cirugia.setNombreCirujano("Dr. Smith");
    m_Cirugia.setNombreCirujano("Apendicectomía");

    std::cout << "Paciente: " << m_Cirugia.getNombrePaciente() << std::endl;
    std::cout << "Cirujano: " << m_Cirugia.getNombreCirujano() << std::endl;
    std::cout << "Tipo de cirugia: " << m_Cirugia.getTipoCirujia() << std::endl;
    
    return 0;
};