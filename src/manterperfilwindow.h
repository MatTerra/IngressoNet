#ifndef MANTERPERFILWINDOW_H
#define MANTERPERFILWINDOW_H

#include <QWidget>
#include <QMainWindow>

#include "session.h"
#include "dashboardwindow.h"
#include "manterperfilprocessor.h"

namespace Ui {
  class ManterPerfilWindow;
}

class ManterPerfilWindow : public QWidget
{
  Q_OBJECT

public:
  explicit ManterPerfilWindow(QWidget *parent = nullptr);
  ~ManterPerfilWindow();

signals:
  void changeSenhaValidationNeeded(QString, QString, QString);

  void changeSenhaValidData(QString);

  void maintenanceError(QString);

  void changeCardValid(unsigned long, unsigned int);

private slots:
  void validateChangeSenhaData(QString,QString,QString);

  void on_numCardEdit_textEdited(const QString &arg1);

  void on_voltarBtn_clicked();

  void on_numSegEdit_textEdited(const QString &arg1);

  void on_changeSenhaBtn_clicked();

  void on_oldSenhaEdit_textEdited(const QString &arg1);

  void on_senhaEdit_textEdited(const QString &arg1);

  void on_confSenhaEdit_textEdited(const QString &arg1);

  void onMaintenanceError(QString);

  void onChangeDone(QString);

  void on_salvarBtn_clicked();

private:
  Ui::ManterPerfilWindow *ui;
  Session* session;
  ManterPerfilProcessor* processor;
  void checkCardDataChanged(QString, QString);
  void checkSenhaLen();
  void connectSignals();
  void setupValidators();
  void setupLayout();
};

#endif // MANTERPERFILWINDOW_H
