typedef struct pagamento Pagamento;
struct pagamento {
	char codigoDeBarra[48];
	int dia, mes, ano;
	char confirmacao[4];
	int dataConfirmacao;
	char valorPagamento [11];
	float preco;
	float precoConfirmacao;
};
void moduloPagamento(void);
char menuPagamento(void);
void cadastrarPagamento(void);
void histPagamento();
Pagamento* telaPreencherPaga(void);
void gravarPagamento(Pagamento* pag);