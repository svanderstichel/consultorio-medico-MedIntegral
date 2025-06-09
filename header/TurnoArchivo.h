#pragma once
#include "Turno.h"

class TurnoArchivo{
    public:
        ///constructor
        TurnoArchivo();
        ///get
        int getPosicion(int idTurno);
        int getCantidadRegistros();
        ///leer un registro
        Turno leer(int pos);
        ///leer todos los registros en un vector
        void leer(int cantidadRegistros,Turno *vec);
        ///escribir un registro
        bool escribir(Turno reg);
        ///modificar un registro
        bool escribir(int pos,Turno reg);
    private:
        char _nombreArchivo[50];
};
