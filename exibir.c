#include <stdio.h>
#include <stdlib.h>
#include "moduloDeposito.h"
#include "moduloTransferencia.h"
#include "moduloPagamento.h"
#include "moduloSaques.h"
#include "validacao.h"


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
  printf("/// Dinheiro Depositado na conta de %s                                    ///\n",Deposito->nome);
	printf("/// CPF: %s                                                               ///\n",Deposito->cpf);
	printf("/// Dinheiro Depositado: R$ %.2f                                          ///\n",Deposito->valorDepositado);
	printf("/// Na Agencia bancaria: %s                                               ///\n",Deposito->numeroBanco);
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

//
/// FUnção responsavel por mostrar a tela Pagamento
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
	printf("/// Codigo de Barras %s:                                                  ///\n",Pagamento->codigoDeBarra);
	printf("/// Esse pagamento Foi Realizado: %i/%i/%i                                ///\n",Pagamento->dia,Pagamento->mes, Pagamento->ano);
  printf("/// No valor de: %f                                                       ///\n",Pagamento->valorPagamento);
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
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
  printf("/// No valor de: %f                                                       ///\n",Saques->valor);
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
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
	printf("///          	= = = = = = =   Historico de Transf   = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
  printf("///  Nome completo do Beneficiario: %s                                    ///\n",Transf->nome);
  printf("///  Na agência Bancaria: %s                                              ///\n",Transf->agencia);
  printf("///  Na conta Bancaria: %s                                                ///\n",Transf->contaBancaria);
  printf("///  No CPF: %s                                                           ///\n",Transf->cpf);
  printf("///  No valor de: %f                                                      ///\n",Transf->valorTranf);
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}