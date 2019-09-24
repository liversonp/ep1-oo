#include <iostream>
#include <string>
#include "produto.hpp"

using namespace std;

Produto::Produto(){
	set_nome("");
	set_quantidade(0);
}

Produto::Produto(string nome, int quantidade){
	set_nome(nome);
	set_quantidade(quantidade);
}

Produto::~Produto(){}

void Produto::set_nome(string nome){
	this->nome = nome;
}

string Produto::get_nome(){
	return nome;
}

void Produto::set_quantidade(int quantidade){
	this ->quantidade = quantidade;
}

int Produto::get_quantidade(){
	return quantidade;
}

void Produto::set_categorias(string categoria){
	categorias.push_back(categoria);
}

void Produto::print_categorias(){
	for(int i=0;i< (int)categorias.size();++i){
		if(i != (int)categorias.size()-1)
			cout << categorias[i] << ", ";

		else
			cout << categorias[i] << endl;
	}
}