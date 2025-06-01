#pragma once
#include "FechaHora.h"


class Turno
{

private:
    int _idTurno;
    int _dniPaciente;
    int _dniMedico;
    FechaHora _fechaAtencion;
    FechaHora _horaAtencion;
    float _importeConsulta;

public:
    Turno();
    Turno(int idTurno, int dniPaciente, int dniMedico, FechaHora fechaAtencion, FechaHora horaAtencion, float importeConsulta);


    int getidTurno();
    int getDniPaciente();
    int getDniMedico();
    FechaHora getFechaAtencion();
    FechaHora getHoraAtencion();
    float getImporteConsulta();
    void setidTurno(int idTurno);
    void setDniPaciente(int dniPaciente);
    void setDniMedico(int dniMedico);
    void setFechaAtencion(FechaHora fechaAtencion);
    void setHoraAtencion(FechaHora horaAtencion);
    void setImporteConsulta(float importeConsulta);

};
