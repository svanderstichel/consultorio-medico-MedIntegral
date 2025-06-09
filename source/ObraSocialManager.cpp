#include <iostream>
#include <iomanip>
#include <cstring>  // NECESARIO para usar strlen()
#include "ObraSocialManager.h"
#include "ObraSocial.h"

using namespace std;

void ObraSocialManager::altaObraSocial() {
    ObraSocial reg;
    int codigo;
    char nombre[50];  // reemplaza std::string
    int intentos = 0;

    ///asignacion de id autoincremental
    codigo=archivo.getCantidadRegistros()+1;
    ///inicializa el primer id en 1
    if(codigo==0){codigo++;}
    reg.setCodigoObraSocial(codigo);

    // Ingreso de nombre
    while (strlen(reg.getNombre()) == 0 && intentos <= 3) {
        cout << "Ingrese nombre de la obra social: ";
        cin.getline(nombre, 50);
        reg.setNombre(nombre);
        intentos++;
    }

    if (intentos > 3) {
        cout << "\nExcedio el limite de intentos.\n";
        return;
    }

    // Escritura en archivo
    if (archivo.escribir(reg)) {
        cout << "\nObra social cargada correctamente.\n";
    } else {
        cout << "\nError al escribir en disco.\n";
    }
}

void ObraSocialManager::listarObraSocial() {
    int cantidad = archivo.getCantidadRegistros();
    ObraSocial* vec;

    if (cantidad <= 0) {
        cout << "No hay obras sociales registradas.\n";
        return;
    }

    vec = new ObraSocial[cantidad];
    if (vec == nullptr) {
        cout << "Error al reservar memoria.\n";
        return;
    }

    archivo.leer(cantidad, vec);

    // Encabezado
    cout << left
        << setw(15) << "Codigo"
        << setw(30) << "Nombre"
        << endl;
    cout << string(45, '-') << endl;

    for (int i = 0; i < cantidad; i++) {
        if (vec[i].getEstado()) {
            cout << left
                << setw(15) << vec[i].getCodigoObraSocial()
                << setw(30) << vec[i].getNombre()
                << endl;
        }
    }

    delete[] vec;
    cout << endl;
}

void ObraSocialManager::bajaObraSocial() {
    int codigo;
    int pos;
    ObraSocial reg;

    cout << "Ingrese el codigo de la obra social a dar de baja: ";
    cin >> codigo;
    cin.ignore();

    pos = archivo.getPosicion(codigo);
    if (pos == -1) {
        cout << "\nRegistro no encontrado.\n";
        return;
    }

    reg = archivo.leer(pos);
    reg.setEstado(false);

    if (archivo.escribir(pos, reg)) {
        cout << "\nObra social dada de baja correctamente.\n";
    } else {
        cout << "\nError al modificar el archivo.\n";
    }
}

void ObraSocialManager::modificarObraSocial() {
    int codigo, pos;
    ObraSocial reg;
    char nombre[50];

    cout << "\nIngresar codigo de obra social a modificar (0 para cancelar): ";
    cin >> codigo;
    cin.ignore();

    if (codigo == 0) {
        cout << "Operación cancelada por el usuario.\n";
        return;
    }

    pos = archivo.getPosicion(codigo);
    if (pos == -1) {
        cout << "El código no existe.\n";
        cout << "\nObras sociales disponibles:\n\n";
        listarObraSocial();
        return;
    }

    reg = archivo.leer(pos);
    cout << "\nNombre actual: " << reg.getNombre() << endl;

    cout << "Ingresar nuevo nombre de obra social: ";
    cin.getline(nombre, 50);

    if (strlen(nombre) == 0) {
        cout << "El nombre no puede estar vacío.\n";
        return;
    }

    if (!reg.setNombre(nombre)) {
        cout << "Error. Nombre inválido o demasiado largo.\n";
        return;
    }

    if (archivo.escribir(pos, reg)) {
        cout << "\nRegistro modificado correctamente.\n";
    } else {
        cout << "\nSe produjo un error de escritura en disco.\n";
    }
}

