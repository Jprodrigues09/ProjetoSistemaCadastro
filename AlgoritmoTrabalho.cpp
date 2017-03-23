#include <iostream>
#include<stdio.h>
#include<string.h>
#include <locale.h>
#include <stdlib.h>
#include <iomanip> 

using namespace std;
int opc, i, x, aux, auxc=1, auxd, aux2, procura_cod;
char decisao, cns;
int produto[100], qtd[100];
double preco[100];
	
	int funcMenu(){
		system("cls");
		cout << " SISTEMA DE CONTROLE DE ESTOQUE - EMPRESA ABC\n"
			" 1. Cadastrar produto\n"
			" 2. Consultar produto\n"
			" 3. Listar produtos\n"
			" 4. Efetuar pedido\n"
			" 9. Sair\n"
			"\nDigite a opção: ";
		cin >> opc;
	
		while (opc!=1 && opc!=2 && opc!=3 && opc!=4 && opc!=9){
		system("cls");
		cout << "\n\nOpção Invalida!\n\n";
		system("PAUSE");
	 
		funcMenu();
		}
	}
int cadastroProduto(){
	
  system("cls");

	do{
		system("cls");
		cout << "\nINCLUSAO DE NOVO CADASTRO\n";
		
		do{
			cout <<	"\nCódigo: ";
			cin >> (produto[x]);
			aux=0;
			aux2=0;
				if (produto[x] < 1000 || produto [x] > 9999){
					cout << "\nCódigo Inválido\n";
					aux = 1;
				}
	
			for (i=0; i<x; i++)	 {
				if (produto[x]==produto[i]){
					cout << "\nProduto já cadastrado\n";  
						aux2=1;
				}	   
			} 

		}while(aux==1 ||aux2==1);
								 
		do{
			aux = 0;
			cout << "\nPreço: ";
			cin >> (preco[x]);
				if(preco[x] <= 0){
					cout << "\nPreço Inválido!\n";
					aux = 1;
				}
		}while (aux==1);
	
		do{
			aux = 0;
			cout << "\nQuantidade em estoque: ";
			cin >> (qtd[x]);
				if (qtd[x] < 0){
					cout << "\nValor Inválido!\n";
					aux = 1;
			}
		}while (aux==1);
	
		cout << "\nDeseja cadastrar outro produto ( S - Sim  / N - Não )?\n";
		cin >> (decisao);
		decisao = toupper (decisao);
		x++;
		system ("cls");
	}while (decisao=='S');
}

int consultarProduto(){
	system("cls");	
	do{
		system("cls");
		cout << "\nInforme o código que deseja consultar: \n";
		cin >> (procura_cod);
			for (int cont=0; cont<=100; cont++){
 				if (procura_cod==produto[cont]){
 					cout <<"\nCódigo: "<< produto[cont] << endl;
 					cout <<"\nPreço: " << preco[cont] << endl;
 					cout <<"\nQuantidade em estoque: " << qtd[cont]; 
 					auxd=1;
 					
				}
		if(auxd==0){
			cout << "\nProduto não cadastrado! \n";
			system("PAUSE");	
		}
		}
		cout << "\n\nDeseja consultar outro produto ( S - Sim  / N - Não )?\n";
		cin >> (cns);
		cns = toupper (cns);
	}while(cns=='S');
}

int listarProdutos(){
	system("cls");
	cout << "\nListagem de produtos\n";
	for (i=0; i<=100; i++){
		if(preco[i] > 0){
 			cout << "\nCÓDIGO    PREÇO    QTDE";
 			cout << "\n"<< setw(5) << produto[i] << setw(8) << preco[i] << setw(9) << qtd[i] <<"\n\n";
 		}
	}
	system("PAUSE");
}

int main(){
	system ("color F9");
	system ("cls");
	setlocale(LC_ALL,"Portuguese");
	
	funcMenu();
	
	switch(opc){
	case 1:
		cadastroProduto();
		main();
		break;
		
	case 2:
		consultarProduto();
		main();
		break;
		
	case 3:
		listarProdutos();
		main();
		break;
	
	case 9:
		system("cls");
		cout << "\n\n                    Saindo do sistema\n\n\n\n";
		break;	
		
	}
	system("PAUSE");
	return 0;
}




