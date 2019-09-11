#ifndef CARTAO_H
#define CARTAO_H

#include "QString"


class Cartao
{
    public:
        /** Default constructor */
        Cartao(unsigned long long, unsigned int);

        /** Default destructor */
        virtual ~Cartao();

        /** Access _Numero
         * \return The current value of _Numero
         */
        unsigned long long getNumero() const { return numero; }

        /** Set _Numero
         * \param val New value to set
         */
        void setNumero(unsigned long long val) { numero = val; }

        /** Access _NumSeguranca
         * \return The current value of _NumSeguranca
         */
        unsigned int getNumSeguranca() const { return numSeguranca; }

        /** Set _NumSeguranca
         * \param val New value to set
         */
        void setNumSeguranca(unsigned int val) { numSeguranca = val; }

        /** Check if card number is valid
         * \param number Card number to check
         * \return true if valid number, false otherwise
         */
        static bool isValidNumber(unsigned long long);

        /** Charge card for value
         * \param valor Value to charge
         * \param numSeguranca Security number received to check
         * \return true if charged sucessfully, false otherwise
         */
        bool cobrar(float, unsigned int);



    private:
        unsigned long long numero; //!< Member variable "_Numero"
        unsigned int numSeguranca; //!< Member variable "_NumSeguranca"

};

#endif // CARTAO_H
