#include <iostream>
#include <cstring>
#include "Especialidad.h"

///constructores
Especialidad::Especialidad(){
    setCodEspecialidad(0);
    setEstado(true);
    strcpy(_nombre, "");
}

Especialidad::Especialidad(int codEspecialidad,std::string nombre,bool estado){
    setCodEspecialidad(codEspecialidad);
}

///getters
int Especialidad::getCodEspecialidad(){
    return _codEspecialidad;
}
bool Especialidad::getEstado() {
    return _estado;
}
std::string Especialidad::getNombre(){
    return _nombre;
}
///setters
void Especialidad::setCodEspecialidad(int codEspecialidad){
    if(codEspecialidad < 0){
        std::cout << "Código ingresado incorrecto. No puede ser negativo";
        return;
    }
    _codEspecialidad = codEspecialidad;
}
bool Especialidad::setNombre(std::string nombre){
    if(nombre.size()+1>50){
        std::cout << "\nNombre invalido (excede max. caracteres).\n";
        return false;}
    if (nombre.size() == 0){
        std::cout << "Nombre de especialidad no puede estar vacio.\n";
        return false;}
    strcpy(_nombre,nombre.c_str());
    return true;
}
void Especialidad::setEstado(bool estado) {
    _estado = estado;
}
