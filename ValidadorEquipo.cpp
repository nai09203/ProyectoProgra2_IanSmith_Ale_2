//
// Created by ian20 on 4/30/2026.
//

#include "ValidadorEquipo.h"
#include "FormatoInvalido.hpp"

void ValidadorEquipo::validarEquipo(const std::string& idEqui_, int criticidadEqui_, int estadoEqui_) {
    if (idEqui_.empty()) {

        throw FormatoInvalido("Id de Equipo vacio");
    }
    if (criticidadEqui_ < 1|| criticidadEqui_ > 10) {

        throw FormatoInvalido("Criticidad de Equipo fuera de rango");
    }
    if (estadoEqui_ < 0 || estadoEqui_ > 100) {

        throw FormatoInvalido("Estado de Equipo fuera de rango");
    }
}