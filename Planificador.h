//
// Created by ian20 on 5/2/2026.
//

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__PLANIFICADOR_H
#define PROYECTOPROGRA2_IANSMITH_ALE__PLANIFICADOR_H
#include <vector>
class Equipo;

class Planificador {
public:
    std::vector<Equipo*> seleccionarEquipos(std::vector<Equipo*>& equipos);
};


#endif //PROYECTOPROGRA2_IANSMITH_ALE__PLANIFICADOR_H