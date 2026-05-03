//
// Created by ian20 on 5/1/2026.
//

#include "CalcularPrioridad.h"
#include "Equipo.h"
#include "FormatoInvalido.hpp"

double CalcularPrioridad::calculaPrioridad(const Equipo* e_) {

    if ( e_ == nullptr) {
        throw FormatoInvalido("No se puede calcular la prioridad de un equipo vacio");
    }

    return (e_->getCriticidadEquipo() * 0.5) + (e_->contarIncidenciasActivas() * 0.3) + (e_->getTiempoInactivo() * 0.2);
}