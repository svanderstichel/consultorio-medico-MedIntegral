#pragma once
#include "FechaHora.h"

class Turno{
    public:
        ///constructores
        Turno();
        Turno(int idTurno,int dniPaciente,int dniMedico,FechaHora horaHoraAtencion,float importeConsulta,bool estado);
        ///getters
        int getidTurno();
        int getDniPaciente();
        int getDniMedico();
        float getImporteConsulta();
        FechaHora getFechaHoraAtencion();
        bool getEstado();
        ///setters
        void setidTurno(int idTurno);
        bool setDniPaciente(int dniPaciente);
        bool setDniMedico(int dniMedico);
        bool setImporteConsulta(float importeConsulta);
        void setFechaHoraAtencion(FechaHora fechaHoraAtencion);
        void setEstado(bool estado);
    private:
        int _idTurno;
        int _dniPaciente;
        int _dniMedico;
        FechaHora _fechaHoraAtencion;
        float _importeConsulta;
        bool _estado;
};
