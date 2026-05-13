//
// Created by ian20 on 5/1/2026.
//

#include "ValidadorArchivos.h"
#include "ArchivoInvalido.hpp"
#include "FormatoInvalido.hpp"

void ValidadorArchivos::validarAperturaArchivo(bool abierto, const std::string &ruta) {

    if (!abierto) {

        throw ArchivoInvalido("No se pudo abrir el Archivo" + ruta);
    }
}

void ValidadorArchivos::validarLineaNoVaciaArchivo(const std::string &linea, int numeroLinea) {

    if (linea.empty()) {

        throw FormatoInvalido("Linea vacia en Linea" + std::to_string(numeroLinea));
    }
}

void ValidadorArchivos::validarCantidadCamposArchivo(std::size_t cantidad, std::size_t erwartetwort, int numeroLinea) {

    if (cantidad != erwartetwort) {

        throw FormatoInvalido("Cantidad de campos de linea invalida" + std::to_string(numeroLinea));
    }
}
