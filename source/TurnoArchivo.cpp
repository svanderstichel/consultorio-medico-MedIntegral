#include "TurnoArchivo.h"
#include "Turno.h"
#include <cstring>
#include <iostream>

TurnoArchivo::TurnoArchivo(){
    strcpy(_nombreArchivo,"turnos.dat");
}
int TurnoArchivo::getPosicion(int idTurno){
    FILE *pFile;
    Turno reg;
    int pos=0;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return -1;}

    while(fread(&reg,sizeof(Turno),1,pFile)==1){
        if(reg.getidTurno()==idTurno && reg.getEstado()){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}
int TurnoArchivo::getCantidadRegistros(){
    FILE *pFile;
    int cantReg;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return -1;}

    fseek(pFile,0,SEEK_END);
    cantReg=ftell(pFile)/sizeof(Turno);

    fclose(pFile);
    return cantReg;
}
Turno TurnoArchivo::leer(int pos){
    Turno reg;
    FILE *pFile;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return reg;}

    fseek(pFile,sizeof(Turno)*pos,SEEK_SET);
    fread(&reg,sizeof(Turno),1,pFile);

    fclose(pFile);
    return reg;
}
void TurnoArchivo::leer(int cantidadRegistros,Turno *vec){
    FILE *pFile;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return;}

    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vec[i], sizeof(Turno),1,pFile);
    }
    fclose(pFile);
}
bool TurnoArchivo::escribir(Turno reg){
    FILE *pFile;
    bool result;

    pFile=fopen(_nombreArchivo, "ab");
    if(pFile==nullptr){return false;}

    result = fwrite(&reg,sizeof(Turno),1,pFile);

    fclose(pFile);
    return result;
}
bool TurnoArchivo::escribir(int pos,Turno reg){
    FILE *pFile;
    bool result;

    pFile=fopen(_nombreArchivo, "rb+");
    if(pFile==nullptr){return false;}

    fseek(pFile,sizeof(Turno)*pos,SEEK_SET);
    result = fwrite(&reg,sizeof(Turno),1,pFile);

    fclose(pFile);
    return result;
}
int TurnoArchivo::getPosicion(int idTurno,bool estado){
    FILE *pFile;
    Turno reg;
    int pos=0;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return -1;}

    while(fread(&reg,sizeof(Turno),1,pFile)==1){
        if(reg.getidTurno()==idTurno && reg.getEstado()==estado){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}
