#ifndef PERSISTANCEHELPER_H
#define PERSISTANCEHELPER_H

#include <string>

template <typename T>
class PersistanceHelper{
public:
  virtual T* query(std::string){return nullptr;}
  virtual void connect(){}
};

#endif // PERSISTANCEHELPER_H
