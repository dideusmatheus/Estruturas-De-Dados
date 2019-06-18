#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct r_hq{
	char nome[10];
	int pag;
}hq;

typedef struct r_celula{
	hq info;
	struct r_celula* next;
}celula;

// Inicia a pilha
void start(celula **p){
	(*p) = NULL;
}

//Vazia
int empty(celula **p){
	if ((*p) == NULL){
		return 1;
	}
	return 0;
}

// Retorna o topo
hq topo(celula **p){
	hq t;
	t.pag = -1;
	strcpy(t.nome, "err");
	if (empty(p)){
		return t;
	}
	
	t.pag = (*p)->info.pag;
	strcpy(t.nome, (*p)->info.nome);
	return t;
}

// Insere - PUSH
int push(celula **p, hq a){
	celula *nova = (celula*) malloc (sizeof(celula));
	nova->next = NULL;
	strcpy(nova->info.nome, a.nome);
	nova->info.pag = a.pag;
	nova->next = (*p);
	(*p) = nova;
	return 1;
}

hq pop(celula **p){
	hq rem;
	rem.pag = -1;
	strcpy(rem.nome, " ");
	if (empty(p)){return rem;}
	
	celula *removida = (*p);
	rem.pag = (*p)->info.pag;
    strcpy(rem.nome, (*p)->info.nome);
	(*p) = (*p)->next;
	return rem;
}

hq add(){
	hq a;
	//system("cls");
	printf("Digite o nome: ");
	fflush(stdin);
	gets(a.nome);
	printf("Digite o numero de paginas: ");
	scanf("%d", &a.pag);
	return a;
}

void printDel(celula **p){
    while(!empty(p)){
        printf("\nNome = ");
        puts((*p)->info.nome);
        printf("\nNumero de paginas: %d\n", (*p)->info.pag);
        pop(p);
	}
}

// Printa sem mudar nada
void print(celula **p){
    celula *p2;;
    p2 = NULL; // iniciei a pilha
    while(!empty(p)){
        printf("\nNome = ");
        puts((*p)->info.nome);
        printf("\nNumero de paginas: %d\n", (*p)->info.pag);
        push(&p2, pop(p));
	}
	while(!empty(&p2)){
        push(p, pop(&p2));
	}
}


// Printa inverso sem mudar nada
void printInv(celula **p){
    celula *aux;
    aux = NULL;
    while(!empty(p)){
        push(&aux, pop(p));
	}
	while(!empty(&aux)){
        printf("\nNome = ");
        puts(aux->info.nome);
        printf("\nNumero de paginas: %d\n", aux->info.pag);
        push(p, pop(&aux));
	}
	
}

// Inverte a pilha
void reverse(celula **p){
    celula *p2;
    p2 = NULL;
    while((*p) != NULL){
        push(&p2, pop(p));
	}
	(*p)= p2;
}

/*
// Inserir na opsição K
int insertK(celula **p, hq ala, int k){
    int cont = 0;
    celula *nova = (celula*) malloc (sizeof(celula));
    if (nova == NULL){return -1;}
    nova->info.pag = ala.pag;
    strcpy(nova->info.nome, ala.nome);
    nova->next = NULL;
    
    //Inserir inicio
    if (k == 0){
      nova->next = (*p);
      (*p) = nova;
      return 1;
	}
    
    celula *pilha2 = NULL;
    while(!empty(p)){
      if (cont == k){
	    push(&pilha2, nova);
	  }else{
	    push(&pilha2, pop(p));
	  }
	  cont++;
	}
    
    //Voltar para pilha original
    while (pilha2 != NULL){
      push(p, pop(&pilha2));
	}
    
    return 1;
}
*/
int compara(celula **pilha1, celula **pilha2){
  celula *pilhaAux1, *pilhaAux2; // Duas pilhas auxiliares para guardar o valor retirado
  pilhaAux1 = NULL;  
  pilhaAux2 = NULL;
  
  int erro=1; // Valor que sera retornado
  
  hq conteudo1, conteudo2; //É Receber o que foi removido das pilhas
  
  while ((*pilha1) != NULL && (*pilha2)!= NULL){
    conteudo1 = pop(pilha1);
    conteudo2 = pop(pilha2);
    
    push(&pilhaAux1, conteudo1);
    push(&pilhaAux2, conteudo2);
    
    if (conteudo1.pag != conteudo2.pag){
         erro = 0;
         break;
    }
  }
  
  // Checar se uma pilha foi maior que a outra
  if ((*pilha1)==NULL && (*pilha2)==NULL){
      printf("Piilhas iguais");
  }else{
    erro = 0;  
  }
  
  // Passar as pilhas pilhas auxiliares para as pilhas originais
  hq retorno;
  while (pilhaAux1 != NULL){
    retorno = pop(&pilhaAux1);
    push(pilha1, retorno);
  }
  
  while (pilhaAux2 != NULL){
    retorno = pop(&pilhaAux2);
    push(pilha2, retorno);
  }
  
  return erro;

}

int main(){
	celula *pilha;
	celula *pilha2;
	
    start(&pilha);
    start(&pilha2);
	hq d;
	int a;
	for (a=0;a<3;a++){
		printf("\nInserir na pilha1\n");
	    d = add();
		push(&pilha, d);
		printf("\nInserir na pilha2\n");
		d=add();
		push(&pilha2, d); 
    }
    
    
    system("cls");
    printf("Pilha 1: \n");
    print(&pilha);
    
    printf("\n\nPilha 2: \n");
    print(&pilha2);
    
	printf("\nComparacao = %d", compara(&pilha, &pilha2));

	
	system("pause");
	return 0;
}
