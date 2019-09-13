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
    qDebug("\n number is %lu", number);
    int numbers[16] = {0};
    int cont=0;
    int soma = 0;
    while(number>1){
        numbers[cont] = number%10;
        number /= 10;
        cont++;
    }
    qDebug("\n%d is cont", cont);
    if(cont<14){
        return false;
    }
    else{
          for(int i = 0; i < cont; i++){
              if(i%2==0){
                  soma+=numbers[i];
              }
              else{
                  if(numbers[i]>4.5){
                      soma-=9;
                  }
                  soma+=numbers[i]*2;
              }
          }
    }
    return soma%10==0;
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
