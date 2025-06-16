#pragma once
#include <string>

class ObraSocial {
private:
    int _codigoObraSocial;
    char _nombre[50];
    bool _estado;

public:
    // Constructores
    ObraSocial();
    ObraSocial(int codigo, std::string nombre, bool estado = true);

    // Setters
    bool setCodigoObraSocial(int codigo);
    bool setNombre(std::string nombre);
    void setEstado(bool estado);

    // Getters
    int getCodigoObraSocial();
    std::string getNombre();
    bool getEstado();
};

