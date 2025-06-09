#pragma once
#include "MedicoArchivo.h"

class MedicoManager{
    public:
        void alta();
        void baja();
        void modificar();
        void listar();
        void buscar();
        void alta(int dni);
        void exportarCSV();
    private:
        MedicoArchivo archivo;
};
