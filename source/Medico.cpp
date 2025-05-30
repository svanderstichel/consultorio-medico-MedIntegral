#include <iostream>
#include "Medico.h"

///constructores
Medico::Medico():Persona(){
    FechaHora fechaNacimiento;
    setCodigoEspecialidad(0);
    setFechaNacimiento(fechaNacimiento);
}

Medico::Medico(int dni,std::string apellido,std::string nombre,std::string telefono,std::string email,bool estado,
               int codigoEspecialidad,FechaHora fechaNacimiento):Persona(dni,apellido,nombre,telefono,email,estado){
                    setCodigoEspecialidad(codigoEspecialidad);
                    setFechaNacimiento(fechaNacimiento);
               }

///getters
int Medico::getCodigoEspecialidad(){
    return _codigoEspecialidad;
}
FechaHora Medico::getFechaNacimiento(){
    return _fechaNacimiento;
}

///setters
void Medico::setCodigoEspecialidad(int codigoEspecialidad){
    if(codigoEspecialidad<0 || codigoEspecialidad>100){
        std::cout << "Codigo especialidad invalido (fuera de rango).";
        return;
    }
    _codigoEspecialidad = codigoEspecialidad;
}
void Medico::setFechaNacimiento(FechaHora fechaNacimiento){
    _fechaNacimiento = fechaNacimiento;
}
