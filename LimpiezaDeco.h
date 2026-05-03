//
// Created by ian20 on 5/1/2026.
//

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__LIMPIEZADECO_H
#define PROYECTOPROGRA2_IANSMITH_ALE__LIMPIEZADECO_H
#include "MantenimientoDecorator.h"
#include <string>

class LimpiezaDeco : public MantenimientoDecorator {
public:
    LimpiezaDeco(Mantenimiento* m);

    void ejecutarMantenimiento(Equipo* e) override;
    std::string describcionMantenimiento() const override;
};


#endif //PROYECTOPROGRA2_IANSMITH_ALE__LIMPIEZADECO_H