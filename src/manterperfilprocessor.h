#ifndef MANTERPERFILPROCESSOR_H
#define MANTERPERFILPROCESSOR_H

#include <QObject>

#include "session.h"
#include "usuariodao.h"
#include "cartaodao.h"

class ManterPerfilProcessor:public QObject
{
Q_OBJECT

public:
  explicit ManterPerfilProcessor(Session* session, QObject * = nullptr):session(session){}

signals:
  void maintenanceError(QString);
  void changeOperationDone(QString);

public slots:
  void changeSenhaRequested(QString);
  void changeCardRequested(unsigned long, unsigned int);

private:
  Session* session;
};

#endif // MANTERPERFILPROCESSOR_H
