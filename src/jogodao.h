#ifndef JOGODAO_H
#define JOGODAO_H

#include "mysqlhelper.h"
#include "genericdao.h"
#include "jogo.h"
#include "notabletoconnectexception.h"



class JogoDAO : public GenericDAO<Jogo>{

  public:
    /** Destrutor padrão */
    virtual ~JogoDAO();

    /** Busca um registro da classe Jogo no banco de dados MySQL.
     *  \param numero Código do Jogo a buscar
     *  \return ~~~~~~ (nome e tipo?)
     */
    Jogo get(std::string) override;

    /** Busca todos os registros de Jogos no banco de dados MySQL.
     * \return Vetor de Jogos do banco de dados MySQL
     */
    std::vector<Jogo> getAll() override;

    /** Salva a instância do Jogo no banco de dados MySQL.
     * \param Jogo Instância a ser salva no banco de dados MySQL
     */
    void save(Jogo) override;

    /** Atualiza a instância do Jogo no banco de dados MySQL de acordo com o campo e valor fornecidos.
     * \param Jogo Instância a ser atualizada no banco de dados MySQL
     * \param field Campo a ser atualizado no banco de dados MySQL
     * \param value Novo valor do campo a ser atualizado no banco de dados MySQL
     */
    void update(Jogo, std::string, std::string) override;

    /** Remove a instância do Cartão do banco de dados MySQL.
     * \param Jogo Instância a ser removida do banco de dados MySQL
     */
    void remove(Jogo) override;

    /** Retorna a instância da classe JogoDAO(Singleton) ou, caso necessário, cria a instância.
     *  \return Instância válida atual
     */
    static JogoDAO* getInstance();


private:
  static JogoDAO* instance; //!< Atributo de classe "instance". Representa a instância da classe.
  static MySQLHelper* mysqlHelper; //!< Atributo de classe "mysqlHelper". Representa o executor de operações no banco de dados MySQL.
};

#endif // JOGODAO_H