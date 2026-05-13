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
    for (Equipo* equipo : equipos_) delete equipo;
    for (Incidencia* incidencia : incidencias_) delete incidencia;
    delete gestorArchivos_;
}

void Simulador::cargarDatos(const std::string& rutaEquipos, const std::string& rutaIncidencias) {
    equipos_ = gestorArchivos_->cargarEquipos(rutaEquipos);
    incidencias_ = gestorArchivos_->cargarIncidencias(rutaIncidencias, equipos_);
}

void Simulador::generarIncidenciasDiarias(int dia) {
    int contador = 1;
    for (Equipo* equipo : equipos_) {
        if (equipo->getEstadoEquipo() < 40) {
            std::string id = "INC-D" + std::to_string(dia) + "-" + std::to_string(contador++);
            Incidencia* inc = new Incidencia(id, 5, dia, equipo);
            equipo->agregarIncidencia(inc);
            incidencias_.push_back(inc);
        }
    }
}

void Simulador::ejecutarsimulacion() {
    Planificador planificador;

    for (int dia = 1; dia <= 30; dia++) {

        for (Equipo* equipo : equipos_) {
            equipo->degradar();
        }

        generarIncidenciasDiarias(dia);  // <- LÍNEA NUEVA

        std::vector<Equipo*> seleccionados = planificador.seleccionarEquipos(equipos_);

        for (Equipo* equipo : seleccionados) {
            Mantenimiento* mantenimiento = FabricaMantenimiento::crearMantenimiento(equipo);  // <- ACTUALIZADO
            EjecutorMantenimiento::aplicarMantenimiento(equipo, mantenimiento);
            delete mantenimiento;
        }

        std::string reporte = Reportador::generarReporteDia(dia, seleccionados, equipos_);
        gestorArchivos_->guardarReporte("Reporte Dia" + std::to_string(dia) + ".txt", reporte);
    }

    gestorArchivos_->guardarReporteGeneral("reporte_final.txt", equipos_);
}