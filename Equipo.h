//
// Created by ian20 on 5/1/2026.
//

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__EQUIPO_H
#define PROYECTOPROGRA2_IANSMITH_ALE__EQUIPO_H

#include <string>
#include <vector>

class Incidencia;

class Equipo {
protected:

    std::string codigoEqui_;
    int criticidadEqui_;
    int estadoEqui_;
    int tiempoInactivo_;
    std::vector<Incidencia*> incidencias_;

public:

    Equipo(const std::string& codigoEqui, int criticidadEqui, int estadoEqui);

    virtual ~Equipo() = default;
    virtual std::string getTipoEquipo() const = 0;
    virtual void degradar() = 0;

    void agregarIncidencia(Incidencia* i);
    int contarIncidenciasActivas()const;
    void cerrarIncidenciasActivas();

    void mejorarEstado(int mejoraEstado);
    void disminuirEstado(int disminuEstado);

    void aumentarTiempoInactivo();
    void reiniciarTiempoInactivo();

    const std::string& getCodigoEquipo() const;
    int getCriticidadEquipo() const;
    int getEstadoEquipo() const;
    int getTiempoInactivo() const;
};


#endif //PROYECTOPROGRA2_IANSMITH_ALE__EQUIPO_H