#ifndef CARTAODAO_H
#define CARTAODAO_H

#include "mysqlhelper.h"
#include "genericdao.h"
#include "cartao.h"
#include "notabletoconnectexception.h"


class CartaoDAO : public GenericDAO<Cartao>{

  public:
  /** Default destructor */
  virtual ~CartaoDAO();

  /** Busca um registro da classe Cartão no banco de dados MySQL.
   *  \param numero Número do Cartão a buscar
   *  \return Cartão encontrado com o Número ou Cartão com Número 0 caso não seja encontrado nenhum registro
   */
  Cartao get(std::string) override;

  /** Busca todos os registros de Cartões no banco de dados MySQL.
   * \return Vetor de Cartões do banco de dados MySQL
   */
  std::vector<Cartao> getAll() override;

  /** Salva a instância do Cartão no banco de dados MySQL.
   * \param Cartao Instância a ser salva no banco de dados MySQL
   */
  void save(Cartao) override;

  /** Atualiza a instância do Cartão no banco de dados MySQL de acordo com o campo e valor fornecidos.
   * \param Cartao Instância a ser atualizada no banco de dados MySQL
   * \param field Campo a ser atualizado no banco de dados MySQL
   * \param value Novo valor do campo a ser atualizado no banco de dados MySQL
   */
  void update(Cartao, std::string, std::string) override;

  /** Remove a instância do Cartão do banco de dados MySQL.
   * \param Cartao Instância a ser removida do banco de dados MySQL
   */
  void remove(Cartao) override;

  /** Retorna a instância da classe CartaoDAO(Singleton) ou, caso necessário, cria a instância.
   *  \return Instância válida atual
   */
  static CartaoDAO* getInstance();


private:

  static CartaoDAO* instance; //!< Atributo de classe "instance". Representa a instância da classe.
  static MySQLHelper* mysqlHelper; //!< Atributo de classe "mysqlHelper". Representa o executor de operações no banco de dados MySQL.
};

#endif // CARTAODAO_H
