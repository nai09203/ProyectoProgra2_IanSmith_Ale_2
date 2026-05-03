
#ifndef PROYECTOPROGRA2_IANSMITH_ALE__PROYECTEXCEPTION_HPP
#define PROYECTOPROGRA2_IANSMITH_ALE__PROYECTEXCEPTION_HPP
#include <stdexcept>
#include <string>


class ProyectException : public std::runtime_error {
public:

   ProyectException(const std::string &msg_): runtime_error(msg_){}

};

#endif //PROYECTOPROGRA2_IANSMITH_ALE__PROYECTEXCEPTION_HPP