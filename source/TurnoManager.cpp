#include <iostream>
#include "Turno.h"
#include "TurnoManager.h"
#include  "FechaHora.h"

using namespace std;

void TurnoManager::alta(){

    Turno reg;
    int idTurno;
    int dniPaciente;
    int dniMedico;
    float importeConsulta;
    FechaHora fechaHoraAtencion;
    int contadorIntentos=0;
    bool turnoValido=1;

    ///asignacion de id autoincremental
    idTurno=archivo.getCantidadRegistros()+1;

    while(reg.getDniPaciente()==1000000 && contadorIntentos<3){
    cout << "\nIngrese DNI del paciente: ";
    cin >> dniPaciente;
    cin.ignore();
    reg.setDniPaciente(dniPaciente);
    contadorIntentos++;}

    ///verificar limite de reintentos
    if(contadorIntentos==3 && reg.getDniPaciente()==1000000)
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    while(reg.getDniMedico()==1000000 && contadorIntentos<3){
    cout << "\nIngrese DNI del medico: ";
    cin >> dniMedico;
    cin.ignore();
    reg.setDniMedico(dniMedico);
    contadorIntentos++;}

    ///verificar limite de reintentos
    if(contadorIntentos==3 && reg.getDniMedico()==1000000)
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    do{
    cout << "\nFecha de atencion" << endl;
    fechaHoraAtencion.cargarFecha();

    cout << "\nHora de atencion" << endl;
    fechaHoraAtencion.cargarHora();

    ///validar que la fechaHora de atencion y el medico no esten ocupados por otro turno
    int cantRegistros=archivo.getCantidadRegistros();
    Turno *vec;

    if(cantRegistros>0){
        vec=new Turno[cantRegistros];
        if(vec==nullptr){cout <<"\nSe produjo un error de asignacion de memoria.\n";return;}

        archivo.leer(cantRegistros,vec);

        for(int i=0;i<cantRegistros;i++){
            if(vec[i].getFechaHoraAtencion()==fechaHoraAtencion &&
               vec[i].getDniMedico()==reg.getDniMedico())
               {turnoValido=0;}}
        delete[] vec;}

    if(turnoValido){reg.setFechaHoraAtencion(fechaHoraAtencion);}
    else{cout << "\nTurno invalido, el medico ya tiene un turno asignado en ese horario.\n";}

    contadorIntentos++;

    }while(!turnoValido && contadorIntentos<3);

    ///verificar limite de reintentos
    if(contadorIntentos==3 && !turnoValido)
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}


    while(reg.getImporteConsulta()==0 && contadorIntentos<3){
    cout << "\nIngrese el importe de la consulta: ";
    cin >> importeConsulta;
    cin.ignore();
    reg.setImporteConsulta(importeConsulta);
    contadorIntentos++;}

    ///verificar limite de reintentos
    if(contadorIntentos==3 && reg.getImporteConsulta()==0)
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    if(archivo.escribir(reg)){cout <<"\nTurno cargado correctamente!\n";}
    else{cout <<"\nSe produjo un error de escritura en disco.\n";}
}

void TurnoManager::baja(){}
void TurnoManager::modificar(){}
void TurnoManager::listar(){}
void TurnoManager::buscar(){}
void TurnoManager::alta(int dni){}
void TurnoManager::exportarCSV(){}
