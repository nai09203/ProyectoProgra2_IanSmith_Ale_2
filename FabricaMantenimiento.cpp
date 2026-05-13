#include "FabricaMantenimiento.h"
#include "Equipo.h"
#include "Mantenimiento.h"
#include "MantenimientoBase.h"
#include "LimpiezaDeco.h"
#include "RevisionDeco.h"
#include "CalibrarDeco.h"

Mantenimiento* FabricaMantenimiento::crearMantenimiento(const Equipo* e) {
    if (e->getTipoEquipo() == "Microscopio de Laboratorio") {
        return new CalibrarDeco(new RevisionDeco(new MantenimientoBase));
    }
    return new RevisionDeco(new LimpiezaDeco(new MantenimientoBase));
}