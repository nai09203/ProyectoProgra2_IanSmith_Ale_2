//
// Created by ian20 on 5/1/2026.
//

#include "MantenimientoBase.h"
#include "Equipo.h"
#include "FormatoInvalido.hpp"

void MantenimientoBase::ejecutarMantenimiento(Equipo *e) {
    if (e == nullptr) {

        throw FormatoInvalido("No se puede ejecutar el mantenimiento a un equipo nulo");
    }
    e->mejorarEstado(40);
}
std::string MantenimientoBase::describcionMantenimiento()const {
    return "Mantenimiento Base";
}
