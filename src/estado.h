#ifndef ESTADO_H
#define ESTADO_H

#include <string>


class Estado{
  public:
    /** Construtor Padrão */
    Estado(int id, std::string sigla):id(id), sigla(sigla){}

    /** Método de acesso a id
     * \return Valor atual de id
     */
    int getId(){return this->id;}

    /** Método de alteração de id
     * \param id Novo valor de id
     */
    void setId(int id){this->id=id;}

    /** Método de acesso a sigla
     * \return Valor atual de sigla
     */
    std::string getSigla(){return this->sigla;}

    /** Método de alteração de sigla
     * \param sigla Novo valor de sigla
     */
    void setSigla(std::string sigla){this->sigla=sigla;}


  private:
    int id; //!< Atributo de instância "id". Representa o id do estado.
    std::string sigla; //!< Atributo de instância "sigla". Representa a sigla do estado.
};

#endif // ESTADO_H
