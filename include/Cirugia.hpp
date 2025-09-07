#pragma once

#include <string>
#include <vector>

enum class Instrumento {
    BISTURI,
    PINZAS,
    TIJERAS,
    ALICATE,
    NINGUNO
};

class Cirugia {
private:
    std::string nombrePaciente;
    std::string nombreCirujano;
    std::string tipoCirugia;
    std::string diagnostico;
    Instrumento instrumentoNeeded;

public:
//te voy a cambiar, te molesta?
    Cirugia() : nombrePaciente(""), nombreCirujano(""), tipoCirugia(""), diagnostico(""), instrumentoNeeded(Instrumento::NINGUNO) {}
    Cirugia(const std::string& paciente, const std::string& diag, Instrumento instrumento)
    : nombrePaciente(paciente), diagnostico(diag), instrumentoNeeded(instrumento) {}

    void setNombrePaciente(const std::string& nombre);
    void setNombreCirujano(const std::string& nombre);
    void setTipoCirugia(const std::string& nombre);

    std::string getNombrePaciente() const;
    std::string getNombreCirujano() const;
    std::string getTipoCirugia() const;
    std::string getDiagnostico() const {return diagnostico; }
    Instrumento getInstrumentoNeeded() const {return instrumentoNeeded; }
};