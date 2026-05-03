//
// Created by ian20 on 5/1/2026.
//

#include "CalibrarDeco.h"

#include "ErrorGeneral.hpp"
#include "FormatoInvalido.hpp"
#include "MicroscopioLab.h"

CalibrarDeco::CalibrarDeco(Mantenimiento *m) : MantenimientoDecorator(m) {
}

void CalibrarDeco::ejecutarMantenimiento(Equipo *e) {
    MantenimientoDecorator::ejecutarMantenimiento(e);

    MicroscopioLab *micros = dynamic_cast<MicroscopioLab *>(e);

    if (micros == nullptr) {
        throw ErrorGeneral("La calibración solo puede ser aplicada a Microscopios");
    }
    micros->calibrarMicroscopio();
}

std::string CalibrarDeco::describcionMantenimiento() const {
    return MantenimientoDecorator::describcionMantenimiento() + "+ Calibración";
}
