#pragma once
#include "PacienteArchivo.h"

class PacienteManager{
    public:
        void altaPaciente();
        void bajaPaciente();
        void listarPaciente();
        void modificarPAciente();
    private:
        PacienteArchivo archivo;
};

