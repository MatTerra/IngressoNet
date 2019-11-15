#ifndef GENERICDAO_H
#define GENERICDAO_H

#include <vector>
#include <string>


template <class T>
class GenericDAO{

  public:
    /** Método abstrato para busca de um registro da classe T específico no banco de dados.
     * \param id Identificador do registro
     * \return Instância do objeto buscado
     */
    virtual T get(std::string)=0;

  /** Método para busca de todos os registros que possuem um valor específico em uma coluna
    * \param property Coluna base da busca
    * \param value Valor da coluna para filtrar os resultados
    * \return Vetor de T com todos os objetos cujo valor da coluna coincide com value
    */
   virtual std::vector<T> getByProperty(std::string, std::string)=0;

    /** Método abstrato para busca de todos os registros da classe T no banco de dados.
     * \return Vetor de T com todos os objetos do banco
     */
    virtual std::vector<T> getAll()=0;

    /** Método abstrato para salvar uma instância da classe T no banco de dados.
     * \param instance Instância de T
     */
    virtual void save(T)=0;

    /** Método abstrato para atualizar uma instância da classe T no banco de dados.
     * \param instance Instância de T
     * \param field Identificador do campo a ser atualizado
     * \param value Novo valor de field
     */
    virtual void update(T, std::string, std::string)=0;

    /** Método abstrato para remover uma instância da classe T no banco de dados.
     * \param instance Instância de T
     */
    virtual void remove(T)=0;
};

#endif // GENERICDAO_H
