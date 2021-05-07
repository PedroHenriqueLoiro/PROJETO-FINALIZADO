#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloRelatorio.h"
#include "moduloDeposito.h"
#include "moduloSaques.h"
#include "moduloPagamento.h"
#include "moduloTransferencia.h"
#include "validacao.h"



void moduloRelatorios(void){
	char opcao;
	do{
		opcao = menuRelatorios();
		switch (opcao)
		{
		case '1':relDeposito();
						 
		 		break;
		
		case '2':relTrans();
					
			break;

		case '3':relSaques();
		    break;

		case '4':relPaga();
				break;
			
	
		}
	}while(opcao != '0');
}




char menuRelatorios(void){
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
	printf("///                Developed by  @pedro_.Guedes - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = =          Relatorios         = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Relatorio Deposito                                       ///\n");
	printf("///           2. Relatorio Transferencia                                  ///\n");
	printf("///           3. Relatorio Saques                                         ///\n");
	printf("///           4. Relatorio Pagamentos                                     ///\n");
	printf("///           0. Sair                                                     ///\n");
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


void exibeRelDpst(Deposito* dpst){
  	printf("/// # Nome:%s                                                             \n",dpst->nome);
		printf("/// # CPF: %s                                                             \n",dpst->cpf);
  	printf("/// # Valor depositos:R$%0.2f                                             \n",dpst->preco);
		printf("-------------------------------------------------------------------------///\n");

}





void apagarLista(Deposito **lista){
    Deposito *pro;
    
    while (*lista != NULL){
   	    pro = *lista;
        *lista = (*lista)->prox;
        free(pro);
    }   
}
void relDeposito(void){
	FILE *fp;
  Deposito* pro;
	limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///                Developed by  @pedro_.Guedes - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = =     Relatorio dos Deposito  = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	pro = (Deposito*) malloc(sizeof(Deposito));
    fp = fopen("Depositos.dat", "rb");

    if (fp == NULL) {
        printf("ERRO");
    }else{
        while(fread(pro, sizeof(Deposito), 1, fp)) {
            if(strcmp(&pro->status,"x") != 0){
                exibeRelDpst(pro);
            }
        }
        printf("\n");
        printf("/////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    fclose(fp);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void exibeRelTrans(Transf* tra){
  	printf("/// # Nome:%s                                                             \n",tra->nome);
		printf("/// # CPF: %s                                                             \n",tra->cpf);
    printf("/// # Na agencia:%s                                                       \n",tra->agencia);
  	printf("/// # Valor depositos:R$%0.2f                                               \n",tra->preco);
		printf("--------------------------------------------------------------------------\n");

}



void apagarListaTra(Deposito **lista){
    Deposito *pro;
    
    while (*lista != NULL){
   	    pro = *lista;
        *lista = (*lista)->prox;
        free(pro);
    }   
}
void relTrans(void){
	FILE *fp;
  Transf* tra;
	limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///                Developed by  @pedro_.Guedes - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = =  Relatorio das Tranferencias  = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	tra = (Transf*) malloc(sizeof(Transf));
    fp = fopen("Transferencia.dat", "rb");

    if (fp == NULL) {
        printf("ERRO");
    }else{
        while(fread(tra, sizeof(Transf), 1, fp)) {
            if(strcmp(&tra->status,"x") != 0){
                exibeRelTrans(tra);
            }
        }
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    fclose(fp);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void exibeRelSaque(Saques* sqs){
		printf("/// # CPF: %s                                                             \n",sqs->cpf);
  	printf("/// # Valor depositos:R$%0.2f                                             \n",sqs->preco);
		printf("--------------------------------------------------------------------------\n");

}



void apagarListaSqs(Saques **lista){
    Saques *sqs;
    
    while (*lista != NULL){
   	    sqs = *lista;
        *lista = (*lista)->prox;
        free(sqs);
    }   
}

void relSaques(void){
	FILE *fp;
  Saques* sqs;
	limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///                Developed by  @pedro_.Guedes - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = =         Relatorio Saques      = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	sqs = (Saques*) malloc(sizeof(Saques));
    fp = fopen("Saques.dat", "rb");

    if (fp == NULL) {
        printf("ERRO");
    }else{
        while(fread(sqs, sizeof(Saques), 1, fp)) {
            if(strcmp(&sqs->status,"x") != 0){
                exibeRelSaque(sqs);
            }
        }
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    fclose(fp);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void exibeRelPag(Pagamento* pag){
		printf("/// # Codigo de barras %s                                                 \n",pag->codigoDeBarra);
		printf("/// # Valor pago:R$%0.2f                                                 \n",pag->preco);
		printf("/// # Data de validade: %02d/%02d/%d                                     \n",pag->dia,pag->mes,pag->ano);
  	printf("--------------------------------------------------------------------------\n");

}



void apagarListaPag(Pagamento **lista){
    Pagamento *pag;
    
    while (*lista != NULL){
   	    pag = *lista;
        *lista = (*lista)->prox;
        free(pag);
    }   
}

void relPaga(void){
	FILE *fp;
  Pagamento* pag;
	limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///                Developed by  @pedro_.Guedes - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = =         Relatorio pagamento   = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	pag = (Pagamento*) malloc(sizeof(Pagamento));
    fp = fopen("Pagamentos.dat", "rb");

    if (fp == NULL) {
        printf("ERRO");
    }else{
        while(fread(pag, sizeof(Pagamento), 1, fp)) {
            if(strcmp(&pag->status,"x") != 0){
                exibeRelPag(pag);
            }
        }
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    fclose(fp);
}

