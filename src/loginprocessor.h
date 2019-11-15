#ifndef LOGINPROCESSOR_H
#define LOGINPROCESSOR_H

#include <QObject>

#include "usuariodao.h"
#include "cartaodao.h"
#include "usuario.h"
#include "cartao.h"

class LoginProcessor : public QObject
{
  Q_OBJECT


  public:
    /** Construtor Padrão */
    explicit LoginProcessor(QObject *parent = nullptr);


  signals:


  public slots:

};

#endif // LOGINPROCESSOR_H
