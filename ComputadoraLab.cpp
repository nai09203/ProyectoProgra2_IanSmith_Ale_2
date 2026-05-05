//
// Created by ian20 on 5/1/2026.
//

#include "ComputadoraLab.h"

ComputadoraLab::ComputadoraLab
(const std::string &codigoEqui, int criticidadEqui, int estadoEqui):
Equipo(codigoEqui,criticidadEqui, estadoEqui){}

std::string ComputadoraLab::getTipoEquipo()const{
    return "Computadora de Laboratorio";
}

void ComputadoraLab::degradar() {

    disminuirEstado(10);
    aumentarTiempoInactivo();
}

void ComputadoraLab::limpiarCompu() {
    mejorarEstado(60);
}
