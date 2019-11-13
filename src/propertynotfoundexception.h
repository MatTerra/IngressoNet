#ifndef PROPERTYNOTFOUNDEXCEPTION_H
#define PROPERTYNOTFOUNDEXCEPTION_H

#include <exception>


class PropertyNotFoundException : public std::exception{
  /** Exceção personalizada para detecção de problemas de campos do banco
    */


  public:
    /** Método para retorno de rastro da exceção e mensagem personalizada.
     * \return Mensagem personalizada descritiva do erro
     */
    const char * what () const noexcept {
          return "The requested property doesn't exists";
    }
};

#endif // PROPERTYNOTFOUNDEXCEPTION_H
