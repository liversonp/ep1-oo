#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "funcionario.hpp"
#include "produto.hpp"
#include "cliente.hpp"
#include "associado.hpp"

#ifdef __WIN32
	#define CLEAR  "cls"
#else
	#define CLEAR  "clear"

#endif

using namespace std;

//Catálogo de funções que são utilizadas durante o programa.
string get_string();
template <typename T1>
T1 getInput();
void menu_funcionario(vector <Funcionario*>& funcionarios_cadastrados);
void loja(vector <Produto*>& produtos_da_padaria, vector <Cliente*>& clientes_da_padaria, vector <Associado*>& clientes_associados);
void modo_venda(vector <Produto*>& produtos_da_padaria, vector <Cliente*>& clientes_da_padaria, vector <Associado*>& clientes_associados);
void processo_venda(vector <Produto*>& produtos_da_padaria, Associado *cliente_associado); // processo de venda para o cliente associado.
void processo_venda(vector <Produto*>& produtos_da_padaria, Cliente *cliente_atual); // processo de venda para o cliente normal.
void modo_estoque(vector <Produto*>& produtos_da_padaria);
//void modo_recomendacao(vector <Produto*>& produtos_da_padaria, vector <Cliente*>& clientes_da_padaria);

int main(){
	vector <Cliente*> clientes;
	vector <Funcionario*> funcionarios;
	vector <Produto*> produtos;
	vector <Associado*> clientes_associados;
	menu_funcionario(funcionarios);
	loja(produtos,clientes,clientes_associados);
}

//apenas para pegar o nome de pessoas, produtos e variaveis do tipo string
string getString(){
    string entrada;
    getline(cin, entrada);
    return entrada;
}

