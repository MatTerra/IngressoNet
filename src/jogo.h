#ifndef JOGO_H
#define JOGO_H

class Jogo
{
public:
    /**default constructor*/
    Jogo();
    /**default destructor*/
    virtual~Jogo();
    /**validations**/
    bool IsValidCodigo();

    bool IsValidEstado();

    bool IsValidCidade();

    bool IsValidTipo();

    bool IsValidNome();

private:
    int codigo;
    int tipo;
    std::string estado;
    std::string cidade;
    std::string nome_do_jogo;

};

#endif // JOGO_H
