#include <iostream>
#include <string>
#include <iomanip>
#include "Medico.h"
#include "MedicoManager.h"
#include "FechaHora.h"

using namespace std;

void MedicoManager::alta(){

    int dni,codigoEspecialidad;
    string apellido,nombre,telefono,email;
    FechaHora fechaNacimiento;
    FechaHora inicioActividad;
    Medico reg;
    int contadorIntentos=0;

    ///ingreso de datos
    ///cargar dni
    while(reg.getDni()==1000000 && contadorIntentos<3){
    cout << "Ingrese DNI: ";
    cin >> dni;
    cin.ignore();
    reg.setDni(dni);
    contadorIntentos++;}

    ///verificar que dni no exista
    if(archivo.getPosicion(dni)!=-1)
    {cout<<"\nEl DNI ya se encuentra registrado\n";return;}

    ///verificar limite de reintentos
    if(contadorIntentos==3)
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    ///carga de apellido
    while(reg.getApellido()=="" && contadorIntentos<3){
    cout << "Ingrese Apellido: ";
    getline(cin, apellido);
    reg.setApellido(apellido);
    contadorIntentos++;}

    ///verificar limite de reintentos
    if(contadorIntentos==3)
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    ///carga de nombre
    while(reg.getNombre()=="" && contadorIntentos<3){
    cout << "Ingrese Nombre: ";
    getline(cin, nombre);
    reg.setNombre(nombre);
    contadorIntentos++;}

    ///verificar limite de reintentos
    if(contadorIntentos==3)
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    ///carga de telefono
    while(reg.getTelefono()=="" && contadorIntentos<3){
    cout << "Ingrese Telefono: ";
    getline(cin, telefono);
    reg.setTelefono(telefono);
    contadorIntentos++;}

    ///verificar limite de reintentos
    if(contadorIntentos==3)
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    ///carga de email
    while(reg.getEmail()=="" && contadorIntentos<3){
    cout << "Ingrese Email: ";
    getline(cin, email);
    reg.setEmail(email);
    contadorIntentos++;}

    ///verificar limite de reintentos
    if(contadorIntentos==3)
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    ///carga de codigo de especialidad
    while(reg.getCodigoEspecialidad()==0 && contadorIntentos<3){
    cout << "Ingrese Codigo de Especialidad: ";
    cin >> codigoEspecialidad;
    cin.ignore();
    reg.setCodigoEspecialidad(codigoEspecialidad);
    contadorIntentos++;}

    ///verificar limite de reintentos
    if(contadorIntentos==3)
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    ///carga de fecha de nacimiento
    cout << "Fecha de Nacimiento\n";
    fechaNacimiento.cargarFecha();
    reg.setFechaNacimiento(fechaNacimiento);

    ///carga de fecha de inicio de actividad
    cout << "Fecha de inicio de actividad\n";
    inicioActividad.cargarFecha();
    reg.setInicioActividad(inicioActividad);

    ///escritura en disco
    if(archivo.escribir(reg)){cout <<"\nMedico cargado correctamente!\n";}
    else{cout <<"\nSe produjo un error de escritura en disco.\n";}
}
void MedicoManager::listar(){
    int cantReg = archivo.getCantidadRegistros();
    Medico *vec;

    if(cantReg<=0){cout <<"No se registran medicos activos.\n";return;}

    vec = new Medico[cantReg];
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
         << setw(15) << "Codigo esp."
         << setw(15) << "Inicio act."
         << endl;

    cout << string(113, '-') << endl;///barra separadora

    for (int i = 0; i < cantReg; i++) {
        if (vec[i].getEstado()) {
            cout << left ///establece alineacion
                 << setw(12) << vec[i].getDni()
                 << setw(15) << vec[i].getApellido()
                 << setw(15) << vec[i].getNombre()
                 << setw(30) << vec[i].getEmail()
                 << setw(15) << vec[i].getTelefono()
                 << setw(15) << vec[i].getCodigoEspecialidad()
                 << vec[i].getInicioActividad().getDia() << "/"
                 << vec[i].getInicioActividad().getMes() << "/"
                 << vec[i].getInicioActividad().getAnio()
                 << setfill(' ') << endl;///establece char de relleno
                 }
        }
    cout << endl;
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

    ///print de tabla
    ///encabezado de columnas
    cout << endl << left
         << setw(15) << "Apellido"
         << setw(15) << "Nombre"
         << setw(30) << "Email"
         << setw(15) << "Telefono"
         << setw(15) << "Codigo esp."
         << setw(15) << "Inicio act."
         << endl;

    cout << string(103, '-') << endl;///barra separadora

    cout << left ///establece alineacion
         << setw(15) << reg.getApellido()
         << setw(15) << reg.getNombre()
         << setw(30) << reg.getEmail()
         << setw(15) << reg.getTelefono()
         << setw(15) << reg.getCodigoEspecialidad()
         << reg.getInicioActividad().getDia() << "/"
         << reg.getInicioActividad().getMes() << "/"
         << reg.getInicioActividad().getAnio()
         << setfill(' ') << endl;///establece char de relleno


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

void MedicoManager::buscar(){
    Medico reg;
    int dni;
    int pos;

    cout << "Ingrese el DNI del medico: ";
    cin >> dni;
    cin.ignore();

    pos = archivo.getPosicion(dni);
    if(pos==-1){cout << "\nEl registro no existe en el disco.\n";}

    reg = archivo.leer(pos);

    ///print de tabla
    ///encabezado de columnas
    cout << endl << left
         << setw(15) << "Apellido"
         << setw(15) << "Nombre"
         << setw(30) << "Email"
         << setw(15) << "Telefono"
         << setw(15) << "Codigo esp."
         << setw(15) << "Inicio act."
         << endl;

    cout << string(103, '-') << endl;///barra separadora

    cout << left ///establece alineacion
         << setw(15) << reg.getApellido()
         << setw(15) << reg.getNombre()
         << setw(30) << reg.getEmail()
         << setw(15) << reg.getTelefono()
         << setw(15) << reg.getCodigoEspecialidad()
         << reg.getInicioActividad().getDia() << "/"
         << reg.getInicioActividad().getMes() << "/"
         << reg.getInicioActividad().getAnio()
         << setfill(' ') << endl << endl;///establece char de relleno
}

void MedicoManager::alta(int dni){
    Medico reg;
    int pos;

    pos = archivo.getPosicion(dni);
    if(pos==-1){cout << "\nEl registro no existe en el disco.\n";}

    if(pos!=-1){
    reg = archivo.leer(pos);
    reg.setEstado(true);
    if(archivo.escribir(pos,reg)){cout << "\nRegistro recuperado correctamente.\n";}
    else{cout << "\nSe produjo un error de escritura en disco.\n";}}
}

void MedicoManager::exportarCSV(){
    int cantReg = archivo.getCantidadRegistros();
    Medico *vec;

    if(cantReg<=0){cout <<"No se registran medicos activos.\n";return;}

    vec = new Medico[cantReg];
    if(vec==nullptr){cout <<"\nSe produjo un error de asignacion de memoria.\n";return;}

    archivo.leer(cantReg,vec);

    cout << "dni,apellido,nombre,email,telefono,cod_especialidad,fecha_nacimiento,inicio_actividad\n";
    for(int i=0;i<cantReg;i++){
        if(vec[i].getEstado()){
        cout << vec[i].getDni() << ",";
        cout << vec[i].getApellido() << ",";
        cout << vec[i].getNombre() << ",";
        cout << vec[i].getEmail() << ",";
        cout << vec[i].getTelefono() << ",";
        cout << vec[i].getCodigoEspecialidad() << ",";
        cout << vec[i].getFechaNacimiento().getDia() << "/";
        cout << vec[i].getFechaNacimiento().getMes() << "/";
        cout << vec[i].getFechaNacimiento().getAnio() << ",";
        cout << vec[i].getInicioActividad().getDia() << "/";
        cout << vec[i].getInicioActividad().getMes() << "/";
        cout << vec[i].getInicioActividad().getAnio() << "\n";}}
}
