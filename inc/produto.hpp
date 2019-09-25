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
	float preco;
public:
	Produto();
	Produto(string nome, int quantidade);
	~Produto();
	void set_nome(string nome);
	string get_nome();
	void set_quantidade(int quantidade);
	int get_quantidade();
	void set_preco(float preco);
	float get_preco();
	void set_categorias(string categoria);
	vector <string> get_categorias();

};

#endif