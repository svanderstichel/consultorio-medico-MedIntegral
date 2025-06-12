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
ObraSocial::ObraSocial(int codigo, std::string nombre, bool estado) {
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

bool ObraSocial::setNombre(std::string nombre) {
    if (nombre.size() == 0){
        std::cout << "Nombre de obra social no puede estar vacio.\n";
        return false;}
    if(nombre.size()+1>50){
        std::cout << "Caracteres maximos excedidos (50).\n";
        return false;}
    strcpy(_nombre,nombre.c_str());
    return true;
}

void ObraSocial::setEstado(bool estado) {
    _estado = estado;
}

/// Getters
int ObraSocial::getCodigoObraSocial() {
    return _codigoObraSocial;
}

std::string ObraSocial::getNombre() {
    return _nombre;
}

bool ObraSocial::getEstado() {
    return _estado;
}
