#ifndef FAILEDQUERYEXCEPTION_H
#define FAILEDQUERYEXCEPTION_H

#include <exception>


class FailedQueryException : public std::exception{
  /** Exceção personalizada para detecção de problemas de execução de operação do banco
    */


  public:
    /** Método para retorno de rastro da exceção e mensagem personalizada.
     * \return Mensagem personalizada descritiva do erro
     */
    const char * what () const noexcept {
          return "The requested query couldn't be completed";
    }
};

#endif // FAILEDQUERYEXCEPTION_H
