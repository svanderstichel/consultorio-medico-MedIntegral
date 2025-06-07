#pragma once
#include <string>

class Especialidad {
    private:
        int _codEspecialidad;
        bool _estado;
        char _nombre[50];
    public:
        ///constructores
        Especialidad();
        Especialidad(int codEspecialidad,std::string nombre,bool estado);
        ///getters
        int getCodEspecialidad();
        bool getEstado();
        std::string getNombre();
        ///setters
        void setCodEspecialidad(int codEspecialidad);
        void setEstado(bool estado);
        bool setNombre(std::string nombre);
};
