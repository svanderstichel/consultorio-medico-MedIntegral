#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "Medico.h"
#include "MedicoManager.h"
#include "FechaHora.h"
#include "EspecialidadManager.h"
#include "EspecialidadArchivo.h"

using namespace std;

void MedicoManager::alta(){

    EspecialidadManager especialidades;
    EspecialidadArchivo especialidadesArchivo;
    int dni,codigoEspecialidad;
    string apellido,nombre,telefono,email;
    FechaHora fechaNacimiento;
    FechaHora inicioActividad;
    Medico reg;
    int contadorIntentos=0;

    system("cls");
    cout << "<Alta de medico>\n\n";

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

    ///ESPECIALIDAD
    //listar especialidades disponibles
    system("cls");
    especialidades.listarEspecialidad();

    while(reg.getCodigoEspecialidad()==0 && contadorIntentos<3){
    cout << "\nIngrese Codigo de Especialidad: ";
    cin >> codigoEspecialidad;

    //validacion de entrada numerica, limpieza de errores y buffer
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');}
    else{cin.ignore();}

    //validacion de que el codigo de especialidad exista
    if(especialidadesArchivo.getPosicion(codigoEspecialidad)==-1){
        cout << "Codigo especialidad invalido.\n";}

    else{reg.setCodigoEspecialidad(codigoEspecialidad);}
    contadorIntentos++;}

    //verificar limite de reintentos
    if(contadorIntentos==3 && reg.getCodigoEspecialidad()==0)
    {cout<<"\nHas excedido el limite de reintentos.\n";return;}
    else{contadorIntentos=0;}

    ///FECHA NACIMIENTO
    system("cls");
    cout << "Fecha de Nacimiento\n";
    cout << "===================\n";
    fechaNacimiento.cargarFecha();
    reg.setFechaNacimiento(fechaNacimiento);

    ///FECHA INICIO ACTIVIDAD
    system("cls");
    cout << "Fecha de inicio de actividad\n";
    cout << "============================\n";
    inicioActividad.cargarFecha();
    reg.setInicioActividad(inicioActividad);

    ///ESCRITURA EN DISCO
    if(archivo.escribir(reg)){cout <<"\nMedico cargado correctamente!\n";}
    else{cout <<"\nSe produjo un error de escritura en disco.\n";}
}
void MedicoManager::listar(){
    int cantReg = archivo.getCantidadRegistros();
    Medico *vec;

    system("cls");
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

    listar();

    cout << "Ingrese el DNI del medico a dar de baja: ";
    cin >> dni;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');}

    else{cin.ignore();}

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

    cout << endl;
    listar();

    cout << "\nIngrese el DNI del medico a modificar: ";
    cin >> dni;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    else{cin.ignore();}

    pos = archivo.getPosicion(dni);
    if(pos==-1){cout << "\nEl registro no existe en el disco.\n";}

    if(pos!=-1){
    reg = archivo.leer(pos);

    ///print de tabla
    ///encabezado de columnas
    system("cls");
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
    cout << "\n\nIndique el atributo a modificar: ";
    cin >> opc;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');}
    else{cin.ignore();}

    switch(opc){
    case 1:{
        {string apellido = reg.getApellido();

        do{cout << "Ingrese nuevo apellido: ";
        getline(cin,apellido);
        reg.setApellido(apellido);
        }while(apellido!=reg.getApellido());

        if(archivo.escribir(pos,reg)){
            cout << "\nRegistro modificado correctamente.\n";
        } else{
            cout << "\nSe produjo un error de escritura en disco.\n";}

        break;}
    case 2:
         {string nombre = reg.getNombre();

        do{cout << "Ingrese nuevo nombre: ";
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

        do{cout << "Ingrese nuevo email: ";
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

        do{cout << "Ingrese nuevo telefono: ";
        getline(cin,telefono);
        reg.setTelefono(telefono);
        }while(telefono!=reg.getTelefono());

        if(archivo.escribir(pos,reg)){
            cout << "\nRegistro modificado correctamente.\n";
        } else{
            cout << "\nSe produjo un error de escritura en disco.\n";}

        break;}
    case 5:
        {int codigoEspecialidad = reg.getCodigoEspecialidad();
        EspecialidadManager especialidades;
        EspecialidadArchivo especialidadesArchivo;

        //listar especialidades disponibles
        system("cls");
        especialidades.listarEspecialidad();

        do{
        cout << "Ingrese nuevo codigo de especialidad: ";
        cin >> codigoEspecialidad;

        //validacion de ingreso de dato valido
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');}
        else{cin.ignore();}

        //validacion de que el codigo de especialidad exista
        if(especialidadesArchivo.getPosicion(codigoEspecialidad)==-1){
        cout << "Codigo especialidad invalido.\n";}

        else{reg.setCodigoEspecialidad(codigoEspecialidad);}}
        while(codigoEspecialidad!=reg.getCodigoEspecialidad());

        if(archivo.escribir(pos,reg)){
            cout << "\nRegistro modificado correctamente.\n";
        } else{
            cout << "\nSe produjo un error de escritura en disco.\n";}

        break;}
    case 6:
        {FechaHora fechaNacimiento;

        system("cls");
        cout << "\nIngrese nueva fecha de nacimiento\n";
        cout << "=================================\n\n";
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

    cout << "\n<Buscar medico>\n";
    cout << "Ingrese el DNI del medico: ";
    cin >> dni;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');}
    else{cin.ignore();}

    pos = archivo.getPosicion(dni);
    if(pos==-1){cout << "\nEl registro no existe en el disco.\n";}

    else{reg = archivo.leer(pos);

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
         << setfill(' ') << endl << endl;}///establece char de relleno
}

void MedicoManager::alta(int dni){
    Medico reg;
    int pos;

    pos = archivo.getPosicion(dni,false);
    if(pos==-1){cout << "\nEl registro no existe o ya se encuentra activo.\n"; return;}

    reg = archivo.leer(pos);
    reg.setEstado(true);
    if(archivo.escribir(pos,reg)){cout << "\nRegistro recuperado correctamente.\n";}
    else{cout << "\nSe produjo un error de escritura en disco.\n";}
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

    delete[] vec;
}
