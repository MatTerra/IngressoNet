#ifndef PERSISTANCEHELPER_H
#define PERSISTANCEHELPER_H

#include <string>

template <class T>
class PersistanceHelper{
public:
  virtual T query(std::string);
  virtual void connect();
  virtual ~PersistanceHelper();
};

#endif // PERSISTANCEHELPER_H
