//
// Created by ian20 on 5/1/2026.
//

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__COMPUTADORALAB_H
#define PROYECTOPROGRA2_IANSMITH_ALE__COMPUTADORALAB_H
#include "Equipo.h"

class ComputadoraLab : public Equipo {
    public:
    ComputadoraLab(const std::string &codigoEqui, int criticidadEqui, int estadoEqui);

    std::string getTipoEquipo()const override;
    void degradar() override;

    void limpiarCompu();
};


#endif //PROYECTOPROGRA2_IANSMITH_ALE__COMPUTADORALAB_H