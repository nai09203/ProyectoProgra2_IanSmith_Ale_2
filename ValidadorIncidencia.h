//
// Created by ian20 on 4/30/2026.
//

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__VALIDADORINCIDENCIA_H
#define PROYECTOPROGRA2_IANSMITH_ALE__VALIDADORINCIDENCIA_H
#include <string>

class Equipo;

class ValidadorIncidencia {
public:
    static void validarIncidencia(const std::string& idInci_, int severidadInci_, int diaRegistroInci_, Equipo* equipo_);
};


#endif //PROYECTOPROGRA2_IANSMITH_ALE__VALIDADORINCIDENCIA_H