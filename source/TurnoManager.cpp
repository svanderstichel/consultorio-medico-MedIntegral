#include <iostream>
#include <iomanip>
#include <limits>
#include "Turno.h"
#include "TurnoManager.h"
#include "MedicoManager.h"
#include "PacienteManager.h"
#include  "FechaHora.h"

using namespace std;

void TurnoManager::alta(){

    MedicoManager medico;
    PacienteManager paciente;
    Turno reg;
    int idTurno;
    int dniPaciente;
    int dniMedico;
    float importeConsulta;
    FechaHora fechaHoraAtencion;
    int contadorIntentos=0;
    bool turnoValido=1;

    ///ASIGNACION ID AUTOINCREMENTAL
    idTurno=archivo.getCantidadRegistros()+1;
    ///inicializa el primer id en 1
    if(idTurno==0){idTurno++;}
    reg.setidTurno(idTurno);

    ///***CARGA DE DATOS***
    ///DNI PACIENTE
    //listado de pacientes
    system("cls");
    cout << "PACIENTES\n";
    cout << "=========\n\n";
    paciente.listarPaciente();

    while(reg.getDniPaciente()==1000000 && contadorIntentos<3){
    cout << "Ingrese DNI del paciente: ";
    cin >> dniPaciente;
    //validar dato numerico, limpiar error y buffer teclado
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nEntrada invalida.\n";}
    else{
        cin.ignore();
        reg.setDniPaciente(dniPaciente);}
    contadorIntentos++;}

    ///verificar limite de reintentos
    if(contadorIntentos==3 && reg.getDniPaciente()==1000000)
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    ///DNI MEDICO
    //listado de medicos
    system("cls");
    cout << "MEDICOS\n";
    cout << "=======\n\n";
    medico.listar();

    while(reg.getDniMedico()==1000000 && contadorIntentos<3){
    cout << "Ingrese DNI del medico: ";
    cin >> dniMedico;
    //validar dato numerico, limpiar error y buffer teclado
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nEntrada invalida.\n";}
    else{
        cin.ignore();
        reg.setDniMedico(dniMedico);}
    contadorIntentos++;}

    ///verificar limite de reintentos
    if(contadorIntentos==3 && reg.getDniMedico()==1000000)
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    ///FECHA Y HORA DE TURNO
    //listado de turnos ocupados
    system("cls");
    cout << "TURNOS OCUPADOS\n";
    cout << "---------------\n";
    listar(dniMedico);
    do{
    turnoValido=1;
    cout << "Fecha de atencion\n";
    cout << "=================\n";
    fechaHoraAtencion.cargarFecha();

    cout << "\nHora de atencion\n";
    cout << "================\n";
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

    ///IMPORTE CONSULTA
    system("cls");
    while(reg.getImporteConsulta()==0 && contadorIntentos<3){
    cout << "\nIngrese el importe de la consulta (AR$): ";
    cin >> importeConsulta;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nEntrada invalida.\n";}
    else{
        cin.ignore();
        reg.setImporteConsulta(importeConsulta);}
    contadorIntentos++;}

    ///verificar limite de reintentos
    if(contadorIntentos==3 && reg.getImporteConsulta()==0)
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    ///ESCRITURA EN DISCO
    if(archivo.escribir(reg)){cout <<"\nTurno cargado correctamente!\n";}
    else{cout <<"\nSe produjo un error de escritura en disco.\n";}
}

void TurnoManager::baja(){
    Turno reg;
    int idTurno;
    int pos;

    system("cls");
    listar();

    cout << "Ingrese el id del turno que desea dar de baja: ";
    cin >> idTurno;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nEntrada invalida.\n";}
    else{
        cin.ignore();}

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

    system("cls");
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
void TurnoManager::listar(int dniMedico){
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
         << setw(15) << "Fecha"
         << setw(6) << "Horario"
         << endl;

    cout << string(48, '-') << endl;///barra separadora

    for (int i = 0; i < cantReg; i++) {
        if (vec[i].getEstado() && vec[i].getDniMedico() == dniMedico) {
        cout << left
             << setw(12) << vec[i].getidTurno()
             << setw(15) << vec[i].getDniMedico()
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
void TurnoManager::modificar(){
    Turno reg;
    int idTurno;
    int pos;
    int opc;

    system("cls");
    listar();

    cout << "Ingrese el ID del turno a modificar: ";
    cin >> idTurno;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nEntrada invalida.\n";}
    else{
        cin.ignore();}

    pos = archivo.getPosicion(idTurno);
    if(pos==-1){cout << "\nEl registro no existe en el disco.\n";}

    if(pos!=-1){
    reg = archivo.leer(pos);

    system("cls");
    //print de tabla
    ///encabezado de columnas
    cout << left
         << setw(12)  << "ID Turno"
         << setw(15) << "DNI Medico"
         << setw(15) << "DNI Paciente"
         << setw(10) << "Importe"
         << setw(15) << "Fecha"
         << setw(6) << "Horario"
         << endl;

    cout << string(75, '-') << endl;///barra separadora

    cout << left
         << setw(12) << reg.getidTurno()
         << setw(15) << reg.getDniMedico()
         << setw(15) << reg.getDniPaciente()
         << setw(10) << reg.getImporteConsulta()
         << setw(15) << (to_string(reg.getFechaHoraAtencion().getDia())) + "/" +
                         to_string(reg.getFechaHoraAtencion().getMes()) + "/" +
                         to_string(reg.getFechaHoraAtencion().getAnio())
         << setw(6) << reg.getFechaHoraAtencion().getHora()
         << endl;

    cout << "\n1 - Medico";
    cout << "\n2 - Paciente";
    cout << "\n3 - Importe";
    cout << "\n4 - Fecha";
    cout << "\n5 - Horario\n";
    cout << "\nIndique el atributo a modificar: ";
    cin >> opc;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nEntrada invalida.\n";}
    else{
        cin.ignore();
        system("cls");}

    switch(opc){
    case 1:
        {int dniMedico = reg.getDniMedico();
        MedicoManager medicos;
        medicos.listar();

        do{
        cout << "Ingrese nuevo dni de medico: ";
        cin >> dniMedico;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "\nEntrada invalida.\n";}
        else{
            cin.ignore();
            reg.setDniMedico(dniMedico);}
        }while(dniMedico!=reg.getDniMedico());

        if(archivo.escribir(pos,reg)){
            cout << "\nRegistro modificado correctamente.\n";
        } else{
            cout << "\nSe produjo un error de escritura en disco.\n";}

        break;}
    case 2:
        {int dniPaciente = reg.getDniPaciente();
        PacienteManager pacientes;
        pacientes.listarPaciente();

        do{
        cout << "Ingrese nuevo dni de paciente: ";
        cin >> dniPaciente;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "\nEntrada invalida.\n";}
        else{
            cin.ignore();
            reg.setDniPaciente(dniPaciente);}
        }while(dniPaciente!=reg.getDniPaciente());

        if(archivo.escribir(pos,reg)){
            cout << "\nRegistro modificado correctamente.\n";
        } else{
            cout << "\nSe produjo un error de escritura en disco.\n";}

        break;}
    case 3:
        {float importeConsulta = reg.getImporteConsulta();

        do{
        cout << "\nIngrese nuevo importe (AR$): ";
        cin >> importeConsulta;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "\nEntrada invalida.\n";}
        else{
            cin.ignore();
            reg.setImporteConsulta(importeConsulta);}
        }while(importeConsulta!=reg.getImporteConsulta());

        if(archivo.escribir(pos,reg)){
            cout << "\nRegistro modificado correctamente.\n";
        } else{
            cout << "\nSe produjo un error de escritura en disco.\n";}
        break;}
    case 4:
        {FechaHora fechaHoraAtencion = reg.getFechaHoraAtencion();
        FechaHora aux;

        do{
        cout << "Ingrese nueva fecha de atencion\n";
        cout << "===============================\n";
        fechaHoraAtencion.cargarFecha();
        reg.setFechaHoraAtencion(fechaHoraAtencion);
        aux=reg.getFechaHoraAtencion();}
        while(fechaHoraAtencion!=aux);

        if(archivo.escribir(pos,reg)){
            cout << "\nRegistro modificado correctamente.\n";
        } else{
            cout << "\nSe produjo un error de escritura en disco.\n";}
        break;}
    case 5:
        {FechaHora fechaHoraAtencion = reg.getFechaHoraAtencion();
        FechaHora aux;

        do{
        cout << "Ingrese nueva hora de atencion\n";
        cout << "==============================\n";
        fechaHoraAtencion.cargarHora();
        reg.setFechaHoraAtencion(fechaHoraAtencion);
        aux=reg.getFechaHoraAtencion();}
        while(fechaHoraAtencion!=aux);

        if(archivo.escribir(pos,reg)){
            cout << "\nRegistro modificado correctamente.\n";
        } else{
            cout << "\nSe produjo un error de escritura en disco.\n";}
        break;}

    default:
        cout << "\nOpcion invalida.\n";
        break;}
    }
}
void TurnoManager::buscar(){
    Turno reg;
    int idTurno;
    int pos;

    cout << "\n<Buscar turno>\n";
    cout << "Ingrese el ID del turno: ";
    cin >> idTurno;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nEntrada invalida.\n";}
    else{
        cin.ignore();}

    pos = archivo.getPosicion(idTurno);
    if(pos==-1){cout << "\nEl registro no existe en el disco.\n";}

    if(pos!=-1){reg = archivo.leer(pos);

    ///print de tabla
    ///encabezado de columnas
    cout << endl;
    cout << left
         << setw(15) << "DNI Medico"
         << setw(15) << "DNI Paciente"
         << setw(10) << "Importe"
         << setw(15) << "Fecha"
         << setw(6) << "Horario"
         << endl;

    cout << string(62, '-') << endl;///barra separadora

    cout << left
     << setw(15) << reg.getDniMedico()
     << setw(15) << reg.getDniPaciente()
     << setw(10) << reg.getImporteConsulta()
     << setw(15) << (to_string(reg.getFechaHoraAtencion().getDia()) + "/" +
                     to_string(reg.getFechaHoraAtencion().getMes()) + "/" +
                     to_string(reg.getFechaHoraAtencion().getAnio()))
     << setw(6) << reg.getFechaHoraAtencion().getHora()
     << endl << endl;}
}
void TurnoManager::alta(int idTurno){
    Turno reg;
    int pos;

    pos = archivo.getPosicion(idTurno,false);
    if(pos==-1){cout << "\nEl registro no existe o ya se encuentra activo.\n"; return;}

    reg = archivo.leer(pos);
    reg.setEstado(true);
    if(archivo.escribir(pos,reg)){cout << "\nRegistro recuperado correctamente.\n";}
    else{cout << "\nSe produjo un error de escritura en disco.\n";}
}
void TurnoManager::exportarCSV(){
    int cantReg = archivo.getCantidadRegistros();
    Turno *vec;

    if(cantReg<=0){cout <<"No se registran turnos activos.\n";return;}

    vec = new Turno[cantReg];
    if(vec==nullptr){cout <<"\nSe produjo un error de asignacion de memoria.\n";return;}

    archivo.leer(cantReg,vec);

    cout << "dni_medico,dni_paciente,importe,fecha,horario\n";
    for(int i=0;i<cantReg;i++){
        if(vec[i].getEstado()){
        cout << vec[i].getDniMedico() << ",";
        cout << vec[i].getDniPaciente() << ",";
        cout << vec[i].getImporteConsulta() << ",";
        cout << vec[i].getFechaHoraAtencion().getDia() << "/";
        cout << vec[i].getFechaHoraAtencion().getMes() << "/";
        cout << vec[i].getFechaHoraAtencion().getAnio() << ",";
        cout << vec[i].getFechaHoraAtencion().getHora() << "\n";}}

    delete[] vec;
}

