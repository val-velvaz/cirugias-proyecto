#pragma once

#include <string>
#include <vector>

class Cirugia {
private:
    std::string nombrePaciente;
    std::string nombreCirujano;
    std::string tipoCirugia;

public:
    Cirugia();

    void setNombrePaciente(const std::string& nombre);
    void setNombreCirujano(const std::string& nombre);
    void setTipoCirugia(const std::string& nombre);

    std::string getNombrePaciente() const;
    std::string getNombreCirujano() const;
    std::string getTipoCirugia() const;
};