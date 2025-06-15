#include <iostream>
#include <iomanip>
#include <cstring>
#include <limits>
#include "ObraSocialManager.h"
#include "ObraSocial.h"

using namespace std;

void ObraSocialManager::altaObraSocial() {
    ObraSocial reg;
    int codigo;
    string nombre;
    int intentos = 0;

    ///ASIGNACION ID AUTOINCREMENTAL
    codigo=archivo.getCantidadRegistros()+1;
    //inicializa el primer id en 1
    if(codigo==0){codigo++;}
    reg.setCodigoObraSocial(codigo);

    ///***CARGA DE DATOS***
    ///NOMBRE OBRA SOCIAL
    while (reg.getNombre().size() == 0 && intentos < 3) {
        cout << "Ingrese nombre de la obra social: ";
        getline(cin,nombre);
        reg.setNombre(nombre);
        intentos++;}

    //validar limite de intentos
    if (intentos == 3 && reg.getNombre().size() == 0){
        cout << "\nExcedio el limite de intentos.\n";
        return;}

    ///ESCRITURA EN DISCO
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
    cout << string(35, '-') << endl;

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

    system("cls");
    cout << "OBRAS SOCIALES";
    cout << "\n==============\n\n";
    listarObraSocial();

    cout << "Ingrese el codigo de la obra social a dar de baja: ";
    cin >> codigo;

    //validar ingreso de dato valido
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nEntrada invalida.\n";
        return;}
    else{cin.ignore();}

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
    string nombre;

    //listar obras sociales
    system("cls");
    cout << "OBRAS SOCIALES";
    cout << "\n==============\n\n";
    listarObraSocial();

    ///INGRESO ID A MODIFICAR
    cout << "\nIngresar codigo de obra social a modificar (0 para cancelar): ";
    cin >> codigo;
    //validar valor numerico, limpiar error y buffer teclado
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nEntrada invalida.\n";
        return;}
    else{cin.ignore();}

    if (codigo == 0) {
        cout << "Operacion cancelada por el usuario.\n";
        return;
    }

    pos = archivo.getPosicion(codigo);
    if (pos == -1) {
        cout << "El codigo no existe.\n";
        return;
    }

    reg = archivo.leer(pos);
    cout << "\nNombre actual: " << reg.getNombre() << endl;

    ///CARGA NUEVO NOMBRE OBRA SOCIAL
    cout << "Ingresar nuevo nombre de obra social: ";
    getline(cin,nombre);

    //validar nuevo nombre de obra social
    if (nombre.size() == 0){
        cout << "El nombre no puede estar vacio.\n";
        return;}
    if(!reg.setNombre(nombre)){return;}

    ///ESCRITURA EN DISCO
    if (archivo.escribir(pos, reg)) {cout << "\nRegistro modificado correctamente.\n";}
        else {cout << "\nSe produjo un error de escritura en disco.\n";}
}
void ObraSocialManager::altaObraSocial(int codObraSocial){
    ObraSocial reg;
    int pos;

    pos = archivo.getPosicion(codObraSocial,false);
    if(pos==-1){cout << "\nEl registro no existe o ya se encuentra activo.\n"; return;}

    reg = archivo.leer(pos);
    reg.setEstado(true);
    if(archivo.escribir(pos,reg)){cout << "\nRegistro recuperado correctamente.\n";}
    else{cout << "\nSe produjo un error de escritura en disco.\n";}
}
