#ifndef COMPRARITEM_H
#define COMPRARITEM_H

#include "partida.h"

#include <QStandardItem>
#include <QObject>
#include <QMouseEvent>
#include <QLabel>

class ComprarItem : public QObject, public QStandardItem
{
  Q_OBJECT
public:
  explicit ComprarItem(Partida& p, QString message):QStandardItem(message), p(p){}
  Partida& getPartida(){return p;}
private:
  Partida p;
};

#endif // COMPRARITEM_H
