//
// Created by ian20 on 5/2/2026.
//

#include "Planificador.h"
#include "Equipo.h"
#include "OrdenadorEquipos.h"

std::vector<Equipo *> Planificador::seleccionarEquipos(std::vector<Equipo*> &equipos) {
    OrdenadorEquipos::ordenarEquipos(equipos);

    std::vector<Equipo*> seleccionados;

    for (int i = 0; i < 3; i++) {
        seleccionados.push_back(equipos[i]);
    }
    return seleccionados;
}
