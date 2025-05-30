#include <iostream>
#include <cstring>
#include "Persona.h"

//constructores
Persona::Persona(){
    setDni(1000000);
    setApellido("");
    setNombre("");
    setTelefono("");
    setEmail("");
    setEstado(true);
}

Persona::Persona(int dni,std::string apellido,std::string nombre,std::string telefono,std::string email,bool estado){
    setDni(dni);
    setApellido(apellido);
    setNombre(nombre);
    setTelefono(telefono);
    setEmail(email);
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
bool Persona::getEstado(){
    return _estado;
}

///setters
void Persona::setDni(int dni){
    if(dni<1000000 || dni>99999999){
        std::cout << "\nDNI invalido (fuera de rango).\n";
        system("pause");
        return;
    }
    _dni = dni;
}

void Persona::setApellido(std::string apellido){
    if(apellido.size()+1>50){
        std::cout << "\nApellido invalido (excede max. caracteres).\n";
        system("pause");
        return;
    }
    strcpy(_apellido,apellido.c_str());
}

void Persona::setNombre(std::string nombre){
    if(nombre.size()+1>50){
        std::cout << "\nNombre invalido (excede max. caracteres).\n";
        system("pause");
        return;
    }
    strcpy(_nombre,nombre.c_str());
}
void Persona::setTelefono(std::string telefono){
    if(telefono.size()+1>50){
        std::cout << "\nTelefono invalido (excede max. caracteres).\n";
        system("pause");
        return;
    }
    strcpy(_telefono,telefono.c_str());
}
void Persona::setEmail(std::string email){
    if(email.size()+1>50){
        std::cout << "\nEmail invalido (excede max. caracteres).\n";
        system("pause");
        return;
    }
    strcpy(_email,email.c_str());
}
void Persona::setEstado(bool estado){
    _estado = estado;
}
