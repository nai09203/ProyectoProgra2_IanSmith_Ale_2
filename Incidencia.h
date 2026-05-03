

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__INCIDENCIA_H
#define PROYECTOPROGRA2_IANSMITH_ALE__INCIDENCIA_H
#include <string>

class Equipo;

class Incidencia {
private:

    std::string idInci_;
    int severidadInci_;
    int diaRegistroInci_;
    bool activaInci_;
    Equipo* equipoInci_;

public:

    Incidencia(const std::string& id, int severidad, int diaRegistroInci, Equipo* equipo);

    std::string getIdInci()const;
    int getSeveridadInci()const;
    int getDiaRegistroInci()const;
    bool getActivaInci()const;
    Equipo* getEquipoInci()const;

    void cerrarInci();
};


#endif //PROYECTOPROGRA2_IANSMITH_ALE__INCIDENCIA_H