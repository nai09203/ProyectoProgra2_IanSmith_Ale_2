//
// Created by ian20 on 5/1/2026.
//

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__VALIDADORARCHIVOS_H
#define PROYECTOPROGRA2_IANSMITH_ALE__VALIDADORARCHIVOS_H
#include <string>


class ValidadorArchivos {

public:
    static void validarAperturaArchivo(bool abierto, const std::string& ruta);
    static void validarLineaNoVaciaArchivo(const std::string& linea, int numeroLinea);
    static void validarCantidadCamposArchivo(std::size_t cantidad, std::size_t esperado, int numeroLinea);
};


#endif //PROYECTOPROGRA2_IANSMITH_ALE__VALIDADORARCHIVOS_H