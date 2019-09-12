#include "cartao.h"

Cartao::Cartao(unsigned long numero, unsigned int numSeguranca){
  //ctor
  this->numero = numero;
  this->numSeguranca = numSeguranca;
}

Cartao::~Cartao(){
    //dtor

}

bool Cartao::isValidNumber(unsigned long number){
  if(number<10000000000000){
    return false;
  } else {
    return true;
  }
}

bool Cartao::cobrar(float value, unsigned int numSeguranca){
  qDebug("Charging %f reais", static_cast<double>(value));
  if (this->numSeguranca == numSeguranca){
      qDebug("Charged successfuly");
      return true;
    }else{
      qDebug("Couldn't charge");
      return false;
    }
}