// Serve para colocar as variaveis que não são do tipo string.
template <typename T1>
T1 getInput(){
    while(true){
 	   T1 entrada;
 	   cin >> entrada;
 	   if(cin.fail()){
 	       cin.clear();
 	       cin.ignore(32767,'\n');
 	       cout << "Entrada inválida! Insira novamente: " << endl;
 	   }
 	   else{
 	       cin.ignore(32767,'\n');
 	       return entrada;
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

void loja(vector <Produto*>& produtos_da_padaria, vector <Cliente*>& clientes_da_padaria, vector <Associado*>& clientes_associados){
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
		escolha = getInput<int>();

		if (escolha >=0 && escolha <=3){
			switch(escolha){
				case 1:
					system(CLEAR);
					modo_venda(produtos_da_padaria,clientes_da_padaria,clientes_associados);
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
//					modo_recomendacao(produtos_da_padaria,clientes_da_padaria);
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

void modo_venda(vector <Produto*>& produtos_da_padaria, vector <Cliente*>& clientes_da_padaria, vector <Associado*>& clientes_associados){
	string nome_do_cliente,cpf_do_cliente, resposta;
	int idade_do_cliente;
	bool eh_cliente=false,eh_associado=false;
	Cliente *cliente_atual;
	Associado *cliente_associado;
	cout << "---------------INFORMAÇÕES DO CLIENTE---------------" << endl;
	cout << "Digite o nome do cliente: ";
	nome_do_cliente = getString();

	for(auto buscador : clientes_da_padaria){
		if(nome_do_cliente == buscador-> get_nome()){
			cout << "Cliente já cadastrado encontrado com sucesso!" << endl;
			cliente_atual = buscador;
			eh_cliente = true;
		}
	}

	if(eh_cliente){
		for(auto buscador : clientes_associados){
			if(buscador->get_nome() == nome_do_cliente){
				cliente_associado = buscador;
				eh_associado = true;
			}
		}
	}

	if(eh_cliente == true && eh_associado == true){
		processo_venda(produtos_da_padaria, cliente_associado);
	}

	else if(eh_cliente == true && eh_associado == false){
		processo_venda(produtos_da_padaria, cliente_atual);	
	}

	else{
		cout << "Digite a idade do cliente: ";
		idade_do_cliente = getInput<int>();

		cout << "Digite o CPF do cliente: ";
		cpf_do_cliente = getString();

		cout << "Deseja ser associado?" << endl;
		cout << "Benefícios:" << endl;
		cout << "Terá 15% de desconto em qualquer produto comprado na padaria;" << endl;
		cout << "Caso compre no cartão não precisará pagar a taxa de cartão de crédito ou débito" << endl;
		resposta = getString();

		if(resposta == "sim"){
			cliente_atual = new Cliente();
			cliente_atual->set_nome(nome_do_cliente);
			cliente_atual->set_idade(idade_do_cliente);
			cliente_atual->set_cpf(cpf_do_cliente);
			clientes_da_padaria.push_back(cliente_atual);
			cliente_associado = new Associado(nome_do_cliente,idade_do_cliente,cpf_do_cliente);
			clientes_associados.push_back(cliente_associado);
			processo_venda(produtos_da_padaria,cliente_associado);
		}

		else{
			cliente_atual = new Cliente();
			cliente_atual->set_nome(nome_do_cliente);
			cliente_atual->set_idade(idade_do_cliente);
			cliente_atual->set_cpf(cpf_do_cliente);
			processo_venda(produtos_da_padaria,cliente_atual);
			clientes_da_padaria.push_back(cliente_atual);
		}
	}
}

void processo_venda(vector <Produto*>& produtos_da_padaria, Associado *cliente_associado){
	vector <string> produtos_que_impedem_compra;
	string produto_do_cliente, forma_de_pagamento;
	int quantidade,valor_final_calculo=0,valor_item;
	bool tem_produto;
	float valor_final=0;

	system(CLEAR);

	cout << "INSTRUÇÕES:" << endl;
	cout << "Aqui serão adicionados os produtos no carrinho do cliente" << endl;
	cout << "Para finalizar a lista, basta digitar fim" << endl << endl;
	while(1){
		tem_produto = false;
		cout << "Digite o produto desejado: ";
		produto_do_cliente = getString();
		if(produto_do_cliente == "fim")
			break;

		for(Produto* buscador : produtos_da_padaria){
			if(buscador->get_nome() == produto_do_cliente){
				tem_produto = true;
				cout << "Digite a quantidade do produto em questão: ";
				quantidade = getInput<int>();
				if(buscador->get_quantidade() >= quantidade){
					cliente_associado->set_produtos_carrinho(produto_do_cliente,quantidade,buscador->get_preco());
					valor_item = (buscador->get_preco()*100*quantidade);
					valor_final_calculo += valor_item;	
				}

				else if(buscador->get_quantidade() < quantidade){
					produtos_que_impedem_compra.push_back(buscador->get_nome());
				}
			}
		}

		if(tem_produto == false){
			cout << "Digite a quantidade do produto em questão: ";
				quantidade = getInput<int>();
			produtos_que_impedem_compra.push_back(produto_do_cliente);
		}
	}

	system(CLEAR);
	if(produtos_que_impedem_compra.size() == 0){
		cout << "---------------PRODUTOS NO SEU CARRINHO---------------" << endl;
		auto produtos_do_cliente = cliente_associado->get_produtos_carrinho();
		for(auto buscador : produtos_do_cliente){
			cout << "Produto: " <<get<0> (buscador) << endl; 
			cout << "Quantidade: " << get<1>(buscador) << endl;
			cout << "valor: R$" << fixed << setprecision(2) << get<2> (buscador) << endl;
			cliente_associado-> set_produtos_comprados(get<0> (buscador));
		}
		valor_final = cliente_associado->calculo_pagamento(valor_final_calculo);
		cliente_associado->set_valor_de_compras(valor_final);
		cout << "Valor a pagar: R$" << fixed << setprecision(2) << cliente_associado->get_valor_de_compras() << endl;
		for(auto buscador : produtos_do_cliente){
			cout << "Produto: " <<get<0> (buscador) << endl; 
			for(auto encontra_produto : produtos_da_padaria){
				if(get<0>(buscador) == encontra_produto->get_nome()){
					encontra_produto->set_quantidade(encontra_produto->get_quantidade()-get<1>(buscador));
				}
			}
		}
	}
	else{
		if(!cliente_associado->get_produtos_carrinho().empty()){
			cout << "Não foi possível realizar a compra devido aos seguintes produtos:" << endl;
			for(int i=0;i<(int) produtos_que_impedem_compra.size(); ++i){
				if(i == (int)produtos_que_impedem_compra.size()-1)
					cout << produtos_que_impedem_compra[i] << " ";
				else
					cout << produtos_que_impedem_compra[i] << endl;
			}
		}

		else{
			cout << "Não foi realizada compra de nenhum produto!!" << endl;
		}
	}
	cliente_associado->esvaziar_produtos_carrinho();
}

void processo_venda(vector <Produto*>& produtos_da_padaria, Cliente *cliente_atual){
	vector <string> produtos_que_impedem_compra;
	string produto_do_cliente, forma_de_pagamento;
	int quantidade,valor_final_calculo=0,valor_item;
	bool tem_produto;
	float valor_final=0;

	system(CLEAR);

	cout << "INSTRUÇÕES:" << endl;
	cout << "Aqui serão adicionados os produtos no carrinho do cliente" << endl;
	cout << "Para finalizar a lista, basta digitar fim" << endl << endl;
	while(1){
		tem_produto = false;
		cout << "Digite o produto desejado: ";
		produto_do_cliente = getString();
		if(produto_do_cliente == "fim")
			break;

		for(Produto* buscador : produtos_da_padaria){
			if(buscador->get_nome() == produto_do_cliente){
				tem_produto = true;
				cout << "Digite a quantidade do produto em questão: ";
				quantidade = getInput<int>();
				if(buscador->get_quantidade() >= quantidade){
					cliente_atual->set_produtos_carrinho(produto_do_cliente,quantidade,buscador->get_preco());
					valor_item = (buscador->get_preco()*100*quantidade);
					valor_final_calculo += valor_item;	
				}
				else if(buscador->get_quantidade() < quantidade){
					produtos_que_impedem_compra.push_back(buscador->get_nome());
					break;
				}
			}
		}
		if(tem_produto == false){
			cout << "Digite a quantidade do produto em questão: ";
			quantidade = getInput<int>();
			produtos_que_impedem_compra.push_back(produto_do_cliente);
		}
	}

	system(CLEAR);
	if(produtos_que_impedem_compra.size() == 0){
		cout << "---------------PRODUTOS NO SEU CARRINHO---------------" << endl;
		auto produtos_do_cliente = cliente_atual->get_produtos_carrinho();
		for(auto buscador : produtos_do_cliente){
			cout << "Produto: " <<get<0> (buscador) << endl; 
			cout << "Quantidade: " << get<1>(buscador) << endl;
			cout << "valor: R$" << fixed << setprecision(2) << get<2> (buscador) << endl;
			cliente_atual-> set_produtos_comprados(get<0>(buscador));
		}
		valor_final = cliente_atual->calculo_pagamento(valor_final_calculo);
		cliente_atual->set_valor_de_compras(valor_final);
		cout << "Valor a pagar: R$" << fixed << setprecision(2) << cliente_atual->get_valor_de_compras() << endl;

		for(auto buscador : produtos_do_cliente){
			cout << "Produto: " <<get<0> (buscador) << endl; 
			for(auto encontra_produto : produtos_da_padaria){
				if(get<0>(buscador) == encontra_produto->get_nome()){
					encontra_produto->set_quantidade(encontra_produto->get_quantidade()-get<1>(buscador));
				}
			}
		}
	}
	else{
		if(!cliente_atual->get_produtos_carrinho().empty()){
			cout << "Não foi possível realizar a compra devido aos seguintes produtos:" << endl;
			for(int i=0;i<(int) produtos_que_impedem_compra.size(); ++i){
				if(i == (int)produtos_que_impedem_compra.size()-1)
					cout << produtos_que_impedem_compra[i] << " ";

				else
					cout << produtos_que_impedem_compra[i] << endl;
			}
		}

		else{
			cout << "Não foi realizada compra de nenhum produto!!" << endl;
		}
	}
	cliente_atual->esvaziar_produtos_carrinho();
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
		cout << "---------------MODO ESTOQUE---------------" << endl;
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
						cout << "---------------PRODUTOS NO ESTOQUE---------------" << endl;
						for(Produto *buscador : produtos_da_padaria){
							cout << endl << "---------------------------------------------------------" << endl;
							cout << "Nome: ";
							cout << buscador -> get_nome() << endl;
							cout << "Quantidade: ";
							cout << buscador ->get_quantidade() << endl;
							cout << fixed;
							cout << "Preço: R$";
							cout << setprecision(2) <<buscador ->get_preco() << endl;
							cout << "Categorias:" << endl;
							auto categ = buscador->get_categorias();
							for(string categories : categ){
									cout << categories << " ";
							}
						}
						cout<< endl << "---------------------------------------------------------" << endl;
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

/*void modo_recomendacao(vector <Produto*>& produtos_da_padaria, vector <Cliente*>& clientes_da_padaria){
	cout << "---------------MODO ESTOQUE---------------" << endl;
}*/