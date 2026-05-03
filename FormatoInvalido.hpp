

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__FORMATOINVALIDO_HPP
#define PROYECTOPROGRA2_IANSMITH_ALE__FORMATOINVALIDO_HPP

#include "ProyectException.hpp"

class FormatoInvalido : public ProyectException {
public:

    FormatoInvalido(const std::string& d_): ProyectException(d_){}

};
#endif //PROYECTOPROGRA2_IANSMITH_ALE__FORMATOINVALIDO_HPP