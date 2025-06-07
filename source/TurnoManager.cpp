#include <iostream>
#include <iomanip>
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
    ///inicializa el primer id en 1
    if(idTurno==0){idTurno++;}
    reg.setidTurno(idTurno);

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
    turnoValido=1;
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
               {turnoValido=0;
                break;}}
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

void TurnoManager::baja(){
    Turno reg;
    int idTurno;
    int pos;

    cout << "Ingrese el id del turno que desea dar de baja: ";
    cin >> idTurno;
    cin.ignore();

    pos = archivo.getPosicion(idTurno);
    if(pos==-1){cout << "\nEl registro no existe en el disco.\n";}

    if(pos!=-1){
    reg = archivo.leer(pos);

    reg.setEstado(false);
    if(archivo.escribir(pos,reg)){
            cout << "\nEl turno fue dado de baja correctamente.\n";
        }else{cout << "\nSe produjo un error de escritura en el disco.\n";}
    }

}
void TurnoManager::listar(){
    int cantReg = archivo.getCantidadRegistros();
    Turno *vec;

    if(cantReg<=0){cout <<"No se registran turnos activos.\n";return;}

    vec = new Turno[cantReg];
    if(vec==nullptr){cout <<"\nSe produjo un error de asignacion de memoria.\n";return;}

    archivo.leer(cantReg,vec);

    ///print de tabla
    ///encabezado de columnas
    cout << left
         << setw(12)  << "ID Turno"
         << setw(15) << "DNI Medico"
         << setw(15) << "DNI Paciente"
         << setw(10) << "Importe"
         << setw(15) << "Fecha"
         << setw(6) << "Horario"
         << endl;

    cout << string(80, '-') << endl;///barra separadora

    for (int i = 0; i < cantReg; i++) {
        if (vec[i].getEstado()) {
        cout << left
             << setw(12) << vec[i].getidTurno()
             << setw(15) << vec[i].getDniMedico()
             << setw(15) << vec[i].getDniPaciente()
             << setw(10) << vec[i].getImporteConsulta()
             << setw(15) << (to_string(vec[i].getFechaHoraAtencion().getDia()) + "/" +
                             to_string(vec[i].getFechaHoraAtencion().getMes()) + "/" +
                             to_string(vec[i].getFechaHoraAtencion().getAnio()))
             << setw(6) << vec[i].getFechaHoraAtencion().getHora()
             << endl;
                 }
        }
    cout << endl;
    delete[] vec;
}
void TurnoManager::modificar(){}
void TurnoManager::buscar(){}
void TurnoManager::alta(int idTurno){}
void TurnoManager::exportarCSV(){}
