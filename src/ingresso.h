#ifndef INGRESSO_H
#define INGRESSO_H

#include "usuario.h"
#include "partida.h"


class Ingresso{

  public:
    /** Construtor padrão */
    Ingresso(int codigo, Partida partida, Usuario usuario) : codigo(codigo), partida(partida), usuario(usuario){};

    /** Método de acesso a codigo
     * \return Valor atual de codigo
     */
    int getCodigo(){ return codigo; }

    /** Método de alteração de codigo
     * \param codigo Novo valor de codigo
     */
    void setCodigo(int codigo){ this->codigo = codigo; }

    /** Método de acesso a partida
     * \return Valor atual de partida
     */
    Partida getPartida(){ return partida; }

    /** Método de alteração de partida
     * \param partida Novo valor de partida
     */
    void setPartida(Partida partida) { this->partida = partida; }

    /** Método de acesso a usuario
     * \return O valor atual de usuario
     */
    Usuario getUsuario() { return usuario; }

    /** Método de alteração de usuario
     * \param usuario
     */
    void setUsuario(Usuario usuario){ this->usuario = usuario; }


  private:
    int codigo; //!< Atributo de instância "codigo". Representa o código do ingresso.
    Partida partida; //!< Atributo de instância "Partida". Representa a partida para qual é o ingresso.
    Usuario usuario; //!< Atributo de instância "usuario". Representa o usuário dono do ingresso
};

#endif // INGRESSO_H
