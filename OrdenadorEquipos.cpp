//
// Created by ian20 on 5/2/2026.
//

#include "OrdenadorEquipos.h"
#include "Equipo.h"
#include "CalcularPrioridad.h"

void OrdenadorEquipos::ordenarEquipos(std::vector<Equipo*>& equipos) {

    int n = equipos.size();
    for (int i = 1; i < n; ++i) {
        Equipo* key = equipos[i];
        double keyPriority = CalcularPrioridad::calculaPrioridad(key);

        int j = i - 1;

        while (j >= 0 && CalcularPrioridad::calculaPrioridad(equipos[j]) > keyPriority) {
            equipos[j + 1] = equipos[j];
            j--;
        }

        equipos[j + 1] = key;
    }
}