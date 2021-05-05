#include <stdio.h>
#include <stdlib.h>
#include "validacao.h"
#include "string.h"
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
///
//
void histDeposito(void){
	Deposito* struDpst;
	char* nom;

	nom = telaBuscaDpst();

	struDpst = pesquisaCPF(nom);

	exibir(struDpst);

	free(struDpst);

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
	scanf("%50[^\n]",dpst->nome);
	getchar();
  // validação do nome
	while (!validaNome(dpst->nome)){ 
		printf("/// Nome da pessoa Invalido !                                           \n");	
		printf("/// Nome da pessoa: ");
		scanf("%50[^\n]", dpst->nome);
		getchar();
	}

  printf("/// Informe o CPF:");
  scanf("%14[^\n]", dpst->cpf);
	getchar(); 
  //validação do cpf
  while (!validaCPF(dpst->cpf)){
		printf("/// CPF INVALIDO                                                         \n");	
    printf("/// Informe o CPF:");
    scanf("%14[^\n]", dpst->cpf);
	  getchar(); 
  }
	printf("/// Valor Depositado: ");
	scanf("%20[^\n]", dpst->valorDepositado);
	getchar();
  // validação do preço
	dpst->preco = atof(dpst->valorDepositado);
  valPre = validaPreco(&dpst->preco);
  while (!valPre){
		printf("/// Valor Depositado: ");
	  scanf("%19[^\n]", dpst->valorDepositado);
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
/// tela na qual vc escreve uma informação e elke puxa o historico pra vc
//
char* telaBuscaDpst(void){
	char* cpf;
	cpf = (char*) malloc(sizeof(char));
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
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = =       Historico deposito    = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe o cpf: ");
	scanf("%12[^\n]",cpf);
	getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return cpf;
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


Deposito* pesquisaCPF(char* nom){
	FILE* fp;
	Deposito* cpf;

	cpf = (Deposito*) malloc(sizeof(Deposito));
	fp = fopen("Depositos.dat","rb");
	if(fp == NULL){
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
	}

	while(!feof(fp)){
		fread(cpf,sizeof(Deposito),1,fp);
		if(strcmp(cpf->cpf, nom) == 0){
			fclose(fp);
			return cpf;
		}
	}

	fclose(fp);
	return NULL;
}


//
/// Função responsavel por mostrar a dela Deposito
//
void exibir(Deposito* Deposito){
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
	printf("///           = = = = = = = = Exibir Deposito = = = = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
  printf("/// Dinheiro Depositado na conta de %s                                    \n",Deposito->nome);
	printf("/// CPF: %s																																\n",Deposito->cpf);
	printf("/// Dinheiro Depositado: R$ %0.2f																					\n",Deposito->preco);
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}