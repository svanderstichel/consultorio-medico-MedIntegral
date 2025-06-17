#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "Paciente.h"
#include "PacienteManager.h"
#include "FechaHora.h"
#include "ObraSocialManager.h"
#include "ObraSocialArchivo.h"

using namespace std;


void PacienteManager::altaPaciente(){

    int dni,codObraSocial;
    string apellido,nombre,telefono,email;
    FechaHora fechaNacimiento;
    Paciente reg;
    ObraSocialManager obraSocial;
    ObraSocialArchivo obraSocialArchivo;
    int contadorIntentos=0;

    ///***CARGA DE DATOS***///
    ///DNI
    while(reg.getDni()==1000000 && contadorIntentos<3){
    cout << "Ingrese DNI: ";
    cin >> dni;

    //validacion de entrada numerica, limpieza de errores y buffer
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nEntrada invalida.\n";}
    else{
        cin.ignore();
        reg.setDni(dni);}

    contadorIntentos++;}

    //verificar que dni no exista
    if(archivo.getPosicion(dni)!=-1)
    {cout<<"\nEl DNI ya se encuentra registrado\n";return;}

    //verificar limite de reintentos
    if(contadorIntentos==3 && reg.getDni()==1000000)
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    ///APELLIDO
    while(reg.getApellido().size()==0 && contadorIntentos<3){
    cout << "Ingrese Apellido: ";
    getline(cin, apellido);
    reg.setApellido(apellido);
    contadorIntentos++;}

    //verificar limite de reintentos
    if(contadorIntentos==3 && reg.getApellido().size()==0)
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    ///NOMBRE
    while(reg.getNombre().size()==0 && contadorIntentos<3){
    cout << "Ingrese Nombre: ";
    getline(cin, nombre);
    reg.setNombre(nombre);
    contadorIntentos++;}

    //verificar limite de reintentos
    if(contadorIntentos==3 && reg.getNombre()=="")
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    ///TELEFONO
    while(reg.getTelefono()=="" && contadorIntentos<3){
    cout << "Ingrese Telefono: ";
    getline(cin, telefono);
    reg.setTelefono(telefono);
    contadorIntentos++;}

    //verificar limite de reintentos
    if(contadorIntentos==3 && reg.getTelefono()=="")
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    ///EMAIL
    while(reg.getEmail()=="" && contadorIntentos<3){
    cout << "Ingrese Email: ";
    getline(cin, email);
    reg.setEmail(email);
    contadorIntentos++;}

    //verificar limite de reintentos
    if(contadorIntentos==3 && reg.getEmail()=="")
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    ///OBRA SOCIAL
    //listar obras sociales disponibles
    system("cls");
    obraSocial.listarObraSocial();

    //carga de codigo
    while(reg.getCodObraSocial()==0 && contadorIntentos<3){
    cout << "Ingrese Codigo de Obra Social: ";
    cin >> codObraSocial;

    //validar dato numerico, limpieza de errores y buffer teclado
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');}
    else{cin.ignore();}

    //validacion de que el codigo de especialidad exista
    if(obraSocialArchivo.getPosicion(codObraSocial)==-1){
        cout << "Codigo de obra social invalido.\n";}

    else{reg.setCodObraSocial(codObraSocial);}
    contadorIntentos++;}

    //verificar limite de reintentos
    if(contadorIntentos==3 && reg.getCodObraSocial()==0)
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    ///FECHA DE NACIMIENTO
    cout << "Fecha de Nacimiento\n";
    fechaNacimiento.cargarFecha();
    reg.setFechaNacimiento(fechaNacimiento);

    ///ESCRITURA EN DISCO
    if(archivo.escribir(reg)){cout <<"\nPaciente cargado correctamente!\n";}
    else{cout <<"\nSe produjo un error de escritura en disco.\n";}
}
void PacienteManager::bajaPaciente(){
    Paciente reg;
    int dni, pos;

    //listar pacientes
    system("cls");
    listarPaciente();

    //ingreso de dni
    cout << "Ingrese el DNI del paciente a dar de baja: ";
    cin >> dni;

    //validacion de entrada numerica, limpieza de errores y buffer
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');}
    else{cin.ignore();}

    pos = archivo.getPosicion(dni);
    if(pos==-1){cout << "\nEl registro no existe en el disco.\n";}

    ///ESCRITURA EN DICOS
    if(pos!=-1){
    reg = archivo.leer(pos);
    reg.setEstado(false);
    if(archivo.escribir(pos,reg)){
            cout << "\nEl paciente fue dado de baja correctamente.\n";
        }else{cout << "\nSe produjo un error de escritura en el disco.\n";}
    }
}
void PacienteManager::modificarPAciente(){
    Paciente reg;
    int dni, pos, opc;

    //listar pacientes
    system("cls");
    listarPaciente();

    cout << "\nIngrese el DNI del paciente a modificar: ";
    cin >> dni;
    //validacion de entrada numerica, limpieza de errores y buffer
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');}
    else{cin.ignore();}

    pos = archivo.getPosicion(dni);
    if(pos==-1){cout << "\nEl registro no existe en el disco.\n";}

    if(pos!=-1){
    reg = archivo.leer(pos);

    ///print de tabla
    ///encabezado de columnas
    cout << endl << left
         << setw(15) << "Apellido"
         << setw(15) << "Nombre"
         << setw(30) << "Email"
         << setw(15) << "Telefono"
         << setw(10) << "Codigo OS"
         << setw(12) << "Nacimiento"
         << endl;

    cout << string(95, '-') << endl;///barra separadora

    cout << left ///establece alineacion
         << setw(15) << reg.getApellido()
         << setw(15) << reg.getNombre()
         << setw(30) << reg.getEmail()
         << setw(15) << reg.getTelefono()
         << setw(10) << reg.getCodObraSocial()
         << reg.getFechaNacimiento().getDia() << "/"
         << reg.getFechaNacimiento().getMes() << "/"
         << reg.getFechaNacimiento().getAnio()
         << setfill(' ') << endl;///establece char de relleno


    cout << "\n1 - Apellido";
    cout << "\n2 - Nombre";
    cout << "\n3 - Email";
    cout << "\n4 - Telefono";
    cout << "\n5 - Codigo OS";
    cout << "\n6 - Fecha de nacimiento";
    cout << "\nIndique el atributo a modificar: ";
    cin >> opc;

    //validacion de dato ingresado
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');}
    else{cin.ignore();}

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
        {int codObraSocial = reg.getCodObraSocial();
        ObraSocialManager obrasSociales;
        ObraSocialArchivo obraSocialArchivo;

        //listar obras sociales
        system("cls");
        obrasSociales.listarObraSocial();

        do{
        cout << "Ingrese nuevo codigo de obra social: ";
        cin >> codObraSocial;

        //validacion de ingreso de dato valido
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');}
        else{cin.ignore();}

        //validacion de que el codigo de obra social exista
        if(obraSocialArchivo.getPosicion(codObraSocial)==-1){
            cout << "Codigo especialidad invalido.\n";}

        else{reg.setCodObraSocial(codObraSocial);}}
        while(codObraSocial!=reg.getCodObraSocial());

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
void PacienteManager::listarPaciente(){
int cantReg = archivo.getCantidadRegistros();
    Paciente *vec;

    if(cantReg<=0){cout <<"No se registran pacientes activos.\n";return;}

    vec = new Paciente[cantReg];
    if(vec==nullptr){cout <<"\nSe produjo un error de asignacion de memoria.\n";return;}

    archivo.leer(cantReg,vec);

    ///print de tabla
    ///encabezado de columnas
    cout << left
         << setw(12) << "DNI"
         << setw(15) << "Apellido"
         << setw(15) << "Nombre"
         << setw(30) << "Email"
         << setw(15) << "Telefono"
         << setw(10) << "Codigo OS"
         << setw(12) << "Nacimiento"
         << endl;

    cout << string(107, '-') << endl;///barra separadora

    for (int i = 0; i < cantReg; i++) {
        if (vec[i].getEstado()) {
            cout << left ///establece alineacion
                 << setw(12) << vec[i].getDni()
                 << setw(15) << vec[i].getApellido()
                 << setw(15) << vec[i].getNombre()
                 << setw(30) << vec[i].getEmail()
                 << setw(15) << vec[i].getTelefono()
                 << setw(10) << vec[i].getCodObraSocial()
                 << vec[i].getFechaNacimiento().getDia() << "/"
                 << vec[i].getFechaNacimiento().getMes() << "/"
                 << vec[i].getFechaNacimiento().getAnio()
                 << setfill(' ') << endl;///establece char de relleno
                 }
        }
    cout << endl;
    delete[] vec;
}

void PacienteManager::altaPaciente(int dni){
    Paciente reg;
    int pos;

    pos = archivo.getPosicion(dni,false);
    if(pos==-1){cout << "\nEl registro no existe o ya se encuentra activo.\n"; return;}

    reg = archivo.leer(pos);
    reg.setEstado(true);
    if(archivo.escribir(pos,reg)){cout << "\nRegistro recuperado correctamente.\n";}
    else{cout << "\nSe produjo un error de escritura en disco.\n";}
}
void PacienteManager::exportarCSV(){
    int cantReg = archivo.getCantidadRegistros();
    Paciente *vec;

    if(cantReg<=0){cout <<"No se registran pacientes activos.\n";return;}

    vec = new Paciente[cantReg];
    if(vec==nullptr){cout <<"\nSe produjo un error de asignacion de memoria.\n";return;}

    archivo.leer(cantReg,vec);

    cout << "dni,apellido,nombre,email,telefono,cod_obra_social,inicio_actividad\n";
    for(int i=0;i<cantReg;i++){
        if(vec[i].getEstado()){
        cout << vec[i].getDni() << ",";
        cout << vec[i].getApellido() << ",";
        cout << vec[i].getNombre() << ",";
        cout << vec[i].getEmail() << ",";
        cout << vec[i].getTelefono() << ",";
        cout << vec[i].getCodObraSocial() << ",";
        cout << vec[i].getFechaNacimiento().getDia() << "/";
        cout << vec[i].getFechaNacimiento().getMes() << "/";
        cout << vec[i].getFechaNacimiento().getAnio() <<  "\n";}}

    delete[] vec;
}
