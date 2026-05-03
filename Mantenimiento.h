//
// Created by ian20 on 5/1/2026.
//

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__MANTENIMIENTO_H
#define PROYECTOPROGRA2_IANSMITH_ALE__MANTENIMIENTO_H
#include <string>

class Equipo;
class Mantenimiento {
public:

    virtual ~Mantenimiento() = default;
    virtual void ejecutarMantenimiento(Equipo* e) = 0;
    virtual std::string describcionMantenimiento()const = 0;

};
#endif //PROYECTOPROGRA2_IANSMITH_ALE__MANTENIMIENTO_H