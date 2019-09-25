#ifndef NOTABLETOCONNECTEXCEPTION_H
#define NOTABLETOCONNECTEXCEPTION_H

#include <exception>

class NotAbleToConnectException : public std::exception{
public:
  const char * what () const throw () {
        return "It wasn't possible to establish a connection!";
     }
};

#endif // NOTABLETOCONNECTEXCEPTION_H
