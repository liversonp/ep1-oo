#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <tuple>
#include "produto.hpp"
#include "pessoa.hpp"

using namespace std;

class Cliente: public Pessoa{
private:
	vector <tuple<string,int,float>> produtos_carrinho;
	set <string> produtos_comprados;
	float valor_de_compras;
public:
	Cliente();
	virtual ~Cliente();

	void set_valor_de_compras(float valor_de_compras);
	float get_valor_de_compras();

	void set_produtos_comprados(string produto);
	set <string> get_produtos_comprados();

	void set_produtos_carrinho(string produto, int quantidade, float valor);
	vector <tuple<string,int,float>> get_produtos_carrinho();

	void esvaziar_produtos_carrinho();

	virtual float calculo_pagamento(int valor_a_pagar);
};

#endif