#pragma once

class FechaHora{
    public:
        ///constructor
        FechaHora();
        ///setters
        void cargarFecha();
        void cargarHora();
        ///getters
        int getDia();
        int getMes();
        int getAnio();
        int getHora();
    private:
        int _dia;
        int _mes;
        int _anio;
        int _hora;
};
