#ifndef PARTIDA_H
#define PARTIDA_H
#include "jogo.h"
#include "data.h" //FAZER CLASSES
#include "cidade.h"
#include "usuario.h"

class Partida{

public:
	Partida(Cidade& cidade, float preco, int disponibilidade, Usuario& responsavel, Data data, Jogo jogo):
	cidade(cidade), preco(preco), disponibilidade(disponibilidade), responsavel(responsavel), data(data), jogo(jogo){};

	bool venderIngresso(Usuario& responsavel);

	
private:
	int codigo;
	Cidade cidade;
	float preco;
	int disponibilidade;
	Usuario responsavel;
	Data data;
	Jogo jogo;
};