#include "teste.h"

Teste::Teste(){

}

bool Teste::testeValidarCartao1(){
  return Cartao::isValidNumber(5555666677778884);
}

bool Teste::testeValidarCartao2(){
  return !(Cartao::isValidNumber(5));
}

bool Teste::testeCobrarCartao1(){
  Cartao cartao(5555666677778884, 123);
  return cartao.cobrar(70.0, 123);
}

bool Teste::testeCobrarCartao2(){
  Cartao cartao(5555666677778884, 123);
  return !(cartao.cobrar(80.0, 142));
}
