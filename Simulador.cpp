//
// Created by ian20 on 5/2/2026.
//

#include "Simulador.h"
#include "Equipo.h"
#include "Incidencia.h"
#include "GestorArchivos.h"
#include "Planificador.h"
#include "Reportador.h"
#include "EjecutorMantenimiento.h"
#include "FabricaMantenimiento.h"
#include "Mantenimiento.h"
#include <string>
#include <vector>

Simulador::Simulador(): gestorArchivos_(new GestorArchivos()) {}

Simulador::~Simulador() {

    for ( Equipo* equipo : equipos_) {
        delete equipo;
    }

    for ( Incidencia* incidencia : incidencias_) {
        delete incidencia;
    }

    delete gestorArchivos_;
}

void Simulador::cargarDatos(const std::string &rutaEquipos, const std::string &rutaIncidencias) {

    equipos_ = gestorArchivos_->cargarEquipos(rutaEquipos);
    incidencias_ = gestorArchivos_->cargarIncidencias(rutaIncidencias, equipos_);
}

void Simulador::ejecutarsimulacion() {
    Planificador planificador;

    for ( int dia = 1; dia <= 30; dia++ ) {

        for (Equipo* equipo : equipos_) {
            equipo->degradar();
        }

        std::vector<Equipo*> seleccionados = planificador.seleccionarEquipos(equipos_);

        for (Equipo* equipo : seleccionados) {
            Mantenimiento* mantenimiento = FabricaMantenimiento::crearMantenimientoDia();

            EjecutorMantenimiento::aplicarMantenimiento(equipo, mantenimiento);

            delete mantenimiento;
        }

        std::string reporte = Reportador::generarReporteDia(dia, seleccionados);
        gestorArchivos_->guardarReporte("Reporte Dia" + std::to_string(dia)+ ".txt", reporte);
    }
}
