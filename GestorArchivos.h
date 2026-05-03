//
// Created by ian20 on 5/1/2026.
//

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__GESTORARCHIVOS_H
#define PROYECTOPROGRA2_IANSMITH_ALE__GESTORARCHIVOS_H
#include <string>
#include <vector>

class Equipo;
class Incidencia;

class GestorArchivos {
public:
    std::vector<Equipo*> cargarEquipos(const std::string& ruta);
    std::vector<Incidencia*> cargarIncidencias(const std::string& ruta, std::vector<Equipo*>& equipos);
    void guardarReporte(const std::string& ruta, const std::string& contenido);
    void guardarReporteGeneral(const std::string& ruta, std::vector<Equipo*>& todos);
};


#endif //PROYECTOPROGRA2_IANSMITH_ALE__GESTORARCHIVOS_H