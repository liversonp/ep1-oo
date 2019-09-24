#include <iostream>
#include <string>
#include <vector>

#ifndef PRODUTO_HPP
#define PRODUTO_HPP

using namespace std;

class Produto{
private:
	vector <string> categorias;
	string nome;
	int quantidade;
public:
	Produto();
	Produto(string nome, int quantidade);
	~Produto();
	void set_nome(string nome);
	string get_nome();
	void set_quantidade(int quantidade);
	int get_quantidade();
	void set_categorias(string categoria);
	void print_categorias();

};

#endif