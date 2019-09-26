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

    bool IsValidDatas();

    bool IsValidEstado();

    bool IsValidCidade();

private:
    int codigo;
    int tipo;
    int datai;
    int dataf;
    std::string estado;
    std::string cidade;
    std::string nome_do_jogo;

};

#endif // JOGO_H
