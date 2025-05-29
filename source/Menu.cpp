#include <iostream>
#include "Menu.h"

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
    system("cls");
    cout << "---- PACIENTES ----\n";
    system("pause");
}

void Menu::menuMedico() {
    system("cls");
    cout << "---- MEDICOS ----\n";
    system("pause");
}

void Menu::menuTurno() {
    system("cls");
    cout << "---- TURNOS ----\n";
    system("pause");
}

void Menu::menuObraSocial() {
    system("cls");
    cout << "---- OBRAS SOCIALES ----\n";
    system("pause");
}

void Menu::menuEspecialidad() {
    system("cls");
    cout << "---- ESPECIALIDADES ----\n";
    system("pause");
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
