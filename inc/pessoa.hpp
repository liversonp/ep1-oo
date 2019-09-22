#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include <string>

using namespace std;

class Pessoa{
private:
	string nome;
	int idade;
	string cpf;

public:
	Pessoa();
	virtual ~Pessoa();

	void set_nome(string base);
    string get_nome();

    void set_idade(int idade);
    int get_idade();

    void set_cpf(string cpf);
    string get_cpf();
};

#endif