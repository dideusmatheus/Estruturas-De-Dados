#include <stdlib.h>
#include <stdio.h>

typedef struct sDados{
	char nome[30];
	int quantidade;
	float preco;
}Dados;

typedef struct sCell{
	Dados info;
	struct sCell *next;
}CELULA;

void iniciarLista(CELULA **lista){ // INICIAR LISTA
	(*lista)=NULL;
}

int listaVazia(CELULA **lista){ // VERIFICAR SE A LISTA TA VAZIA
	if((*lista)==NULL){
		return 1;
	}
	return 0;
}

CELULA* criarCelula(){ // CRIAR CELULA
	CELULA *nova=(CELULA*)malloc(sizeof(CELULA));
	return nova;
}

void iniciarLista(CELULA **lista){ // INICIAR LISTA
	(*lista)=NULL;
}

int inserirFinal(CELULA **lista, Dados elem){ // INSERIR FIM
	CELULA nova=criarCelula();
	
	if(nova==NULL){
		return 0;
	}
	nova->info=elem;
	nova->next=NULL;
	
	if(listaVazia(lista)){
		nova->next=nova;
		(*lista)=nova
	}
	
	nova->next=(*lista)->next;
	(*lista)->next=nova;
	(*lista)=nova;
	return 1;
}

int inserirInicio (CELULA **lista){  // INSERIR INICIO
	CELULA *nova;
	nova=criarCelula();
	if (criarCelula==NULL){
		printf ("Memória cheia!\n");
		return 0;
	}
	if (listaVazia(lista)){
		return inserirFim(lista);
	}
	nova->prev=NULL;
	nova->info=preenche();
	nova->next=(*lista);
	(*lista)->prev=nova;
	(*lista)=nova;
	return 1;
}

Dados removerInicio(CELULA **lista){ // REMOVER INICIO
	CELULA removido;
	Dados d;
	
	if(listaVazia(lista)){
		return;
	}
	d=removido->info
	removido=(*lista)->next;
	if((*lista)->next==(*lista)){
		iniciarLista(lista);
	}else{
		(*lista)->next=removido->next
	}
	free(removido);
	return d;
}

char removerFim (CELULA **lista){ // REMOVER FIM
	CELULA *removida;
	CELULA *aux;
	char x[20];
	strcpy(x, "invalido");
	if(listaVazia(lista)){
		return x[20];
	}else{
	removida=(*lista);
	aux=(*lista)->next;
	strcpy(removida->info, x);
	if((*lista)->next==(*lista)){
		inicializa(lista);
	}else{
		while(aux->next != (*lista)){
			aux=aux->next;
		}
		aux->next=(*lista)->next;
		(*lista)=aux;
	}
	free(removida);
	return x[20];
    }
}

void imprimirLista(CELULA **lista){ //IMPRIMIR LISTA
	CELULA *aux;
	if(listaVazia(lista)){
		return 0;
	}else
	aux=(*lista)->next;
	do{
		imprimirElemento(aux->info);
		aux=aux->next
	}while(aux!=(*lista)->next);
}

void imprimirFim (CELULA **lista){  // IMPRIMIR FIM
	CELULA *aux=(*lista);
	if(listaVazia(lista)){
		printf ("Lista vazia!\n");
	}else{
		aux=(*lista);
		while(aux->next != NULL){
			aux=aux->next;
		}
		while(aux!=NULL){
			imprimirElemento(aux->info);
			aux=aux->prev;
		}		
	}
}

CELULA* buscar (CELULA **lista){ // BUSCAR POR NOME
	CELULA *aux;
	CLIENTE elemento;
	printf ("Digite o nume do cliente\n");
    scanf ("%s", elemento.nome);
    aux=(*lista);
	while(aux!=NULL){
		if(strcmp(elemento.nome, aux->info.nome)==0){
			return aux;
		}
		aux=aux->next;
	}
	return NULL;
}

int liberarLista (CELULA **lista){ // LIBERAR LISTA
	do{
		removerFinal(lista);
	}while (listaVazia(lista) != 1);
}



