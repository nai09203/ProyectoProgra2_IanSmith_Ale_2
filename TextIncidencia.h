//
// Created by ian20 on 5/2/2026.
//

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__TEXTINCIDENCIA_H
#define PROYECTOPROGRA2_IANSMITH_ALE__TEXTINCIDENCIA_H
#include <vector>
#include <string>

class Equipo;
class Incidencia;

class TextIncidencia {
private:
    static Equipo* buscarEquipo(const std::string& codigo, std::vector<Equipo*>& equipos);

public:
    static Incidencia* convertir(const std::string& linea, int numeroLinea, std::vector<Equipo*>& equipos);


};


#endif //PROYECTOPROGRA2_IANSMITH_ALE__TEXTINCIDENCIA_H