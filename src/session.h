#ifndef SESSION_H
#define SESSION_H

#include "usuario.h"
#include <QObject>

class Session : public QObject{
  Q_OBJECT
  private slots:
  bool authenticate(QString, QString){return true;}
  private:
    /** Construtor privado para garantir a arquitetura Singleton da classe
     */
    Session(Usuario u): usuario(u){}

    static Session* instance; //!< Atributo de classe "instance". Representa a instância da classe.

    Usuario usuario; //!< Atributo de instância "usuario". Representa o usuário da sessão.
};

#endif // SESSION_H
