#include "Turno.h"
#include "FechaHora.h"


Turno::Turno()
{
    FechaHora fechaAtencion, horaAtencion;
    setidTurno(0);
    setDniPaciente(0);
    setDniMedico(0);
    setFechaAtencion(fechaAtencion);
    setHoraAtencion(horaAtencion);
    setImporteConsulta(0.0f);
}
Turno::Turno(int idTurno, int dniPaciente, int dniMedico, FechaHora fechaAtencion, FechaHora horaAtencion, float importeConsulta)
{
    setidTurno(idTurno);
    setDniPaciente(dniPaciente);
    setDniMedico(dniMedico);
    setFechaAtencion(fechaAtencion);
    setHoraAtencion(horaAtencion);
    setImporteConsulta(importeConsulta);
}

int Turno::getidTurno()
{
    return _idTurno;
}
int Turno::getDniPaciente()
{
    return _dniPaciente;
}
int Turno::getDniMedico()
{
    return _dniMedico;
}
FechaHora Turno::getFechaAtencion()
{
    return _fechaAtencion;
}
FechaHora Turno::getHoraAtencion()
{
    return _horaAtencion;
}
float Turno::getImporteConsulta()
{
    return _importeConsulta;
}
void Turno::setidTurno(int idTurno)
{
    _idTurno = idTurno;
}

void Turno::setDniPaciente(int dniPaciente)
{
    _dniPaciente = dniPaciente;
}

void Turno::setDniMedico(int dniMedico)
{
    _dniMedico = dniMedico;
}

void Turno::setFechaAtencion(FechaHora fechaAtencion)
{
    _fechaAtencion = fechaAtencion;
}

void Turno::setHoraAtencion(FechaHora horaAtencion)
{
    _horaAtencion = horaAtencion;
}

void Turno::setImporteConsulta(float importeConsulta)
{
    _importeConsulta = importeConsulta;
}

