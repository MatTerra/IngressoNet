#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QRegExp>
#include <QRegExpValidator>
#include <QMessageBox>
#include <QMainWindow>

#include "cartao.h"
#include "usuario.h"
#include "signupprocessor.h"
#include "loginwindow.h"

namespace Ui {
  class SignupWindow;
}

class SignupWindow : public QWidget
{
  Q_OBJECT


  public:
    /** Construtor padrão */
    explicit SignupWindow(QWidget *parent = nullptr);

    /** Destrutor padrão */
    ~SignupWindow();


  signals:
    /** Sinal emitido após solicitação de cadastro para solicitar validadação dos dados de entrada.
     * \param usuario Usuario com os dados para cadastrar.
     * \param rSenha Repetição de senha fornecida pelo usuário.
     */
    void validationNeeded(Usuario&, QString);

    /** Sinal emitido após verificação positiva dos dados de cadastro.
     * \param usuario Usuario com os dados validados
     */
    void validSignupData(Usuario&);


  private slots:
    /** Slot de verificação do usuário e senha repetida.
     * \param usuario Usuario com os dados para cadastrar
     * \param rSenha Repetição de senha fornecida pelo usuário
     */
    void validateData(Usuario&, QString);

    /** Slot de reação à falha de cadastro. Mostra um diálogo com a mensagem de erro.
     */
    void onSignupError(QString);

    /** Slot de finalização de cadastro
     */
    void signupEnded();

    /** Slot de reação ao clique no botão de cadastro.
     */
    void on_signupBtn_clicked();

    /** Slot para ajuste de estilo do input do cartão após falha na validação
     * @param arg1 Texto do input
     */
    void on_cardEdit_textEdited(const QString &arg1);

    /** Slot para ajuste de estilo do input do cpf após falha na validação e inserção automática de '.' e '-'
     * @param arg1 Texto do input
     */
    void on_cpfEdit_textEdited(const QString &arg1);

    /** Slot para ajuste de estilo do input de repetição de senha após falha na validação
     * @param arg1 Texto do input
     */
    void on_rSenhaEdit_textEdited(const QString &arg1);

    /** Slot para ajuste de estilo do input de senha após falha na validação
     * @param arg1 Texto do input
     */
    void on_senhaEdit_textEdited(const QString &arg1);

    /** Slot para ajuste de estilo do input do número de segurança após falha na validação
     * @param arg1 Texto do input
     */
    void on_numSecEdit_textEdited(const QString &arg1);


    void on_voltarBtn_clicked();

private:
    Ui::SignupWindow *ui; //!< Atributo de instância "ui". Representa a interface gráfica da tela de cadastro.
    SignupProcessor* processor; //!< Atributo de instância "processor". Representa a instância da classe de processamento de cadastro.

    /** Função de configuração dos pré-validadores dos dados de entrada.
     */
    void setupValidators();

    /** Conecta os Sinais e Slots necessários.
     */
    void connectSignals();

    /** Mostra a mensagem de erro em vermelho no lEdit.
     * \param lEdit QLineEdit em que deve ser mostrada a mensagem de erro.
     * \param message Mensagem que deve ser mostrada
     */
    void setErrorMessage(QLineEdit*, QString);

    /** Executa a pré-validação dos campos de entrada e ajusta o estilo conforme necessário.
     * \param lEdit QLineEdit alvo da validação
     * \param placeholder Texto placeholder a ser definido no input alvo
     */
    void validate(QLineEdit*, QString);

    void displayErrorMessage(){

    }
};

#endif // SIGNUPWINDOW_H
