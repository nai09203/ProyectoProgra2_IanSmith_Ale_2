//
// Created by ian20 on 5/2/2026.
//

#include "Reportador.h"
#include <sstream>
#include <vector>
#include "Equipo.h"
#include "CalcularPrioridad.h"
#include "OrdenadorEquipos.h"

std::string Reportador::generarReporteDia(int dia, const std::vector<Equipo *> &seleccionados) {
    std::stringstream s;

    s<<"Dia: "<<dia <<std::endl;

    s<<"Top Prioridad: ";

    for (size_t i = 0; i < seleccionados.size(); i++) {

        double prior = CalcularPrioridad::calculaPrioridad(seleccionados[i]);

        s << seleccionados[i]->getCodigoEquipo()<< " (" << prior << ")"
        << " estado: " << seleccionados[i]->getEstadoEquipo();

        if ( i < seleccionados.size() - 1 ) {
            s<< ", ";
        }
    }
    s<<std::endl;

    s<<"Asignados: ";

    for (size_t i = 0; i < seleccionados.size(); i++) {
        s<<seleccionados[i]->getCodigoEquipo();

        if ( i < seleccionados.size() - 1 ) {
            s<< ", ";
        }
    }
    s<<std::endl;

    return s.str();
}

std::string Reportador::ReporteGeneral(std::vector <Equipo *> &todos) {
    std::stringstream s;

    s << "=== Reporte de 30 dias ===\n\n";
    s << "Estado final de equipos:\n";

    std::vector<Equipo*> ordenados = todos;
    OrdenadorEquipos::ordenarEquipos(ordenados);

    double totalPrioridad = 0.0;

    for (size_t i = 0; i < ordenados.size(); i++) {
        double prioridad = CalcularPrioridad::calculaPrioridad(ordenados[i]);
        totalPrioridad += prioridad;

        s << ordenados[i]->getCodigoEquipo()
          << "   | Estado: " << ordenados[i]->getEstadoEquipo()
          << "   | Prioridad: " << prioridad
          << "   | Incidencias Activas: " << ordenados[i]->contarIncidenciasActivas()
          << "   | Modelo antes de simulacion: " << ordenados[i]->getTipoEquipo()
          << "   | Criticidad: " << ordenados[i]->getCriticidadEquipo()
          << "\n";
    }

    s << "\n";

    // Calculo simple de riesgo: suma de prioridades y promedio
    double riesgoGlobal = totalPrioridad;
    double promedio = ordenados.empty() ? 0.0 : (totalPrioridad / ordenados.size());

    s << "Riesgo global final: " << riesgoGlobal << "\n";
    s << "Promedio prioridad: " << promedio << "\n";
    s << "Total de equipos en simulacion: " << ordenados.size() << "\n";

    return s.str();
}
