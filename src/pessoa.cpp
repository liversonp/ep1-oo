#include <iostream>
#include <string>

#include "pessoa.hpp"

using namespace std;

Pessoa::Pessoa(){
	set_nome("");
	set_idade(0);
	set_cpf("");
}

Pessoa::~Pessoa(){}

void Pessoa::set_nome(string nome){
	this->nome = nome;
}

string Pessoa::get_nome(){
	return nome;
}

void Pessoa::set_idade(int idade){
	this->idade = idade;
}

int Pessoa::get_idade(){
	return idade;
}

void Pessoa::set_cpf(string cpf){
	this->cpf = cpf;
}

string Pessoa::get_cpf(){
	return cpf;
}