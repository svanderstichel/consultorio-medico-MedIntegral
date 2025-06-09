#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "Especialidad.h"
#include "EspecialidadManager.h"

using namespace std;

void EspecialidadManager::altaEspecialidad() {
    int codEspecialidad;
    std::string nombre;
    Especialidad reg;

    ///asignacion de id autoincremental
    codEspecialidad=archivo.getCantidadRegistros()+1;
    ///inicializa el primer id en 1
    if(codEspecialidad==0){codEspecialidad++;}
    reg.setCodEspecialidad(codEspecialidad);

    cout << "Ingresar Nombre: ";
    getline(cin, nombre);

    if (nombre.empty()) {
        cout << "Error. Nombre vacio. Intente nuevamente.\n";
        return;}

    if (!reg.setNombre(nombre)){
        cout << "El nombre es demasiado largo. Intente nuevamente.\n";
        return;}

    if (archivo.escribir(reg)) {
        cout << "\nEspecialidad cargada correctamente.\n";
    } else {
        cout << "\nSe produjo un error de escritura en disco.\n";
    }
}

void EspecialidadManager::bajaEspecialidad(){
    Especialidad reg;
    int codEspecialidad, pos;

    cout << "Ingrese el codigo de especialidad: ";
    cin >> codEspecialidad;
    cin.ignore();

    pos = archivo.getPosicion(codEspecialidad);
    if(pos==-1){cout << "\nEl registro no existe en el disco.\n";}

    if(pos!=-1){
    reg = archivo.leer(pos);
    reg.setEstado(false);
    if(archivo.escribir(pos,reg)){
            cout << "\nLa especialidad fue dada de baja correctamente.\n";
        }else{cout << "\nSe produjo un error de escritura en el disco.\n";}
    }
}

void EspecialidadManager::modificarEspecialidad() {
    Especialidad reg;
    string nombre;
    int codEspecialidad, pos;

    cout << "\nIngresar codigo de especialidad a modificar (0 para cancelar): ";
    cin >> codEspecialidad;
    cin.ignore();

    if (codEspecialidad == 0) {
        cout << "Operación cancelada por el usuario.\n";
        return;}

    pos = archivo.getPosicion(codEspecialidad);
    if (pos == -1) {
        cout << "El codigo no existe.\n";
        cout << "Especialidades disponibles:\n\n\n";
        listarEspecialidad();
        return;}


    reg = archivo.leer(pos);
    cout << "\nNombre actual: " << reg.getNombre() << endl;


    cout << "Ingresar nuevo nombre de especialidad: ";
    getline(cin, nombre);

    if (nombre.empty()) {
        cout << "El nombre no puede estar vacio.\n";
        return;}

    if (!reg.setNombre(nombre)) {
        cout << "Error. Nombre demasiado largo. Intente nuevamente.\n";
        return;}

    if (archivo.escribir(pos, reg)) {
        cout << "\nRegistro modificado correctamente.\n";
    } else {
        cout << "\nSe produjo un error de escritura en disco.\n";
    }
}

void EspecialidadManager::listarEspecialidad(){
int cantReg = archivo.getCantidadRegistros();
    Especialidad *vec;

    if(cantReg<=0){cout <<"No se registran especialidades activas.\n";return;}

    vec = new Especialidad[cantReg];
    if(vec==nullptr){cout <<"\nSe produjo un error de asignacion de memoria.\n";return;}

    archivo.leer(cantReg,vec);

    cout << endl;
    cout << left
         << setw(7) << "Codigo"
         << setw(13) << "Especialidad"
         << endl;

    cout << "======+=============" << endl;///barra separadora

    for (int i = 0; i < cantReg; i++) {
        if (vec[i].getEstado()) {
            cout << left ///establece alineacion
                << setw(7) << vec[i].getCodEspecialidad()
                << setw(13) << vec[i].getNombre()
                << setfill(' ') << endl;}}///establece char de relleno
    cout << endl;
    delete[] vec;
}
/*void EspecialidadManager::activarEspecialidad(){
    Especialidad reg;
    int codEspecialidad, pos;

    cout << "Ingrese el codigo de especialidad: ";
    cin >> codEspecialidad;
    cin.ignore();

    pos = archivo.getPosicion(codEspecialidad);
    if(pos==-1){cout << "\nEl registro no existe en el disco.\n";}

    if(pos!=-1){
    reg = archivo.leer(pos);
    reg.setEstado(true);
    if(archivo.escribir(pos,reg)){
            cout << "\nLa especialidad f correctamente.\n";
        }else{cout << "\nSe produjo un error de escritura en el disco.\n";}
    }
}*/
