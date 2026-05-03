

#ifndef PROYECTOPROGRA2_IANSMITH_ALE__ARCHIVOINVALIDO_HPP
#define PROYECTOPROGRA2_IANSMITH_ALE__ARCHIVOINVALIDO_HPP

#include "ProyectException.hpp"


class ArchivoInvalido : public ProyectException {
  public:

  ArchivoInvalido(const std::string& d_): ProyectException(d_) {}


};

#endif //PROYECTOPROGRA2_IANSMITH_ALE__ARCHIVOINVALIDO_HPP