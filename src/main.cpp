#include <SFML/Graphics.hpp>
#include <iostream> 
#include "Cirugia.hpp"
#include "InterfazUsuario.hpp"
#include "Juego.hpp"

int main() {
    //probar para Cirugia
    Cirugia miCirugia; 
    miCirugia.setNombrePaciente("Paciente X");
    miCirugia.setNombreCirujano("Dr. Smith");
    miCirugia.setTipoCirugia("Apendicectomia"); 

    std::cout << "Paciente: " << miCirugia.getNombrePaciente() << std::endl;
    std::cout << "Cirujano: " << miCirugia.getNombreCirujano() << std::endl;
    std::cout << "Tipo de cirugia: " << miCirugia.getTipoCirugia() << std::endl; 
    
    return 0;
}