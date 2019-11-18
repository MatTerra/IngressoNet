#ifndef ESTADODAO_H
#define ESTADODAO_H

#include "estado.h"
#include "genericdao.h"
#include "mysqlhelper.h"
#include "propertynotfoundexception.h"
#include "notabletoconnectexception.h"
#include "failedqueryexception.h"

class EstadoDAO : public GenericDAO<Estado>{

public:
  /** Destrutor padrão */
  virtual ~EstadoDAO();

  /** Busca um registro da classe Estado no banco de dados MySQL.
   *  \param id ID do Estado a buscar
   *  \return Instância do Estado buscado ou Estado com id 0, caso não encontrado
   */
  Estado get(std::string) override;

  /** Método para busca de todos os registros que possuem um valor específico em uma coluna
    * \param property Coluna base da busca
    * \param value Valor da coluna para filtrar os resultados
    * \return Vetor de T com todos os objetos cujo valor da coluna coincide com value
    */
   std::vector<Estado> getByProperty(std::string, std::string) override;

  /** Busca todos os registros de Estados no banco de dados MySQL.
   * \return Vetor de Estados do banco de dados MySQL
   */
  std::vector<Estado> getAll() override;

  /** Salva a instância do Estado no banco de dados MySQL.
   * \param Estado Instância a ser salva no banco de dados MySQL
   */
  void save(Estado) override;

  /** Atualiza a instância do Estado no banco de dados MySQL de acordo com o campo e valor fornecidos.
   * \param Estado Instância a ser atualizada no banco de dados MySQL
   * \param field Campo a ser atualizado no banco de dados MySQL
   * \param value Novo valor do campo a ser atualizado no banco de dados MySQL
   */
  void update(Estado, std::string, std::string) override;

  /** Remove a instância do Estado do banco de dados MySQL.
   * \param Estado Instância a ser removida do banco de dados MySQL
   */
  void remove(Estado) override;

  /** Retorna a instância da classe EstadoDAO(Singleton) ou, caso necessário, cria a instância.
   *  \return Instância válida atual
   */
  static EstadoDAO* getInstance();


private:
  static EstadoDAO* instance; //!< Atributo de classe "instance". Representa a instância da classe.
  static MySQLHelper* mysqlHelper; //!< Atributo de classe "mysqlHelper". Representa o executor de operações no banco de dados MySQL.
};

#endif // ESTADODAO_H
