//
// Created by ian20 on 5/1/2026.
//

#include "RevisionDeco.h"

#include "Equipo.h"

RevisionDeco::RevisionDeco(Mantenimiento *m): MantenimientoDecorator(m){}

void RevisionDeco::ejecutarMantenimiento(Equipo* e) {
    MantenimientoDecorator::ejecutarMantenimiento(e);

    e->cerrarIncidenciasActivas();
    e->mejorarEstado(6);
}
std::string RevisionDeco::describcionMantenimiento() const {
    return MantenimientoDecorator::describcionMantenimiento() + "+ Revisión";
}