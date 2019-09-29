#ifndef CARTAO_H
#define CARTAO_H

#include "QString"


class Cartao{

  public:
    /** Construtor padrão */
    Cartao(unsigned long, unsigned int);

    /** Destrutor padrão */
    virtual ~Cartao();

    /** Método de acesso a numero.
     * \return O valor atual de numero
     */
    unsigned long getNumero() const { return numero; }

    /** Método de alteração de numero.
     * \param numero Novo valor de numero
     */
    void setNumero(unsigned long numero) { this->numero = numero; }

    /** Método de acesso a numSeguranca.
     * \return O valor atual de numSeguranca
     */
    unsigned int getNumSeguranca() const { return numSeguranca; }

    /** Método de alteração de numSeguranca.
     * \param numSeguranca Novo valor de numSeguranca
     */
    void setNumSeguranca(unsigned int numSeguranca) { this->numSeguranca = numSeguranca; }

    /** Verifica se um número de cartão é válido.
     * \param number Número a verificar
     * \return Verdadeiro(true) se o número é válido, falso(false), caso contrário
     */
    static bool isValidNumber(unsigned long);

    /** Cobra um determinado valor do cartão.
     * \param valor Valor a cobrar
     * \param numSeguranca Número de segurança fornecido para a operação.
     * \return Verdadeiro(true) se a cobrança foi bem sucedida e falso(false) caso contrário.
     */
    bool cobrar(float, unsigned int);


  private:
    unsigned long numero; //!< Atributo de instância "numero". Representa o numero do cartão.
    unsigned int numSeguranca; //!< Atributo de instância "numSeguranca". Representa o código de Segurança do cartão.
};

#endif // CARTAO_H
