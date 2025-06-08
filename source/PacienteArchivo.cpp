#include "PacienteArchivo.h"
#include "Paciente.h"
#include <cstring>

PacienteArchivo::PacienteArchivo(){
    strcpy(_nombreArchivo,"pacientes.dat");
}
int PacienteArchivo::getPosicion(int dni){
    FILE *pFile;
    Paciente reg;
    int pos=0;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return -1;}

    while(fread(&reg,sizeof(Paciente),1,pFile)==1){
        if(reg.getDni()==dni && reg.getEstado()){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}
int PacienteArchivo::getCantidadRegistros(){
    FILE *pFile;
    int cantReg;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return -1;}

    fseek(pFile,0,SEEK_END);
    cantReg=ftell(pFile)/sizeof(Paciente);

    fclose(pFile);
    return cantReg;
}
Paciente PacienteArchivo::leer(int pos){
    Paciente reg;
    FILE *pFile;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return reg;}

    fseek(pFile,sizeof(Paciente)*pos,SEEK_SET);
    fread(&reg,sizeof(Paciente),1,pFile);

    fclose(pFile);
    return reg;
}
void PacienteArchivo::leer(int cantidadRegistros,Paciente *vec){
    FILE *pFile;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){return;}

    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vec[i], sizeof(Paciente),1,pFile);
    }
    fclose(pFile);
}
bool PacienteArchivo::escribir(Paciente reg){
    FILE *pFile;
    bool result;

    pFile=fopen(_nombreArchivo, "ab");
    if(pFile==nullptr){return false;}

    result = fwrite(&reg,sizeof(Paciente),1,pFile);

    fclose(pFile);
    return result;
}
bool PacienteArchivo::escribir(int pos,Paciente reg){
    FILE *pFile;
    bool result;

    pFile=fopen(_nombreArchivo, "rb+");
    if(pFile==nullptr){return false;}

    fseek(pFile,sizeof(Paciente)*pos,SEEK_SET);
    result = fwrite(&reg,sizeof(Paciente),1,pFile);

    fclose(pFile);
    return result;
}
