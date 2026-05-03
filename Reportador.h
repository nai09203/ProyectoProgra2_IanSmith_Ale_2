//
// Created by ian20 on 5/2/2026.
//

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__REPORTADOR_H
#define PROYECTOPROGRA2_IANSMITH_ALE__REPORTADOR_H
#include <string>
#include <vector>

class Equipo;

class Reportador {
public:
    static std::string generarReporteDia(int dia, const std::vector<Equipo*>& seleccionados);
};


#endif //PROYECTOPROGRA2_IANSMITH_ALE__REPORTADOR_H