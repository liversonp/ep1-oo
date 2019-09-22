#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <iostream>
#include <string>

#include "pessoa.hpp"

using namespace std;

class Funcionario: public Pessoa{
private:
	string email;
	string funcao;
	string senha;
public:
	Funcionario();
	Funcionario(string nome, int idade, string cpf, string email, string funcao, string senha);
	~Funcionario();

	void set_email(string email);
	string get_email();

	void set_funcao(string funcao);
	string get_funcao(); 

	void set_senha(string senha);
	string get_senha(); 
};
#endif