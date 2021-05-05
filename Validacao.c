//
/// Validação de data (feito com a ajuda de Habby)
//
int bissexto(int ano) {
  if ((ano % 4 == 0) && (ano % 100 != 0)) {
    return 1;
  } else if (ano % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}
int validacao (int dia, int mes, int ano){
	int maiorDia;
// Recebe uma data no formato (dia, mes, ano) e valida a mesma
// Retorna 1 se a data é válida ou 0 caso contrário
/// Como é uma data de validade, o programa não aceita anos anteriores
	if (ano < 2021 || mes < 1 || mes > 12)
		return 0;
	if (mes == 2) {
		if (bissexto(ano)) 
		maiorDia = 29;
		else
		maiorDia = 28;
	} else if (mes == 4 || mes == 6 || 
				mes == 9 || mes == 11) {
				maiorDia = 30;
	} else
		maiorDia = 31;

	if (dia < 1 || dia > maiorDia)
		return 0;

	return 1;
}

//
/// Validação de nome (feito com a ajuda de Habby)
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int validaNome(char nome[]){
	int tam;
	tam = strlen(nome);
	if(tam == 0  || tam == 1){
		return 0;
	}
	for(int i = 0;i < tam; i++){
		if(nome[i] >= 'A'  && nome[i] <= 'Z'){
			continue;
		}else if(nome[i] >= 'a' && nome[i] <= 'z'){
			continue;
		}else if(nome[i]== ' '){
			continue;
		}else{
			return 0;
		}
	}
	return 1;
}


//
/// Validação de preço (feito com a ajuda de Habby)
//
#include <stdio.h>
float validaPreco(float pre[]){
	float preco[1];

	for(int i = 0; i<1;i++){
		if(pre[i] < 0 || pre[i] == 0){
			return 0;
		}else{
			for(int i = 0;i < 1;i++){
			return 1;
		  }	
	
		}
  }
	return 1;
}

#include <stdlib.h>

//
/// Validação de limpa a tela (feito com a ajuda de Habby)
//
void limpaTela(void){
	if(system("clear") || system("cls")){

	}
}

//
/// validação de codigo de barra( com ajuda do habby)
//
int validacodBarra(char num[]){
	int tam;
	tam = strlen(num);
	if(tam != 13){
		return 0;
	}
	for(int i = 0;i < tam; i++){
		if(num[i] >= '0'  && num[i] <= '9'){
			continue;
		}else{
			return 0;
		}
	}
	return 1;
}

//
/// validação da agencia( com ajuda do habby)
//
int validaAgencia(char num[]){
	int tam;
	tam = strlen(num);
	if(tam != 4){
		return 0;
	}
	for(int i = 0;i < tam; i++){
		if(num[i] >= '0'  && num[i] <= '9'){
			continue;
		}else{
			return 0;
		}
	}
	return 1;
}

//
/// validação do cpf( com ajuda do habby)
//
int validaCPF(char num[]){
	int tam;
	tam = strlen(num);
	//printf("Tamanho: %i\n",tam);
	if(tam != 11){
		return 0;
	}
	for(int i = 0;i < tam; i++){
		if(num[i] >= '0'  && num[i] <= '9'){
			continue;
		}else{
			return 0;
		}
	}
	return 1;
}
