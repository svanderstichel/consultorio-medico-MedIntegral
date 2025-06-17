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
    int cantTurno = archivo1.getCantidadRegistros();
    int cantMedico = archivo2.getCantidadRegistros();

    cout << "- Cantidad de pacientes atendidos por medico." << endl << endl;
    for (int i=0;i<cantMedico;i++){
        reg2 = archivo2.leer(i);
        std::set<int> pacientesUnicos;
            for (int j=0;j<cantTurno;j++){
            reg1 = archivo1.leer(j);
            if(reg2.getDni() == reg1.getDniMedico()){
            pacientesUnicos.insert(reg1.getDniPaciente());
            }
        }
        if (reg2.getEstado() == 1 && !pacientesUnicos.empty()) {
            cout << "- " << reg2.getApellido() << " " << reg2.getNombre() << ": " << pacientesUnicos.size() << " paciente(s)." << endl;
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

    cout << "- Cantidad de turnos registrados por medico." << endl << endl;
    for (int i=0;i<cantMedico;i++){
        reg2 = archivo2.leer(i);
        turnosTotales = 0;
            for (int j=0;j<cantTurno;j++){
            reg1 = archivo1.leer(j);
            if(reg2.getDni() == reg1.getDniMedico()){
                turnosTotales++;
            }
        }
        if (reg2.getEstado() == 1) {
            cout << "- " << reg2.getApellido() << " " << reg2.getNombre() << ": " << turnosTotales << " turnos registrados." << endl;
        }
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

    cout << "- Cantidad de turnos registrados por paciente." << endl << endl;
    for (int i=0;i<cantPaciente;i++){
        reg2 = archivo2.leer(i);
        turnosTotales = 0;
            for (int j=0;j<cantTurno;j++){
            reg1 = archivo1.leer(j);
            if(reg2.getDni() == reg1.getDniPaciente()){
                turnosTotales++;
            }
        }
        if (reg2.getEstado() == 1 && turnosTotales > 0) {
            cout << "- " << reg2.getApellido() << " " << reg2.getNombre() << ": " << turnosTotales << " turnos registrados." << endl;
        }
    }
}
