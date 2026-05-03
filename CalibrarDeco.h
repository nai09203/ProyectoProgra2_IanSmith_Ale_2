//
// Created by ian20 on 5/1/2026.
//

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__CALIBRARDECO_H
#define PROYECTOPROGRA2_IANSMITH_ALE__CALIBRARDECO_H
#include "MantenimientoDecorator.h"

class CalibrarDeco : public MantenimientoDecorator {
    public:
    CalibrarDeco(Mantenimiento* m);
    void ejecutarMantenimiento(Equipo *e) override;
    std::string describcionMantenimiento() const override;
};


#endif //PROYECTOPROGRA2_IANSMITH_ALE__CALIBRARDECO_H