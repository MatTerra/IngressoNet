#ifndef SIGNUPPROCESSOR_H
#define SIGNUPPROCESSOR_H

#include <QObject>

#include "usuario.h"
#include "cartao.h"
#include "usuariodao.h"
#include "cartaodao.h"

class SignupProcessor : public QObject
{
  Q_OBJECT


  public:
    /** Construtor padrão */
    explicit SignupProcessor(QObject *parent = nullptr);


  signals:
    /** Sinal emitido após verificação de existência do Usuário no banco de dados caso ele não exista.
     * \param usuario Instância de Usuário a ser verificada
     */
    void userDoesntExist(Usuario&);

    /** Sinal emitido após verificação de existência do Usuário no banco de dados caso ele exista.
     */
    void userExist();

    /** Sinal emitido após registro do Usuário no banco de dados.
     */
    void userRegistered();

    /** Sinal emitido quando ocorre um erro no registro do Usuário.
     */
    void registrationError();


  public slots:
    /** Slot de verificação de existência do Usuário no banco.
     *\param usuario Instância de Usuário a ser verificada
     *\return Emite o sinal userDoesnExist caso o usuário não exista; userExist caso o usuário exista e registrationError caso não seja possível verificar a existência.
     */
    void verifyExistingUser(Usuario&);

    /** Slot para cadastro de Usuário no banco.
     * \param usuario Usuário a ser cadastrado
     * \return Emite o sinal userRegistered em caso de sucesso ou registrationError caso contrário.
     */
    void signupUser(Usuario&);
};

#endif // SIGNUPPROCESSOR_H
