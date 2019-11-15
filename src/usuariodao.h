#ifndef USUARIODAO_H
#define USUARIODAO_H

#include "mysqlhelper.h"
#include "genericdao.h"
#include "usuario.h"
#include "notabletoconnectexception.h"
#include "propertynotfoundexception.h"
#include "failedqueryexception.h"
#include <mysql/mysql.h>


class UsuarioDAO : public GenericDAO<Usuario>{

  public:
    /** Default destructor */
    virtual ~UsuarioDAO();

    /** Busca um registro da classe Usuário no banco de dados MySQL.
     *  \param cpf CPF do Usuário a buscar
     *  \return Usuário encontrado com o CPF ou Usuário com CPF 000.000.000-00 caso não seja encontrado nenhum registro
     */
    Usuario get(std::string) override;

    /** Método para busca de todos os Usuários que possuem um valor específico em uma coluna
      * \param property Coluna base da busca
      * \param value Valor da coluna para filtrar os resultados
      * \return Vetor de todos os Usuários cujo valor da coluna coincide com value. Não é selecionada a senha e os usuários retornados tem senha vazia.
      */
    std::vector<Usuario> getByProperty(std::string, std::string) override;

    /** Busca todos os registros de Usuários no banco de dados MySQL.
     * \return Vetor de Usuários do banco de dados MySQL. Não é selecionada a senha e os usuários retornados tem senha vazia.
     */
    std::vector<Usuario> getAll() override;

    /** Salva a instância do Usuário no banco de dados MySQL.
     * \param usuario Instância a ser salva no banco de dados MySQL
     */
    void save(Usuario) override;

    /** Atualiza a instância do Usuário no banco de dados MySQL de acordo com o campo e valor fornecidos.
     * \param usuario Instância a ser atualizada no banco de dados MySQL
     * \param field Campo a ser atualizado no banco de dados MySQL
     * \param value Novo valor do campo a ser atualizado no banco de dados MySQL
     */
    void update(Usuario, std::string, std::string) override;

    /** Remove a instância do Usuário do banco de dados MySQL.
     * \param usuario Instância a ser removida do banco de dados MySQL
     */
    void remove(Usuario) override;

    /** Retorna a instância da classe UsuarioDAO(Singleton) ou, caso necessário, cria a instância.
     *  \return Instância válida atual
     */
    static UsuarioDAO* getInstance();


  private:
    static UsuarioDAO* instance; //!< Atributo de classe "instance". Representa a instância da classe.
    static MySQLHelper* mysqlHelper; //!< Atributo de classe "mysqlHelper". Representa o executor de operações no banco de dados MySQL.
};

#endif // USUARIODAO_H
