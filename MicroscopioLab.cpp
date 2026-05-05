//
// Created by ian20 on 5/1/2026.
//

#include "MicroscopioLab.h"

MicroscopioLab::MicroscopioLab(const std::string& codigoEqui, int criticidadEqui, int estadoEqui)
: Equipo(codigoEqui, criticidadEqui, estadoEqui){}

std::string MicroscopioLab::getTipoEquipo() const {
    return "Microscopio de Laboratorio";
}

void MicroscopioLab::degradar() {
    disminuirEstado(5);
    aumentarTiempoInactivo();

}

void MicroscopioLab::calibrarMicroscopio() {
    mejorarEstado(40);
}
