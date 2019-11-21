#ifndef MANTERPERFILPROCESSOR_H
#define MANTERPERFILPROCESSOR_H

#include <QObject>

#include "session.h"
#include "usuariodao.h"

class ManterPerfilProcessor:public QObject
{
Q_OBJECT

public:
  explicit ManterPerfilProcessor(Session* session, QObject * = nullptr):session(session){}

signals:
  void maintenanceFailed(QString);

public slots:
  void changeSenhaRequested(QString);

private:
  Session* session;
};

#endif // MANTERPERFILPROCESSOR_H
