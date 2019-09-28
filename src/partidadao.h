#ifndef PARTIDADAO_H
#define PARTIDADAO_H

#include "genericdao.h"
#include "partida.h"
#include "mysqlhelper.h"


class PartidaDAO : public GenericDAO<Partida>{

  public:
    /** Default destructor */
    virtual ~PartidaDAO();

    /** Busca um registro da classe Partida no banco de dados MySQL.
     *  \param codigo Código da Partida a buscar
     *  \return Partida encontrado com o codigo ou Partida com código 0 caso não seja encontrado nenhum registro
     */
    Partida get(std::string) override;

    /** Busca todos os registros de Partidas no banco de dados MySQL.
     * \return Vetor de Partidas do banco de dados MySQL
     */
    std::vector<Partida> getAll() override;

    /** Salva a instância de Partida no banco de dados MySQL.
     * \param partida Instância a ser salva no banco de dados MySQL
     */
    void save(Partida) override;

    /** Atualiza a instância de Partida no banco de dados MySQL de acordo com o campo e valor fornecidos.
     * \param partida Instância a ser atualizada no banco de dados MySQL
     * \param field Campo a ser atualizado no banco de dados MySQL
     * \param value Novo valor do campo a ser atualizado no banco de dados MySQL
     */
    void update(Partida, std::string, std::string) override;

    /** Remove a instância de Partida do banco de dados MySQL.
     * \param partida Instância a ser removida do banco de dados MySQL
     */
    void remove(Partida) override;

    /** Retorna a instância da classe PartidaDAO(Singleton) ou, caso necessário, cria a instância.
     *  \return Instância válida atual
     */
    static PartidaDAO* getInstance();


  private:
    static PartidaDAO* instance; //!< Atributo de classe "instance". Representa a instância da classe.
    static MySQLHelper* mysqlHelper; //!< Atributo de classe "mysqlHelper". Representa o executor de operações no banco de dados MySQL.
};

#endif // PARTIDADAO_H
