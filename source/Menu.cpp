#include <iostream>
#include <limits>
#include "Menu.h"
#include "PacienteManager.h"
#include "MedicoManager.h"
#include "ObraSocialManager.h"
#include "TurnoManager.h"
#include "EspecialidadManager.h"
#include "Configuracion.h"

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
                cout << "\n<Alta de paciente>\n\n";
                obj.altaPaciente();
                break;
            case 2:
                cout << "\n<Baja de paciente>\n\n";
                obj.bajaPaciente();
                break;
            case 3:
                cout << "\n<Modificar paciente>\n\n";
                obj.modificarPAciente();
                break;
            case 4:
                cout << "\n<Listar pacientes>\n\n";
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
                cout << "\n<Alta de medico>\n\n";
                obj.alta();
                break;
            case 2:
                cout << "\n<Baja de medico>\n\n";
                obj.baja();
                break;
            case 3:
                cout << "\n<Modificar medico>\n\n";
                obj.modificar();
                break;
            case 4:
                cout << "\n<Listar medicos>\n\n";
                obj.listar();
                break;
            case 5:
                cout << "\n<Buscar medico>\n\n";
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
                cout << "\n<Alta de turno>\n\n";
                manager.alta();
                break;
            case 2:
                cout << "\n<Baja de turno>\n\n";
                manager.baja();
                break;
            case 3:
                cout << "\n<Modificar turno>\n\n";
                manager.modificar();
                break;
            case 4:
                cout << "\n<Listar turnos>\n\n";
                manager.listar();
                break;
            case 5:
                cout << "\n<Buscar turno>\n\n";
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
                cout << "\n<Alta de obra social>\n\n";
                obj.altaObraSocial();
                break;
            case 2:
                cout << "\n<Baja de obra social>\n\n";
                obj.bajaObraSocial();
                break;
            case 3:
                cout << "\n<Modificar obras sociales>\n\n";
                obj.modificarObraSocial();
                break;
            case 4:
                cout << "\n<Listar obras sociales>\n\n";
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
                cout << "\n<Nueva especialidad>\n\n";
                obj.altaEspecialidad();
                break;
            case 2:
                cout << "\n<Baja especialidad>\n\n";
                obj.bajaEspecialidad();
                break;
            case 3:
                cout << "\n<Modificar especialidad>\n\n";
                obj.modificarEspecialidad();
                break;
            case 4:
                cout << "\n<Listar especialidades>\n\n";
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
    system("cls");
    cout << "---- REPORTES ----\n";
    system("pause");
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
