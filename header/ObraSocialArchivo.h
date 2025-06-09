#pragma once
#include "ObraSocial.h"

class ObraSocialArchivo {
private:
    char _nombreArchivo[30];

public:
    ObraSocialArchivo();

    int getCantidadRegistros();
    int getPosicion(int codigo);
    ObraSocial leer(int pos);
    void leer(int cantidadRegistros, ObraSocial* vec);
    bool escribir(ObraSocial reg);
    bool escribir(int pos, ObraSocial reg);
};

