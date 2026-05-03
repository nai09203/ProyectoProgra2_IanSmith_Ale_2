//
// Created by ian20 on 5/2/2026.
//

#include "Reportador.h"
#include <sstream>
#include <vector>
#include "Equipo.h"
#include "CalcularPrioridad.h"

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
