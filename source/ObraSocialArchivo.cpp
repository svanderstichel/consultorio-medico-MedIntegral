#include "ObraSocialArchivo.h"
#include <cstring>
#include <cstdio>

ObraSocialArchivo::ObraSocialArchivo() {
    strcpy(_nombreArchivo, "obrassociales.dat");
}

int ObraSocialArchivo::getCantidadRegistros() {
    FILE* pFile = fopen(_nombreArchivo, "rb");
    if (pFile == nullptr) return -1;

    fseek(pFile, 0, SEEK_END);
    int cantidad = ftell(pFile) / sizeof(ObraSocial);
    fclose(pFile);
    return cantidad;
}

int ObraSocialArchivo::getPosicion(int codigo) {
    FILE* pFile = fopen(_nombreArchivo, "rb");
    if (pFile == nullptr) return -1;

    ObraSocial reg;
    int pos = 0;

    while (fread(&reg, sizeof(ObraSocial), 1, pFile) == 1) {
        if (reg.getCodigoObraSocial() == codigo) {
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

ObraSocial ObraSocialArchivo::leer(int pos) {
    ObraSocial reg;
    FILE* pFile = fopen(_nombreArchivo, "rb");
    if (pFile == nullptr) return reg;

    fseek(pFile, sizeof(ObraSocial) * pos, SEEK_SET);
    fread(&reg, sizeof(ObraSocial), 1, pFile);
    fclose(pFile);
    return reg;
}

void ObraSocialArchivo::leer(int cantidadRegistros, ObraSocial* vec) {
    FILE* pFile = fopen(_nombreArchivo, "rb");
    if (pFile == nullptr) return;

    for (int i = 0; i < cantidadRegistros; i++) {
        fread(&vec[i], sizeof(ObraSocial), 1, pFile);
    }

    fclose(pFile);
}

bool ObraSocialArchivo::escribir(ObraSocial reg) {
    FILE* pFile = fopen(_nombreArchivo, "ab");
    if (pFile == nullptr) return false;

    bool resultado = fwrite(&reg, sizeof(ObraSocial), 1, pFile);
    fclose(pFile);
    return resultado;
}

bool ObraSocialArchivo::escribir(int pos, ObraSocial reg) {
    FILE* pFile = fopen(_nombreArchivo, "rb+");
    if (pFile == nullptr) return false;

    fseek(pFile, sizeof(ObraSocial) * pos, SEEK_SET);
    bool resultado = fwrite(&reg, sizeof(ObraSocial), 1, pFile);
    fclose(pFile);
    return resultado;
}
