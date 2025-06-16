#pragma once
#include "PacienteArchivo.h"

class PacienteManager{
    public:
        void altaPaciente();
        void altaPaciente(int dni);
        void bajaPaciente();
        void listarPaciente();
        void modificarPAciente();
    private:
        PacienteArchivo archivo;
};

