#include <iostream>
#include "Menu.h"
#include "PacienteManager.h"
#include "MedicoManager.h"

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
        cin.ignore();

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
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << ">> ALTA de paciente\n";
                altaPaciente();
                break;
            case 2:
                cout << ">> BAJA de paciente\n";
                bajaPaciente();
                break;
            case 3:
                cout << ">> MODIFICAR paciente\n";
                modificarPAciente();
                break;
            case 4:
                cout << ">> LISTAR pacientes\n";
                listarPaciente();
                break;
            case 0:
                cout << "Volviendo al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
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
        cout << "0 - Volver al menu principal\n";
        cout << "--------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "\n<Alta de medico>\n";
                obj.alta();
                break;
            case 2:
                cout << "\n<Baja de medico>\n";
                obj.baja();
                break;
            case 3:
                cout << "\n<Modificar medico>\n";
                obj.modificar();
                break;
            case 4:
                cout << "\n<Listar medico>\n";
                obj.listar();
                break;
            case 0:
                cout << "Volviendo al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
        }
        system("pause");
    } while (opcion != 0);
}

void Menu::menuTurno() {
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
        cout << "0 - Volver al menu principal\n";
        cout << "--------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << ">> ALTA de turno\n";
                // Llamar a la función de alta aquí
                break;
            case 2:
                cout << ">> BAJA de turno\n";
                // Llamar a la función de baja aquí
                break;
            case 3:
                cout << ">> MODIFICAR turno\n";
                // Llamar a la función de modificar aquí
                break;
            case 4:
                cout << ">> LISTAR turnos\n";
                // Llamar a la función de listar aquí
                break;
            case 0:
                cout << "Volviendo al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
        }
        system("pause");
    } while (opcion != 0);
}


void Menu::menuObraSocial() {
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
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << ">> ALTA de obra social\n";
                // Llamar a la función de alta aquí
                break;
            case 2:
                cout << ">> BAJA de obra social\n";
                // Llamar a la función de baja aquí
                break;
            case 3:
                cout << ">> MODIFICAR obra social\n";
                // Llamar a la función de modificar aquí
                break;
            case 4:
                cout << ">> LISTAR obras sociales\n";
                // Llamar a la función de listar aquí
                break;
            case 0:
                cout << "Volviendo al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
        }
        system("pause");
    } while (opcion != 0);
}


void Menu::menuEspecialidad() {
    int opcion;
    do {
        system("cls");
        cout << "================================\n";
        cout << "\tMENU ESPECIALIDADES \n";
        cout << "================================\n";
        cout << "1 - Alta de especialidad\n";
        cout << "2 - Baja de especialidad\n";
        cout << "3 - Modificar especialidad\n";
        cout << "4 - Listar especialidades\n";
        cout << "0 - Volver al menu principal\n";
        cout << "--------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << ">> ALTA de especialidad\n";
                // Llamar a la función de alta aquí
                break;
            case 2:
                cout << ">> BAJA de especialidad\n";
                // Llamar a la función de baja aquí
                break;
            case 3:
                cout << ">> MODIFICAR especialidad\n";
                // Llamar a la función de modificar aquí
                break;
            case 4:
                cout << ">> LISTAR especialidades\n";
                // Llamar a la función de listar aquí
                break;
            case 0:
                cout << "Volviendo al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
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
    system("cls");
    cout << "---- CONFIGURACION ----\n";
    system("pause");
}
