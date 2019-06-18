#include <stdio.h>
#include <stdlib.h>

typedef struct sDados{
	char nome[30];
	int matricula;
	float n1,n2,n3;
}Dados;

typedef struct sCell{
	Dados info;
	struct sCell *next;
}CELULA;

CELULA* criarCelula(){ //CRIAR CELULA
	CELULA *nova=(CELULA*)malloc(sizeof(CELULA));
	return nova;
}

void iniciarLista(CELULA **lista){ // INICIAR LISTA
	(*lista)=NULL;
}

void imprimirElemento(Dados elem){ // IMPRIMIR ELEMENTO
	printf("%s", Dados.nome);
}

int listaVazia(CELULA **lista){ // VERIFICAR SE A LISTA TA VAZIA
	if((*lista)==NULL){
		return 1;
	}
	return 0;
}

int inserirFIM(CELULA **lista, Dados elem){ // INSERIR NO FIM
	CELULA *nova=criarCelula();
	CELULA *aux;
	
	if(nova==NULL){
		return 0;
	}
	nova->info=elem;
	nova->next=NULL;
	
	if(listaVazia(*lista)){
		(*lista)=nova;
	}
	aux=(*lista);
	while(aux->next!=NULL){
		aux=aux->next;
	}
	aux->next=nova;
	return 1;
}

int inserirInicio(CELULA **lista,Dados elem){ // INSERIR NO INICIO
	CELULA *nova=criarCelula();
	if(nova==NULL){
		return 0;
	}
	if(listaVazia(*lista)){
		return inserirFim(lista,elem);
	}
	nova->info=elem;
	nova->next=(*lista);
	(*lista)=nova;
	return 1;
	
}

void imprimirLista(CELULA **lista){ // IMPRIMIR LISTA
	CELULA *aux=(*lista);
	
	if(listaVazia(lista)){
		return 0;
	}else 
		printf("Lista: ");
		while(aux->next!=NULL){
			imprimirElemento(aux->info);
			aux=aux->next;
		}
}

Dados removerInicio(CELULA **lista){ //  REMOVER DO INICIO
	CELULA *removida;
	Dados removido;
	strcpy(removido.nome,"");
	removido.matricula=-1;
	
	if(listaVazia(lista)){
		return removido;
	}
	
	removida=(*lista);
	removido=removida->info;
	
	(*lista)= (*lista)->next;
	
	free(removida);
	return removido;
}

Dados removerFim(CELULA **lista){ //REMOVER FIM
	CELULA *removido;
	CELULA *ant;
	
	if(listaVazia(lista)){
		return removido;
	}
	
	if((*lista)->next==NULL){
		removido->info=(*lista)->info;
		free((*lista));
		return removido;
	}
	
	removido=(*lista);
	while(removido->next!=NULL){
		ant=removido;
		removido=removido->next;
	}
	
	free(removido);
	return ant;	
}

CELULA pesquisarMatricula(CELULA **lista , Dados matricula){ // PESQUISAR PELA MATRICULA
	CELULA *aux;
	
	if(listaVazia(lista)){
		return ;
	}
	aux=(*lista);
	while(aux->next!=NULL){
		if(aux->info.matricula=matricula){
			return aux;
		}
		aux=aux->next;
	}
	return ;
}

PESSOA removerMatricula(CELULA **lista, Dados matricula){ // REMOVER PELA MATRICULA
	CELULA *removido;
	CELULA *ant;
	
	if(listaVazia(lista)){
		return;
	}
	removido=pesquisarMatricula(lista,matricula);
	if(removido==NULL){
		return;
	}
	if(removido==(*lista)){
		return removerInicio(lista);
	}
	ant=(*lista);
	while(ant->next!=removido){
		ant=ant->next;
	}
	ant->next= removido->next;
	free(removido);
	return ant;	
}

int InserirPosicaoK(CELULA **lista, int elemento , int posicao){ //INSERIR POSICAO K
	CELULA *nova=criarCelula();
	CELULA *aux;
	CELULA *ant;
	int i=1;
	
	aux=(*lista);
	nova->info=elemento;
	nova->next=NULL;
	
	if(posicao=0){
		return 0;
	}
	
	while(aux->next!=NULL){
		if(i==posicao){
			nova->next=aux;
			ant->next=nova
			return 1;
		}	
		ant=aux;
		aux=aux->next;
		i++;
	}
}



