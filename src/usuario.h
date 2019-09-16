#ifndef USUARIO_H
#define USUARIO_H

#include "cartao.h"
#include <string>


class Usuario
{
    public:
        /** Default constructor */
        Usuario(std::string cpf, std::string senha, Cartao& cartao): cpf(cpf), senha(senha), cartao(cartao){};

        /** Default destructor */
        virtual ~Usuario();

        /** Access CPF
         * \return The current value of CPF
         */
        std::string getCPF() const { return cpf; }

        /** Set CPF
         * \param val New value to set
         */
        void setCPF(std::string val) { cpf = val; }
        /** Access senha
         * \return The current value of senha
         */
        std::string getSenha() const { return senha; }
        /** Set senha
         * \param val New value to set
         */
        void setSenha(std::string val) { senha = val; }
        /** Access cartao
         * \return The current value of cartao
         */
        Cartao getCartao() const { return cartao; }

        /** Check if CPF is valid
         * \param cpf Number to test
         * \return true if cpf is valid, false otherwise
         */
        static bool isValidCPF(std::string){return true;}

    protected:

    private:
        std::string cpf; //!< Member variable "CPF"
        std::string senha; //!< Member variable "senha"
        Cartao cartao; //!< Member variable "cartao"
};

#endif // USUARIO_H
