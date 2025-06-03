#pragma once
#include "MedicoArchivo.h"

class MedicoManager{
    public:
        void alta();
        ///cantidad maxima de reintentos o consultar al usuario
        void baja();
        void modificar();
        void listar();
    private:
        MedicoArchivo archivo;
};
