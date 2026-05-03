//
// Created by ian20 on 5/1/2026.
//

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__MANTENIMIENTODECORATOR_H
#define PROYECTOPROGRA2_IANSMITH_ALE__MANTENIMIENTODECORATOR_H
#include "Mantenimiento.h"
#include <string>

class MantenimientoDecorator : public Mantenimiento{
    protected:
    Mantenimiento* mantenimiento_;

    public:
    MantenimientoDecorator(Mantenimiento* m);
    ~MantenimientoDecorator() override = default;

    void ejecutarMantenimiento(Equipo* e) override;
    std::string describcionMantenimiento()const override;
};


#endif //PROYECTOPROGRA2_IANSMITH_ALE__MANTENIMIENTODECORATOR_H