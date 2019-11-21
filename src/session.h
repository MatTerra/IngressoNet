#ifndef SESSION_H
#define SESSION_H

#include "usuario.h"
#include <QObject>

class Session : public QObject{
  Q_OBJECT


  public:
    ~Session();

    static Session* getInstance();

    static void setInstance(Usuario&);

    Usuario getUsuario(){return usuario;}

    void updateSenhaUsuario(QString);

    void updateCartaoUsuario(Cartao);

 signals:
    void logoutDone();

  private slots:
    /** Slot de reação à finalização de login
     * \param usuario Usuário logado
     */
    void loginDone(Usuario&);

    void logout();

  private:
    /** Construtor privado para garantir a arquitetura Singleton da classe
     */
    Session(Usuario u): usuario(u){}

    static Session* instance; //!< Atributo de classe "instance". Representa a instância da classe.

    Usuario usuario; //!< Atributo de instância "usuario". Representa o usuário da sessão.
};

#endif // SESSION_H
