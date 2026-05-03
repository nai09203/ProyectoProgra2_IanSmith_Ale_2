//
// Created by ian20 on 5/1/2026.
//

#include "Equipo.h"
#include "Incidencia.h"
#include "ValidadorEquipo.h"
#include "FormatoInvalido.hpp"

Equipo::Equipo(const std::string& codigoEqui, int criticidadEqui, int estadoEqui)
: codigoEqui_(codigoEqui), criticidadEqui_(criticidadEqui), estadoEqui_(estadoEqui),
tiempoInactivo_(0) {

    ValidadorEquipo::validarEquipo(codigoEqui, criticidadEqui, estadoEqui);
}

void Equipo::agregarIncidencia(Incidencia *i) {

    if (i == nullptr) {

        throw FormatoInvalido("No se puede agregar una incidencia nula");
    }
    incidencias_.push_back(i);
}

int Equipo::contarIncidenciasActivas() const {
    int iActive = 0;

    for ( Incidencia * incidencia : incidencias_) {
        if (incidencia !=  nullptr && incidencia->getActivaInci()) {
            iActive++;
        }
    }
    return iActive;
}

void Equipo::cerrarIncidenciasActivas() {
    for (Incidencia* incidencia : incidencias_) {
        if (incidencia != nullptr && incidencia->getActivaInci()) {
            incidencia->cerrarInci();
        }
    }
}

void Equipo::mejorarEstado(int mejoraEstado) {

    if ( mejoraEstado < 0 ) {

        throw FormatoInvalido("La cantidad para mejorar el estado no puede ser negativa");
    }
    estadoEqui_ += mejoraEstado;

    if ( estadoEqui_ > 100) {
        estadoEqui_ = 100;
    }
}

void Equipo::disminuirEstado(int disminuEstado) {
    if ( disminuEstado < 0 ) {
        throw FormatoInvalido("La cantidad para disminuir el estado no puede ser negativa");
    }
    estadoEqui_ -= disminuEstado;

    if ( estadoEqui_ < 0 ) {
        estadoEqui_ = 0;
    }
}

void Equipo::aumentarTiempoInactivo() {
    tiempoInactivo_++;
}

void Equipo::reiniciarTiempoInactivo() {
    tiempoInactivo_ = 0;
}


const std::string& Equipo::getCodigoEquipo() const {
    return codigoEqui_;
}
int Equipo::getCriticidadEquipo() const {
    return criticidadEqui_;
}
int Equipo::getEstadoEquipo() const {
    return estadoEqui_;
}
int Equipo::getTiempoInactivo() const {
    return tiempoInactivo_;
}