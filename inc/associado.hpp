#ifndef ASSOCIADO_HPP
#define ASSOCIADO_HPP
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <tuple>
#include "produto.hpp"
#include "cliente.hpp"

using namespace std;

class Associado: public Cliente{
public:
	Associado();
	Associado(string nome,int idade, string cpf);
	~Associado();
	
	float calculo_pagamento(int valor_a_pagar);
};

#endif