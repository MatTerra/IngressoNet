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
    /** Construtor padrão */
    explicit LoginWindow(QWidget *parent = nullptr);

    /** Destrutor padrão */
    ~LoginWindow();


  private slots:
    /** Slot de reação ao clique no botão de cadastro.
     */
    void on_signupButton_clicked();


  private:
    Ui::LoginWindow *ui; //!< Atributo de instância "ui". Representa a interface gráfica da tela de login.
};

#endif // LOGINWINDOW_H
