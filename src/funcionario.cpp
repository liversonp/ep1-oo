#include "funcionario.hpp"
#include <iostream>
#include <string>

using namespace std;

Funcionario::Funcionario(string nome, int idade, string cpf, string email, string funcao, string senha){
    set_nome(nome);
    set_idade(idade);
    set_cpf(cpf);
    set_email(email);
    set_funcao(funcao);
    set_senha(senha);
}

Funcionario::~Funcionario(){}

void Funcionario::set_email(string email){
    this->email = email;
}

string Funcionario::get_email(){
    return email;
}

void Funcionario::set_funcao(string funcao){
    this->funcao = funcao;
}

string Funcionario::get_funcao(){
    return funcao;
}

void Funcionario::set_senha(string senha){
    this->senha = senha;
}

string Funcionario::get_senha(){
    return senha;
}