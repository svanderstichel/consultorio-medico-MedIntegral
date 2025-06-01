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
    delete[] vec;
}
void MedicoManager::baja(){
    Medico reg;
    int dni;
    int pos;

    cout << "Ingrese el DNI del medico: ";
    cin >> dni;
    cin.ignore();

    pos = archivo.getPosicion(dni);
    if(pos==-1){cout << "\nEl registro no existe en el disco.\n";}

    if(pos!=-1){
    reg = archivo.leer(pos);
    reg.setEstado(false);
    if(archivo.escribir(pos,reg)){
            cout << "\nEl medico fue dado de baja correctamente.\n";
        }else{cout << "\nSe produjo un error de escritura en el disco.\n";}
    }

}
void MedicoManager::modificar(){
    Medico reg;
    int dni;
    int pos;
    int opc;

    cout << "\nIngrese el DNI del medico: ";
    cin >> dni;
    cin.ignore();

    pos = archivo.getPosicion(dni);
    if(pos==-1){cout << "\nEl registro no existe en el disco.\n";}

    if(pos!=-1){
    reg = archivo.leer(pos);
    cout << reg.getApellido() << "\t"
        << reg.getNombre() << "\t"
        << reg.getEmail() << "\t"
        << reg.getTelefono() << "\t"
        << reg.getCodigoEspecialidad() << "\t"
        << reg.getFechaNacimiento().getDia() << "/"
        << reg.getFechaNacimiento().getMes() << "/"
        << reg.getFechaNacimiento().getAnio() << endl;

    cout << "\n1 - Apellido";
    cout << "\n2 - Nombre";
    cout << "\n3 - Email";
    cout << "\n4 - Telefono";
    cout << "\n5 - Codigo de especialidad";
    cout << "\n6 - Fecha de nacimiento";
    cout << "\nIndique el atributo a modificar: ";
    cin >> opc;
    cin.ignore();

    switch(opc){
    case 1:{
        {string apellido = reg.getApellido();

        do{
        cout << "Ingrese nuevo apellido: ";
        getline(cin,apellido);
        reg.setApellido(apellido);}
        while(apellido!=reg.getApellido());

        if(archivo.escribir(pos,reg)){
            cout << "\nRegistro modificado correctamente.\n";
        } else{
            cout << "\nSe produjo un error de escritura en disco.\n";}

        break;}
    case 2:
         {string nombre = reg.getNombre();

        do{
        cout << "Ingrese nuevo nombre: ";
        getline(cin,nombre);
        reg.setNombre(nombre);}
        while(nombre!=reg.getNombre());

        if(archivo.escribir(pos,reg)){
            cout << "\nRegistro modificado correctamente.\n";
        } else{
            cout << "\nSe produjo un error de escritura en disco.\n";}

        break;}
    case 3:
        {string email = reg.getEmail();

        do{
        cout << "Ingrese nuevo email: ";
        getline(cin,email);
        reg.setEmail(email);}
        while(email!=reg.getEmail());

        if(archivo.escribir(pos,reg)){
            cout << "\nRegistro modificado correctamente.\n";
        } else{
            cout << "\nSe produjo un error de escritura en disco.\n";}
        break;}
    case 4:
        {string telefono = reg.getTelefono();

        do{
        cout << "Ingrese nuevo telefono: ";
        getline(cin,telefono);
        reg.setTelefono(telefono);}
        while(telefono!=reg.getTelefono());

        if(archivo.escribir(pos,reg)){
            cout << "\nRegistro modificado correctamente.\n";
        } else{
            cout << "\nSe produjo un error de escritura en disco.\n";}

        break;}
    case 5:
        {int codigoEspecialidad = reg.getCodigoEspecialidad();

        do{
        cout << "Ingrese nuevo codigo de especialidad: ";
        cin >> codigoEspecialidad;
        cin.ignore();
        reg.setCodigoEspecialidad(codigoEspecialidad);}
        while(codigoEspecialidad!=reg.getCodigoEspecialidad());

        if(archivo.escribir(pos,reg)){
            cout << "\nRegistro modificado correctamente.\n";
        } else{
            cout << "\nSe produjo un error de escritura en disco.\n";}

        break;}
    case 6:
        {FechaHora fechaNacimiento;

        cout << "\nIngrese nueva fecha de nacimiento\n";
        fechaNacimiento.cargarFecha();
        reg.setFechaNacimiento(fechaNacimiento);}

        if(archivo.escribir(pos,reg)){
            cout << "\nRegistro modificado correctamente.\n";
        } else{
            cout << "\nSe produjo un error de escritura en disco.\n";}

        break;}
    default:
        cout << "\nOpcion invalida.\n";
        break;
            }
        }
    }


