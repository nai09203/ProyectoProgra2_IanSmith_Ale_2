//
// Created by ian20 on 5/2/2026.
//

#include "Planificador.h"
#include "Equipo.h"
#include "OrdenadorEquipos.h"

std::vector<Equipo *> Planificador::seleccionarEquipos(std::vector<Equipo*> &equipos) {
    OrdenadorEquipos::ordenarEquipos(equipos);

    std::vector<Equipo*> seleccionados;
    size_t toSelect = 3;
    if (toSelect > equipos.size()) {
        toSelect = equipos.size();
    }

    for (size_t i = 0; i < toSelect; i++) {
        seleccionados.push_back(equipos[i]);
    }

    // Garantiza al menos una computadora si existe en la lista
    bool tieneComputadora = false;
    for (Equipo* e : seleccionados) {
        if (e != nullptr && e->getTipoEquipo().find("Computadora") != std::string::npos) {
            tieneComputadora = true;
            break;
        }
    }

    if (!tieneComputadora) {
        for (Equipo* candidato : equipos) {
            if (candidato == nullptr) {
                continue;
            }
            if (candidato->getTipoEquipo().find("Computadora") == std::string::npos) {
                continue;
            }

            bool yaSeleccionado = false;
            for (Equipo* s : seleccionados) {
                if (s == candidato) {
                    yaSeleccionado = true;
                    break;
                }
            }
            if (yaSeleccionado) {
                continue;
            }

            if (seleccionados.size() < 3) {
                seleccionados.push_back(candidato);
            } else if (!seleccionados.empty()) {
                seleccionados.back() = candidato;
            }
            break;
        }
    }

    return seleccionados;
}
