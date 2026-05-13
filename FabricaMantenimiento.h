#ifndef PROYECTOPROGRA2_IANSMITH_ALE__FABRICAMANTENIMIENTO_H
#define PROYECTOPROGRA2_IANSMITH_ALE__FABRICAMANTENIMIENTO_H

class Mantenimiento;
class Equipo;

class FabricaMantenimiento {
public:
    static Mantenimiento* crearMantenimiento(const Equipo* e);
};

#endif