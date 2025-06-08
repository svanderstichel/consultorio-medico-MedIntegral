#pragma once
#include "EspecialidadArchivo.h"

class EspecialidadManager{
    public:
        void altaEspecialidad();
        void bajaEspecialidad();
        void listarEspecialidad();
        void modificarEspecialidad();
       //void activarEspecialidad();
    private:
        EspecialidadArchivo archivo;
};

