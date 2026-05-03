

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__ERRORGENERAL_HPP
#define PROYECTOPROGRA2_IANSMITH_ALE__ERRORGENERAL_HPP

#include "ProyectException.hpp"

class ErrorGeneral : public ProyectException {
    public:
    ErrorGeneral(const std::string& d_): ProyectException(d_) {}
};

#endif //PROYECTOPROGRA2_IANSMITH_ALE__ERRORGENERAL_HPP