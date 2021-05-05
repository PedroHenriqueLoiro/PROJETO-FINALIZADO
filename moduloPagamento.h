typedef struct pagamento Pagamento;
struct pagamento {
	char codigoDeBarra[14];
	int dia, mes, ano;
	char confirmacao[4];
	int dataConfirmacao;
	char valorPagamento [11];
	float preco;
	float precoConfirmacao;
};

//
/// assinaturas da função referente ao pagamentos
//
void moduloPagamento(void);
char menuPagamento(void);
void cadastrarPagamento(void);
void histPagamento();
Pagamento* telaPreencherPaga(void);
void gravarPagamento(Pagamento* pag);

//funções que servem para o historico
Pagamento* codBarra(char* nom);
char* telaBuscaPag(void);