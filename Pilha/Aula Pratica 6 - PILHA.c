#include <stdio.h>
#include <stdlib.h>

typedef struct sDados{
	char nome[30];
	int numpag;
	char categoria[30];
}dados;

typedef struct sPilha{
	int *elem[10];
	int topo;
}PILHA;

void criarPilha(PILHA *pilha){
	pilha->topo=-1;
}

int pilhaVazia(PILHA *pilha){
	if(pilha->topo==-1){
		printf("pilha vazia");
		return 1;
	}
	return 0;
}

int pilhaCheia(PILHA *pilha){
	if(pilha->topo==9){
		printf("pilha cheia");
		return 1;
	}
	return 0;
}

int push(PILHA *pilha, dados elem){
	if(pilhaCheia(pilha)){
		return 0;
	}
	pilha->elem[pilha->topo+1]=elem;
	pilha->topo++;
		
}

int pop(PILHA *pilha){
	int removido=-1;
	
	if(pilhaVazia(pilha)){
		return 0;
	}
	removido=pilha->elem[pilha->topo];
	pilha->topo--;
	return removido;	
}

int topoElemento(PILHA *pilha){
	int topo=-1;
	if(pilhaVazia(pilha)){
		return topo;
	}
	
	topo=pilha->elem[pilha->topo];
	return topo;	
}

int imprimirDesempilha(PILHA *pilha){
	int removido=-1;
	int i;
	if(pilhaVazia(pilha)){
		return removido;
	}
	
	removido=pilha->elem[pilha->topo];
	pilha->topo--;
	
	
	
	
}
