#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QRegExp>
#include <QRegExpValidator>

#include "cartao.h"
#include "usuario.h"

namespace Ui {
  class SignupWindow;
}

class SignupWindow : public QWidget
{
  Q_OBJECT

public:
  explicit SignupWindow(QWidget *parent = nullptr);
  ~SignupWindow();
signals:
  void validationNeeded(Usuario&, Cartao&, QString);
  void validSignupData(Usuario&, Cartao&);

private slots:
  void validateData(Usuario&, Cartao&, QString);

//  void verifyExistingUser(Usuario&, Cartao&);

  void on_pushButton_clicked();

  void on_cardEdit_textEdited(const QString &arg1);

  void on_cpfEdit_textEdited(const QString &arg1);

  void on_rSenhaEdit_textEdited(const QString &arg1);

  void on_senhaEdit_textEdited(const QString &arg1);

  void on_numSecEdit_textEdited(const QString &arg1);

private:
  Ui::SignupWindow *ui;
  QLineEdit* cardEdit;
  QLineEdit* cpfEdit;
  QLineEdit* senhaEdit;
  QLineEdit* rSenhaEdit;
  QLineEdit* numSecEdit;

};

#endif // SIGNUPWINDOW_H
