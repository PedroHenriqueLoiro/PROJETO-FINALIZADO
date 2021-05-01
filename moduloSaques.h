typedef struct saques Saques;
struct saques {
 char cpf[15]; 
 char valor [11]; 
 float preco;
};


void moduloSaques();
char menuSaque(void);
Saques* TelaSaques(void);
void cadastrarSaques(void);
void extratoSaques(void);
void gravarSaques(Saques* saq);