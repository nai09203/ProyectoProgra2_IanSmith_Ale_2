//
// Created by ian20 on 5/2/2026.
//

#include "FabricaMantenimiento.h"
#include "MantenimientoBase.h"
#include "Mantenimiento.h"
#include "LimpiezaDeco.h"
#include "RevisionDeco.h"

Mantenimiento* FabricaMantenimiento::crearMantenimientoDia() {
    return new RevisionDeco(new LimpiezaDeco(new MantenimientoBase));
}