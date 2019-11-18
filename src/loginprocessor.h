#ifndef LOGINPROCESSOR_H
#define LOGINPROCESSOR_H

#include <QObject>

#include "usuariodao.h"
#include "cartaodao.h"
#include "usuario.h"
#include "cartao.h"

class LoginProcessor : public QObject
{
  Q_OBJECT


  public:
    /** Construtor Padrão */
    explicit LoginProcessor(QObject *parent = nullptr);


  signals:
    /** Sinal emitido quando ocorre um erro no login do Usuário.
     * \param Descrição do erro no login
     */
    void loginError(QString);

    /** Sinal emitido ao final do processo de login quando bem sucedido.
     * \param Usuario logado
     */
    void loginSuccessful(Usuario&);

  public slots:
    /** Slot para login de Usuário
     * \param cpf CPF do usuário logando
     * \param senha Senha do usuário logando
     */
    void loginUser(QString, QString);

};

#endif // LOGINPROCESSOR_H
