#pragma once
#include <string>
#include "FechaHora.h"

class Persona{
    public:
        ///constructores
        Persona();
        Persona(int dni,std::string apellido,std::string nombre,std::string telefono,std::string email,FechaHora fechaNacimiento,bool estado);
        ///getters
        int getDni();
        std::string getApellido();
        std::string getNombre();
        std::string getTelefono();
        std::string getEmail();
        FechaHora getFechaNacimiento();
        bool getEstado();
        ///setters
        bool setDni(int dni);
        bool setApellido(std::string apellido);
        bool setNombre(std::string nombre);
        bool setTelefono(std::string telefono);
        bool setEmail(std::string email);
        void setFechaNacimiento(FechaHora fechaNacimiento);
        void setEstado(bool estado);
    private:
        int _dni;
        char _apellido[50];
        char _nombre[50];
        char _telefono[50];
        char _email[50];
        FechaHora _fechaNacimiento;
        bool _estado;
};
