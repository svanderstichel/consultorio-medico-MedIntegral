#include <iostream>
#include <limits>
#include "FechaHora.h"

using namespace std;

FechaHora::FechaHora(){
    _dia=1;
    _mes=1;
    _anio=1900;
    _hora=0;
}

int FechaHora::getDia(){
    return _dia;
}
int FechaHora::getMes(){
    return _mes;
}
int FechaHora::getAnio(){
    return _anio;
}
int FechaHora::getHora(){
    return _hora;
}

void FechaHora::cargarFecha(){
    int dia=0;
    int mes=0;
    int anio=0;

    ///validacion de ingreso de anio
    while(anio<1900 || anio>2050){
        cout << "Ingrese anio: ";
        cin >> anio;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');}
        else{
            cin.ignore();}

        if(anio<1900 || anio>2050){
            cout << "Anio invalido (fuera de rango).\n";
        }
    }
    _anio = anio;

    ///validacion de ingreso de mes
    while(mes<1 || mes>12){
        cout << "Ingrese mes: ";
        cin >> mes;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');}
        else{
            cin.ignore();}

        if(mes<1 || mes>12){
            cout << "Mes invalido (fuera de rango).\n";
        }
    }
    _mes = mes;

    ///validacion de ingreso de dia
    while(dia==0){
        cout << "Ingrese dia: ";
        cin >> dia;

        //validacion de entrada numerica valida
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');}
        else{cin.ignore();}

        //validacion de dia valido
        if(dia<1 || dia>31){cout << "Dia invalido (fuera de rango).\n"; dia=0;}

        //validacion meses de 30 dias
        if(dia>30 && (getMes()==4 || getMes()==6 || getMes()==9 || getMes()==11)){
            cout << "Dia invalido (fuera de rango).\n"; dia=0; dia=0;}

        // Año bisiesto
        if (getMes() == 2 && ((getAnio() % 4 == 0 && getAnio() % 100 != 0) || (getAnio() % 400 == 0)) && dia > 29){
            cout << "Dia invalido (fuera de rango).\n"; dia=0;}

        // Año no bisiesto
        if (getMes() == 2 && !((getAnio() % 4 == 0 && getAnio() % 100 != 0) || (getAnio() % 400 == 0)) && dia > 28){
            cout << "Dia invalido (fuera de rango).\n"; dia=0;}

        _dia = dia;
    }
}
void FechaHora::cargarHora(){
    int hora=24;

    ///validacion de ingreso de hora
    while(hora<0 || hora>23){
        cout << "Ingrese hora (formato 0-23): ";
        cin >> hora;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            hora=24;}
        else{cin.ignore();}

        if(hora<0 || hora>23){
            cout << "Hora invalida (fuera de rango).\n";}
        }
    _hora = hora;
}

bool FechaHora::operator==(FechaHora &source){
    if(
    getHora()==source.getHora() &&
    getDia()==source.getDia() &&
    getMes()==source.getMes() &&
    getAnio()==source.getAnio()
    ){return true;}
    return false;
}
bool FechaHora::operator!=(FechaHora &source){
    if(
    getHora()!=source.getHora() ||
    getDia()!=source.getDia() ||
    getMes()!=source.getMes() ||
    getAnio()!=source.getAnio()
    ){return true;}
    return false;
}
