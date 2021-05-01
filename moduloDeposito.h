typedef struct deposito Deposito;
struct deposito {
  char nome[51];
  char cpf[15];
  char numeroBanco[4];
  char agencia[5];
  char confirmacao[4];
  char valorDepositado [11];
	float preco;
};	

//
/// assinaturas das funções
//
void moduloDeposito();
char menuDeposito (void);
Deposito* TelaDeposito (void);
void cadastrarDeposito(void);
void gravarDeposito(Deposito* dep);
void histDeposito(void);



