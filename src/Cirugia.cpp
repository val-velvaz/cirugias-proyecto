#include "Cirugia.hpp"

void Cirugia::setNombrePaciente(const std::string& nombre) {
    nombrePaciente = nombre;
}

void Cirugia::setNombreCirujano(const std::string& nombre) {
    nombreCirujano = nombre;
}

void Cirugia::setTipoCirugia(const std::string& tipo) {
    tipoCirugia = tipo;
}

std::string Cirugia::getNombrePaciente() const {
    return nombrePaciente;
}

std::string Cirugia::getNombreCirujano() const {
    return nombreCirujano;
}

std::string Cirugia::getTipoCirugia() const {
    return tipoCirugia;
}