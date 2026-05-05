//
// Created by ian20 on 5/1/2026.
//

#include "GestorArchivos.h"
#include <fstream>
#include <string>
#include <vector>
#include "ValidadorArchivos.h"
#include "TextEquipo.h"
#include "TextIncidencia.h"
#include "Reportador.h"

std::vector<Equipo*> GestorArchivos::cargarEquipos(const std::string& ruta) {

    std::ifstream archivo(ruta);
    ValidadorArchivos::validarAperturaArchivo(archivo.is_open(), ruta);

    std::vector<Equipo*> equipos;
    std::string linea;
    int numeroLinea = 0;

    while (std::getline(archivo, linea)) {
        numeroLinea++;

        ValidadorArchivos::validarLineaNoVaciaArchivo(linea, numeroLinea);

        equipos.push_back(TextEquipo::convertir(linea, numeroLinea));
    }
    return equipos;
}

std::vector<Incidencia*> GestorArchivos::cargarIncidencias(const std::string& ruta, std::vector<Equipo*>& equipos) {

    std::ifstream archivo(ruta);
    ValidadorArchivos::validarAperturaArchivo(archivo.is_open(), ruta);

    std::vector<Incidencia*> incidencias;
    std::string linea;
    int numeroLinea = 0;

    while (std::getline(archivo, linea)) {
        numeroLinea++;

        ValidadorArchivos::validarLineaNoVaciaArchivo(linea, numeroLinea);

        incidencias.push_back(TextIncidencia::convertir(linea, numeroLinea, equipos));
    }
    return incidencias;
}

void GestorArchivos::guardarReporte(const std::string& ruta, const std::string& contenido) {
    std::ofstream archivo(ruta);

    ValidadorArchivos::validarAperturaArchivo(archivo.is_open(), ruta);

    archivo << contenido;
}

void GestorArchivos::guardarReporteGeneral(const std::string& ruta, std::vector<Equipo*>& todos) {

    std::string contenido = Reportador::ReporteGeneral(todos);
    guardarReporte(ruta, contenido);
}
