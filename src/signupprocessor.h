#ifndef SIGNUPPROCESSOR_H
#define SIGNUPPROCESSOR_H

#include <QObject>

#include "usuario.h"
#include "cartao.h"
#include "usuariodao.h"
#include "cartaodao.h"

class SignupProcessor : public QObject
{
  Q_OBJECT
public:
  explicit SignupProcessor(QObject *parent = nullptr);

signals:
  void userDoesntExist(Usuario&);
  void userExist();
  void userRegistered();
  void registrationError();

public slots:
  void verifyExistingUser(Usuario&);
  void signupUser(Usuario&);

private:
};

#endif // SIGNUPPROCESSOR_H
