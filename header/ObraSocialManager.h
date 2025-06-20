#pragma once
#include "ObraSocialArchivo.h"

class ObraSocialManager {
public:
    void altaObraSocial();
    void altaObraSocial(int codObraSocial);
    void bajaObraSocial();
    void modificarObraSocial();
    void listarObraSocial();
    void exportarCSV();
private:
    ObraSocialArchivo archivo;
};

