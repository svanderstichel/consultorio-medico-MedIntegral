#include "MedicoArchivo.h"
#include "Medico.h"
#include <cstring>

MedicoArchivo::MedicoArchivo(){
    strcpy(_nombreArchivo,"medicos.dat");
}
int MedicoArchivo::getPosicion(int dni){
    FILE *pFile;
    Medico reg;
    int pos=0;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return -1;}

    while(fread(&reg,sizeof(Medico),1,pFile)==1){
        if(reg.getDni()==dni && reg.getEstado()){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}
int MedicoArchivo::getCantidadRegistros(){
    FILE *pFile;
    int cantReg;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return -1;}

    fseek(pFile,0,SEEK_END);
    cantReg=ftell(pFile)/sizeof(Medico);

    fclose(pFile);
    return cantReg;
}
Medico MedicoArchivo::leer(int pos){
    Medico reg;
    FILE *pFile;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return reg;}

    fseek(pFile,sizeof(Medico)*pos,SEEK_SET);
    fread(&reg,sizeof(Medico),1,pFile);

    fclose(pFile);
    return reg;
}
void MedicoArchivo::leer(int cantidadRegistros,Medico *vec){
    FILE *pFile;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return;}

    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vec[i], sizeof(Medico),1,pFile);
    }
    fclose(pFile);
}
bool MedicoArchivo::escribir(Medico reg){
    FILE *pFile;
    bool result;

    pFile=fopen(_nombreArchivo, "ab");
    if(pFile==nullptr){return false;}

    result = fwrite(&reg,sizeof(Medico),1,pFile);

    fclose(pFile);
    return result;
}
bool MedicoArchivo::escribir(int pos,Medico reg){
    FILE *pFile;
    bool result;

    pFile=fopen(_nombreArchivo, "rb+");
    if(pFile==nullptr){return false;}

    fseek(pFile,sizeof(Medico)*pos,SEEK_SET);
    result = fwrite(&reg,sizeof(Medico),1,pFile);

    fclose(pFile);
    return result;
}

int MedicoArchivo::getPosicion(int dni,bool estado){
    FILE *pFile;
    Medico reg;
    int pos=0;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return -1;}

    while(fread(&reg,sizeof(Medico),1,pFile)==1){
        if(reg.getDni()==dni && reg.getEstado()==estado){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}
