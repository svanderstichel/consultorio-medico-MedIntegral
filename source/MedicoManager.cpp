#include <iostream>
#include <string>
#include "Medico.h"
#include "MedicoManager.h"
#include "FechaHora.h"

using namespace std;

void MedicoManager::alta(){
    int dni,codigoEspecialidad;
    string apellido,nombre,telefono,email;
    FechaHora fechaNacimiento;


    cout << "\nIngrese DNI: ";
    cin >> dni;
    cin.ignore();

    cout << "Ingrese Apellido: ";
    getline(cin, apellido);

    cout << "Ingrese Nombre: ";
    getline(cin, nombre);

    cout << "Ingrese Telefono: ";
    getline(cin, telefono);

    cout << "Ingrese Email: ";
    getline(cin, email);

    cout << "Ingrese Codigo de Especialidad: ";
    cin >> codigoEspecialidad;
    cin.ignore();

    cout << "Ingrese Fecha de Nacimiento:\n";
    fechaNacimiento.cargarFecha();

    Medico reg(dni,apellido,nombre,telefono,email,true,codigoEspecialidad,fechaNacimiento);
    if(archivo.escribir(reg)){
        cout <<"\nMedico cargado correctamente!";
    } else{
        cout <<"\nSe produjo un error inesperado.";
    }
}
void MedicoManager::baja(){return;}
void MedicoManager::modificar(){return;}
void MedicoManager::listar(){return;}
