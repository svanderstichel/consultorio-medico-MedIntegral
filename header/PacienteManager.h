#pragma once
#include "PacienteArchivo.h"

class PacienteManager{
    public:
        void altaPaciente();
        void altaPaciente(int dni);
        void bajaPaciente();
        void listarPaciente();
        void modificarPAciente();
        void exportarCSV();
    private:
        PacienteArchivo archivo;
};

