#ifndef GENERICDAO_H
#define GENERICDAO_H

#include <vector>
#include <string>

template <class T>
class GenericDAO
{
public:
  virtual T get(std::string);
  virtual std::vector<T> getAll();
  virtual void save(T);
  virtual void update(T, std::string[]);
  virtual void remove(T);
};

#endif // GENERICDAO_H
