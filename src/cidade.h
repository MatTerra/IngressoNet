#ifndef CIDADE_H
#define CIDADE_H

#include <string>

#include "estado.h"


class Cidade{

  public:
    /** Construtor Padrão */
    Cidade(std::string nome, Estado& estado): id(-1), nome(nome), estado(estado){}

    /** Construtor Com Id */
    Cidade(int id, std::string nome, Estado& estado):id(id), nome(nome), estado(estado){}

    /** Destrutor Padrão */
    ~Cidade(){}

    /** Método de acesso a nome.
     * \return O valor atual de nome
     */
    std::string getNome() const { return nome; }

    /** Método de alteração de nome.
     * \param nome Novo nome da cidade
     */
    void setNome (std::string nome) { this->nome = nome; }

    /** Método de acesso a id.
     * \return O valor atual de id
     */
    int getId() const { return id; }

    /** Método de alteração de id.
     * \param id Novo id da cidade
     */
    void setId (int id) { this->id = id; }

    /** Método de acesso a estado.
     * \return O valor atual de estado
     */
    Estado getEstado() const { return estado; }

    /** Método de alteração de estado.
     * \param estado O novo valor de estado
     */
    void setEstado(Estado& estado) { this->estado = estado; }


  private:
    int id; //!< Atributo de instância "id". Representa o id da cidade.
    std::string nome; //!< Atributo de instância "nome". Representa o nome da cidade.
    Estado estado; //!< Atributo de instância "estado". Representa o estado da cidade.
};

#endif // CIDADE_H
