#ifndef INGRESSODAO_H
#define INGRESSODAO_H

#include "mysqlhelper.h"
#include "genericdao.h"
#include "ingresso.h"
#include "notabletoconnectexception.h"



class IngressoDAO : public GenericDAO<Ingresso>{

  public:
    /** Destrutor padrão */
    virtual ~IngressoDAO();

    /** Busca um registro da classe Ingresso no banco de dados MySQL.
     *  \param numero Código do Ingresso a buscar
     *  \return ~~~~~~ (partida e usuário?)
     */
    Ingresso get(std::string) override;

    /** Busca todos os registros de Ingressos no banco de dados MySQL.
     * \return Vetor de Ingressos do banco de dados MySQL
     */
    std::vector<Ingresso> getAll() override;

    /** Salva a instância do Ingresso no banco de dados MySQL.
     * \param Ingresso Instância a ser salva no banco de dados MySQL
     */
    void save(Ingresso) override;

    /** Atualiza a instância do Ingresso no banco de dados MySQL de acordo com o campo e valor fornecidos.
     * \param Ingresso Instância a ser atualizada no banco de dados MySQL
     * \param field Campo a ser atualizado no banco de dados MySQL
     * \param value Novo valor do campo a ser atualizado no banco de dados MySQL
     */
    void update(Ingresso, std::string, std::string) override;

    /** Remove a instância do Cartão do banco de dados MySQL.
     * \param Ingresso Instância a ser removida do banco de dados MySQL
     */
    void remove(Ingresso) override;

    /** Retorna a instância da classe IngressoDAO(Singleton) ou, caso necessário, cria a instância.
     *  \return Instância válida atual
     */
    static IngressoDAO* getInstance();


private:
  static IngressoDAO* instance; //!< Atributo de classe "instance". Representa a instância da classe.
  static MySQLHelper* mysqlHelper; //!< Atributo de classe "mysqlHelper". Representa o executor de operações no banco de dados MySQL.
};

#endif // INGRESSODAO_H