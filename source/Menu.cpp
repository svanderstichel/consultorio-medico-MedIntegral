#include <iostream>
#include <limits>
#include "Menu.h"
#include "PacienteManager.h"
#include "MedicoManager.h"
#include "ObraSocialManager.h"
#include "TurnoManager.h"
#include "EspecialidadManager.h"
#include "Configuracion.h"
#include "Reporte.h"

using namespace std;

void Menu::menuPrincipal(){
    int opcion;
    do {
        system("cls");
        cout << "======================================\n";
        cout << "   CONSULTORIO MEDICO MedIntegral\n";
        cout << "======================================\n";
        cout << "1 - Pacientes\n";
        cout << "2 - Medicos\n";
        cout << "3 - Turnos\n";
        cout << "4 - Obras Sociales\n";
        cout << "5 - Especialidades\n";
        cout << "6 - Reportes\n";
        cout << "7 - Configuracion\n";
        cout << "0 - Salir\n";
        cout << "--------------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            opcion=-1;}
        else{cin.ignore();}

         switch (opcion) {
            case 1: menuPaciente(); break;
            case 2: menuMedico(); break;
            case 3: menuTurno(); break;
            case 4: menuObraSocial(); break;
            case 5: menuEspecialidad(); break;
            case 6: menuReportes(); break;
            case 7: menuConfiguracion(); break;
            case 0:
                cout << "Saliendo del programa...\n";
                system("pause");
                break;
            default:
                cout << "Opcion invalida.\n";
                system("pause");
                break;
            }
    }while(opcion != 0);
}

void Menu::menuPaciente() {
    PacienteManager obj;
    int opcion;
    do {
        system("cls");
        cout << "================================\n";
        cout << "\tMENU PACIENTES \n";
        cout << "================================\n";
        cout << "1 - Alta de paciente\n";
        cout << "2 - Baja de paciente\n";
        cout << "3 - Modificar paciente\n";
        cout << "4 - Listar pacientes\n";
        cout << "0 - Volver al menu principal\n";
        cout << "--------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            opcion=-1;}
        else{cin.ignore();}

        switch (opcion) {
            case 1:
                obj.altaPaciente();
                break;
            case 2:
                obj.bajaPaciente();
                break;
            case 3:
                obj.modificarPAciente();
                break;
            case 4:
                obj.listarPaciente();
                break;
            case 0:
                cout << "\nVolviendo al menu principal...\n\n";
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n\n";
        }
        system("pause");
    } while (opcion != 0);
}

void Menu::menuMedico() {
    MedicoManager obj;
    int opcion;

    do {
        system("cls");
        cout << "================================\n";
        cout << "\tMENU MEDICOS \n";
        cout << "================================\n";
        cout << "1 - Alta de medico\n";
        cout << "2 - Baja de medico\n";
        cout << "3 - Modificar medico\n";
        cout << "4 - Listar medicos\n";
        cout << "5 - Buscar medico\n";
        cout << "0 - Volver al menu principal\n";
        cout << "--------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            opcion=-1;}
        else{cin.ignore();}

        switch (opcion) {
            case 1:
                obj.alta();
                break;
            case 2:
                obj.baja();
                break;
            case 3:
                obj.modificar();
                break;
            case 4:
                obj.listar();
                break;
            case 5:
                obj.buscar();
                break;
            case 0:
                cout << "\nVolviendo al menu principal...\n\n";
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n\n";
        }
        system("pause");
    } while (opcion != 0);
}

void Menu::menuTurno() {
    TurnoManager manager;
    int opcion;
    do {
        system("cls");
        cout << "================================\n";
        cout << "\tMENU TURNOS \n";
        cout << "================================\n";
        cout << "1 - Alta de turno\n";
        cout << "2 - Baja de turno\n";
        cout << "3 - Modificar turno\n";
        cout << "4 - Listar turnos\n";
        cout << "5 - Buscar turno\n";
        cout << "0 - Volver al menu principal\n";
        cout << "--------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            opcion=-1;}
        else{cin.ignore();}

        switch (opcion) {
            case 1:
                manager.alta();
                break;
            case 2:
                manager.baja();
                break;
            case 3:
                manager.modificar();
                break;
            case 4:
                manager.listar();
                break;
            case 5:
                manager.buscar();
                break;
            case 0:
                cout << "\nVolviendo al menu principal...\n\n";
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n\n";
        }
        system("pause");
    } while (opcion != 0);
}


