#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacao.h"
#include "exibir.h"


//
/// Switch responsavel por escolher as opção do menu Pagamento
//
void moduloPagamento(void){
	char opcao;
	do{
		opcao = menuPagamento();
		switch(opcao)
		{
			case '1':cadastrarPagamento();
						break;

			case '2':histPagamento();
						break;
		}
	}while(opcao!='0');

}

// hisotirco pagamento
void histPagamento(void){
	Pagamento* struPag;
	char* nom;

	nom = telaBuscaPag();

	struPag = codBarra(nom);

	exibirPag(struPag);

	free(struPag);

}




//
/// tela responsavel por exibir as opções da tela pagamento
//
char menuPagamento(void){
	limpaTela();
	char opcao;
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
	  printf("///           = = = = = = = =   Menu Pagamento  = = = = = = =             ///\n");
	  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	  printf("///                                                                       ///\n");
	  printf("///           1. Cadastrar Pagamentos                                     ///\n");
	  printf("///           2. Consultar Historico de Pagamentos                        ///\n");
	  printf("///           0. Voltar ao menu anterior                                  ///\n");
	  printf("///                                                                       ///\n");
	  printf("///           Escolha a opção desejada:                                   ///\n");
	  scanf("%c", &opcao);
	  getchar();                                                         
	  printf("///                                                                       ///\n");
	  printf("///                                                                       ///\n");
	  printf("/////////////////////////////////////////////////////////////////////////////\n");
	  printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	  getchar();
	return opcao;
}

//
/// tela responsavel por ler os dados do pagamento
//
void cadastrarPagamento(void){
	Pagamento* pag;
	
	pag = telaPreencherPaga();

	gravarPagamento(pag);

	free(pag);
 }

//
/// ler os arquivos salvos para mandar pro historico
//
 Pagamento* codBarra(char* nom){
	FILE* fp;
	Pagamento* codigo;

	codigo = (Pagamento*) malloc(sizeof(Pagamento));
	fp = fopen("Pagamentos.dat","rb");
	if(fp == NULL){
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
	}

	while(!feof(fp)){
		fread(codigo,sizeof(Pagamento),1,fp);
		if(strcmp(codigo->codigoDeBarra, nom) == 0){
			fclose(fp);
			return codigo;
		}
	}

	fclose(fp);
	return NULL;
}

///// em desenvolvimento

Pagamento* telaPreencherPaga(void){
	Pagamento* paga;
  float valPre;
	int dataValida;
	paga = (Pagamento*) malloc(sizeof(Pagamento));
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
	printf("///           = = = = = = = = Cadastro do Pagamento = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
  printf("/// informe o codigo de barras da conta a ser paga: ");
	scanf("%41[^\n]", paga->codigoDeBarra);
	getchar();
  //validação do codigo de barra
	while (!validacodBarra(paga->codigoDeBarra)){
		printf("/// Codigo INVALIDO                                                     ///\n");	
    printf("/// Informe o Codigo De Barra:");
    scanf("%14[^\n]", paga->codigoDeBarra);
	  getchar(); 
  }
  
  printf("/// informe o valor da conta a ser paga:  ");
	scanf("%10[^\n]", paga->valorPagamento);
	getchar();
  // validação do pagamento
	paga->preco = atof(paga->valorPagamento);
  valPre = validaPreco(&paga->preco);
  while (!valPre){
    printf("/// Valor invalido");
		printf("/// Valor Pago: ");
	  scanf("%10[^\n]",paga->valorPagamento);
	  getchar();
	  paga->preco = atof(paga->valorPagamento);
    valPre = validaPreco(&paga->preco);
	}
  printf("/// informe a data de vencimento:                                       ///\n");
	printf("Dia:");
	scanf("%i", &paga->dia);
	getchar();
	printf("Mes:");
	scanf("%i", &paga->mes);
	getchar();
	printf("Ano:");
	scanf("%i", &paga->ano);
	getchar();
  // validação da data
	dataValida = validacao (paga->dia,paga->mes,paga->ano);
  while(!dataValida){
    printf("/// Data INVALIDA!                                                      ///\n");
    printf("/// informe a data de vencimento:                                       ///\n");
	  printf("Dia:");
	  scanf("%i", &paga->dia);
	  getchar();
	  printf("Mes:");
	  scanf("%i", &paga->mes);
	  getchar();
	  printf("Ano:");
	  scanf("%i", &paga->ano);
	  getchar();
		paga->dia = (int)paga->dia ;paga->mes=(int)paga->mes; paga->ano = (int)paga->ano;
		dataValida = validacao (paga->dia,paga->mes,paga->ano);
  }
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return paga;
}



//
/// função responsavel por salvar no arquivo
//
void gravarPagamento(Pagamento* pag){
	FILE* fp;
	fp = fopen("Pagamentos.dat","ab");
	if(fp == NULL){
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
		exit(1);
	}

	fwrite(pag, sizeof(Pagamento),1,fp);
	fclose(fp);
}

//
/// tela na qual vc escreve uma informação e elke puxa o historico pra vc
//
char* telaBuscaPag(void){
	char* codigo;
	codigo = (char*) malloc(sizeof(char));
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
	printf("///           = = = = =       Buscar Pagamento      = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe o codigo: ");
	scanf("%14[^\n]",codigo);
	getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return codigo;
}

//
/// essa tela é o proprio historico
//
void exibirPag(Pagamento* Pagamento){
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
	printf("///           = = = = = = = = Exibir Pagamento= = = = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("/// Codigo de Barras %s:                                                  \n",Pagamento->codigoDeBarra);
	printf("/// Esse pagamento Foi Realizado: %i/%i/%i                                \n",Pagamento->dia,Pagamento->mes, Pagamento->ano);
  printf("/// No valor de: R$%.2f                                                       \n",Pagamento->preco);
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

