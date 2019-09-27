#ifndef PARTIDA_H
#define PARTIDA_H
#include "jogo.h"
#include "data.h" //FAZER CLASSES
#include "cidade.h"
#include "usuario.h"

class Partida{

public:
	/** Construtor padrão */
	Partida(Cidade& cidade, float preco, int disponibilidade, Usuario& responsavel, Data data, Jogo jogo):
	cidade(cidade), preco(preco), disponibilidade(disponibilidade), responsavel(responsavel), data(data), jogo(jogo){};

	/** Vende um ingresso da partida a um usuário */
	bool venderIngresso(Usuario& responsavel);

	/** Método de acesso a codigo.
     	* \return O valor atual de codigo
    	*/
   	int getCodigo() const { return codigo; }

	/** Método de alteração de codigo.
 	* \param codigo Novo valor de codigo
 	*/
	void setCodigo(int codigo) { this->codigo = codigo; }

	/** Método de acesso a preco.
     	* \return O valor atual de preco
    	*/
   	float getPreco() const { return preco; }

	/** Método de alteração de preco.
 	* \param preco Novo valor de preco
 	*/
	void setPreco(float preco) { this->preco = preco; }

	/** Método de acesso a disponibilidade.
     	* \return O valor atual de disponibilidade
    	*/
   	int getDisponibilidade() const { return disponibilidade; }

	/** Método de alteração de disponibilidade.
 	* \param disponibilidade Novo valor de disponibilidade
 	*/
	void setDisponibilidade(int disponibilidade) { this->disponibilidade = disponibilidade; }

	
private:
	int codigo;
	Cidade cidade;
	float preco;
	int disponibilidade;
	Usuario responsavel;
	Data data;
	Jogo jogo;
};
