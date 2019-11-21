#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QRegExp>
#include <QRegExpValidator>
#include <QMessageBox>

#include "signupwindow.h"
#include "usuario.h"
#include "loginprocessor.h"
#include "session.h"
#include "dashboardwindow.h"

namespace Ui {
  class LoginWindow;
}

class LoginWindow : public QWidget
{
  Q_OBJECT


  public:
    /** Construtor padrão */
    explicit LoginWindow(QWidget *parent = nullptr);

    /** Destrutor padrão */
    ~LoginWindow();


  signals:
    /** Sinal emitido após solicitação de login para solicitar validadação dos dados de entrada.
     * \param cpf CPF fornecido
     * \param senha Senha fornecida
     */
    void loginDataValidationNeeded(QString, QString);

    /** Sinal emitido após verificação positiva dos dados de login.
     * \param cpf CPF validado
     * \param senha Senha validada
     */
    void validData(QString, QString);


  private slots:
    /** Slot de reação ao clique no botão de cadastro.
     */
    void on_signupBtn_clicked();

    /** Slot de reação ao clique no botão de login.
     */
    void on_loginBtn_clicked();

    /** Slot de verificação do usuário e senha.
     * \param cpf CPF fornecido
     * \param senha Senha fornecida
     */
    void validateData(QString, QString);

    /** Slot para inserção automática de '.' e '-' e ajuste do errorLabel
     * \param arg1 Texto do input
     */
    void on_cpfEdit_textEdited(const QString &arg1);

    /** Slot para ajuste do errorLabel
     * \param arg1
     */
    void on_senhaEdit_textEdited(const QString &arg1);

    /** Slot para reação ao erro de login
     * \param message Mensagem descritiva do erro
     */
    void onLoginError(QString);

    /** Slot para finalização de login.
     */
    void finishLogin(Usuario&);

  private:
    Ui::LoginWindow *ui; //!< Atributo de instância "ui". Representa a interface gráfica da tela de login.
    LoginProcessor* processor; //!< Atributo de instância "processor". Representa a instância da classe de processamento de login.
    Session* session; //!< Atributo de instância "session". Representa a sessão de usuário.

    /** Função de configuração dos pré-validadores dos dados de entrada.
     */
    void setupValidators();

    /** Conecta os Sinais e Slots necessários.
     */
    void connectSignals();

    /** Verifica se cpf e senha estão preenchidos e ativa ou desativa o botão de login
     * \param cpfLen Comprimento do cpf inserido
     * \param senhaLen Comprimento da senha inserida
     */
    void controlButtonEnablement(int, int);
};

#endif // LOGINWINDOW_H
