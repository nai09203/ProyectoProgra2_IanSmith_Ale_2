//
// Created by ian20 on 4/30/2026.
//

#include "Incidencia.h"
#include "ValidadorIncidencia.h"

Incidencia::Incidencia(const std::string& id, int severidad, int diaRegistroInci, Equipo* equipo)
: idInci_(id), severidadInci_(severidad), diaRegistroInci_(diaRegistroInci), activaInci_(true),
equipoInci_(equipo) {

    ValidadorIncidencia::validarIncidencia(id, severidad, diaRegistroInci, equipo);
}

std::string Incidencia::getIdInci() const {
    return idInci_;
}
int Incidencia::getSeveridadInci() const {
    return severidadInci_;
}
int Incidencia::getDiaRegistroInci() const {
    return diaRegistroInci_;
}
bool Incidencia::getActivaInci() const {
    return activaInci_;
}
Equipo* Incidencia::getEquipoInci() const {
    return equipoInci_;
}

void Incidencia::cerrarInci(){
    activaInci_ = false;
}



