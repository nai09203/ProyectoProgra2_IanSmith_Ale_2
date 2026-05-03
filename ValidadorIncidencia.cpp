//
// Created by ian20 on 4/30/2026.
//

#include "ValidadorIncidencia.h"
#include "FormatoInvalido.hpp"
#include "Equipo.h"

void ValidadorIncidencia::validarIncidencia(const std::string &idInci_, int severidadInci_, int diaRegistroInci_, Equipo *equipo_) {

    if (idInci_.empty()) {

        throw FormatoInvalido("Id de incidencia vacio");
    }
    if (severidadInci_ < 1 || severidadInci_ > 10) {

        throw FormatoInvalido("Severidad de Incidencia fuera de rango (1-10)");
    }
    if (diaRegistroInci_ < 0) {

        throw FormatoInvalido("Dia de registro de incidencia invalido");
    }
    if (equipo_ == nullptr) {

        throw FormatoInvalido("Incidencia sin Equipo asociado");
    }
}
