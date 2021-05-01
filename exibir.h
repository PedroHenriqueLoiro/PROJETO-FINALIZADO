#include <stdio.h>
#include <stdlib.h>
#include "moduloDeposito.h"
#include "moduloPagamento.h"
#include "moduloSaques.h"
#include "moduloTransferencia.h"

void exibir(Deposito* Deposito);
void exibirPag(Pagamento* Pagamento);
void exibirExtrato(Saques* Saques);
void exibirTranf(Transf* Transf);