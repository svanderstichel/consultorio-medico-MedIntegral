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
    int intentos = 0;

    ///ASIGNACION ID AUTOINCREMENTAL
    codEspecialidad=archivo.getCantidadRegistros()+1;
    //inicializa el primer id en 1
    if(codEspecialidad==0){codEspecialidad++;}
    reg.setCodEspecialidad(codEspecialidad);

    ///***CARGA DE DATOS***
    ///NOMBRE ESPECIALIDAD
    while(reg.getNombre().size()==0 && intentos<3){
        cout << "Ingresar nombre de especialidad: ";
        getline(cin, nombre);
        reg.setNombre(nombre);
        intentos++;}

    //validar limite de intentos
    if (intentos == 3 && reg.getNombre().size() == 0){
    cout << "\nExcedio el limite de intentos.\n";
    return;}

    ///ESCRITURA EN DISCO
    if (archivo.escribir(reg)) {
        cout << "\nEspecialidad cargada correctamente.\n";
    } else {
        cout << "\nSe produjo un error de escritura en disco.\n";
    }
}

void EspecialidadManager::bajaEspecialidad(){
    Especialidad reg;
    int codEspecialidad, pos;

    system("cls");
    listarEspecialidad();

    cout << "Ingrese el codigo de especialidad a dar de baja: ";
    cin >> codEspecialidad;
    //validar ingreso de dato valido
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nEntrada invalida.\n";
        return;}
    else{cin.ignore();}


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

    system("cls");
    listarEspecialidad();

    cout << "\nIngresar codigo de especialidad a modificar (0 para cancelar): ";
    cin >> codEspecialidad;
    //validar ingreso de dato valido
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nEntrada invalida.\n";
        return;}
    else{cin.ignore();}

    //verificar si la operacion fue cancelada
    if (codEspecialidad == 0) {
        cout << "Operacion cancelada por el usuario.\n";
        return;}

    //verificar posicion del registro en archivo
    pos = archivo.getPosicion(codEspecialidad);
    if (pos == -1) {
        cout << "El codigo no existe.\n";
        return;}

    ///INGRESO DE NUEVO NOMBRE DE ESPECIALIDAD
    reg = archivo.leer(pos);
    cout << "\nNombre actual: " << reg.getNombre() << endl;
    cout << "Ingresar nuevo nombre de especialidad: ";
    getline(cin, nombre);

    //validar nuevo dato ingresado
    if(!reg.setNombre(nombre)){return;}

    ///ESCRITURA EN DISCO
    if (archivo.escribir(pos, reg)) {
        cout << "\nRegistro modificado correctamente.\n";}
        else{cout << "\nSe produjo un error de escritura en disco.\n";}
}

void EspecialidadManager::listarEspecialidad(){
int cantReg = archivo.getCantidadRegistros();
    Especialidad *vec;

    if(cantReg<=0){cout <<"No se registran especialidades activas.\n";return;}

    vec = new Especialidad[cantReg];
    if(vec==nullptr){cout <<"\nSe produjo un error de asignacion de memoria.\n";return;}

    archivo.leer(cantReg,vec);

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
void EspecialidadManager::altaEspecialidad(int codEspecialidad){
    Especialidad reg;
    int pos;

    pos = archivo.getPosicion(codEspecialidad,false);
    if(pos==-1){cout << "\nEl registro no existe o ya se encuentra activo.\n"; return;}

    reg = archivo.leer(pos);
    reg.setEstado(true);
    if(archivo.escribir(pos,reg)){cout << "\nRegistro recuperado correctamente.\n";}
    else{cout << "\nSe produjo un error de escritura en disco.\n";}
}

void EspecialidadManager::exportarCSV(){
    int cantReg = archivo.getCantidadRegistros();
    Especialidad *vec;

    if(cantReg<=0){cout <<"No se registran especialidades activas.\n";return;}

    vec = new Especialidad[cantReg];
    if(vec==nullptr){cout <<"\nSe produjo un error de asignacion de memoria.\n";return;}

    archivo.leer(cantReg,vec);

    cout << "codigo,especialidad\n";
    for(int i=0;i<cantReg;i++){
        if(vec[i].getEstado()){
        cout << vec[i].getCodEspecialidad() << ",";
        cout << vec[i].getNombre() <<  "\n";}}
}
