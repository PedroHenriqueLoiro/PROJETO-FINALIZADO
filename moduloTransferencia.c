#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacao.h"
#include "exibir.h"

//
/// Switch responsavel por escolher as opção do menu transferencia
//
void moduloTransf(){
	char opcao;
		do{
		opcao =  menuTransf();
		switch (opcao)
		{
			case '1':cadastrarTrans();
						break;
		
			case '2':histTransf();
						break;
		}
	}while(opcao!='0');

}
void cadastrarTrans(void){
	Transf* tra;
	tra = TelacadastrarTransf();
	gravarTransf(tra);
	free(tra);
}


void histTransf(void){
	Transf* struTrans;
	char* nom;

	nom = telaBuscaTransf();

	struTrans = nomeTransf(nom);

	exibirTranf(struTrans);

	free(struTrans);

}

Transf* nomeTransf(char* nom){
	FILE* fp;
	Transf* nome;

	nome = (Transf*) malloc(sizeof(Transf));
	fp = fopen("Transferencia.dat","rb");
	if(fp == NULL){
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
	}

	while(!feof(fp)){
		fread(nome,sizeof(Transf),1,fp);
		if(strcmp(nome->nome, nom) == 0){
			fclose(fp);
			return nome;
		}
	}

	fclose(fp);
	return NULL;
}


//
/// tela responsavel por mostrar as escolhas do cliente
//
char menuTransf(void){
	char op;
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
	printf("///           = = = = = = = = Menu Tranferencia = = = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Cadastrar Transferencia                                  ///\n");
	printf("///           2. Historico Tranferencia                                   ///\n");
  printf("///           0. Sair da tela                                             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Escolha a opção desejada:                                   ///\n");
  scanf("%c", &op);
  getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return op;
}


//
/// Função responsavel por capturar os dados do cliente
//
Transf* TelacadastrarTransf(void){
	Transf* tra;
	float valPre;
	tra = (Transf*) malloc(sizeof(Transf));
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
	printf("///           = = = = = = = = Cadastro do Deposito  = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("/// Nome da Pessoa: ");
	scanf("%50[^\n]", tra->nome);
	getchar();
  // validação do nome
	while (!validaNome(tra->nome)){ 
		printf("/// Nome da pessoa: Invalido                                             ///\n");	
		printf("/// Nome da pessoa: ");
		scanf("%50[^\n]", tra->nome);
		getchar();
	}

	printf("/// Valor da tranferencia: ");
  scanf("%20[^\n]", tra->valorTranf);
  getchar();
  // validação do valor
	tra->preco = atof(tra->valorTranf);
  valPre = validaPreco(&tra->preco);
  while (!valPre){
		printf("/// Valor Depositado: ");
	  scanf("%20[^\n]", tra->valorTranf);
	  getchar();
		tra->preco= atof(tra->valorTranf);
    valPre = validaPreco(&tra->preco);
	}
  
  printf("/// Agencia da pessoa na qual voce deseja transferir: ");
  scanf("%20[^\n]", tra->agencia);
  getchar();
// validação da agencia bancaria
	while (!validaAgencia(tra->agencia)){
		printf("/// Agencia INVALIDA                                                    ///\n");	
    printf("/// Informe a angencia:");
    scanf("%14[^\n]", tra->agencia);
	  getchar(); 
  }
  
  printf("/// informe o cpf da pessoa na qual voce deseja transferir: ");
  scanf("%20[^\n]", tra->cpf);
  getchar();
  //validação do cpf
	while (!validaCPF(tra->cpf)){
		printf("/// CPF INVALIDO                                                         ///\n");	
    printf("/// Informe o CPF:");
    scanf("%14[^\n]", tra->cpf);
	  getchar(); 
  }
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return tra;
}



//
/// função responsavel por salvar no arquivo
//
void gravarTransf(Transf* tra){
	FILE* fp;
	fp = fopen("Transferencia.dat","ab");
	if(fp == NULL){
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
		exit(1);
	}

	fwrite(tra, sizeof(Transf),1,fp);
	fclose(fp);
}

//
/// Tela que ajuda a buscar
//
char* telaBuscaTransf(void){
	char* nome;
	nome = (char*) malloc(sizeof(char));
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
	printf("///           = = = = =          Transferencia      = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe o nome: ");
	scanf("%14[^\n]",nome);
	getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return nome;
}
//
/// Função responsavel por mostrar a transferencia
//
void exibirTranf(Transf* Transf){
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
	printf("///          	= = = = = = Buscar por transferencia  = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
  printf("///  Nome completo do Beneficiario: %s                                    \n",Transf->nome);
  printf("///  Na conta Bancaria: %s                                                \n",Transf->contaBancaria);
  printf("///  No CPF: %s                                                           \n",Transf->cpf);
  printf("///  No valor de: R$%0.2f                                                 \n",Transf->preco);
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}