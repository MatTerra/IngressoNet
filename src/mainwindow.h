#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginwindow.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT


  public:
    /** Construtor padrão */
    explicit MainWindow(QWidget *parent = nullptr);

    /** Destrutor padrão */
    ~MainWindow();


  private:
    Ui::MainWindow *ui; //!< Atributo de instância "ui". Representa a interface gráfica da tela.
};

#endif // MAINWINDOW_H
