#pragma once
#include "MedicoArchivo.h"

class MedicoManager{
    public:
        void alta();
        void baja();
        void modificar();
        void listar();
        void buscar();
    private:
        MedicoArchivo archivo;
};
