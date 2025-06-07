#pragma once
#include "TurnoArchivo.h"

class TurnoManager{
    public:
        void alta();
        void baja();
        void modificar();
        void listar();
        void buscar();
        void alta(int dni);
        void exportarCSV();
    private:
        TurnoArchivo archivo;
};
