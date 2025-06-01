#pragma once
#include <string>
#include "FechaHora.h"
#include "Persona.h"

class Medico: public Persona{
    public:
        ///constructores
        Medico();
        Medico(int dni,std::string apellido,std::string nombre,std::string telefono,std::string email,bool estado,int codigoEspecialidad,FechaHora fechaNacimiento);
        ///getters
        int getCodigoEspecialidad();
        FechaHora getFechaNacimiento();
        ///setters
        bool setCodigoEspecialidad(int codigoEspecialidad);
        bool setFechaNacimiento(FechaHora fechaNacimiento);
    private:
        int _codigoEspecialidad;
        FechaHora _fechaNacimiento;
};
