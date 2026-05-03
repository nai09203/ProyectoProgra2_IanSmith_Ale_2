//
// Created by ian20 on 5/2/2026.
//

#include "TextIncidencia.h"
#include <sstream>
#include <vector>
#include <string>
#include "Equipo.h"
#include "Incidencia.h"
#include "ValidadorArchivos.h"
#include "ValidadorIncidencia.h"
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

Equipo* TextIncidencia::buscarEquipo(const std::string& codigo, std::vector<Equipo*> &equipos) {

    for (Equipo* e : equipos) {
        if ( e != nullptr && e->getCodigoEquipo() == codigo) {
            return e;
        }
    }

    return nullptr;
}

Incidencia *TextIncidencia::convertir(const std::string& linea, int numeroLinea, std::vector<Equipo*>& equipos) {

    std::vector<std::string> campos;
    std::stringstream ss(linea);
    std::string campo;

    while (std::getline(ss, campo, ',')) {
        campos.push_back(trimCampo(campo));
    }

    ValidadorArchivos::validarCantidadCamposArchivo(campos.size(), 4, numeroLinea);

    std::string id = trimCampo(campos[0]);
    std::string codigoEquipo = trimCampo(campos[1]);
    int severidad = std::stoi(campos[2]);
    int diaRegistro = std::stoi(campos[3]);

    Equipo* equipo = buscarEquipo(codigoEquipo, equipos);

    if ( equipo == nullptr ) {

        throw FormatoInvalido("Equipo no encontrado en linea" + std::to_string(numeroLinea));
    }

    ValidadorIncidencia::validarIncidencia(id, severidad, diaRegistro, equipo);

    Incidencia* incidencia = new Incidencia(id, severidad, diaRegistro, equipo);

    equipo->agregarIncidencia(incidencia);

    return incidencia;
}
