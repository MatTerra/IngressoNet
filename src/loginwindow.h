#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include "signupwindow.h"

namespace Ui {
  class LoginWindow;
}

class LoginWindow : public QWidget
{
  Q_OBJECT

public:
  explicit LoginWindow(QWidget *parent = nullptr);
  ~LoginWindow();

private slots:
  void on_signupButton_clicked();

private:
  Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
