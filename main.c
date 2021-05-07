///////////////////////////////////////////////////////////////////////////////
///  Projeto de Pedro Henrique Guedes Brito.                                ///
///  aluno de progamação DCT1106 - T01                                      ///
///  Projeto focado na simulação de uma gestão Bancária onde criarei um     ///
///  algoritmo cujo seu objetivo será o cadastramento de contas, tanto de   ///
///  pessoas fisicas como pessoas juridicas.                                ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloDeposito.h"
#include "moduloTransferencia.h"
#include "moduloSaques.h"
#include "moduloPagamento.h"
#include "validacao.h"
#include "moduloRelatorio.h"

//
/// São algumas assinaturas 
//
int menuPrincipal(void);
void menuSobre(void);
void fimProg(void);

//
/// são as structs do progamas
//
typedef struct deposito Deposito;
typedef struct pagamento Pagamento;
typedef struct saques Saques;
typedef struct transferencia Transf;


//
/// é a função main
//
int main(void) {
	Deposito* dep;
	Pagamento* pag;
	Transf* tra;
	Saques* saq;
	dep = (Deposito*)malloc(sizeof(Deposito));
  pag = (Pagamento*)malloc(sizeof(Pagamento));
  tra = (Transf*)malloc(sizeof(Transf));
  saq = (Saques*)malloc(sizeof(Saques));

	char opcao;
    menuSobre();
	do{
		opcao = menuPrincipal();
		switch (opcao)
		{
		case '1':moduloDeposito();
						 
			break;
		
		case '2':moduloTransf();
					
			break;

		case '3':moduloSaques();
		    break;

		case '4':moduloPagamento();
			break;

    case '5':moduloRelatorios();
		  break;
			
		case '6':menuSobre();
			break;
	
		}
	}while(opcao != '0');
	fimProg();
	free(dep);
	free(pag);
	free(tra);
	free(saq);
return 0;
}

int menuPrincipal(void){
		limpaTela();
		char op;
		printf("\n");
	  printf("/////////////////////////////////////////////////////////////////////////////\n");
	  printf("///                                                                       ///\n");
	  printf("///          ===================================================          ///\n");
	  printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	  printf("///          = = = =           Sistema Bancario          = = = =          ///\n");
	  printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	  printf("///          ===================================================          ///\n");
	  printf("///                Developed by  @Pedro_.Guedes- Jan, 2021                ///\n");
	  printf("///                                                                       ///\n");
		printf("///                                                                       ///\n");
		printf("/////////////////////////////////////////////////////////////////////////////\n");
		printf("///                                                                       ///\n");
		printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
		printf("///           = = = = = = = =  Menu Principal = = = = = = = =             ///\n");
		printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
		printf("///                                                                       ///\n");
		printf("///           1. Deposito                                                 ///\n");
		printf("///           2. Transferencia                                            ///\n");
		printf("///           3. Saques                                                   ///\n");
		printf("///           4. Pagamentos                                               ///\n");
		printf("///           5. Relatorios                                               ///\n");
    printf("///           6. Menu Sobre                                               ///\n");
		printf("///           0. Encerra o programa                                       ///\n");
		printf("///                                                                       ///\n");
		printf("///           Escolha a opção desejada: ");
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
/// explico sobre o que é o progama
//
void menuSobre(void) {
		limpaTela();
    printf("\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                  ///\n");
    printf("///             Centro de Ensino Superior do Serido                          ///\n");
    printf("///             Departamento de Computacao e Tecnologia                      ///\n");
    printf("///             Disciplina DCT1106 -- Programacao                            ///\n");
    printf("///             Projeto Sitema de controle de contas Bancarias               ///\n");
    printf("///             Developed by  @pedro_.guedes - Jan, 2021                     ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///          = = =  Um Sistema de Controle de Contas Bancárias = = =         ///\n");
    printf("///                                                                          ///\n");
    printf("///        Bom dia! Me chamo Pedro Henrique Guedes Brito, sou estudante      ///\n");
    printf("///        Da disciplina de progamacao ministrada pelo professor Flavius     ///\n");
    printf("///        DCT1106 - T01. Meu projeto a priori foi pensado a fim de criar    ///\n");
    printf("///        um algoritmo que imita a realidade bancaria no que diz respeito   ///\n");
    printf("///        a criacao de conta em um banco.                                   ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    getchar();
    printf("\n");
}


//
/// tchauzinho
//
void fimProg(void){
	limpaTela();
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          = = = =           FIM DO PROGRAMA           = = = =          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///                Developed by  @Pedro_.Guedes - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	getchar();
}

//
/// um mini alerta so pra deixar bonito mesmo
//
void TeladeAviso(void){
	limpaTela();
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          = = = =               AVISO!                = = = =          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///                Developed by  @pedro_.guedes - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("///                       DADOS NÃO ENCONTRADOS                           ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	getchar();
}