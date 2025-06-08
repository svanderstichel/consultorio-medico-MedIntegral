#include "ObraSocial.h"
#include <iostream>
#include <cstring>

/// Constructor por defecto
ObraSocial::ObraSocial() {
    _codigoObraSocial = 0;
     strcpy(_nombre, "");
    _estado = true;
}

/// Constructor con parámetros
ObraSocial::ObraSocial(int codigo, const char* nombre, bool estado) {
    setCodigoObraSocial(codigo);
    setNombre(nombre);
    setEstado(estado);
}

/// Setters
bool ObraSocial::setCodigoObraSocial(int codigo) {
    if (codigo <= 0) {
        std::cout << "Código de obra social inválido.\n";
        return false;
    }
    _codigoObraSocial = codigo;
    return true;
}

bool ObraSocial::setNombre(const char* nombre) {
    if (strlen(nombre) == 0) {
        std::cout << "Nombre de obra social no puede estar vacío.\n";
        return false;
    }
    strcpy(_nombre, nombre);
    return true;
}

void ObraSocial::setEstado(bool estado) {
    _estado = estado;
}

/// Getters
int ObraSocial::getCodigoObraSocial() {
    return _codigoObraSocial;
}

const char* ObraSocial::getNombre() {
    return _nombre;
}

bool ObraSocial::getEstado() {
    return _estado;
}
