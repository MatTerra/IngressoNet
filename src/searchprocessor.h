#ifndef SEARCHPROCESSOR_H
#define SEARCHPROCESSOR_H

#include <QObject>

class SearchProcessor : public QObject
{
  Q_OBJECT
public:
  explicit SearchProcessor(QObject *parent = nullptr);

signals:

public slots:
  void searchGame(QString, QString, QString, QString);
};

#endif // SEARCHPROCESSOR_H
