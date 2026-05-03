//
// Created by ian20 on 5/1/2026.
//

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__MANTENIMIENTOBASE_H
#define PROYECTOPROGRA2_IANSMITH_ALE__MANTENIMIENTOBASE_H

#include "Mantenimiento.h"

class MantenimientoBase : public Mantenimiento{
    public:
    void ejecutarMantenimiento(Equipo* e) override;
    std::string describcionMantenimiento()const override;
};


#endif //PROYECTOPROGRA2_IANSMITH_ALE__MANTENIMIENTOBASE_H