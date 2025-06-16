#pragma once
#include "TurnoArchivo.h"

class TurnoManager{
    public:
        void alta();
        void baja();
        void modificar();
        void listar();
        void buscar();
        void alta(int idTurno);
        void exportarCSV();
    private:
        TurnoArchivo archivo;
};
