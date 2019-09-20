#include "usuario.h"

Usuario::~Usuario()
{
    //dtor
}

bool Usuario::isValidCPF(std::string cpf){
  if(cpf.length()!=14){
      return false;
  }
  cpf.erase(std::remove(cpf.begin(), cpf.end(), '.'), cpf.end());
  cpf.erase(std::remove(cpf.begin(), cpf.end(), '-'), cpf.end());
  const char* cpfNumbers = cpf.c_str();
  int soma = 0;
  for(int cont = 0; cont < 9; cont++){
    soma += (cpfNumbers[cont]-'0')*(10-cont);
  }
  int resultado = (11-(soma%11));
  if(resultado == 10 || resultado == 11){
    resultado = 0;
  }
  if(resultado != (cpfNumbers[9]-'0')){
      return false;
  }
  soma = 0;
  for(int cont = 0; cont < 10; cont++){
    soma += (cpfNumbers[cont]-'0')*(11-cont);
  }
  resultado = (11-(soma%11));
  if(resultado == 10 || resultado == 11){
    resultado = 0;
  }

  if(resultado != (cpfNumbers[10]-'0')){
      return false;
  }
  return true;
}
