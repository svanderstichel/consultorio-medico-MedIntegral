#pragma once
#include <string>

class Persona{
    public:
        ///constructores
        Persona();
        Persona(int dni,std::string apellido,std::string nombre,std::string telefono,std::string email,bool estado);
        ///getters
        int getDni();
        std::string getApellido();
        std::string getNombre();
        std::string getTelefono();
        std::string getEmail();
        bool getEstado();
        ///setters
        bool setDni(int dni);
        bool setApellido(std::string apellido);
        bool setNombre(std::string nombre);
        bool setTelefono(std::string telefono);
        bool setEmail(std::string email);
        void setEstado(bool estado);
    private:
        int _dni;
        char _apellido[50];
        char _nombre[50];
        char _telefono[50];
        char _email[50];
        bool _estado;
};
