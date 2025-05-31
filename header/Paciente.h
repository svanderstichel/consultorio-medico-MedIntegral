#pragma once
#include <string>
#include "FechaHora.h"
#include "Persona.h"

class Paciente : public Persona{
    private:
        int _codObraSocial;
        FechaHora _fechaNacimiento;
    public:
        ///constructores
        Paciente();
        Paciente(int dni,std::string apellido,std::string nombre,std::string telefono,std::string email,bool estado,int codObraSocial,FechaHora fechaNacimiento);
        ///getters
        int getCodObraSocial();
        FechaHora getFechaNacimiento();
        ///setters
        void setCodObraSocial(int codObraSocial);
        void setFechaNacimiento(FechaHora fechaNacimiento);
};

