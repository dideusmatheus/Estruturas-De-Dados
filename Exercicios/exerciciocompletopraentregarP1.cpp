//Agadir José Dias Aquinoo     4887
//exercicio 1:
/*	 a- melhor caso: a lista esta vazia ou so possue um elemento
		 pior caso: a lista esta cheia com n elementos
   	b- melhor caso: elemento pesquisado esta na primeira posicao
	   pior caso: ter que percorrer a lista toda ate achar o elemento
	c- melhor caso: lista esta vazia ou possue um elemento
		pior caso: lista cheia com n elemento 
	d- melhor caso: lista vazia ou com um elemento
		pior caso: nao existe o pior caso , pois o ponteiro estara sempre apontando pro primeiro da lista*/
		
//exercicio 2:
/*	a- melhor caso: lista esta vazia
		pior caso: lista cheia
	b- melhor caso: lista vazia
		pior caso: nao existe
	c- melhor caso: lista com um elemento
		pior caso: nao existe
	d- melhor caso: lista com um elemento
		pior caso:	lista cheia com n elementos
*/

//exercicio 3
	/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct sCelula{
	int info;
	struct sCelula *next;
}CELULA;

void inicializaLista(CELULA **ptrLista){
	(*ptrLista) = NULL;
}

int verificaListaVazia(CELULA *ptrLista){
	if(ptrLista == NULL){
		return 1;
	}
	return 0;
}

CELULA* criarCelula(){
	CELULA *nova = (CELULA*)malloc(sizeof(CELULA));
	return nova;
}

int insereK(CELULA **ptrLista, int k){
	CELULA *nova = criarCelula();
	nova->info = 13;
	nova->next = NULL;
	
	if(verificaListaVazia(*ptrLista)==1){
		(*ptrLista) = nova;
		return 1;
	}
	
	int i=0;
	CELULA *aux;
	aux = (*ptrLista);
	
	while(aux!=NULL){
		if(i == k){ //elemento = posição k.
			nova->next = aux->next;
			aux->next = nova;
			return 1;		
		}
		i++;
		aux = aux->next;
	}
	
	return 0;
}

CELULA* removeK(CELULA **ptrLista, int k){
	CELULA *removida = criarCelula();
	removida->info = -1;
	
	if(verificaListaVazia(*ptrLista)==1){
		printf("Impossivel remocao, Lista Vazia");
		return NULL;
	}else{
		CELULA *aux;
		aux = (*ptrLista);
		int cont = 0;
		while(aux!= NULL){
			if(cont == k){
				removida->info = aux->info;
				free(aux);
				return removida;
			}
			cont++;
			aux = aux->next;
		}
	}
	return NULL;
}

void liberaLista(CELULA **ptrLista){
	CELULA *aux;
	aux = (*ptrLista);
	
	if(verificaListaVazia(*ptrLista)==1){
		printf("Impossivel liberar lista, Lista vazia.\n");
		return ;
	}
	
	while(aux!=NULL){
		free(aux);
		aux = aux->next;
	}
}

int main(){
	
	CELULA *ptrLista;
	
	CELULA *elemento = criarCelula();
	
	CELULA *ptrResposta;
	
	elemento->info = 13;
	elemento->next = NULL;
	
	inicializaLista(&ptrLista);
	
	
	
	int a = insereK(&ptrLista,0);
	
	
	ptrResposta = removeK(&ptrLista,0);
	
	system("pause");
	return 0;
}*/

//exercicio 4:
/*  Lista auto organizadas
	- metodo de mover pra frente: o elemento pesquisado vai para o inicio da lista
	- metodo de transposicao: o elemento buscado troca de posicao com o anterior dele , menos se o elemento buscado for o primeiro da lista
	- metodo de contagem: armazena um campo de contagem que sempre é incrementado pelo numero de vez buscado e a lista é ordenada de acordo com o campo
	
	 Metodo ordenado
	- A ordenacao da lista depende do campo de informacao. Ao contrario do metodo de contagem, neste tipo de ordenacao qualquer campo pode ser escolhido
*/

