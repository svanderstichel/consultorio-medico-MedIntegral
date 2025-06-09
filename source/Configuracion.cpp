#include <iostream>
#include "Configuracion.h"
#include "ConfiguracionArchivo.h"
#include "MedicoManager.h"
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
    cin.ignore();

    switch(opcion){
        case 1:
            {
                ConfiguracionArchivo archivo("medicos.dat");
                if(archivo.crearCopia()){cout << "\n\nCopia de respaldo creada en el directorio /backup.\n\n";}
                else{cout << "\n\nNo se pudo generar la copia de respaldo.\n\n";}
            }
            break;
        case 2:
        {
            ConfiguracionArchivo archivo("pacientes.dat");
            if(archivo.crearCopia()){cout << "\n\nCopia de respaldo creada en el directorio /backup.\n\n";}
            else{cout << "\n\nNo se pudo generar la copia de respaldo.\n\n";}
        }
        break;
            case 3:
        {
            ConfiguracionArchivo archivo("turnos.dat");
            if(archivo.crearCopia()){cout << "\n\nCopia de respaldo creada en el directorio /backup.\n\n";}
            else{cout << "\n\nNo se pudo generar la copia de respaldo.\n\n";}
        }
        break;
            case 4:
        {
            ConfiguracionArchivo archivo("obrasocial.dat");
            if(archivo.crearCopia()){cout << "\n\nCopia de respaldo creada en el directorio /backup.\n\n";}
            else{cout << "\n\nNo se pudo generar la copia de respaldo.\n\n";}
        }
        break;
            case 5:
        {
            ConfiguracionArchivo archivo("especialidad.dat");
            if(archivo.crearCopia()){cout << "\n\nCopia de respaldo creada en el directorio /backup.\n\n";}
            else{cout << "\n\nNo se pudo generar la copia de respaldo.\n\n";}
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
            {cout << "\n\nCopia de respaldo creada en el directorio /backup.\n\n";}
            else{cout << "\n\nNo se pudo generar la copia de respaldo.\n\n";}
        }
        break;
        default:
            break;}

    system("pause");
    }while(opcion!=0);

}
void Configuracion::restaurarCopiaRespaldo(){}
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
    cin.ignore();

    switch(opcion){
        case 1:{
            int dni;
            MedicoManager obj;

            cout << "\nIngrese el DNI del registro que desea restaurar: ";
            cin >> dni;

            obj.alta(dni);
            break;}
        default:
            break;
            }
    system("pause");
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
    cin.ignore();

    switch(opcion){
        case 1:{
            MedicoManager obj;
            cout << "\nExportando CSV...\n\n";
            system("pause");
            cout << endl << endl;
            obj.exportarCSV();
            cout << endl;
            break;}
        default:
            break;
            }
    system("pause");
    }while(opcion!=0);
}
