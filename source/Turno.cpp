#include <iostream>
#include "Turno.h"
#include "FechaHora.h"
#include "MedicoArchivo.h"
#include "PacienteArchivo.h"


Turno::Turno()
{
    FechaHora fechaHoraAtencion;
    setidTurno(0);
    setDniPaciente(1000000);
    setDniMedico(1000000);
    setImporteConsulta(0.0f);
    setFechaHoraAtencion(fechaHoraAtencion);
    setEstado(true);
}
Turno::Turno(int idTurno,int dniPaciente,int dniMedico,FechaHora fechaHoraAtencion,float importeConsulta,bool estado)
{
    setidTurno(idTurno);
    setDniPaciente(dniPaciente);
    setDniMedico(dniMedico);
    setImporteConsulta(importeConsulta);
    setFechaHoraAtencion(fechaHoraAtencion);
    setEstado(estado);
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
FechaHora Turno::getFechaHoraAtencion()
{
    return _fechaHoraAtencion;
}
float Turno::getImporteConsulta()
{
    return _importeConsulta;
}
bool Turno::getEstado(){
    return _estado;
}
void Turno::setidTurno(int idTurno)
{
    _idTurno = idTurno;
}

bool Turno::setDniPaciente(int dniPaciente)
{
    PacienteArchivo archivo;
    if(archivo.getPosicion(dniPaciente)==-1 && dniPaciente != 1000000){
        std::cout << "\nDNI invalido, el paciente no se encuentra registrado en el sistema.\n";
        return false;
    }
    _dniPaciente = dniPaciente;
    return true;
}

bool Turno::setDniMedico(int dniMedico)
{
    MedicoArchivo archivo;
    if(archivo.getPosicion(dniMedico)==-1 && dniMedico != 1000000){
        std::cout << "\nDNI invalido, el medico no se encuentra registrado en el sistema.\n";
        return false;
    }
    _dniMedico = dniMedico;
    return true;
}
bool Turno::setImporteConsulta(float importeConsulta)
{
    if(importeConsulta<0 || importeConsulta>1000000){std::cout << "\nImporte invalido (fuera de rango).\n";return false;}
    _importeConsulta = importeConsulta;
    return true;
}
void Turno::setFechaHoraAtencion(FechaHora fechaHoraAtencion)
{
    _fechaHoraAtencion = fechaHoraAtencion;
}

void Turno::setEstado(bool estado){
    _estado=estado;
}

