//
// Created by ian20 on 5/1/2026.
//

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__MICROSCOPIOLAB_H
#define PROYECTOPROGRA2_IANSMITH_ALE__MICROSCOPIOLAB_H
#include "Equipo.h"

class MicroscopioLab : public Equipo {
public:
    MicroscopioLab(const std::string& codigoEqui, int criticidadEqui, int estadoEqui);

    std::string getTipoEquipo() const override;
    void degradar() override;

    void calibrarMicroscopio();
};


#endif //PROYECTOPROGRA2_IANSMITH_ALE__MICROSCOPIOLAB_H