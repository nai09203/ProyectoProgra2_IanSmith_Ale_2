//
// Created by ian20 on 5/2/2026.
//

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__TEXTEQUIPO_H
#define PROYECTOPROGRA2_IANSMITH_ALE__TEXTEQUIPO_H
#include <string>

class Equipo;

class TextEquipo {
public:
    static Equipo *convertir(const std::string &linea, int numeroDeLinea);
};


#endif //PROYECTOPROGRA2_IANSMITH_ALE__TEXTEQUIPO_H
