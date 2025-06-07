#include <iostream>
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

    ///validacion de ingreso de dia
    while(dia<1 || dia>31){
        cout << "Ingrese dia: ";
        cin >> dia;
        cin.ignore();

        if(dia<1 || dia>31){
            cout << "Dia invalido (fuera de rango).\n";
        }
    }
    _dia = dia;

    ///validacion de ingreso de mes
    while(mes<1 || mes>12){
        cout << "Ingrese mes: ";
        cin >> mes;
        cin.ignore();

        if(mes<1 || mes>12){
            cout << "Mes invalido (fuera de rango).\n";
        }
    }
    _mes = mes;

    ///validacion de ingreso de anio
    while(anio<1900 || anio>2050){
        cout << "Ingrese anio: ";
        cin >> anio;
        cin.ignore();

        if(anio<1900 || anio>2050){
            cout << "Anio invalido (fuera de rango).\n";
        }
    }
    _anio = anio;
}
void FechaHora::cargarHora(){
    int hora=24;

    ///validacion de ingreso de hora
    while(hora<0 || hora>23){
        cout << "Ingrese hora (formato 0-23): ";
        cin >> hora;
        cin.ignore();

        if(hora<0 || hora>23){
            cout << "Hora invalida (fuera de rango).\n";
        }
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
