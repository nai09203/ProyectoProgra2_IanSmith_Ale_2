#ifndef PROYECTOPROGRA2_IANSMITH_ALE__SIMULADOR_H
#define PROYECTOPROGRA2_IANSMITH_ALE__SIMULADOR_H
#include <vector>
#include <string>

class Equipo;
class Incidencia;
class GestorArchivos;

class Simulador {
private:
    std::vector<Equipo*> equipos_;
    std::vector<Incidencia*> incidencias_;
    GestorArchivos* gestorArchivos_;

    void generarIncidenciasDiarias(int dia);  // <- LÍNEA NUEVA

public:
    Simulador();
    ~Simulador();
    void cargarDatos(const std::string& rutaEquipos, const std::string& rutaIncidencias);
    void ejecutarsimulacion();
};

#endif