#include <iostream>
using namespace std;
#include <set>
#include "Reporte.h"
#include "Paciente.h"
#include "Medico.h"
#include "PacienteArchivo.h"
#include "MedicoArchivo.h"
#include "Turno.h"
#include "TurnoArchivo.h"
#include "EspecialidadArchivo.h"
#include "ObraSocial.h"
#include "ObraSocialArchivo.h"
#include <iomanip>
#include <limits>
#include <map>

void Reporte::recaudacionAnualMensual(){
     TurnoArchivo archivo;
    int cantidad = archivo.getCantidadRegistros();

    if (cantidad <= 0) {
        cout << "No hay registros de turnos cargados.\n";
        return;
    }

    Turno* vec = new Turno[cantidad];
    if (vec == nullptr) {
        cout << "Error al asignar memoria.\n";
        return;
    }

    archivo.leer(cantidad, vec);

    int anio, mes;

    cout << "Ingrese el anio a consultar: ";
    cin >> anio;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida.\n";
        delete[] vec;
        return;}

    cout << "Ingrese el mes (1-12) o 0 para ver todo el anio: ";
    cin >> mes;
    if (cin.fail() || mes < 0 || mes > 12) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida.\n";
        delete[] vec;
        return;}

    if (mes == 0){
        float recaudacion[12]={0};

        system("cls");
        cout << "\n<Recaudacion del anio " << anio << ">\n\n";

        for (int i = 0; i < cantidad; i++){
        FechaHora fh = vec[i].getFechaHoraAtencion();

        if(fh.getAnio() == anio && vec[i].getEstado())
        {recaudacion[fh.getMes()-1] += vec[i].getImporteConsulta();}}

        //impresion tabla
        //header
        cout << left
         << setw(5) << "Mes"
         << setw(10) << "Total ($)" << endl;
        cout << string(15, '=') << endl;
        //valores
        for(int i=0;i<12;i++){
        cout << left
             << setw(5) << i+1
             << fixed << setprecision(2)<< setw(10) << recaudacion[i]
             << setfill(' ') << endl;}}

    if (mes != 0){
        float recaudacion = 0.0;
        for (int i = 0; i < cantidad; i++) {
        FechaHora fh = vec[i].getFechaHoraAtencion();

        if (fh.getAnio() == anio && (fh.getMes() == mes) && vec[i].getEstado()) {
            recaudacion += vec[i].getImporteConsulta();}}

        cout << "\n<Recaudacion del periodo " << mes << "-" << anio <<  ": " << fixed << setprecision(2) << recaudacion << ">";

        }

    cout << endl << endl;
    delete[] vec;

}
void Reporte::recaudacionObraSocial(){
    TurnoArchivo turnoArchivo;
    PacienteArchivo pacienteArchivo;
    ObraSocialArchivo obrasocialArchivo;
    ObraSocial reg;
    float obraSocial[15]={0};

    int cantTurnos = turnoArchivo.getCantidadRegistros();
    int cantPacientes = pacienteArchivo.getCantidadRegistros();

    system("cls");
    cout << "\n<Recaudacion segun obra social>\n\n";


    if (cantTurnos <= 0 || cantPacientes <= 0) {
        cout << "No hay datos suficientes para generar el reporte.\n";
        return;}

    Paciente* pacientes = new Paciente[cantPacientes];
    pacienteArchivo.leer(cantPacientes, pacientes);

    Turno* turnos = new Turno[cantTurnos];
    turnoArchivo.leer(cantTurnos, turnos);

    for(int i=0;i<cantTurnos;i++){
        if(turnos[i].getEstado()){
            for(int e=0;e<cantPacientes;e++){
                if(pacientes[e].getEstado() && pacientes[e].getDni()==turnos[i].getDniPaciente()){
                    obraSocial[pacientes[e].getCodObraSocial()-1] += turnos[i].getImporteConsulta();
                    break;
                }
            }
        }
    }

    delete[] pacientes;
    delete[] turnos;

    //impresion tabla
    //header

    cout << left
     << setw(20) << "Obra social"
     << setw(10) << "Total ($)" << endl;
    cout << string(30, '=') << endl;
    //valores
    for(int i=0;i<15;i++){
    reg=obrasocialArchivo.leer(i);
        if(reg.getEstado()){
        cout << left
             << setw(20) << reg.getNombre()
             << fixed << setprecision(2)<< setw(10) << obraSocial[i]
             << setfill(' ') << endl;}}
    cout << endl;

}
void Reporte::recaudacionEspecialidad(){
    TurnoArchivo turnoArchivo;
    MedicoArchivo medicoArchivo;
    EspecialidadArchivo especialidadArchivo;
    Especialidad reg;
    float especialidades[15]={0};

    int cantTurnos = turnoArchivo.getCantidadRegistros();
    int cantMedicos = medicoArchivo.getCantidadRegistros();

    system("cls");
    cout << "\n<Recaudacion segun especialidad>\n\n";


    if (cantTurnos <= 0 || cantMedicos <= 0) {
        cout << "No hay datos suficientes para generar el reporte.\n";
        return;}

    Medico* medicos = new Medico[cantMedicos];
    medicoArchivo.leer(cantMedicos, medicos);

    Turno* turnos = new Turno[cantTurnos];
    turnoArchivo.leer(cantTurnos, turnos);

    for(int i=0;i<cantTurnos;i++){
        if(turnos[i].getEstado()){
            for(int e=0;e<cantMedicos;e++){
                if(medicos[e].getEstado() && medicos[e].getDni()==turnos[i].getDniMedico()){
                    especialidades[medicos[e].getCodigoEspecialidad()-1] += turnos[i].getImporteConsulta();
                    break;
                }
            }
        }
    }

    delete[] medicos;
    delete[] turnos;

    //impresion tabla
    //header
    cout << left
     << setw(25) << "Especialidades"
     << setw(10) << "Total ($)" << endl;
    cout << string(35, '=') << endl;
    //valores
    for(int i=0;i<10;i++){
    reg = especialidadArchivo.leer(i);
    if(reg.getEstado()){
        cout << left
             << setw(25) << reg.getNombre()
             << fixed << setprecision(2)<< setw(10) << especialidades[i]
             << setfill(' ') << endl;}}
    cout << endl;


}
void Reporte::cantidadPacientesMedico(){
    Turno regTurno;
    Medico regMedico;
    TurnoArchivo archivoTurnos;
    MedicoArchivo archivoMedicos;

    int cantTurno = archivoTurnos.getCantidadRegistros();
    int cantMedico = archivoMedicos.getCantidadRegistros();

    system("cls");
    cout << "<Cantidad de pacientes por medico>" << endl << endl;

     if (cantTurno <= 0 || cantMedico <= 0) {
        cout << "No hay datos suficientes para generar el reporte.\n";
        return;}

    cout << left
     << setw(30) << "Medico"
     << setw(21) << "Cantidad de pacientes" << endl;
    cout << string(51, '=') << endl;

    for(int i=0;i<cantMedico;i++){
        regMedico = archivoMedicos.leer(i);
        //estructura de datos que permite almacenar valores unicos
        set<int> pacientesUnicos;

        if(regMedico.getEstado()){
            for(int j=0;j<cantTurno;j++){
                regTurno = archivoTurnos.leer(j);
                if(regMedico.getDni() == regTurno.getDniMedico()){
                        //inserta dni paciente en la lista de valores unicos
                        pacientesUnicos.insert(regTurno.getDniPaciente());
                    }
                }
            }
         cout << left
         << setw(30) << regMedico.getApellido() + " " + regMedico.getNombre()
         //obtener cantidad de elementos de la lista de pacientes
         << setw(21) << pacientesUnicos.size()
         << setfill(' ') << endl;}
         cout << endl;
}
void Reporte::cantidadTurnosMedico(){
    Turno regTurno;
    Medico regMedico;
    TurnoArchivo archivoTurnos;
    MedicoArchivo archivoMedicos;
    int turnosTotales = 0;
    int cantTurno = archivoTurnos.getCantidadRegistros();
    int cantMedico = archivoMedicos.getCantidadRegistros();

    system("cls");
    cout << "<Cantidad de turnos por medico>\n\n";

    cout << left
     << setw(30) << "Medico"
     << setw(18) << "Cantidad de turnos" << endl;
    cout << string(48, '=') << endl;

    for (int i=0;i<cantMedico;i++){
        regMedico = archivoMedicos.leer(i);
        if(regMedico.getEstado()){
        turnosTotales = 0;
            for (int j=0;j<cantTurno;j++){
            regTurno = archivoTurnos.leer(j);
            if(regMedico.getDni() == regTurno.getDniMedico()){
                turnosTotales++;}}}
    cout << left
         << setw(30) << regMedico.getApellido() + " " + regMedico.getNombre()
         << setw(18) << turnosTotales
         << setfill(' ') << endl;
    }
    cout << endl;
}
void Reporte::cantidadTurnosPaciente(){
    Turno regTurno;
    Paciente regPaciente;
    TurnoArchivo archivoTurnos;
    PacienteArchivo archivoPacientes;
    int turnosTotales = 0;
    int cantTurno = archivoTurnos.getCantidadRegistros();
    int cantPaciente = archivoPacientes.getCantidadRegistros();

    system("cls");
    cout << "<Cantidad de turnos por paciente>\n\n";

    cout << left
     << setw(30) << "Paciente"
     << setw(18) << "Cantidad de turnos" << endl;
    cout << string(48, '=') << endl;

    for (int i=0;i<cantPaciente;i++){
        regPaciente = archivoPacientes.leer(i);
        if(regPaciente.getEstado()){
        turnosTotales = 0;
            for (int j=0;j<cantTurno;j++){
            regTurno = archivoTurnos.leer(j);
            if(regPaciente.getDni() == regTurno.getDniPaciente()){
                turnosTotales++;}}}
    cout << left
         << setw(30) << regPaciente.getApellido() + " " + regPaciente.getNombre()
         << setw(18) << turnosTotales
         << setfill(' ') << endl;
    }
    cout << endl;
}
