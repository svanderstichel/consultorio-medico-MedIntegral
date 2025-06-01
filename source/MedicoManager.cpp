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
    Medico reg;

    while(reg.getDni()==1000000){
    cout << "Ingrese DNI: ";
    cin >> dni;
    cin.ignore();
    reg.setDni(dni);}

    while(reg.getApellido()==""){
    cout << "Ingrese Apellido: ";
    getline(cin, apellido);
    reg.setApellido(apellido);}

    while(reg.getNombre()==""){
    cout << "Ingrese Nombre: ";
    getline(cin, nombre);
    reg.setNombre(nombre);}

    while(reg.getTelefono()==""){
    cout << "Ingrese Telefono: ";
    getline(cin, telefono);
    reg.setTelefono(telefono);}

    while(reg.getEmail()==""){
    cout << "Ingrese Email: ";
    getline(cin, email);
    reg.setEmail(email);}

    while(reg.getCodigoEspecialidad()==0){
    cout << "Ingrese Codigo de Especialidad: ";
    cin >> codigoEspecialidad;
    cin.ignore();
    reg.setCodigoEspecialidad(codigoEspecialidad);}

    cout << "Fecha de Nacimiento\n";
    fechaNacimiento.cargarFecha();

    if(archivo.escribir(reg)){cout <<"\nMedico cargado correctamente!\n";}
    else{cout <<"\nSe produjo un error de escritura en disco.\n";}
}
void MedicoManager::listar(){
    int cantReg = archivo.getCantidadRegistros();
    Medico *vec;

    vec = new Medico[cantReg];
    if(vec==nullptr){cout <<"\nSe produjo un error de asignacion de memoria.\n";return;}

    archivo.leer(cantReg,vec);

    for(int i=0;i<cantReg;i++){
        if(vec[i].getEstado()){
        cout << vec[i].getDni() << "\t"
            << vec[i].getApellido() << "\t"
            << vec[i].getNombre() << "\t"
            << vec[i].getEmail() << "\t"
            << vec[i].getTelefono() << "\t"
            << vec[i].getCodigoEspecialidad() << "\t"
            << vec[i].getFechaNacimiento().getDia() << "/"
            << vec[i].getFechaNacimiento().getMes() << "/"
            << vec[i].getFechaNacimiento().getAnio() << endl;
        }
    }
}
void MedicoManager::baja(){return;}
void MedicoManager::modificar(){return;}
