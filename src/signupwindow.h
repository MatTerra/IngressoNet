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
  explicit SignupWindow(QWidget *parent = nullptr);
  ~SignupWindow();
signals:
  void validationNeeded(Usuario&, QString);
  void validSignupData(Usuario&);

private slots:
  void validateData(Usuario&, QString);

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
  SignupProcessor* processor;

};

#endif // SIGNUPWINDOW_H
