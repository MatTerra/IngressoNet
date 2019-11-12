#ifndef PERSISTANCEHELPER_H
#define PERSISTANCEHELPER_H

#include <string>


template <typename T>
class PersistanceHelper{

  public:
    /** Executa uma operação no banco de dados e retorna o resutado.
     * \param query Operação a ser executada
     * \return Resultado da operação
     */
    virtual T* query(std::string)=0;

    /** Conecta a um banco de dados remoto.
     */
    virtual void connect()=0;

    /** Encerra a conexão com um banco de dados remoto.
     */
    virtual void close()=0;
};

#endif // PERSISTANCEHELPER_H
