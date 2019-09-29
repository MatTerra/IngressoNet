#ifndef JOGO_H
#define JOGO_H
#include <string>

class Jogo{

  public:
    /** Enum Tipo. Representa os tipos de jogos possíveis: Local(0), Estadual(1), Nacional(2) e Internacional(3).
     */
    enum Tipo {Local=0, Estadual=1, Nacional=2, Internacional=3};

    /** Construtor padrão */
    Jogo(int codigo, std::string nome, enum Tipo tipo) : codigo(codigo), nome(nome), tipo(tipo){}

    /** Método de alteração de codigo
     * \param codigo Novo valor de codigo
     */
    void setCodigo(int codigo){ this->codigo = codigo; }

    /** Método de acesso a codigo
     * \return Valor atual de codigo
     */
    int getCodigo(){ return codigo; }

    /** Método de alteração de nome
     * \param nome Novo valor de nome
     */
    void setNome(std::string nome){ this->nome = nome; }

    /** Método de acesso a nome
     * \return Valor atual de nome
     */
    std::string getNome() { return nome; }

    /** Método de alteração de tipo
     * \param tipo Novo valor de tipo
     */
    void setTipo(enum Tipo tipo) { this->tipo = tipo; }

    /** Método de acesso a tipo
     * \return Valor atual de tipo
     */
    enum Tipo getTipo() { return tipo; }


  private:
    int codigo; //!< Atributo de instância "codigo". Representa o código do jogo.
    std::string nome; //!< Atributo de instância "nome". Representa o nome do jogo.
    enum Tipo tipo; //!< Atributo de instância "tipo". Representa o tipo do jogo.
};

#endif // JOGO_H
