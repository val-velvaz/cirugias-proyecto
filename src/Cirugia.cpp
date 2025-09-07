#include "Cirugia.hpp"

Cirugia::Cirugia() {    
}

void Cirugia::setNombrePaciente(const std::string& nombre) {
    this->nombrePaciente = nombre;
}

void Cirugia::setNombreCirujano(const std::string& nombre) {
    this->nombreCirujano = nombre;
}

void Cirugia::setTipoCirujia(const std::string& tipo) {
    this->tipoCirugia = tipo;
}

std::string Cirugia::getNombrePaciente() const {
    return nombrePaciente;
}

std::string Cirugia::getNombreCirujano() const {
    return nombreCirujano;
}

std::string Cirugia::getTipoCirujia() const {
    return tipoCirugia;
}