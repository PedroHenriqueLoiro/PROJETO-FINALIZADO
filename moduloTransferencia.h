typedef struct transferencia Transf;
struct transferencia{
	char nome[51];
  char cpf[15];
  char agencia[5];
  char contaBancaria[7];
  char valorTranf [11];
	float preco;
	char status;
};


void moduloTransf();
char menuTransf(void);
Transf* TelacadastrarTransf(void);
void cadastrarTrans(void);
void histTransf(void);
void gravarTransf(Transf* tra);

//histTransf
void exibirTranf(Transf* Transf);
Transf* nomeTransf(char* nom);
char* telaBuscaTransf(void);