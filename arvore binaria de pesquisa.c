#include <stdio.h>
#include <stdlib.h>

typedef struct sInfo{
	int num;
}ELEM;

typedef struct sNo{
	ELEM info;
	struct sNo *esq;
	struct sNo *dir;	
}NO;

void InserirRecursivo(NO **raiz, int elemento){ // INSERIR RECURSIVO
	if(*raiz==NULL){ 
		(*raiz)=criarNo();
		(*raiz)->esq=NULL;
		(*raiz)->dir=NULL;
		(*raiz)->info=elemento;
	}else
		if(elemento<(*raiz)->info){ //elemento menor que a raiz
			inserirRecursivo(&(*raiz)->esq,elemento);
		}
		if(elemento>(*raiz)->info){ // elemento maior que a raiz
			inserirRecursivo(&(*raiz)->dir,elemento);
		}	
}

NO PesquisarElemento(NO **raiz, int elemento){ // PESQUISAR ELEMENTO
	if(raiz==NULL){
		return NULL;
	}
	if(raiz->info==elemento){
		return raiz;
	}
	else if(raiz->info>elemento){ // raiz maior que o elemento
		return pesquisarElemento(raiz->esq,elemento);
	}else 
		return pesquisarElemento(raiz->dir,elemento);
}

void RemoverRecursivo(No **raiz,int elemento){ // REMOVER RECURSIVO
	NO *aux;
	
	if(vazia(raiz)){
		printf("ERRO");
		return;
	}
	if(elemento<(*raiz)->info){
		removerRecursivo(&(*raiz)->esq,elemento);
	}else
	if(elemento>(*raiz)->info){
		removerRecursivo(&(*raiz)->dir,elemento);
	}
	else
	aux=*raiz;
		if(((*raiz)->esq==NULL) && ((*raiz)->dir==NULL)){
			free(aux);
			(*raiz)=NULL;
		}
	else //aqui pra baixo
		if((*raiz)->esq==NULL){
			(*raiz)=(*raiz)->dir;
			aux->dir=NULL;
			free(aux);
	}else
		if((*raiz)->dir==NULL){
			(*raiz)=(*raiz)->esq;
			aux->esq=NULL;
			free(aux);
	}	
	else
		aux=maiorElemento(&(*raiz)->esq);
		aux->esq=(*raiz)->esq;
		aux->esq=(*raiz)->dir;
		free((*raiz));
		*raiz=aux;
			
		
}

NO *MaiorElemento(NO **no){ // REMOVER MAIOR ELEMENTO
	if((*no)->dir!=NULL){
		return maiorElemento(&(*no)->dir);
	}else
	NO *aux=*no;
	if((*no)->esq!=NULL){
		*no=(*no->esq);
	}else
		*no=NULL;
		return aux;
	
}

void PreOrdem (NO **raiz){ // PRE ORDEM
	if(vazia(raiz)){
		return ;
	}
	print("%d", (*raiz)->info);
	PreOrdem(&(*raiz)->esq);
	PreOrdem(&(*raiz)->dir);
}

void Ordem(NO **raiz){ // ORDEM
	if(vazia(raiz)){
		return ;
	}
	Ordem(&(*raiz)->esq);
	printf("%d", (*raiz)->info);
	Ordem(&(*raiz)->dir);
}

void PosOrdem(NO **raiz){ // POR ORDEM
	if(vazia(raiz)){
		return ;
	}
	Ordem(&(*raiz)->esq);
	Ordem(&(*raiz)->dir);
	printf("%d", (*raiz)->info);
}

void TrasPraFrente(NO **raiz){ // TRAS PRA FRENTE
	if(vazia(raiz)){
		return;
	}
	TrasPraFrente(&(*raiz)->dir);
	printf("%d", (*raiz)->info);
	TrasPraFrente(&(*raiz)->esq);
}

int AlturaArvore(NO **raiz){ // ALTURA = NIVEL (PODE USAR A MESMA FUNCAO TROCANDO O NOME)
	if(vazia(raiz)){
		return 0;
	}
	int esquerda = 1+Altura(&(*raiz)->esq);
	int direita = 1+Altura(&(*raiz)->dir);
	if(esquerda>direita){
		return esquerda;
	}
	return direita;
}

int QntNos(NO **raiz){ // QUANTIDADE DE NOS
	if(vazia(raiz)){
		return 0;
	}
	return 1 + QntNos(&(*raiz)->esq) + QntNos(&(*raiz)->dir);
}

void PrintFolhaEmOrdem(NO **raiz){ // PRINT FOLHA EM ORDEM ( pode mudar a ordem do print para primeiro e depois chamar as funcao esq e dir)
	if(vazia(raiz)){
		return ;
	}
	PrintFolhaEmOrdem(&(*raiz)->esq);
	if((*raiz)->esq==NULL && (*raiz)->dir==NULL){
		print("%d", (*raiz)->info);
	}
	PrintFolhaEmOrdem(&(*raiz)->dir);
}

int InserirIterativo(NO **raiz, ALUNO i){ // INSERIR ITERATIVO
	NO *novo = criarno();
	if(novo == NULL)
		return 0;
	novo->info = i;
	novo->dir = NULL;
	novo->esq = NULL;
	
	if(vazia(raiz)){
		*raiz = novo;
		return 0;
	}	
	NO *aux = *raiz;
	NO *ant = NULL;
	
	while(aux!=NULL){
		ant = aux;
		if(i.matricula >= aux->info.matricula)
			aux = aux->dir;
		else 
			aux = aux->esq;
	}
	if(i.matricula > aux->info.matricula)
		ant->dir = novo;
	else
		ant->esq = novo;
	return 1;
}








