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

    // Ingreso de código, validando existencia y tipo
    while (true) {
        cout << "Ingresar codigo de Especialidad: ";
        cin >> codEspecialidad;

        // Validar si se ingresó un número
        if (cin.fail()) {
            cout << "\nError. Debe ingresar un numero.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cin.ignore();

        // Validar número positivo
        if (codEspecialidad <= 0) {
            cout << "\nEl codigo debe ser un numero positivo.\n";
            continue;
        }

        // Validar código no existente
        if (archivo.getPosicion(codEspecialidad) != -1) {
            cout << "\nLa especialidad ya se encuentra registrada. Ingresar nuevo codigo.\n";
            continue;
        }

        // Código válido
        reg.setCodEspecialidad(codEspecialidad);
        break;
    }

    // Ingreso del nombre, validando longitud y que no esté vacío
    while (true) {
        cout << "Ingresar Nombre: ";
        getline(cin, nombre);

        // Verificar nombre no vacío
        if (nombre.empty()) {
            cout << "Error. Nombre vacio. Intente nuevamente.\n";
            continue;
        }

        // Verificar longitud válida (en tu clase, el límite es 50)
        if (!reg.setNombre(nombre)) {
            cout << "El nombre es demasiado largo. Intente nuevamente.\n";
            continue;
        }

        break;
    }

    // Activar y guardar
    reg.setEstado(true);

    if (archivo.escribir(reg)) {
        cout << "\n¡Especialidad cargada correctamente!\n";
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

    // Bucle para pedir un codigo valido
    while (true) {
        cout << "\nIngresar codigo a modificar (0 para cancelar): ";
        cin >> codEspecialidad;

        // Validar entrada
        if (cin.fail()) {
            cout << "Error. Debe ingresar un numero.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cin.ignore();

        if (codEspecialidad == 0) {
            cout << "Operación cancelada por el usuario.\n";
            return;
        }

        if (codEspecialidad < 0) {
            cout << "El codigo debe ser positivo.\n";
            continue;
        }

        // Buscar el código
        pos = archivo.getPosicion(codEspecialidad);
        if (pos == -1) {
            cout << "El codigo no existe.\n";
            cout << "Especialidades disponibles:\n";
            listarEspecialidad();  // ← Mostrar al usuario los códigos válidos
            continue;
        }

        break;  // Código válido y existe
    }

    // Leer el registro y mostrar su estado actual
    reg = archivo.leer(pos);
    cout << "\nNombre actual: " << reg.getNombre() << endl;

    // Pedir nuevo nombre validado
    while (true) {
        cout << "Ingresar nuevo nombre de especialidad: ";
        getline(cin, nombre);

        if (nombre.empty()) {
            cout << "El nombre no puede estar vacio.\n";
            continue;
        }

        if (!reg.setNombre(nombre)) {
            cout << "Error. Nombre demasiado largo. Intente nuevamente.\n";
            continue;
        }
        break;
    }

    // Guardar
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

    cout << left
         << setw(12) << "Codigo"
         << setw(15) << "Especialidad"
         << endl;

    cout << string(60, '-') << endl;///barra separadora


    for (int i = 0; i < cantReg; i++) {
        if (vec[i].getEstado()) {
            cout << left ///establece alineacion
                << setw(12) << vec[i].getCodEspecialidad()
                << setw(15) << vec[i].getNombre()
                << setfill(' ') << endl;///establece char de relleno
        }

    }
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
