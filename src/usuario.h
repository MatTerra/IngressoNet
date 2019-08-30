#ifndef USUARIO_H
#define USUARIO_H

#include "cartao.h"
#include <string>


class Usuario
{
    public:
        /** Default constructor */
        Usuario(std::string cpf, std::string senha, Cartao& cartao): _CPF(cpf), _Senha(senha), _Cartao(cartao){};
        /** Default destructor */
        virtual ~Usuario();

        /** Access CPF
         * \return The current value of CPF
         */
        std::string GetCPF() const { return _CPF; }
        /** Set CPF
         * \param val New value to set
         */
        void SetCPF(std::string val) { _CPF = val; }
        /** Access senha
         * \return The current value of senha
         */
        std::string Getsenha() const { return _Senha; }
        /** Set senha
         * \param val New value to set
         */
        void Setsenha(std::string val) { _Senha = val; }
        /** Access cartao
         * \return The current value of cartao
         */
        Cartao Getcartao() const { return _Cartao; }

    protected:

    private:
        std::string _CPF; //!< Member variable "CPF"
        std::string _Senha; //!< Member variable "senha"
        Cartao _Cartao; //!< Member variable "cartao"
};

#endif // USUARIO_H
