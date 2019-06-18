#include <stdio.h>
#include <stdlib.h>

typedef struct sItem{
	char nome[20];
	float preco;
}Item;

typedef struct sLista{
	Item elem[max_tam];
	int ultimo;
}Lista;

void iniciarLista(Lista *lista){ // INICIAR LISTA
	lista->ultimo=-1;
}

int listaCheia(Lista *lista){  // VERIFICAR SE ESTA CHEIA
	if(lista->ultimo==(max_tam-1)){
		return 1;
	}
	return 0;
}

int listaVazia(Lista *lista){ // VERIFICAR SE ESTA VAZIA
	if(lista->ultimo==-1){
		return 1;
	}
	return 0;
}

int inserirFinal(Lista *lista , Item elem){ // INSERIR ELEMENTO NO FINAL
	if(listaCheia(lista)){
		return 0;
	}
	lista->elem[lista->ultimo+1]=elem;
	lista->ultimo=(lista->ultimo+1);
	return 1;
}

int mudarElemento(Lista *lista , int posicao , item elem){ // MUDAR ELEMENTO EXISTENTE
	if(posicao<0 || posicao>lista->ultimo){
		return 0;
	}
	lista->elem[posicao]=elem;
	return 1;
}

int removerElemento(Lista *lista, int posicao){ // REMOVER ELEMENTO POSICAO K
	int i;
	if(listaVazia(lista)){
		return 0;
	}
	if(posicao<0 || posicao>lista->ultimo){
		return 0;
	}	
	for(i=posicao;i<lista->ultimo; i++){ // mover os elementos posteriores ao removido
		lista->elem[i]=lista->elem[i+1];
	}
	lista->ultimo--;
}

Item acessarElemento(Lista *lista, int posicao){ // ACESSAR ELEMENTO POSICAO K
	if(listaVazia(lista)){
		return 0;
	}
	if(posicao<0 || posicao > lista->ultimo){
		return ;
	}
	return lista->elem[posicao];
}

int pesquisarElemento(Lista *lista,Item elem){ // PESQUISAR ELEMENTO NA LISTA
	int i;
	if(listaVazia(lista)){
		return 0;
	}
	for(i=0;i<=lista->ultimo;i++){
		if(lista->elem[i]==elem){
			return i;
		}
	}
	return -1;
}

int tamanhoLista(Lista *lista){ // RETORNA TAMANHO DA LISTA
	return lista->ultimo+1;
}




































