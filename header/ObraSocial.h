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
    ObraSocial(int codigo, const char* nombre, bool estado = true);

    // Setters
    bool setCodigoObraSocial(int codigo);
    bool setNombre(const char* nombre);
    void setEstado(bool estado);

    // Getters
    int getCodigoObraSocial();
    const char* getNombre();
    bool getEstado();
};

