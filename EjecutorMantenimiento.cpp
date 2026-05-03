//
// Created by ian20 on 5/1/2026.
//

#include "EjecutorMantenimiento.h"
#include "Equipo.h"
#include "Mantenimiento.h"
#include "FormatoInvalido.hpp"

void EjecutorMantenimiento::aplicarMantenimiento(Equipo* e_, Mantenimiento* m_) {

    if (e_ == nullptr) {

        throw FormatoInvalido("No se puede aplicar mantenimiento a un equipo Nulo");
    }
    if (m_ == nullptr) {

        throw FormatoInvalido("No se puede aplicar un mantenimiento Nulo");
    }

    m_->ejecutarMantenimiento(e_);
    e_->reiniciarTiempoInactivo();
}
