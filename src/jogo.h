#ifndef JOGO_H
#define JOGO_H
#include <string>

class Jogo
{
public:
    /**default constructor*/
    Jogo();
    /**default destructor*/
    virtual~Jogo();
    /**validations**/

    Jogo getDados(int datai, int dataf, std::string estado, std::string cidade);
    /**Access data base
        * \return Games found
        * \param Dates received
        * \param estado
        * \param cidade

    **/

private:
    int codigo;
    std::string nome_do_jogo;
    tipo Tipo;

};

#endif // JOGO_H
