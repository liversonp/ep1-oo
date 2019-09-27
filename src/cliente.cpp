#include <iostream>
#include <string>
#include <set>
#include <tuple>
#include "cliente.hpp"

using namespace std;

Cliente::Cliente(){
	set_nome("");
	set_idade(0);
	set_cpf("");
	set_valor_de_compras(0.0);
}

Cliente::~Cliente(){}

void Cliente::set_valor_de_compras(float valor_de_compras){
	this->valor_de_compras = valor_de_compras;
}

float Cliente::get_valor_de_compras(){
	return valor_de_compras;
}

void Cliente::set_produtos_comprados(string produto){
	produtos_comprados.insert(produto);
}

set <string> Cliente::get_produtos_comprados(){
	return this->produtos_comprados;
}

void Cliente::set_produtos_carrinho(string produto, int quantidade, float valor){
	produtos_carrinho.push_back(make_tuple(produto,quantidade,valor));
}

vector <tuple<string,int,float>> Cliente::get_produtos_carrinho(){
	return this->produtos_carrinho;
}

void Cliente::esvaziar_produtos_carrinho(){
	while(!produtos_carrinho.empty()){
		produtos_carrinho.pop_back();
	}
}

float Cliente::calculo_pagamento(int valor_a_pagar){
	return (float) valor_a_pagar/100;
}