#include <iostream>
#include <limits>
#include "Configuracion.h"
#include "ConfiguracionArchivo.h"
#include "MedicoManager.h"
#include "PacienteManager.h"
#include "EspecialidadManager.h"
#include "ObraSocialManager.h"
#include "TurnoManager.h"
#include "ConfiguracionArchivo.h"

using namespace std;

void Configuracion::crearCopiaRespaldo(){
    int opcion;
    do{
    system("cls");
    cout << "ARCHIVOS\n";
    cout << "---------\n";
    cout << "1 - medicos.dat\n";
    cout << "2 - pacientes.dat\n";
    cout << "3 - turnos.dat\n";
    cout << "4 - obrassociales.dat\n";
    cout << "5 - especialidades.dat\n";
    cout << "6 - respaldar todos\n";
    cout << "\n0 - Volver al menu anterior\n";
    cout << "---------------------------\n";
    cout << "Seleccione archivo a respaldar: ";
    cin >> opcion;
    if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            opcion=-1;}
    else{cin.ignore();}

    switch(opcion){
        case 1:
            {
                ConfiguracionArchivo archivo("medicos.dat");
                if(archivo.crearCopia()){cout << "\n\nCopia de respaldo creada en el directorio /backup.\n\n";}
                else{cout << "\n\nNo se pudo generar la copia de respaldo.\n\n";}
                system("pause");
            }
            break;
        case 2:
        {
            ConfiguracionArchivo archivo("pacientes.dat");
            if(archivo.crearCopia()){cout << "\n\nCopia de respaldo creada en el directorio /backup.\n\n";}
            else{cout << "\n\nNo se pudo generar la copia de respaldo.\n\n";}
            system("pause");
        }
        break;
            case 3:
        {
            ConfiguracionArchivo archivo("turnos.dat");
            if(archivo.crearCopia()){cout << "\n\nCopia de respaldo creada en el directorio /backup.\n\n";}
            else{cout << "\n\nNo se pudo generar la copia de respaldo.\n\n";}
            system("pause");
        }
        break;
            case 4:
        {
            ConfiguracionArchivo archivo("obrassociales.dat");
            if(archivo.crearCopia()){cout << "\n\nCopia de respaldo creada en el directorio /backup.\n\n";}
            else{cout << "\n\nNo se pudo generar la copia de respaldo.\n\n";}
            system("pause");
        }
        break;
            case 5:
        {
            ConfiguracionArchivo archivo("especialidades.dat");
            if(archivo.crearCopia()){cout << "\n\nCopia de respaldo creada en el directorio /backup.\n\n";}
            else{cout << "\n\nNo se pudo generar la copia de respaldo.\n\n";}
            system("pause");
        }
        break;
            case 6:
        {
            ConfiguracionArchivo archivoMedicos("medicos.dat");
            ConfiguracionArchivo archivoPacientes("pacientes.dat");
            ConfiguracionArchivo archivoTurnos("turnos.dat");
            ConfiguracionArchivo archivoObrasocial("obrassociales.dat");
            ConfiguracionArchivo archivoEspecialidades("especialidades.dat");
            if(archivoMedicos.crearCopia() &&
               archivoPacientes.crearCopia() &&
               archivoObrasocial.crearCopia() &&
               archivoEspecialidades.crearCopia() &&
               archivoTurnos.crearCopia())
            {cout << "\n\nCopias de respaldo creadas en el directorio /backup.\n\n";}
            else{cout << "\n\nNo se pudo generar las copias de respaldo.\n\n";}
            system("pause");
        }
            break;
        case 0:
            cout << "\nVolviendo al menu anterior...\n\n";
            break;
        default:
            cout << "\nOpcion invalida\n";
            system("pause");
            break;}

    }while(opcion!=0);

}
void Configuracion::restaurarCopiaRespaldo(){

    int opcion;
    do{
    system("cls");
    cout << "ARCHIVOS\n";
    cout << "---------\n";
    cout << "1 - medicos.dat\n";
    cout << "2 - pacientes.dat\n";
    cout << "3 - turnos.dat\n";
    cout << "4 - obrassociales.dat\n";
    cout << "5 - especialidades.dat\n";
    cout << "6 - restaurar todos\n";
    cout << "\n0 - Volver al menu anterior\n";
    cout << "---------------------------\n";
    cout << "Seleccione archivo a restaurar: ";
    cin >> opcion;
    if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            opcion=-1;}
    else{cin.ignore();}

    switch(opcion){
        case 1:
            {
                ConfiguracionArchivo archivo("medicos.dat");
                if(archivo.restaurarCopia()){cout << "\n\nCopia de respaldo restaurada desde el directorio /backup.\n\n";}
                else{cout << "\n\nNo se pudo restaurar la copia de respaldo.\n\n";}
                system("pause");
            }
            break;
        case 2:
        {
            ConfiguracionArchivo archivo("pacientes.dat");
            if(archivo.restaurarCopia()){cout << "\n\nCopia de respaldo restaurada desde el directorio /backup.\n\n";}
            else{cout << "\n\nNo se pudo restaurar la copia de respaldo.\n\n";}
            system("pause");
        }
        break;
            case 3:
        {
            ConfiguracionArchivo archivo("turnos.dat");
            if(archivo.restaurarCopia()){cout << "\n\nCopia de respaldo restaurada desde el directorio /backup.\n\n";}
            else{cout << "\n\nNo se pudo restaurar la copia de respaldo.\n\n";}
            system("pause");
        }
        break;
            case 4:
        {
            ConfiguracionArchivo archivo("obrassociales.dat");
            if(archivo.restaurarCopia()){cout << "\n\nCopia de respaldo restaurada desde el directorio /backup.\n\n";}
            else{cout << "\n\nNo se pudo restaurar la copia de respaldo.\n\n";}
            system("pause");
        }
        break;
            case 5:
        {
            ConfiguracionArchivo archivo("especialidades.dat");
            if(archivo.restaurarCopia()){cout << "\n\nCopia de respaldo restaurada desde el directorio /backup.\n\n";}
            else{cout << "\n\nNo se pudo restaurar la copia de respaldo.\n\n";}
            system("pause");
        }
        break;
            case 6:
        {
            ConfiguracionArchivo archivoMedicos("medicos.dat");
            ConfiguracionArchivo archivoPacientes("pacientes.dat");
            ConfiguracionArchivo archivoTurnos("turnos.dat");
            ConfiguracionArchivo archivoObrasocial("obrassociales.dat");
            ConfiguracionArchivo archivoEspecialidades("especialidades.dat");
            if(archivoMedicos.restaurarCopia() &&
               archivoPacientes.restaurarCopia() &&
               archivoObrasocial.restaurarCopia() &&
               archivoEspecialidades.restaurarCopia() &&
               archivoTurnos.restaurarCopia())
            {cout << "\n\nCopias de respaldo restauradas desde el directorio /backup.\n\n";}
            else{cout << "\n\nNo se pudo restaurar las copias de respaldo.\n\n";}
            system("pause");
        }
            break;
        case 0:
            cout << "\nVolviendo al menu anterior...\n\n";
            break;
        default:
            cout << "\nOpcion invalida\n";
            system("pause");
            break;}

    }while(opcion!=0);

}
void Configuracion::recuperarRegistro(){
    int opcion;
    do{
    system("cls");
    cout << "ENTIDADES\n";
    cout << "---------\n";
    cout << "1 - Medicos\n";
    cout << "2 - Pacientes\n";
    cout << "3 - Turnos\n";
    cout << "4 - Obra Social\n";
    cout << "5 - Especialidad\n";
    cout << "\n0 - Volver al menu anterior\n";
    cout << "---------------------------\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            opcion=-1;}
    else{cin.ignore();}

    switch(opcion){
        case 1:{
            int dni;
            MedicoManager obj;

            cout << "\nIngrese el DNI del registro que desea restaurar: ";
            cin >> dni;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');}
            else{cin.ignore();}

            obj.alta(dni);
            system("pause");
            break;}
        case 2:{
            int dni;
            PacienteManager obj;

            cout << "\nIngrese el DNI del registro que desea restaurar: ";
            cin >> dni;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');}
            else{cin.ignore();}

            obj.altaPaciente(dni);
            system("pause");
            break;}
        case 3:{
            int idTurno;
            TurnoManager obj;

            cout << "\nIngrese el id del turno que desea restaurar: ";
            cin >> idTurno;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');}
            else{cin.ignore();}

            obj.alta(idTurno);
            system("pause");
            break;}
        case 4:{
            int codObraSocial;
            ObraSocialManager obj;

            cout << "\nIngrese el codigo de obra social que desea restaurar: ";
            cin >> codObraSocial;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');}
            else{cin.ignore();}

            obj.altaObraSocial(codObraSocial);
            system("pause");
            break;}
        case 5:{
            int codEspecialidad;
            EspecialidadManager obj;

            cout << "\nIngrese el codigo de especialidad que desea restaurar: ";
            cin >> codEspecialidad;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');}
            else{cin.ignore();}

            obj.altaEspecialidad(codEspecialidad);
            system("pause");
            break;}
        case 0:
            cout << "\nVolviendo al menu anterior...\n\n";
            break;
        default:
            cout << "\nOpcion invalida\n";
            system("pause");
            break;
            }
    }while(opcion!=0);
}
void Configuracion::exportarCSV(){
    int opcion;
    do{
    system("cls");
    cout << "Archivos\n";
    cout << "--------\n";
    cout << "1 - medicos.csv\n";
    cout << "2 - pacientes.csv\n";
    cout << "3 - turnos.csv\n";
    cout << "4 - obrasocial.csv\n";
    cout << "5 - especialidades.csv\n";
    cout << "\n0 - Volver al menu anterior\n";
    cout << "---------------------------\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            opcion=-1;}
    else{cin.ignore();}

    switch(opcion){
        case 1:{
            MedicoManager obj;
            cout << "\nExportando CSV...\n\n";
            system("pause");
            cout << endl << endl;
            obj.exportarCSV();
            cout << endl;
            break;}
        case 0:
            cout << "\nVolviendo al menu anterior...\n\n";
            break;
        default:
            cout << "\nOpcion invalida\n";
            system("pause");
            break;
            }
    }while(opcion!=0);
}
