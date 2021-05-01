#include <stdio.h>
#include <stdlib.h>
#include "validacao.h"
#include "exibir.h"


//
/// Switch responsavel por escolher as opção do menu deposito
//
void moduloDeposito(){
	char opcao;
	do{
		opcao = menuDeposito();
		switch (opcao)
		{
			case '1':cadastrarDeposito();
						break;
		
			case '2':histDeposito();
						break;
		}
	}while(opcao!='0');
}


void cadastrarDeposito(void){
	Deposito* dep;
	
	dep = TelaDeposito();

	gravarDeposito(dep);

	free(dep);
}


//
/// função que mostra a dela do deposito
//
char menuDeposito(void) {
	limpaTela();
	char op;
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          = = = =           Banco Mundial             = = = =          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///                Developed by  @pedro_.guedes - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = = = = = Menu Deposito = = = = = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Cadastrar Deposito                                       ///\n");
	printf("///           2. Historico de Depositos                                   ///\n");
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\nEscolha a opcao (apenas numeros): ");
    scanf("%c", &op);
    getchar();
	return op;
}

//
/// função responsavel por pegar os dados do deposito
//
Deposito* TelaDeposito(void){
	Deposito* dpst;
	int dataValida;
	float valPre;
	dpst = (Deposito*) malloc(sizeof(Deposito));
	limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          = = = =           Banco Mundial             = = = =          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///                Developed by  @pedro_.guedes - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = = = = = Cadastro do Deposito  = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("/// Nome da Pessoa: ");
	scanf("%20[^\n]",dpst->nome);
	getchar();
    // validação do nome
	while (!validaNome(dpst->nome)){ 
		printf("/// Nome da pessoa: Invalido                                             ///\n");	
		printf("/// Nome da pessoa: ");
		scanf("%20[^\n]", dpst->nome);
		getchar();
	}

	printf("/// Informe o CPF:");
	scanf("%14[^\n]", dpst->cpf);
	getchar(); 
    //validação do cpf
    while (!validaCPF(dpst->cpf)){
		printf("/// CPF INVALIDO                                                         ///\n");	
    	printf("/// Informe o CPF:");
    	scanf("%14[^\n]", dpst->cpf);
	    getchar(); 
    }
	printf("/// Valor Depositado: ");
	scanf("%10[^\n]", dpst->valorDepositado);
	getchar();
    // validação do preço
	dpst->preco = atof(dpst->valorDepositado);
    valPre = validaPreco(&dpst->preco);
    while (!valPre){
		printf("/// Valor Depositado: ");
		scanf("%10[^\n]", dpst->valorDepositado);
		getchar();
		dpst->preco = atof(dpst->valorDepositado);
    	valPre = validaPreco(&dpst->preco);
	}
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return dpst;
}






//
/// função responsavel por salvar no arquivo
//
void gravarDeposito(Deposito* dep){
	FILE* fp;
	fp = fopen("Depositos.dat","ab");
	if(fp == NULL){
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
		exit(1);
	}

	fwrite(dep, sizeof(Deposito),1,fp);
	fclose(fp);

}

//
/// função responsavel por mostrar o historico de deposito
//
void histDeposito(void){
	Deposito* dep;
 	exibir(dep);
}
