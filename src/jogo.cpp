#include "jogo.h"
#include <string>

Jogo::Jogo(int codigo, int tipo, std::string estado, std::string cidade, std::string nome_do_jogo)
{
    //ctor
    cin >> codigo;
    cin.cls();              //Substituir cls por clear antes da entrega

    this-> codigo = codigo;

    cin >> estado;
    cin.cls();

    this-> estado = estado;

    getline(cin, cidade);
    cin.cls();

    this-> cidade = cidade;

    cin >> tipo;
    cin.cls();

    this-> tipo = tipo;

    getline(cin, nome_do_jogo);
    cin.cls();

    this-> nome_do_jogo = nome_do_jogo;

}

Jogo::~Jogo(){
    //dtor

}

bool IsValidDatas(){

}

bool IsValidEstado(){

}

bool IsValidCidade(){

}


