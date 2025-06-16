#include "ConfiguracionArchivo.h"
#include <cstring>
#include <string>
#include <iostream>

ConfiguracionArchivo::ConfiguracionArchivo(std::string nombreArchivo){
    strcpy(_nombreArchivo,nombreArchivo.c_str());}

bool ConfiguracionArchivo::crearCopia(){

    ///enlace con archivo origen
    FILE *origen=fopen(_nombreArchivo,"rb");
    if(origen==nullptr){return 0;}

    ///definicion de directorio/archivo destino
    std::string archivoDestino="backup/";
    archivoDestino+=_nombreArchivo;

    ///enlace con archivo destino
    FILE *destino=fopen(archivoDestino.c_str(),"wb");
    if(destino==nullptr){return 0;}

    ///calcular cantidad de bytes de origen
    fseek(origen,0,SEEK_END);
    int cantBytes=ftell(origen);

    ///solicitar memoria dinamica para almacenar buffer de operacion
    char *buffer;
    buffer = new char[cantBytes];

    ///lectura de arhivo origen en el buffer
    fseek(origen, 0, SEEK_SET);
    fread(buffer,1,cantBytes,origen);

    ///escritura del buffer en archivo destino
    fwrite(buffer,1,cantBytes,destino);

    ///libero memoria dinamica y punteros file
    delete[] buffer;
    fclose(origen);
    fclose(destino);

    return 1;
}
bool ConfiguracionArchivo::restaurarCopia(){

    ///definicion de directorio/archivo origen
    std::string archivoOrigen="backup/";
    archivoOrigen+=_nombreArchivo;

    ///enlace con archivo origen
    FILE *origen=fopen(archivoOrigen.c_str(),"rb");
    if(origen==nullptr){return 0;}

    ///enlace con archivo destino
    FILE *destino=fopen(_nombreArchivo,"wb");
    if(destino==nullptr){return 0;}

    ///calcular cantidad de bytes de origen
    fseek(origen,0,SEEK_END);
    int cantBytes=ftell(origen);

    ///solicitar memoria dinamica para almacenar buffer de operacion
    char *buffer;
    buffer = new char[cantBytes];

    ///lectura de arhivo origen en el buffer
    fseek(origen, 0, SEEK_SET);
    fread(buffer,1,cantBytes,origen);

    ///escritura del buffer en archivo destino
    fwrite(buffer,1,cantBytes,destino);

    ///libero memoria dinamica y punteros file
    delete[] buffer;
    fclose(origen);
    fclose(destino);

    return 1;

}
