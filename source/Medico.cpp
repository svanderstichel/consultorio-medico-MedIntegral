#include <iostream>
#include "Medico.h"

///constructores
Medico::Medico():Persona(){
    FechaHora inicioActividad;
    setCodigoEspecialidad(0);
    setInicioActividad(inicioActividad);
}

Medico::Medico(int dni,std::string apellido,std::string nombre,std::string telefono,std::string email,bool estado,
               int codigoEspecialidad,FechaHora fechaNacimiento,FechaHora inicioActividad):Persona(dni,apellido,nombre,telefono,email,fechaNacimiento,estado){
                    setCodigoEspecialidad(codigoEspecialidad);
                    setInicioActividad(inicioActividad);
               }

///getters
int Medico::getCodigoEspecialidad(){
    return _codigoEspecialidad;
}
FechaHora Medico::getInicioActividad(){
    return _inicioActividad;
}

///setters
bool Medico::setCodigoEspecialidad(int codigoEspecialidad){
    if(codigoEspecialidad<0 || codigoEspecialidad>100){
        std::cout << "Codigo especialidad invalido (fuera de rango).\n";
        return false;
    }
    _codigoEspecialidad = codigoEspecialidad;
    return true;
}
bool Medico::setInicioActividad(FechaHora inicioActividad){
    _inicioActividad = inicioActividad;
    return true;
}
