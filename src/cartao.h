#ifndef CARTAO_H
#define CARTAO_H


class Cartao
{
    public:
        /** Default constructor */
        Cartao(unsigned int, unsigned int);
        /** Default destructor */
        virtual ~Cartao();

        /** Access _Numero
         * \return The current value of _Numero
         */
        unsigned int Getnumero() const { return _Numero; }
        /** Set _Numero
         * \param val New value to set
         */
        void Setnumero(unsigned int val) { _Numero = val; }
        /** Access _NumSeguranca
         * \return The current value of _NumSeguranca
         */
        unsigned int GetnumSeguranca() const { return _NumSeguranca; }
        /** Set _NumSeguranca
         * \param val New value to set
         */
        void SetnumSeguranca(unsigned int val) { _NumSeguranca = val; }

    protected:

    private:
        unsigned int _Numero; //!< Member variable "_Numero"
        unsigned int _NumSeguranca; //!< Member variable "_NumSeguranca"
    public:
        static bool _isValidNumber(int);
};

#endif // CARTAO_H
