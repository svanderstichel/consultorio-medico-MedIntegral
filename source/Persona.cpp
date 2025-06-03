#include <iostream>
#include <cstring>
#include "Persona.h"

//constructores
Persona::Persona(){
    FechaHora fechaNacimiento;
    setDni(1000000);
    setApellido("");
    setNombre("");
    setTelefono("");
    setEmail("");
    setFechaNacimiento(fechaNacimiento);
    setEstado(true);
}

Persona::Persona(int dni,std::string apellido,std::string nombre,std::string telefono,std::string email,FechaHora fechaNacimiento,bool estado){
    setDni(dni);
    setApellido(apellido);
    setNombre(nombre);
    setTelefono(telefono);
    setEmail(email);
    setFechaNacimiento(fechaNacimiento);
    setEstado(estado);
}

///getters
int Persona::getDni(){
    return _dni;
}
std::string Persona::getApellido(){
    return _apellido;
}
std::string Persona::getNombre(){
    return _nombre;
}
std::string Persona::getTelefono(){
    return _telefono;
}
std::string Persona::getEmail(){
    return _email;
}
FechaHora Persona::getFechaNacimiento(){
    return _fechaNacimiento;
}
bool Persona::getEstado(){
    return _estado;
}

///setters
bool Persona::setDni(int dni){
    if(dni<1000000 || dni>99999999){
        std::cout << "\nDNI invalido (fuera de rango).\n";
        return false;
    }
    _dni = dni;
    return true;
}

bool Persona::setApellido(std::string apellido){
    if(apellido.size()+1>50){
        std::cout << "\nApellido invalido (excede max. caracteres).\n";
        return false;
    }
    strcpy(_apellido,apellido.c_str());
    return true;
}

bool Persona::setNombre(std::string nombre){
    if(nombre.size()+1>50){
        std::cout << "\nNombre invalido (excede max. caracteres).\n";
        return false;
    }
    strcpy(_nombre,nombre.c_str());
    return true;
}
bool Persona::setTelefono(std::string telefono){
    if(telefono.size()+1>50){
        std::cout << "\nTelefono invalido (excede max. caracteres).\n";
        return false;
    }
    strcpy(_telefono,telefono.c_str());
    return true;
}
bool Persona::setEmail(std::string email){
    if(email.size()+1>50){
        std::cout << "\nEmail invalido (excede max. caracteres).\n";
        return false;
    }
    strcpy(_email,email.c_str());
    return true;
}
void Persona::setEstado(bool estado){
    _estado = estado;
}
void Persona::setFechaNacimiento(FechaHora fechaNacimiento){
    _fechaNacimiento = fechaNacimiento;
}

