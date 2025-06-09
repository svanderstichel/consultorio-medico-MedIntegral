#pragma once
#include "ObraSocialArchivo.h"

class ObraSocialManager {
public:
    void altaObraSocial();
    void bajaObraSocial();
    void modificarObraSocial();
    void listarObraSocial();
private:
    ObraSocialArchivo archivo;
};

