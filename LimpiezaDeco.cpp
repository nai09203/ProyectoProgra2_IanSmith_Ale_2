//
// Created by ian20 on 5/1/2026.
//

#include "LimpiezaDeco.h"
#include "Equipo.h"

LimpiezaDeco::LimpiezaDeco(Mantenimiento *m): MantenimientoDecorator(m){}

void LimpiezaDeco::ejecutarMantenimiento(Equipo *e) {
    MantenimientoDecorator::ejecutarMantenimiento(e);
    e->mejorarEstado(30);
}
std::string LimpiezaDeco::describcionMantenimiento() const {
    return MantenimientoDecorator::describcionMantenimiento() + "+ Limpieza";
}