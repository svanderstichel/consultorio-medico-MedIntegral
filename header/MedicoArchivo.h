#pragma once
#include "Medico.h"

class MedicoArchivo{
    public:
        MedicoArchivo();
        int getPosicion(int dni);
        int getCantidadRegistros();
        Medico leer(int pos);
        void leer(int cantidadRegistros,Medico *vec);
        bool escribir(Medico reg);
        bool escribir(int pos,Medico reg);
    private:
        char _nombreArchivo[50];
};
