//
// Created by ian20 on 5/2/2026.
//

#include "TextEquipo.h"
#include <sstream>
#include <vector>
#include "Equipo.h"
#include "MicroscopioLab.h"
#include "ComputadoraLab.h"
#include "ValidadorArchivos.h"
#include "ValidadorEquipo.h"
#include "FormatoInvalido.hpp"

Equipo* TextEquipo::convertir(const std::string& linea, int numeroLinea) {

    std::vector<std::string> campos;
    std::stringstream ss(linea);
    std::string campo;

    while ( std::getline(ss, campo, ',') ) {
        campos.push_back(campo);
    }

    ValidadorArchivos::validarCantidadCamposArchivo(static_cast<int>(campos.size()), 4, numeroLinea);

    std::string tipo = campos[0];
    std::string codigo = campos[1];
    int criticidad = std::stoi(campos[2]);
    int estado = std::stoi(campos[3]);

    ValidadorEquipo::validarEquipo(codigo, criticidad, estado);

    if ( tipo == "Microscopio") {

        return new MicroscopioLab(codigo, criticidad, estado);
    }
    if ( tipo == "Computadora") {

        return new ComputadoraLab(codigo, criticidad, estado);
    }

    throw FormatoInvalido("Tipo de Equipo invalido en linea" + std::to_string(numeroLinea));
}