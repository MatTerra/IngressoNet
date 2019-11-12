#ifndef USUARIO_H
#define USUARIO_H

#include "cartao.h"
#include <string>


class Usuario{

  public:
    /** Construtor padrão */
    Usuario(std::string cpf, std::string senha, Cartao& cartao): cpf(cpf), senha(senha), cartao(cartao){};

    /** Destrutor padrão */
    virtual ~Usuario();

    /** Método de acesso a cpf.
    * \return O valor atual de cpf
    */
    std::string getCPF() const { return cpf; }

    /** Método de acesso a senha.
    * \return O valor atual de senha
    */
    std::string getSenha() const { return senha; }

    /** Método de alteração de senha.
    * \param senha Novo valor de senha
    */
    void setSenha(std::string senha) { this->senha = senha; }

    /** Método de acesso a cartao.
    * \return A instância atual de cartao
    */
    Cartao getCartao() const { return cartao; }

    /** Método de alteração de cartao.
    * \param cartao Nova instância de cartao
    */
    void setCartao(Cartao& cartao){this->cartao = cartao;}

    /** Verifica se o cpf é válido.
    * \param cpf Número a ser validado
    * \return Verdadeiro(true) se o cpf é válido e falso(false) caso contrário.
    */
    static bool isValidCPF(std::string);

    /** Remove '.' e '-' do CPF retornando apenas os números.
    * \param cpf CPF a ser higienizado
    * \return CPF apenas com os números
    */
    static std::string getCPFNumbers(std::string);

    /** Compara dois usuários para determinar a igualdade
     * \return Verdadeiro(true) se os usuários são iguais e falso(false) caso contrário.
     */
    bool compararUsuarios(Usuario, Usuario);


  private:
    std::string cpf; //!< Atributo de instância "cpf". Representa o cpf do Usuário
    std::string senha; //!< Atributo de instância "senha". Representa a senha do Usuário
    Cartao cartao; //!< Atributo de instância "cartao". Representa a instância do cartão do Usuário
};

#endif // USUARIO_H
