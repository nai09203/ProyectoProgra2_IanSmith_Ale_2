//
// Created by ian20 on 5/1/2026.
//

#include "MantenimientoDecorator.h"
#include "FormatoInvalido.hpp"

MantenimientoDecorator::MantenimientoDecorator(Mantenimiento* m) : mantenimiento_(m) {
    if ( mantenimiento_ == nullptr ) {
        throw FormatoInvalido("El mantenimiento Decorator no puede ser nulo");

    }
}
void MantenimientoDecorator::ejecutarMantenimiento(Equipo* e) {
    mantenimiento_->ejecutarMantenimiento(e);
}
std::string MantenimientoDecorator::describcionMantenimiento()const {
    return mantenimiento_->describcionMantenimiento();
}
