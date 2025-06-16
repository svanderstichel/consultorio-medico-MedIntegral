#include "EspecialidadArchivo.h"
#include "Especialidad.h"
#include <cstring>

EspecialidadArchivo::EspecialidadArchivo(){
    strcpy(_nombreArchivo,"especialidades.dat");
}
int EspecialidadArchivo::getPosicion(int codEspecialidad){
    FILE *pFile;
    Especialidad reg;
    int pos=0;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return -1;}

    while(fread(&reg,sizeof(Especialidad),1,pFile)==1){
        if(reg.getCodEspecialidad()==codEspecialidad && reg.getEstado()){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}
int EspecialidadArchivo::getCantidadRegistros(){
    FILE *pFile;
    int cantReg;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return -1;}

    fseek(pFile,0,SEEK_END);
    cantReg=ftell(pFile)/sizeof(Especialidad);

    fclose(pFile);
    return cantReg;
}
Especialidad EspecialidadArchivo::leer(int pos){
    Especialidad reg;
    FILE *pFile;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return reg;}

    fseek(pFile,sizeof(Especialidad)*pos,SEEK_SET);
    fread(&reg,sizeof(Especialidad),1,pFile);

    fclose(pFile);
    return reg;
}
void EspecialidadArchivo::leer(int cantidadRegistros,Especialidad *vec){
    FILE *pFile;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return;}

    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vec[i], sizeof(Especialidad),1,pFile);
    }
    fclose(pFile);
}
bool EspecialidadArchivo::escribir(Especialidad reg){
    FILE *pFile;
    bool result;

    pFile=fopen(_nombreArchivo, "ab");
    if(pFile==nullptr){return false;}

    result = fwrite(&reg,sizeof(Especialidad),1,pFile);

    fclose(pFile);
    return result;
}
bool EspecialidadArchivo::escribir(int pos,Especialidad reg){
    FILE *pFile;
    bool result;

    pFile=fopen(_nombreArchivo, "rb+");
    if(pFile==nullptr){return false;}

    fseek(pFile,sizeof(Especialidad)*pos,SEEK_SET);
    result = fwrite(&reg,sizeof(Especialidad),1,pFile);

    fclose(pFile);
    return result;
}
int EspecialidadArchivo::getPosicion(int codEspecialidad,bool estado){
    FILE *pFile;
    Especialidad reg;
    int pos=0;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return -1;}

    while(fread(&reg,sizeof(Especialidad),1,pFile)==1){
        if(reg.getCodEspecialidad()==codEspecialidad && reg.getEstado()==estado){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}
