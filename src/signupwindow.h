#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QRegExp>
#include <QRegExpValidator>

#include "cartao.h"
#include "usuario.h"
#include "signupprocessor.h"

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
    /** Slot de verificação do usuário e senha repetida
     * \param usuario Usuario com os dados para cadastrar.
     * \param rSenha Repetição de senha fornecida pelo usuário.
     */
    void validateData(Usuario&, QString);

    /** Slot de reação à existência do usuário no banco de dados.
     */
    void existingUser();

    /** Slot de reação à falha de cadastro
     */
    void failedToRegister();

    /** Slot de reação ao clique no botão de cadastro.
     */
    void on_pushButton_clicked();

    /** Slot para ajuste de estilo do input do cartão após falha na validação
     * @param arg1 Texto do input
     */
    void on_cardEdit_textEdited(const QString &arg1);

    /** Slot para ajuste de estilo do input do cpf após falha na validação
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


  private:
    Ui::SignupWindow *ui; //!< Atributo de instância "ui". Representa a interface gráfica da tela de cadastro.
    QLineEdit* cardEdit; //!< Atributo de instância "cardEdit". Representa o input do numero do cartão.
    QLineEdit* cpfEdit; //!< Atributo de instância "cpfEdit". Representa o input do cpf.
    QLineEdit* senhaEdit; //!< Atributo de instância "senhaEdit". Representa o input da senha.
    QLineEdit* rSenhaEdit; //!< Atributo de instância "rSenhaEdit". Representa o input da repetição da senha.
    QLineEdit* numSecEdit; //!< Atributo de instância "numSecEdit". Representa o input do numero de segurança do cartão.
    SignupProcessor* processor; //!< Atributo de instância "processor". Representa a instância da classe de processamento de cadastro.
};

#endif // SIGNUPWINDOW_H
