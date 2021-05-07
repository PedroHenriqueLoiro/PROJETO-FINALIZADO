typedef struct saques Saques;
struct saques {
 char cpf[15]; 
 char valor [11]; 
 float preco;
 char status;
 struct saques* prox;
};


void moduloSaques();
char menuSaque(void);
Saques* TelaSaques(void);
void cadastrarSaques(void);
void extratoSaques(void);
void gravarSaques(Saques* saq);

//Extrato
Saques* cpfExtrato(char* nom);
void Extrato(void);
char* telaBuscaSaq(void);
void exibirExtrato(Saques* Saques);