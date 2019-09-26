#ifndef INGRESSO_H
#define INGRESSO_H

#include "usuario.h"
#include "partida.h"


class Ingresso{

  public:
    /** Construtor padrão */
    Ingresso(int, Partida, Usuario);


  private:
    int codigo; //!< Atributo de instância "codigo". Representa o código do ingresso.
    Partida partida; //!< Atributo de instância "Partida". Representa a partida para qual é o ingresso.
    Usuario usuario; //!< Atributo de instância "usuario". Representa o usuário dono do ingresso
};

#endif // INGRESSO_H
