#include <iostream>
#include "Configuracion.h"
#include "MedicoManager.h"

using namespace std;

void Configuracion::crearCopiaRespaldo(){}
void Configuracion::restaurarCopiaRespaldo(){}
void Configuracion::recuperarRegistro(){
    int opcion;
    do{
    system("cls");
    cout << "Entidades\n";
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
