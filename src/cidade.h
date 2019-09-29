#ifndef CIDADE_H
#define CIDADE_H

#include <string>


class Cidade{

  public:
    /** Construtor Padrão */
    Cidade(std::string nome, std::string estado):nome(nome), estado(estado){}

    /** Destrutor Padrão */
    virtual ~Cidade();

    /** Método de acesso a nome.
     * \return O valor atual de nome
     */
    std::string getNome() const { return nome; }

    /** Método de alteração de nome.
     * \param nome Novo nome da cidade
     */
    void setNome (std::string nome) { this->nome = nome; }

    /** Método de acesso a estado.
     * \return O valor atual de estado
     */
    std::string getEstado() const { return estado; }

    /** Método de alteração de estado.
     * \param estado O novo valor de estado
     */
    void setEstado(std::string estado) { this->estado = estado; }


  private:
    std::string nome; //!< Atributo de instância "nome". Representa o nome da cidade.
    std::string estado; //!< Atributo de instância "estado". Representa o estado da cidade.
};

#endif // CIDADE_H
