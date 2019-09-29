#ifndef PARTIDA_H
#define PARTIDA_H

#include "jogo.h"
#include "cidade.h"
#include "usuario.h"
#include <time.h>


class Partida{

  public:
    /** Construtor padrão */
    Partida(Cidade& cidade, float preco, int disponibilidade, Usuario& responsavel, time_t data, Jogo jogo):
    cidade(cidade), preco(preco), disponibilidade(disponibilidade), responsavel(responsavel), data(data), jogo(jogo){}

    /** Vende um ingresso da partida a um usuário.
     * \param usuario Usuario que esta comprando ingresso
     * \return Verdadeiro(true) se a operação de venda foi concluída com sucesso e falso(false) caso contrário
     */
    bool venderIngresso(Usuario& usuario);

    /** Método de acesso a codigo.
    * \return O valor atual de codigo
    */
    int getCodigo() const { return codigo; }

    /** Método de alteração de codigo.
    * \param codigo Novo valor de codigo
    */
    void setCodigo(int codigo) { this->codigo = codigo; }

    /** Método de acesso a preco.
    * \return O valor atual de preco
    */
    float getPreco() const { return preco; }

    /** Método de alteração de preco.
    * \param preco Novo valor de preco
    */
    void setPreco(float preco) { this->preco = preco; }

    /** Método de acesso a disponibilidade.
    * \return O valor atual de disponibilidade
    */
    int getDisponibilidade() const { return disponibilidade; }

    /** Método de alteração de disponibilidade.
    * \param disponibilidade Novo valor de disponibilidade
    */
    void setDisponibilidade(int disponibilidade) { this->disponibilidade = disponibilidade; }

    /** Método de acesso a cidade.
     * \return O valor atual de cidade
     */
    Cidade getCidade(){ return cidade; }

    /** Método de alteração de cidade.
     * \param cidade Novo valor de cidade
     */
    void setCidade(Cidade cidade){ this->cidade = cidade; }

    /** Método de acesso a responsavel.
     * \return O valor atual de responsavel
     */
    Usuario getResponsavel() { return responsavel; }

    /** Método de alteração de responsavel
     * \param responsavel Novo valor do responsável pela partida (responsavel)
     */
    void setResponsavel(Usuario responsavel) { this->responsavel = responsavel; }

    /** Método de acesso a data
     * \return O valor atual de data
     */
    time_t getData(){ return data; }

    /** Método de alteração de data
     * \param data Novo valor de data
     */
    void setData(time_t data) { this->data = data; }

    /** Método de acesso a jogo
     * \return Valor atual de jogo
     */
    Jogo getJogo() { return jogo; }

    /** Método de alteração de jogo
     * \param jogo Novo valor de jogo
     */
    void setJogo(Jogo jogo) { this->jogo = jogo; }


  private:
    int codigo; //!< Atributo de instância "codigo". Representa o codigo da partida
    Cidade cidade; //!< Atributo de instância "cidade". Representa a cidade da partida
    float preco; //!< Atributo de instância "preco". Representa o preco da partida
    int disponibilidade; //!< Atributo de instância "disponibilidade". Representa a disponibilidade de ingressos da partida
    Usuario responsavel; //!< Atributo de instância "responsavel". Representa o Usuário responsável pela partida
    time_t data; //!< Atributo de instância "data". Representa a data de realização da partida
    Jogo jogo; //!< Atributo de instância "jogo". Representa o jogo desta partida
};

#endif
