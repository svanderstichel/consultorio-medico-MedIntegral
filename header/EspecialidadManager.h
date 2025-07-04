#pragma once
#include "EspecialidadArchivo.h"

class EspecialidadManager{
    public:
        void altaEspecialidad();
        void altaEspecialidad(int codEspecialidad);
        void bajaEspecialidad();
        void listarEspecialidad();
        void modificarEspecialidad();
        void exportarCSV();
    private:
        EspecialidadArchivo archivo;
};

