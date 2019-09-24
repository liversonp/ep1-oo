#include <iostream>
#include <fstream>
#include <vector>
#include "funcionario.hpp"
#include "produto.hpp"

#ifdef __WIN32
	#define CLEAR  "cls"
#else
	#define CLEAR  "clear"

#endif

using namespace std;

void menu_funcionario(vector <Funcionario*>& funcionarios_cadastrados);
void loja(vector <Produto*>& produtos_da_padaria);
void modo_estoque(vector <Produto*>& produtos_da_padaria);


int main(){
	vector <Funcionario*> funcionarios;
	vector <Produto*> produtos;
	menu_funcionario(funcionarios);
	loja(produtos);
}

// criando o login do funcionario para poder utilizar a plataforma
void menu_funcionario(vector <Funcionario*>& funcionarios_cadastrados){
	string nome,cpf,email,funcao, senha;
	int idade, escolha;
	char continuar;
	bool menu_funcionario = true,usuario_correto = false;
	Funcionario *funcionario_da_padaria;
	while(menu_funcionario){
		system(CLEAR);
		cout << "1 - Entrar no sistema" << endl;
		cout << "2 - Registrar um funcionario" << endl;
		cout << "->> ";
		cin >> escolha;

		if(escolha >= 1 && escolha <= 2){
			switch(escolha){
				case 1:
					cout << "Digite o funcionário que irá utilizar a plataforma: ";
					cin >> nome;

					cout << "Digite a respectiva senha de usuário: ";
					cin >> senha;

					if(!funcionarios_cadastrados.empty()){
						for(Funcionario *buscador : funcionarios_cadastrados){
							if(nome == buscador->get_nome() && senha == buscador->get_senha()){
								usuario_correto = true;
							}
						}
					}
					if(usuario_correto == true)
						menu_funcionario = false;
					break;

				case 2:
					cout<< "Digite o nome do funcionário: ";
					cin >> nome;

					cout<< "Digite a idade do funcionário: ";
					cin >> idade;

					cout << "Digite o CPF do funcionário: ";
					cin >> cpf;

					cout << "Digite o Email do funcionário: ";
					cin >> email;

					cout << "Digite a função do funcionário: ";
					cin >> funcao;

					cout << "Digite a senha do funcionário(4-16 caracteres sem espaços): ";
					cin >> senha;

					cout << "Funcionario registrado com sucesso!!" << endl;
					cout << "\nDigite qualquer tecla para continuar..." << endl;
					cin >> continuar;

					funcionario_da_padaria = new Funcionario(nome,idade,cpf,email,funcao,senha);
					funcionarios_cadastrados.push_back(funcionario_da_padaria);
					//delete funcionario_da_padaria;
					break;
			}
		}
	}
}

void loja(vector <Produto*>& produtos_da_padaria){
	bool continua = true;
	int escolha;
	char pause;

	while(continua){
		system(CLEAR);
		cout << "     Bem vindos à minha loja" << endl;
		cout << "Digite o modo que deseja utilizar:" << endl;
		cout << "1 - Modo venda" << endl;
		cout << "2 - Modo estoque" << endl;
		cout << "3 - Modo recomendação" << endl;
		cout << "0 - Sair da loja" << endl;
		cout << "->> ";
		cin >> escolha;

		if (escolha >=0 && escolha <=3){
			switch(escolha){
				case 1:
					system(CLEAR);
					cout << "Modo venda" << endl;
					cout << "\nDigite qualquer tecla para poder continuar..." << endl;
					cin >> pause;
					break;

				case 2:
					system(CLEAR);
					//cout << "Modo estoque" << endl;
					modo_estoque(produtos_da_padaria);
					break;
				
				case 3:
					system(CLEAR);
					cout << "Modo recomendação" << endl;
					cout << "\nDigite qualquer tecla para poder continuar..." << endl;
					cin >> pause;
					break;
			
				case 0:
					cout << "Obrigado por utilizar o programa." << endl;
					continua = false;
					break;
			}
		}
	}
}

void modo_estoque(vector <Produto*>& produtos_da_padaria){
	char pause;
	string nome,categorias;
	int escolha, quantidade, quantidade_categorias, quantidade_nova;
	bool continua = true,existe;
	Produto *produto_da_padaria;
	while(continua){
		system(CLEAR);
		cout << "Digite a opção desejada:" << endl;
		cout << "1 - Listar produtos que há na loja." << endl;
		cout << "2 - Adicionar produtos." << endl;
		cout << "0 - voltar para o menu" << endl;
		cout << "->> ";
		cin >> escolha;

		if(escolha >= 0 && escolha <= 2){
			switch(escolha){
				case 1:
					system(CLEAR);
					if(!produtos_da_padaria.empty()){
						for(Produto *buscador : produtos_da_padaria){
							cout << "-------------------------------------\n";
							cout << "Nome: ";
							cout << buscador -> get_nome() << endl;
							cout << "Quantidade: ";
							cout << buscador ->get_quantidade() << endl;
							cout << "Categorias:" << endl;
							buscador -> print_categorias();
						}
						cout << "-------------------------------------\n";
					}
					else{
						cout << "Não há produtos!!!" << endl;
					}
					cout << "\nDigite qualquer tecla para continuar..." << endl;
					cin >> pause;
					break;

				case 2:
					system(CLEAR);
					existe = false;
					produto_da_padaria = new Produto();
					cout << "Digite o nome do produto que deseja adicionar:" << endl;
					cin >> nome;
					for(Produto *buscador : produtos_da_padaria){
						if(buscador->get_nome() == nome)
							existe = true;
					}

					if(existe == false){
						produto_da_padaria->set_nome(nome);

						cout << "Digite a quantidade do produto que deseja adicionar:" << endl;
						cin >> quantidade;
						produto_da_padaria->set_quantidade(quantidade);
							
						cout << "Digite quantas categorias o produto pertence:" << endl;
						cin >> quantidade_categorias;
					
						while(quantidade_categorias--){
							cout << "Digite a categoria do produto:\n";
							cin >> categorias;
							produto_da_padaria->set_categorias(categorias);
						}

						produtos_da_padaria.push_back(produto_da_padaria);
						cout << "Produto adicionado com sucesso!!" << endl;
					}

					else{
							cout << "Produto encontrado em nosso estoque!\n";
						for(Produto *buscador : produtos_da_padaria){
							if(buscador->get_nome() == nome){
								cout << "Digite a quantidade que deseja adicionar do produto:\n";
								cin >> quantidade;
								quantidade_nova = buscador->get_quantidade()+quantidade;
								buscador->set_quantidade(quantidade_nova);
							}
						}
						cout << "Estoque do produto atualizado com sucesso!!" << endl;
					}
					cout << "\nDigite qualquer tecla para continuar..." << endl;
					cin >> pause;
					break;

				case 0:
					continua = false;
					break;
			}
		}
	}
}