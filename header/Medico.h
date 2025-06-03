#pragma once
#include <string>
#include "FechaHora.h"
#include "Persona.h"

class Medico: public Persona{
    public:
        ///constructores
        Medico();
        Medico(int dni,std::string apellido,std::string nombre,std::string telefono,std::string email,bool estado,int codigoEspecialidad,FechaHora fechaNacimiento,FechaHora inicioActividad);
        ///getters
        int getCodigoEspecialidad();
        FechaHora getInicioActividad();
        ///setters
        bool setCodigoEspecialidad(int codigoEspecialidad);
        bool setInicioActividad(FechaHora inicioActividad);
    private:
        int _codigoEspecialidad;
        FechaHora _inicioActividad;
};
