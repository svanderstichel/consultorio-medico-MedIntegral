#pragma once
#include "Especialidad.h"

class EspecialidadArchivo{
    public:
        ///constructor
        EspecialidadArchivo();
        ///get
        int getPosicion(int codEspecialidad);
        int getCantidadRegistros();
        ///leer un registro
        Especialidad leer(int pos);
        ///leer todos los registros en un vector
        void leer(int cantidadRegistros,Especialidad *vec);
        ///escribir un registro
        bool escribir(Especialidad reg);
        ///modificar un registro
        bool escribir(int pos,Especialidad reg);
    private:
        char _nombreArchivo[50];
};
