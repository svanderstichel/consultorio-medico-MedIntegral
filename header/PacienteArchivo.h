#pragma once
#include "Paciente.h"

class PacienteArchivo{
    public:
        ///constructor
        PacienteArchivo();
        ///get
        int getPosicion(int dni);
        int getCantidadRegistros();
        ///leer un registro
        Paciente leer(int pos);
        ///leer todos los registros en un vector
        void leer(int cantidadRegistros,Paciente *vec);
        ///escribir un registro
        bool escribir(Paciente reg);
        ///modificar un registro
        bool escribir(int pos,Paciente reg);
    private:
        char _nombreArchivo[50];
};

