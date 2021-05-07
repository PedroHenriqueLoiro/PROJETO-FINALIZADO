typedef struct deposito Deposito;
typedef struct transferencia Transf;
typedef struct pagamento Pagamento;
typedef struct saques Saques;

void moduloRelatorios(void);
char menuRelatorios(void);
void relDeposito(void);
void ExibiDeposito(Deposito* dpst);
void exibeRelDpst(Deposito* pro);
void apagarLista(Deposito **lista);
void apagarListaTra(Deposito **lista);

void relTrans(void);
void relSaques(void);

void exibeRelPag(Pagamento* pag);
void apagarListaPag(Pagamento **lista);
void relPaga(void);