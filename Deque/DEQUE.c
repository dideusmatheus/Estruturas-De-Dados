#include <stdio.h>
#include <stdlib.h>

typedef struct sCell{
	int info;
	struct sCell *next;
	struct sCell *prev;
}CELULA;

typedef strcut sDeque{
	CELULA *inicio;
	CELULA *fim;
}DEQUE;

int DequeVazio(DEQUE *deque){
	if(d->inicio==NULL){
		return 1;
	}
	return 0;
}

int enfileirarFim(DEQUE *deque, int elem){
	CELULA *nova=criarCelula();
	if(nova==NULL){
		return 0;
	}
	
	nova->info=elem;
	nova->next=NULL;
	if(dequeVazio(deque)){
		nova->prev=NULL;
		deque->inicio=nova;
		deque->fim=nova;
		return 1;
	}
	deque->fim->next=nova;
	nova->prev=deque->fim;
	deque->fim=nova;
	return 1;
}


int enfileirarInicio(DEQUE *deque, int elem){
	CELULA *nova=criarCelula();
	if(nova==NULL){
		return 0;
	}
	nova->info=elem;
	if(DequeVazio(deque)){
		infileirarFim(deque, elem);
		return 1;
	}
	nova->prev=NULL;
	d->inicio->prev=nova;
	nova->next=d->inicio;
	d->inicio=nova;
	return 1;
}

int desenfileirarInicio (DEQUE *deque){
	ALUNO removido;
 	CELULA *aux;
 	if(dequeVazia(deque)){
 		printf("Deque Vazia\n");
 		return removido;
	 }
 	deque->inicio->info.saldo=deque->inicio->info.saldo-2;
 	aux=deque->inicio;
 	removido = aux->info;
 	deque->inicio=deque->inicio->next;
	 if(deque->inicio==NULL){
		 deque->fim=NULL;
		 free(aux);
 		return removido;
	 }
 	deque->inicio->prev=NULL;
 	free(aux);
 	deque->cont--;
 	return removido;
}

ALUNO desenfileirarFim (DEQUE *deque){
	ALUNO removido;
 	CELULA *aux;
 	if(dequeVazia(deque)){
 		printf("Deque Vazia\n");
 		return removido;
	 }
 	deque->inicio->info.saldo=deque->inicio->info.saldo-2;
 	aux=deque->fim;
	 removido = aux->info;
	 deque->fim=deque->fim->prev;
 	if(deque->fim==NULL){
		deque->inicio=NULL;
 		free(aux);
 		deque->cont--;
 		return removido;
	}
 	deque->fim->next=NULL;
 	free(aux);
 	return removido;
 }
 
 void imprimirdoInicio (DEQUE *deque){ // imprimir do inicio e desenfileirar
 	while(!dequeVazia(deque)){ 
 		imprimirInicio(deque);
 		desenfileirarInicio(deque);
 	}
 }
 
 void imprimirdoFim (DEQUE *deque){ // imprimir do fim e desenfileirar
 	while(!dequeVazia(deque)){ 
		 imprimirFim(deque);
 		desenfileirarFim(deque);
	 }
 }
