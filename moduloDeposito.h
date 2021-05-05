typedef struct deposito Deposito;
struct deposito {
  char nome[51];
  char cpf[15];
  char numeroBanco[4];
  char agencia[5];
  char valorDepositado [20];
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


void exibir(Deposito* Deposito);
char* telaBuscaDpst(void);
Deposito* pesquisaCPF(char* nom);
