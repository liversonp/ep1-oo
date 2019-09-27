#include <iostream>
#include <string>
#include <set>
#include <tuple>
#include "associado.hpp"

using namespace std;

Associado::Associado(){
	set_nome("");
	set_idade(0);
	set_cpf("");
}

Associado::Associado(string nome, int idade, string cpf){
	set_nome(nome);
	set_idade(idade);
	set_cpf(cpf);
}

Associado::~Associado(){}

float Associado::calculo_pagamento(int valor_a_pagar){
	return (float) ((85*valor_a_pagar)/100)/100;
}