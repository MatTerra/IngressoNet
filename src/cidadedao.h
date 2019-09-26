#ifndef CIDADEDAO_H
#define CIDADEDAO_H

#include "cidade.h"
#include "genericdao.h"
#include "mysqlhelper.h"
#include "notabletoconnectexception.h"


class CidadeDAO : public GenericDAO<Cidade>{

  public:
    /** Destrutor padrão */
    virtual ~CidadeDAO();

    /** Busca um registro da classe Cidade no banco de dados MySQL.
     *  \param nomeEstado Nome e estado da Cidade a buscar no formato nome-estado
     *  \return Cidade encontrado com o nome ou Cidade com nome "" caso não seja encontrado nenhum registro
     */
    Cidade get(std::string) override;

    /** Busca todos os registros de Cidades no banco de dados MySQL.
     * \return Vetor de Cidades do banco de dados MySQL
     */
    std::vector<Cidade> getAll() override;

    /** Salva a instância da Cidade no banco de dados MySQL.
     * \param Cidade Instância a ser salva no banco de dados MySQL
     */
    void save(Cidade) override;

    /** Atualiza a instância da Cidade no banco de dados MySQL de acordo com o campo e valor fornecidos.
     * \param Cidade Instância a ser atualizada no banco de dados MySQL
     * \param field Campo a ser atualizado no banco de dados MySQL
     * \param value Novo valor do campo a ser atualizado no banco de dados MySQL
     */
    void update(Cidade, std::string, std::string) override;

    /** Remove a instância da Cidade do banco de dados MySQL.
     * \param Cidade Instância a ser removida do banco de dados MySQL
     */
    void remove(Cidade) override;

    /** Retorna a instância da classe CidadeDAO(Singleton) ou, caso necessário, cria a instância.
     *  \return Instância válida atual
     */
    static CidadeDAO* getInstance();


  private:
    static CidadeDAO* instance; //!< Atributo de classe "instance". Representa a instância da classe.
    static MySQLHelper* mysqlHelper; //!< Atributo de classe "mysqlHelper". Representa o executor de operações no banco de dados MySQL.
};

#endif // CIDADEDAO_H