void Menu::menuObraSocial() {
    ObraSocialManager obj;
    int opcion;
    do {
        system("cls");
        cout << "================================\n";
        cout << "\tMENU OBRAS SOCIALES \n";
        cout << "================================\n";
        cout << "1 - Alta de obra social\n";
        cout << "2 - Baja de obra social\n";
        cout << "3 - Modificar obra social\n";
        cout << "4 - Listar obras sociales\n";
        cout << "0 - Volver al menu principal\n";
        cout << "--------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            opcion=-1;}
        else{cin.ignore();}

        switch (opcion) {
            case 1:
                obj.altaObraSocial();
                break;
            case 2:
                obj.bajaObraSocial();
                break;
            case 3:
                obj.modificarObraSocial();
                break;
            case 4:
                obj.listarObraSocial();
                break;
            case 0:
                cout << "\nVolviendo al menu principal...\n";
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
        }
        system("pause");
    } while (opcion != 0);
}


void Menu::menuEspecialidad() {
    EspecialidadManager obj;
    int opcion;
    do {
        system("cls");
        cout << "================================\n";
        cout << "\tMENU ESPECIALIDADES \n";
        cout << "================================\n";
        cout << "1 - Nueva especialidad\n";
        cout << "2 - Baja de especialidad\n";
        cout << "3 - Modificar especialidad\n";
        cout << "4 - Listar especialidades\n";
        cout << "0 - Volver al menu principal\n";
        cout << "--------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            opcion=-1;}
        else{cin.ignore();}

        switch (opcion) {
            case 1:
                obj.altaEspecialidad();
                break;
            case 2:
                obj.bajaEspecialidad();
                break;
            case 3:
                obj.modificarEspecialidad();
                break;
            case 4:
                obj.listarEspecialidad();
                break;
            case 0:
                cout << "\nVolviendo al menu principal...\n\n";
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n\n";
        }
        system("pause");
    } while (opcion != 0);
}


void Menu::menuReportes() {
    Reporte obj;
    int opcion;
    do {
        system("cls");
        cout << "================================\n";
        cout << "\tMENU REPORTES\n";
        cout << "================================\n";
        cout << "1 - Recaudacion anual/mensual\n";
        cout << "2 - Recaudacion segun obra social\n";
        cout << "3 - Recaudacion segun especialidad\n";
        cout << "4 - Cantidad pacientes por medico\n";
        cout << "5 - Cantidad de turnos por medico\n";
        cout << "6 - Cantidad de turnos por paciente\n";
        cout << "0 - Volver al menu principal\n";
        cout << "--------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            opcion=-1;}
        else{cin.ignore();}

        switch (opcion) {
            case 1:
                obj.recaudacionAnualMensual();
                break;
            case 2:
                obj.recaudacionObraSocial();
                break;
            case 3:
                obj.recaudacionEspecialidad();
                break;
            case 4:
                obj.cantidadPacientesMedico();
                break;
            case 5:
                obj.cantidadTurnosMedico();
                break;
            case 6:
                obj.cantidadTurnosPaciente();
                break;
            case 0:
                cout << "\nVolviendo al menu principal...\n\n";
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n\n";
        }
        system("pause");
    } while (opcion != 0);
}

void Menu::menuConfiguracion() {
    Configuracion obj;
    int opcion;
    do {
        system("cls");
        cout << "================================\n";
        cout << "\tMENU CONFIGURACION\n";
        cout << "================================\n";
        cout << "1 - Realizar copia de respaldo\n";
        cout << "2 - Restaurar copia de respaldo\n";
        cout << "3 - Recuperar registro eliminado\n";
        cout << "4 - Exportar datos CSV\n";
        cout << "0 - Volver al menu principal\n";
        cout << "--------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            opcion=-1;}
        else{cin.ignore();}

        switch (opcion) {
            case 1:
                obj.crearCopiaRespaldo();
                break;
            case 2:
                obj.restaurarCopiaRespaldo();
                break;
            case 3:
                cout << "\n<Recuperar regisro>\n\n";
                obj.recuperarRegistro();
                break;
            case 4:
                obj.exportarCSV();
                break;
            case 0:
                cout << "\nVolviendo al menu principal...\n\n";
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n\n";
        }
        system("pause");
    } while (opcion != 0);
}
