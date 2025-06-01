#include <iostream>
using namespace std;
#include "TurnoManager.h"
#include  "FechaHora.h"
#include "Turno.h"


    void TurnoManager::altaTurno(){
        int idTurno;
        int dniPaciente;
        int dniMedico;
        FechaHora fechaAtencion;
        FechaHora horaAtencion;
        float importeConsulta;

        //falta el idTurno

        cout << "Ingrese DNI del paciente: ";
        cin >> dniPaciente;

        cout << "Ingrese DNI del medico: ";
        cin >> dniMedico;

        cout << "Ingrese la fecha de atencion (dd/mm/aaaa): " << endl;
        fechaAtencion.cargarFecha();

        cout << "Ingrese la hora de atencion (hh:mm): " << endl;
        horaAtencion.cargarHora();

        cout << "Ingrese el importe de la consulta: ";
        cin >> importeConsulta;

        Turno nuevoTurno(idTurno, dniPaciente, dniMedico, fechaAtencion, horaAtencion, importeConsulta);

        cout << "Turno generado #: " << idTurno << endl;

    }