//exercicio 5:
	/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct sCELL{
	int info;
	struct sCELL *next;
}CELULA;

void inicializaLista(CELULA **ptrLista){
	(*ptrLista) = NULL;
}

int verificaListaVazia(CELULA **ptrLista){
	if((*ptrLista)==NULL){
		return 1;
	}
	return 0;
}

int move_PraFrente(CELULA **ptrLista, int elemento){
	CELULA *aux;
	CELULA *auxiliar;
	
	aux = (*ptrLista);
	
	if(verificaListaVazia(ptrLista)==1){
		printf("Impossivel mover pra frente, Lista Vazia.\n");
		return 0;
	}
	
	CELULA *antaux;
	CELULA *antantaux;
	while(aux!=NULL){
		if(aux->info == elemento){
			antaux->next = aux->next;
			aux->next = (*ptrLista);
			(*ptrLista) = aux;
			return 1;
		}
		antantaux = antaux;
		antaux = aux;
		aux = aux->next;
		return 1;
	}
}

int Transposicao(CELULA **ptrLista, int elemento){
	if(verificaListaVazia(ptrLista)==1){
		printf("Lista Vazia, Impossivel Transposicao.\n");
		return 0;
	}
	
	if((*ptrLista)->next == NULL){
		printf("Impossivel Transposicao, existe apenas um elemento na Lista.\n");
		return 0;
	}
	
	CELULA *aux;
	while(aux!=NULL){
		
		aux = aux->next;
	}
	
	return 1;	
}
int main(){
	CELULA *ptrLista;
	
	inicializaLista(&ptrLista);
	
	int a = move_PraFrente(&ptrLista,2);
	
	system("pause");
	return 0;
}*/

//exercicio 6:
/*	#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct sCELL{
	int info;
	struct sCELL *prev;
	struct sCELL *next;
}CELULA;
CELULA* criarCelula(){
	CELULA *nova = (CELULA*) malloc(sizeof(CELULA));
	return nova;
}
void inicializaLista(CELULA **ptrLista){
	(*ptrLista) = NULL;
}

int verificaListaVazia(CELULA **ptrLista){
	if((*ptrLista)==NULL){
		return 1;
	}
	return 0;
}

int insereK(CELULA **ptrLista, int elemento, int k){
	CELULA *nova= criarCelula();
	nova->info = elemento;
	nova->next = NULL;
	nova->prev = NULL;
	
	if(verificaListaVazia(ptrLista)==1){
		(*ptrLista) = nova;
		return 1;
	}
	
	int a=0;
	CELULA *aux = (*ptrLista);
	while(aux!=NULL){
		if(a == k){
			nova->next = aux->next;
			nova->prev = aux;
			aux->next = nova;
			return 1;
		}
		a++;
		aux = aux->next;
	}
	
	// se nao tiver posicao k insere no final.
	nova->next = aux->next;
	nova->prev = aux;
	aux->next = nova;
	return 1;
}

CELULA removeK(CELULA **ptrLista,int k){
	if(verificaListaVazia(ptrLista)==1){
		printf("Lista Vazia, impossivel remover");
	}
	CELULA removido;
	removido.info = -1;
	CELULA *aux;
	aux=(*ptrLista);
	int a=0;
	while(aux!=NULL){
		if(a == k){
			removido.info = aux->info;                   
			removido.next = aux->next;
			removido.prev = aux->prev;
			aux->prev->next = aux->next;
			aux->next->prev = aux->prev;
			free(aux);
			return removido;
		}
		a++;
		aux = aux->next;
	}
}

int insereOrdenado(CELULA **ptrLista, int elemento){
	CELULA *nova = criarCelula();
	nova->info = elemento;
	nova->prev = NULL;
	nova->next = NULL;
	
	CELULA *antaux, *antantaux;
	
	if(verificaListaVazia(ptrLista)==1){
		(*ptrLista) = nova;
		return 1;
	}else{
		CELULA *aux = (*ptrLista);
		while(aux!=NULL){
			if(aux->info >= nova->info){
				nova->next = aux;
				nova->prev = antaux;
				antaux->next = nova;
				aux->prev = nova;
				return 1;
			}
			antantaux = antaux;
			antaux = aux;
			aux = aux->next;
		}
		nova->next = NULL;
		nova->prev = aux;
		aux->next = nova;
		return 1;
	}
}

void liberaLista(CELULA **ptrLista){
	if(verificaListaVazia(ptrLista)==1){
		printf("Lista Vazia, impossivel liberar");
		return ;
	}else{
		CELULA *aux = (*ptrLista);
		while(aux!=NULL){
			free(aux);
			aux = aux->next;
		}
		return ;
	}
}

int main(){
	CELULA *ptrLista;
	
	inicializaLista(&ptrLista);

	int a = verificaListaVazia(&ptrLista);
		
	system("pause");
	return 0;
} */

