#include "Reporte.h"
#include "Turno.h"
#include "TurnoArchivo.h"
#include "PacienteArchivo.h"
#include "MedicoArchivo.h"
#include "EspecialidadArchivo.h"
#include "ObraSocial.h"
#include "ObraSocialArchivo.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <iomanip>
#include <iostream>

using namespace std;

void Reporte::recaudacionAnualMensual(){
     TurnoArchivo archivo;
    int cantidad = archivo.getCantidadRegistros();

    if (cantidad <= 0) {
        cout << "No hay registros de turnos cargados.\n";
        return;
    }

    Turno* vec = new Turno[cantidad];
    if (vec == nullptr) {
        cout << "Error al asignar memoria.\n";
        return;
    }

    archivo.leer(cantidad, vec);

    int anio, mes;
    float recaudacion = 0.0;

    cout << "Ingrese el anio a consultar: ";
    cin >> anio;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida.\n";
        delete[] vec;
        return;
    }

    cout << "Ingrese el mes (1-12) o 0 para ver todo el anio: ";
    cin >> mes;
    if (cin.fail() || mes < 0 || mes > 12) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida.\n";
        delete[] vec;
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        if (!vec[i].getEstado()) continue;

        FechaHora fh = vec[i].getFechaHoraAtencion();

        if (fh.getAnio() == anio && (mes == 0 || fh.getMes() == mes)) {
            recaudacion += vec[i].getImporteConsulta();
        }
    }

    cout << fixed << setprecision(2);
    if (mes == 0) {
        cout << "\nRecaudación del anio " << anio << ": $" << recaudacion << "\n";
    } else {
        cout << "\nRecaudacion de mes " << mes << " / " << anio << ": $" << recaudacion << "\n";
    }

    delete[] vec;
}
void Reporte::recaudacionObraSocial(){

      TurnoArchivo turnoArchivo;
    PacienteArchivo pacienteArchivo;
    ObraSocialArchivo obraArchivo;

    int cantTurnos = turnoArchivo.getCantidadRegistros();
    int cantPacientes = pacienteArchivo.getCantidadRegistros();
    int cantObras = obraArchivo.getCantidadRegistros();

    if (cantTurnos <= 0 || cantPacientes <= 0 || cantObras <= 0) {
        cout << "No hay datos suficientes para generar el reporte.\n";
        return;
    }

    int anio, mes;
    cout << "Ingrese el año a consultar: ";
    cin >> anio;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida.\n";
        return;
    }

    cout << "Ingrese el mes (1-12) o 0 para ver todo el anio: ";
    cin >> mes;
    if (cin.fail() || mes < 0 || mes > 12) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida.\n";
        return;
    }

    Paciente* pacientes = new Paciente[cantPacientes];
    pacienteArchivo.leer(cantPacientes, pacientes);

    map<int, int> dniAobraSocial;
    for (int i = 0; i < cantPacientes; i++) {
        if (pacientes[i].getEstado()) {
            dniAobraSocial[pacientes[i].getDni()] = pacientes[i].getCodObraSocial();
        }
    }
    delete[] pacientes;

    map<int, string> obrasSociales;
    for (int i = 0; i < cantObras; i++) {
        ObraSocial os = obraArchivo.leer(i);
        if (os.getEstado()) {
            obrasSociales[os.getCodigoObraSocial()] = os.getNombre();
        }
    }

    Turno* turnos = new Turno[cantTurnos];
    turnoArchivo.leer(cantTurnos, turnos);

    map<int, float> recaudacionPorOS;
    for (int i = 0; i < cantTurnos; i++) {
        if (!turnos[i].getEstado()) continue;

        FechaHora fh = turnos[i].getFechaHoraAtencion();
        if (fh.getAnio() != anio || (mes != 0 && fh.getMes() != mes)) continue;

        int dni = turnos[i].getDniPaciente();
        auto it = dniAobraSocial.find(dni);
        if (it != dniAobraSocial.end()) {
            int codOS = it->second;
            recaudacionPorOS[codOS] += turnos[i].getImporteConsulta();
        }
    }
    delete[] turnos;

    cout << "\n" << left
         << setw(10) << "Codigo"
         << setw(25) << "Obra Social"
         << right << setw(15) << "Recaudacion ($)" << "\n";
    cout << string(50, '-') << "\n";

    for (const auto& item : recaudacionPorOS) {
        int codigo = item.first;
        float monto = item.second;
        string nombreOS = obrasSociales.count(codigo) ? obrasSociales[codigo] : "Desconocida";

        cout << left
             << setw(10) << codigo
             << setw(25) << nombreOS
             << right << setw(15) << fixed << setprecision(2) << monto << "\n";
    }

    cout << endl;

}
void Reporte::recaudacionEspecialidad(){
   TurnoArchivo turnoArchivo;
    MedicoArchivo medicoArchivo;
    EspecialidadArchivo especialidadArchivo;

    int cantidadTurnos = turnoArchivo.getCantidadRegistros();
    if (cantidadTurnos <= 0) {
        std::cout << "No hay turnos registrados.\n";
        return;
    }

    int anio, mes;
    std::cout << "Ingrese el anio a consultar: ";
    std::cin >> anio;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada invalida.\n";
        return;
    }

    std::cout << "Ingrese el mes (1-12) o 0 para ver todo el anio: ";
    std::cin >> mes;
    if (std::cin.fail() || mes < 0 || mes > 12) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada invalida.\n";
        return;
    }

    Turno* turnos = new Turno[cantidadTurnos];
    if (turnos == nullptr) {
        std::cout << "Error al asignar memoria.\n";
        return;
    }
    turnoArchivo.leer(cantidadTurnos, turnos);

    std::map<int, float> recaudacionPorEspecialidad;

    for (int i = 0; i < cantidadTurnos; ++i) {
        if (!turnos[i].getEstado()) continue;

        FechaHora fh = turnos[i].getFechaHoraAtencion();
        if (fh.getAnio() != anio || (mes != 0 && fh.getMes() != mes)) continue;

        int dniMedico = turnos[i].getDniMedico();
        int posMedico = medicoArchivo.getPosicion(dniMedico);
        if (posMedico != -1) {
            Medico medico = medicoArchivo.leer(posMedico);
            int codEspecialidad = medico.getCodigoEspecialidad();
            recaudacionPorEspecialidad[codEspecialidad] += turnos[i].getImporteConsulta();
        }
    }

    delete[] turnos;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::left
              << std::setw(10) << "Codigo"
              << std::setw(25) << "Especialidad"
              << std::right << std::setw(15) << "Recaudacion ($)"
              << "\n";
    std::cout << std::string(50, '-') << "\n";

    for (const auto& par : recaudacionPorEspecialidad) {
        int codigo = par.first;
        float monto = par.second;

        int posEspecialidad = especialidadArchivo.getPosicion(codigo);
        std::string nombre = (posEspecialidad != -1) ? especialidadArchivo.leer(posEspecialidad).getNombre() : "Desconocido";

        std::cout << std::left
                  << std::setw(10) << codigo
                  << std::setw(25) << nombre
                  << std::right << std::setw(15) << monto
                  << "\n";
    }

    std::cout << std::endl;
}
void Reporte::cantidadPacientesMedico(){}
void Reporte::cantidadTurnosMedico(){}
void Reporte::cantidadTurnosPaciente(){}
