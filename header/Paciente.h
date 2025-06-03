#pragma once
#include <string>
#include "FechaHora.h"
#include "Persona.h"

class Paciente : public Persona{
    private:
        int _codObraSocial;
    public:
        ///constructores
        Paciente();
        Paciente(int dni,std::string apellido,std::string nombre,std::string telefono,std::string email,bool estado,int codObraSocial,FechaHora fechaNacimiento);
        ///getters
        int getCodObraSocial();
        ///setters
        void setCodObraSocial(int codObraSocial);
};

