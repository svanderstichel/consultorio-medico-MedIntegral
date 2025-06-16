#include <iostream>
using namespace std;
#include <set>
#include "Reporte.h"
#include "Paciente.h"
#include "Medico.h"
#include "PacienteArchivo.h"
#include "MedicoArchivo.h"
#include "TurnoArchivo.h"

void Reporte::recaudacionAnualMensual(){}
void Reporte::recaudacionObraSocial(){}
void Reporte::recaudacionEspecialidad(){}
void Reporte::cantidadPacientesMedico(){
    Turno reg1;
    Medico reg2;
    TurnoArchivo archivo1;
    MedicoArchivo archivo2;
    std::set<int> pacientesUnicos;
    int cantTurno = archivo1.getCantidadRegistros();
    int cantMedico = archivo2.getCantidadRegistros();

    for (int i=0;i<cantMedico;i++){
        reg2 = archivo2.leer(i);
            for (int j=0;j<cantTurno;j++){
            reg1 = archivo1.leer(j);
            if(reg2.getDni() == reg1.getDniMedico()){
                //pacientePorMedico++;
                pacientesUnicos.insert(reg1.getDniPaciente());
            }
        }
        if (reg2.getEstado() == 1 && !pacientesUnicos.empty()) {
            cout << "El medico " << reg2.getApellido() << " tiene " << pacientesUnicos.size() << " paciente(s) unicos." << endl;
        }
    }
}
void Reporte::cantidadTurnosMedico(){
    Turno reg1;
    Medico reg2;
    TurnoArchivo archivo1;
    MedicoArchivo archivo2;
    int turnosTotales = 0;
    int cantTurno = archivo1.getCantidadRegistros();
    int cantMedico = archivo2.getCantidadRegistros();

    for (int i=0;i<cantMedico;i++){
        reg2 = archivo2.leer(i);
            for (int j=0;j<cantTurno;j++){
            reg1 = archivo1.leer(j);
            if(reg2.getDni() == reg1.getDniMedico()){
                turnosTotales++;
            }
        }
        if (reg2.getEstado() == 1) {
            cout << "El medico " << reg2.getApellido() << " tiene " << turnosTotales << " turnos registrados." << endl;
        }
        turnosTotales = 0;
    }
}
void Reporte::cantidadTurnosPaciente(){
    Turno reg1;
    Paciente reg2;
    TurnoArchivo archivo1;
    PacienteArchivo archivo2;
    int turnosTotales = 0;
    int cantTurno = archivo1.getCantidadRegistros();
    int cantPaciente = archivo2.getCantidadRegistros();

    for (int i=0;i<cantPaciente;i++){
        reg2 = archivo2.leer(i);
            for (int j=0;j<cantTurno;j++){
            reg1 = archivo1.leer(j);
            if(reg2.getDni() == reg1.getDniPaciente()){
                turnosTotales++;
            }
        }
        if (reg2.getEstado() == 1) {
            cout << "El paciente " << reg2.getApellido() << " tiene " << turnosTotales << " turnos registrados." << endl;
        }
        turnosTotales = 0;
    }
}
