#pragma once
#include "Medico.h"

class MedicoArchivo{
    public:
        ///constructor
        MedicoArchivo();
        ///get
        int getPosicion(int dni);
        int getCantidadRegistros();
        ///leer un registro
        Medico leer(int pos);
        ///leer todos los registros en un vector
        void leer(int cantidadRegistros,Medico *vec);
        ///escribir un registro
        bool escribir(Medico reg);
        ///modificar un registro
        bool escribir(int pos,Medico reg);
    private:
        char _nombreArchivo[50];
        ///incluir tamañoRegistro sizeOf(Medico)
};
