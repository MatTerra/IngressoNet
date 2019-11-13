#ifndef NOTABLETOCONNECTEXCEPTION_H
#define NOTABLETOCONNECTEXCEPTION_H

#include <exception>


class NotAbleToConnectException : public std::exception{
  /** Exceção personalizada para detecção de problemas de conexão
    */


  public:
    /** Método para retorno de rastro da exceção e mensagem personalizada.
     * \return Mensagem personalizada descritiva do erro
     */
    const char * what () const noexcept {
          return "It wasn't possible to establish a connection!";
    }
};

#endif // NOTABLETOCONNECTEXCEPTION_H
