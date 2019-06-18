#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct v{
  int num, ano;
  char nome[100];
}aviao;

typedef struct scell{
  aviao info;
  struct scell *next;
}celula;

typedef struct f{
  celula *ini, *fim;
  int num;
}fila;

void inicializar(fila *f){
  f->ini = NULL;
  f->fim = NULL;
  f->num=0;
}

int vazia(fila *f){
  if (f->ini == NULL){ return 1;}
  return 0;
}


int enfileirar(fila *f, aviao n){
  celula *nova = (celula*) malloc (sizeof(celula));
  nova->info = n;
  nova->next = NULL;
  f->num ++;
  
  if (f->ini == NULL){
    f->ini = nova;
    f->fim = nova;
    return 1;
  }
  f->fim->next = nova;
  f->fim = nova;
  return 1;
}

aviao desenfileirar(fila *f){
  aviao invalido;
  invalido.num=-1;
  if (vazia(f)){
    return invalido; // Erro
  }
  
  celula *removida = f->ini;
  aviao removido = f->ini->info;
  f->num--;
  
  if (f->ini == f->fim){
    f->ini = NULL;
    f->fim = NULL;
    f->num = 0;
    free(removida);
    return removido;
  }
  
  f->ini = f->ini->next;
  free(removida);
  return removido;
}

int numero(fila *f){
  return f->num;
}

void caracteristicas(fila *f){
  if (f->ini != NULL){
    printf("\nAVIAO: \n");
    printf("Nome: ");
    puts(f->ini->info.nome);
    printf("Codigo: %d\n", f->ini->info.num);
    printf("ano: %d", f->ini->info.ano);
  }
}

int main(){
  fila f;
  inicializar(&f);
  
  aviao tmp;
  tmp.num=1;
  strcpy(tmp.nome, "Gol");
  tmp.ano=11997;
  
  enfileirar(&f, tmp);
  enfileirar(&f, tmp);
  
  desenfileirar(&f);
  
  printf("numero de avioes: %d\n", numero(&f));
  
  caracteristicas(&f);
  
  system("pause>nul");
  return 0;
}
