#include "Simulador.h"
#include <iostream>

int main() {
    try {
        Simulador simulador;

        simulador.cargarDatos(
            "equipos.txt",
            "incidencias.txt"
        );

        simulador.ejecutarsimulacion();

        std::cout << "Simulacion completada correctamente.\n";
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}