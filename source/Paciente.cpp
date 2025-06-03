#include <iostream>
#include "Paciente.h"

///constructores
Paciente::Paciente():Persona(){
    setCodObraSocial(0);
}

Paciente::Paciente(int dni,std::string apellido,std::string nombre,std::string telefono,std::string email,bool estado, int codObraSocial,FechaHora fechaNacimiento):Persona(dni,apellido,nombre,telefono,email,fechaNacimiento,estado){
    setCodObraSocial(codObraSocial);
}

///getters
int Paciente::getCodObraSocial(){
    return _codObraSocial;
}

///setters
void Paciente::setCodObraSocial(int codObraSocial){
    if(codObraSocial < 0){
        std::cout << "Código ingresado incorrecto. No puede ser negativo";
        return;
    }
    _codObraSocial = codObraSocial;
}
