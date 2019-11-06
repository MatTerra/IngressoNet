#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QWidget>
#include <QLineEdit>

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

private slots:
  void on_pushButton_clicked();

  void on_cardEdit_textEdited(const QString &arg1);

  void on_cpfEdit_textEdited(const QString &arg1);

  void on_rSenhaEdit_textEdited(const QString &arg1);

private:
  Ui::SignupWindow *ui;
};

#endif // SIGNUPWINDOW_H