//exercicio 7:
/*	#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//duplamente encadeada circular.
typedef struct sCELL{
	int info;
	struct sCELL *next;
	struct sCELL *prev;
}CELULA;

CELULA* criarCelula(){
	CELULA *nova = (CELULA*) malloc (sizeof(CELULA));
	return nova;
}

void inicializaLista(CELULA **ptrLista){
	(*ptrLista) = NULL;
	
}

int verificaListaVazia(CELULA **ptrLista){
	if((*ptrLista)==NULL){
		return 1;
	}
	return 0;
}

int insereInicio(CELULA **ptrLista, int elemento){
	CELULA *nova = criarCelula();
	nova->info = elemento;
	
	if(verificaListaVazia(ptrLista)==1){
		(*ptrLista) = nova;
		return 1;
	}else{
		nova->prev = (*ptrLista);
		nova->next = (*ptrLista)->next;
		(*ptrLista)->next = nova;
		nova->next->prev = nova;
		(*ptrLista) = nova;	
		return 1;
	}
	return 0;
}

int inserirFinal(CELULA **ptrLista, int elemento){
	CELULA *nova = criarCelula();
	nova->info = elemento;
	
	if(verificaListaVazia(ptrLista)==1){
		(*ptrLista) = nova;
		return 1;
	}else{
		nova->prev = (*ptrLista);
		nova->next = (*ptrLista)->next;
		(*ptrLista)->next->prev = nova;
		(*ptrLista)->next = nova;
		return 1;
	}
	return 0;
}

CELULA removeInicio(CELULA **ptrLista){
	CELULA removida;
	removida.info = -1;
	if(verificaListaVazia(ptrLista)==1){
		printf("Impossivel remover inicio, Lista Vazia");
		return removida;
	}else{
		CELULA *aux = (*ptrLista);
		removida.info = aux->info;
		removida.next = aux->next;
		removida.prev = aux->prev;
		
		//modificando a lista
		aux->prev->next = aux->next;
		aux->next->prev = aux->prev;
		(*ptrLista) = aux->prev;		
		return removida;
	}
	return removida;
}

CELULA removeFinal(CELULA **ptrLista){
	CELULA removida;
	CELULA *aux;
	aux = (*ptrLista);
	
	removida.info = -1;
	
	if(verificaListaVazia(ptrLista)==1){
		printf("Erro.\n");
		return removida;
	}else{
		//inserindo informação na removida
		removida.info = aux->next->info;
		removida.next = aux->next;
		removida.prev = aux->next->prev;
		
		//atualizando a lista
		aux->next = aux->next->next;
		aux->next->next->prev = aux;
		
		//liberando a celula;
		aux = aux->next;
		free(aux);
		return removida;
	}
}

void liberaLista(CELULA **ptrLista){
	if(verificaListaVazia(ptrLista)==1){
		printf("Erro, lista vazia.\n");
		return ;
	}
	
	CELULA *aux;
	aux = (*ptrLista);
	
	while(aux->next!=aux){
		free(aux);
		aux = aux->next;
	}
	free(aux);
}

int main(){
	CELULA *ptrLista;
	int elemento;
	
	inicializaLista(&ptrLista);
	
	insereInicio(&ptrLista,elemento);
	
	system("pause");
	return 0;
}*/


