#pragma once
#include <string>

class ConfiguracionArchivo{
    public:
        ConfiguracionArchivo(std::string nombreArchivo);
        bool crearCopia();
        bool restaurarCopia();
    private:
        char _nombreArchivo[50];
};
