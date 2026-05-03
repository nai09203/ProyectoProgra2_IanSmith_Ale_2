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

namespace {
    std::string trimCampo(const std::string& valor) {
        size_t inicio = 0;
        while (inicio < valor.size() && (valor[inicio] == ' ' || valor[inicio] == '\t' || valor[inicio] == '\r' || valor[inicio] == '\n')) {
            inicio++;
        }
        size_t fin = valor.size();
        while (fin > inicio && (valor[fin - 1] == ' ' || valor[fin - 1] == '\t' || valor[fin - 1] == '\r' || valor[fin - 1] == '\n')) {
            fin--;
        }
        return valor.substr(inicio, fin - inicio);
    }
}

Equipo* TextEquipo::convertir(const std::string& linea, int numeroLinea) {

    std::vector<std::string> campos;
    std::stringstream ss(linea);
    std::string campo;

    while ( std::getline(ss, campo, ',') ) {
        campos.push_back(trimCampo(campo));
    }

    ValidadorArchivos::validarCantidadCamposArchivo(campos.size(), 4, numeroLinea);

    std::string tipo = trimCampo(campos[0]);
    std::string codigo = trimCampo(campos[1]);
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