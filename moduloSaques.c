#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacao.h"
#include "exibir.h"

//
/// Switch responsavel por escolher as opção do menu Saques
//
void moduloSaques(){
	char opcao;
	do{
		opcao = menuSaque();
		switch (opcao)
		{
			case '1':cadastrarSaques();
						break;
		
			case '2':extratoSaques();
						break;
		}
	}while(opcao!='0');
}

//
/// tela responsavel por capturar e preencher as informação do saque
//
void cadastrarSaques(void){
	Saques* sqa;
	
	sqa = TelaSaques();

	gravarSaques(sqa);

	free(sqa);
}


// historico do saque
void extratoSaques(void){
	Saques* struSqst;
	char* nom;

	nom = telaBuscaSaq();

	struSqst = cpfExtrato(nom);

	exibirExtrato(struSqst);

	free(struSqst);

}


//
/// ler os arquivos salvos para mandar pro historico
//
 Saques* cpfExtrato(char* nom){
	FILE* fp;
	Saques* cpf;

	cpf = (Saques*) malloc(sizeof(Saques));
	fp = fopen("Saques.dat","rb");
	if(fp == NULL){
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
	}

	while(!feof(fp)){
		fread(cpf,sizeof(Pagamento),1,fp);
		if(strcmp(cpf->cpf, nom) == 0){
			fclose(fp);
			return cpf;
		}
	}

	fclose(fp);
	return NULL;
}


//
/// tela responsavel por mostrar as opção para o cliente
//
char menuSaque(void){
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
	printf("///           = = = = = = = =    Menu Saques    = = = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Realizar Saque                                           ///\n");
	printf("///           2. Extrato                                                  ///\n");
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///           Escolha a opção desejada:                                   ///\n");
	printf("///                                                                       ///\n");
	scanf("%c",&opcao);
	getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return opcao;
}


//
/// função responsavel por capturar as informações do cliente
//
Saques* TelaSaques(void){
	Saques *sqs;
	float valPre;
  sqs = (Saques*)malloc(sizeof(Saques));
	limpaTela();
	printf("\n");
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
	printf("///           = = = = =       Cadastro Saques       = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("/// Valor do saque: ");
  scanf("%20[^\n]", sqs->valor);
	getchar();
  // valdidaçõa do valor
	sqs->preco = atof(sqs->valor);
  valPre = validaPreco(&sqs->preco);
  while (!valPre){
    printf("/// Valor invalido!!");
		printf("/// Insiita um novo valor para saque: ");
	  scanf("%20[^\n]", sqs->valor);
	  getchar();
		sqs->preco = atof(sqs->valor);
    valPre = validaPreco(&sqs->preco);
	}
  printf("/// Digite o seu cpf: ");
  scanf("%20[^\n]", sqs->cpf);
	getchar();
  // validação do numero de cpf
	while (!validaCPF(sqs->cpf)){
		printf("/// CPF INVALIDO                                                         ///\n");	
    printf("/// Informe o CPF:");
    scanf("%14[^\n]", sqs->cpf);
	  getchar(); 
  }
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return sqs;
}



//
/// função responsavel por salvar no arquivo
//
void gravarSaques(Saques* saq){
	FILE* fp;
	fp = fopen("Saques.dat","ab");
	if(fp == NULL){
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
		exit(1);
	}

	fwrite(saq, sizeof(Saques),1,fp);
	fclose(fp);
}

//
/// tela na qual vc escreve uma informação e elke puxa o historico pra vc
//
char* telaBuscaSaq(void){
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
	printf("///           = = = = =           Extrato           = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe o cpf: ");
	scanf("%14[^\n]",cpf);
	getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return cpf;
}
//
/// Função responsavel por mostrar o Extrato
//
void exibirExtrato(Saques* Saques){
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
	printf("///          	= = = = = = =        Extrato          = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
  printf("/// O saque Foi feito no cpf: %s                                          ///\n",Saques->cpf);
  printf("/// No valor de: R$%s                                                      ///\n",Saques->valor);
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}