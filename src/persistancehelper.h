#ifndef PERSISTANCEHELPER_H
#define PERSISTANCEHELPER_H

#include <string>

class PersistanceHelper{
public:
  virtual void query(std::string);
  virtual void connect();
  virtual ~PersistanceHelper();
};

#endif // PERSISTANCEHELPER_H
