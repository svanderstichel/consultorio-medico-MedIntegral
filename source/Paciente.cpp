#include <iostream>
#include "Paciente.h"

///constructores
Paciente::Paciente():Persona(){
    FechaHora fechaNacimiento;
    setCodObraSocial(0);
    setFechaNacimiento(fechaNacimiento);
}

Paciente::Paciente(int dni,std::string apellido,std::string nombre,std::string telefono,std::string email,bool estado, int codObraSocial,FechaHora fechaNacimiento):Persona(dni,apellido,nombre,telefono,email,estado){
    setCodObraSocial(codObraSocial);
    setFechaNacimiento(fechaNacimiento);
}

///getters
int Paciente::getCodObraSocial(){
    return _codObraSocial;
}
FechaHora Paciente::getFechaNacimiento(){
    return _fechaNacimiento;
}

///setters
void Paciente::setCodObraSocial(int codObraSocial){
    if(codObraSocial < 0){
        std::cout << "Código ingresado incorrecto. No puede ser negativo";
        return;
    }
    _codObraSocial = codObraSocial;
}
void Paciente::setFechaNacimiento(FechaHora fechaNacimiento){
    _fechaNacimiento = fechaNacimiento;
}

