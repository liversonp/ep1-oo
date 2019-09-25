#include <iostream>
#include <fstream>
#include <vector>
#include "funcionario.hpp"
#include "produto.hpp"
#include "cliente.hpp"

#ifdef __WIN32
	#define CLEAR  "cls"
#else
	#define CLEAR  "clear"

#endif

using namespace std;

//Catálogo de funções que são utilizadas durante o programa.
void menu_funcionario(vector <Funcionario*>& funcionarios_cadastrados);
void loja(vector <Produto*>& produtos_da_padaria, vector <Cliente*>& clientes_da_padaria);
void modo_venda(vector <Produto*>& produtos_da_padaria, vector <Cliente*>& clientes_da_padaria);
void modo_estoque(vector <Produto*>& produtos_da_padaria);
string get_string();

template <typename T1>
T1 getInput();

int main(){
	vector <Cliente*> clientes;
	vector <Funcionario*> funcionarios;
	vector <Produto*> produtos;
	menu_funcionario(funcionarios);
	loja(produtos,clientes);
}

//apenas para pegar o nome de pessoas, produtos e variaveis do tipo string
string getString(){
    string valor;
    getline(cin, valor);
    return valor;
}

// Serve para colocar as variaveis que não são do tipo string.
template <typename T1>
T1 getInput(){
    while(true){
 	   T1 valor;
 	   cin >> valor;
 	   if(cin.fail()){
 	       cin.clear();
 	       cin.ignore(32767,'\n');
 	       cout << "Entrada inválida! Insira novamente: " << endl;
 	   }
 	   else{
 	       cin.ignore(32767,'\n');
 	       return valor;
 	   }
    }
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
		cout << "---------------MENU DE FUNCIONÁRIOS---------------\n";
		cout << "Digite o número respectivo ao que deseja utilizar:\n" << endl;
		cout << "1 - Entrar no sistema" << endl;
		cout << "2 - Registrar um funcionario" << endl;
		cout << "->> ";
		escolha = getInput<int>();

		if(escolha >= 1 && escolha <= 2){
			switch(escolha){
				case 1:
					cout << "Digite o funcionário que irá utilizar a plataforma: ";
					nome = getString();

					cout << "Digite a respectiva senha de usuário: ";
					senha = getString();

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
					nome = getString();

					cout<< "Digite a idade do funcionário: ";
					idade = getInput<int>();

					cout << "Digite o CPF do funcionário: ";
					cpf = getString();

					cout << "Digite o Email do funcionário: ";
					email = getString();

					cout << "Digite a função do funcionário: ";
					funcao = getString();

					cout << "Digite a senha do funcionário(4-16 caracteres sem espaços): ";
					senha = getString();

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

void loja(vector <Produto*>& produtos_da_padaria, vector <Cliente*>& clientes_da_padaria){
	bool continua = true;
	int escolha;
	char pause;

	while(continua){
		system(CLEAR);
		//cout << "     Bem vindos à minha loja" << endl;
		cout << "---------------MENU PRINCIPAL---------------\n";
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
					modo_venda(produtos_da_padaria,clientes_da_padaria);
					cout << "\nDigite qualquer tecla para poder continuar..." << endl;
					cin >> pause;
					break;

				case 2:
					system(CLEAR);
					modo_estoque(produtos_da_padaria);
					break;
				
				case 3:
					system(CLEAR);
					cout << "Modo recomendação" << endl;
				//	modo_recomendacao();
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

void modo_venda(vector <Produto*>& produtos_da_padaria, vector <Cliente*>& clientes_da_padaria){
	cout << "ENOIS" << endl;
}

void modo_estoque(vector <Produto*>& produtos_da_padaria){
	char pause;
	string nome,categorias;
	int escolha, quantidade, quantidade_categorias, quantidade_nova;
	float preco;
	bool continua = true,existe;
	Produto *produto_da_padaria;
	while(continua){
		system(CLEAR);
		cout << "---------------MODO ESTOQUE---------------\n";
		cout << "Digite a opção desejada:" << endl;
		cout << "1 - Listar produtos que há na loja." << endl;
		cout << "2 - Adicionar produtos." << endl;
		cout << "0 - voltar para o menu" << endl;
		cout << "->> ";
		escolha = getInput<int>();

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
							cout << "Preço: ";
							cout << buscador ->get_preco() << endl;
							cout << "Categorias:" << endl;
							auto categ = buscador->get_categorias();
							for(string categories : categ){
								cout << categories << endl;
							}
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
					nome = getString();
					for(Produto *buscador : produtos_da_padaria){
						if(buscador->get_nome() == nome)
							existe = true;
					}

					if(existe == false){
						produto_da_padaria->set_nome(nome);

						cout << "Digite a quantidade do produto que deseja adicionar:" << endl;
						quantidade = getInput<int>();
						produto_da_padaria->set_quantidade(quantidade);
							
						cout << "Digite o preço do produto:" << endl;
						preco = getInput<float>();
						produto_da_padaria->set_preco(preco);

						cout << "Digite quantas categorias o produto pertence:" << endl;
						quantidade_categorias = getInput<int>();
					
						while(quantidade_categorias--){
							cout << "Digite a categoria do produto:\n";
							categorias = getString();
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