#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct scel{
  char info;
  struct scel *next, *ant;
}celula;

typedef struct d{
  celula *ini, *fim;
}deque;

void inicializar(deque *d){
  d->ini = NULL;
  d->fim = NULL;
}

int vazia(deque *d){
  if (d->ini == NULL){
    return 1;
  }
  return 0;
}

int inserirInicio(deque *d, char n){
  celula *nova = (celula*) malloc (sizeof(celula));
  if (nova == NULL)
  	{return 0;}
   // Checa se teve espaço o suficiente para criar celula
  nova->info = n;
  nova->next = d->ini;
  nova->ant = NULL;
  
  if (d->ini == NULL){
    d->ini = nova;
    d->fim = nova;
    return 1;
  }
   
  d->ini->ant = nova;
  d->ini = nova;
  
  return 1;
}


char removerInicio(deque *d){
  char invalido;
  invalido= 'z'; // Item invalido
  // Nao consigo remover se a pilha estiver vazia
  if (d->ini == NULL){
      return invalido; 
  }
  
  celula *removida = d->ini; // Primeiro item da pilha sera removido
  char itemRemovido = d->ini->info; // Item removido está no inicio da pilha
  
  if (d->ini == d->fim){
    d->fim = NULL;
    d->ini = NULL;
  }else{
    d->ini = d->ini->next;
    d->ini->ant = NULL;
  }
  
  free(removida);
  return itemRemovido;
}


//Mostra em ordem normal
void mostrar(deque *d){
  if (d->ini ==  NULL){
      return;
  }
  
  deque d2;       // Criei pilha auxiliar para receber os itens da pilha original
  inicializar(&d2); // Inicializei a pilha auxiliar
  
  char temp; // Função dele, é pegar o item que será removido da pilha originial
  do {
    printf("%c", d->ini->info); // Mostra o item do topo
    temp = removerInicio(d);
    inserirInicio(&d2, temp);
  }while(d->ini != NULL);
  
  //volto para pilha normal
  do{
    inserirInicio(d, removerInicio(&d2));
  }while(d2.ini != NULL);
}


//recebe a string e coloca na pilha
void string2deque(deque *d1){
  //Pego a string
  printf("Digite a string:   ");
  char nome[100];
  fflush(stdin);
  gets(nome);
  
  //Coloco ela na pilha
  int a=0;
  while(nome[a] != '\0'){
    inserirInicio(d1, nome[a]);
    a++;
  }
}


int palindromo(deque *d){
  if (d->ini == NULL){return 0;} // Nao tem nada, entao nao é palindromo
  
  //Crio uma nova pilha, sem pontos ou espaços.
  char tmp;
  deque d1;
  d1.ini = NULL; d1.fim = NULL;
  
  while (d->ini != NULL){
    tmp = removerInicio(d); 
    if (tmp != ' ' && tmp != '.'){
      inserirInicio(&d1, tmp);
	}
  }
  //DAQUI EM DIANTE, P1, é uma pilha inversa da original, sem pontos ou espaços.
  
  //Crio 2 pilhas para criar uma pilha inversa, para poder compará-las:
  deque d2, d3; 
  inicializar(&d2); inicializar(&d3);
  // A minha "P2", terá a pilha normal, enquanto a "P3", tera a inversa:
  
  while (d1.ini != NULL){
    tmp = removerInicio(&d1);
    inserirInicio(&d2, tmp);
    inserirInicio(&d3, tmp);
  }
  
  //Inverto uma delas
  while(d2.ini != NULL){
    inserirInicio(&d1, removerInicio(&d2));
  }
  
  //Colocar na pilha auxiliar (P2) agora, para teste de palindromo, comparando p1 e p3:
  char tmp1, tmp3;
  int retorno = 1; // vira zero, caso encontre um char diferente.
  while (d3.ini != NULL){
    tmp1 = removerInicio(&d1);
    tmp3 = removerInicio(&d3);
    
    // ja coloco o p1 na pilha original, para ela nao ficar vazia
    inserirInicio(d, tmp1);
    
    //Checo se sao iguais
    if (tmp1 != tmp3){
	  retorno = 0;
      break;
	}
  }
  
  //Insiro o restante da pilha p1 na original
  while (d1.ini != NULL){
    inserirInicio(d, removerInicio(&d1));
  }
  
  return retorno;
}


int main(){
  
  deque d;
  inicializar(&d);
  
  string2deque(&d);
  
  //Imprimir em ordem inversa:
  printf("Palavra invertida: ");
  mostrar(&d);
  
  
  //Ver se é palindroma
  int a = palindromo(&d);
  if (a==1){
    printf("\nSao palindromas!");
  }else{
    printf("\nNao sao palindromas!");
  }
  
  system("pause>nul");
  return 0;
}








