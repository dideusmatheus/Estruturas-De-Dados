#include <stdio.h>
#include <stdlib.h>

typedef struct sEspadachim{
	char apelido[30];
	int elemento[30];
	int forca;
}Espadachim;

typedef struct sCell{
	Espadachim info;
	struct sCell *next;
}CELULA;

typedef struct sFila{
	CELULA *cabecario;
	CELULA *ultimo;
}FILA;

int filaVazia(FILA *f){
	if(f->cabecario==NULL && f->ultimo==NULL){
		printf("fila vazia");
		return 1;
	}
	
	return 0; 
}

void iniciarFila(FILA *f){
	f->cabecario=NULL;
	f->ultimo=NULL;
}

CELULA *criarCelula(){
	CELULA *nova;
	nova=(CELULA*)malloc(sizeof(CELULA));
	return nova;
}

int enfileirar(FILA *f,Espadachim elem){
	CELULA *nova=criarCelula();
	
	if(nova==NULL){
		return 0;
	}	
	nova->info=elem;
	nova->next=NULL;
	
	if(filaVazia(f)){
		f->cabecario=nova;
		f->ultimo=nova;
		return 1;	
	}
	
	f->ultimo->next=nova;
	f->ultimo=nova;
}

int desenfileirar(FILA *f){
	CELULA *aux;
	aux->next==NULL;
	
	if(aux==NULL){
		return 1;
	}
	
	if(filaVazia(f)){
		return 0;
	}
	
	if(f->cabecario->next!=NULL){
		aux=f->cabecario;
		f->cabecario=f->cabecario->next;
		free(aux);
	}
	
	free(f->cabecario);
	
}

int imprimirInicio(FILA *f){
	Espadachim e;
	if(filaVazia(f)){
		return 0;
	}
	
	if(f->cabecario->next!=NULL){
	
		gets(e.apelido);
		gets(e.elemento);
		printf("%d",&e.forca);
		
		f->cabecario=f->cabecario->next;	
	}
	
	gets(e.apelido);
	gets(e.elemento);
	printf("%d",&e.forca);
}

int imprimirFilaAux(FILA *f){
	FILA aux;
	iniciaFila(&aux);
	Espadachim t;
	
	if(filaVazia(f)){
		printf("Nao ha espadachins para mostrar.\n");
	}	
	
	while(f->cabecario != NULL){
		t = desenfileirar(f);
		printf("\n\nNome: %s\nElemento: %d\nForca: %d\n", temp.apelido , temp.elemento , temp.forca);		
		enfileirar(&aux , t);
	}
	while(aux.inicio != NULL){
		t = desenfileirar(&aux);
		enfileirar(fila , t);
	}
}

void liberarFila(FILA *f){
	Espadachim aux;
	if(verificaVazia(f)){
			printf("Sem Espadachim no continente!");
		}else{
			aux=desenfileirar(f);
			printf("Espadachim deletado: ");
			puts(aux.apelido);
			printf("\nElemento: %d", aux.elemento);
			printf("\nForca: %d", aux.forca);
			}
}

int integrandes(FILA *f){
	int A=0;
	FILA aux;
	iniciarFila(&aux);
	Espadachim t;
	
	if(filaVazia(f)){
		return 0;
	}
	
	while(f->cabecario!=NULL){
		t=desenfileirar(f);
		enfileirar(&aux, t);
		A++;
	}
	while(aux.cabecario!=NULL){
		t=desenfileirar(&aux);
		enfileirar(f,t);
	}
	return A;
}

void comecarTorneio(FILA* *fAB, FILA *fCD){
	int i,j;
	int forca1, forca2;
	
	Espadachim AB,CD,CAMPEAO;
	
	i=integrandes(fAB);
	j=integrandes(fCD);
	
	if(1>i || i>3){
		printf("Continente AB: sem espadachins");
		return 0;
	}
	if(1>j || j>3){
		printf("Continente CD: sem espadachins");
		return 0;
	}
	
	do{
		AB=desenfileirar(fAB);
		CD=desenfileirar(fCD);
	
		if(AB.elemento=CD.elemento){
			AB.forca= AB.forca;
			CD.forca=CD.forca
		}
		
		if(AB.elemento+1==CD.elemento || AB.elemento+3==CD.elemento){
			forca1=AB.forca+((AB.forca/100)*10);
		}
		if(CD.elemento+1==AB.elemento || CD.elemento+3==AB.elemento){
			forca2=AB.forca+((AB.forca/100)*10);
		}
		
		printf("Atributos espadachim cont AB");
		puts(AB.apelido);
		printf("\nElemento: %d",AB.elemento);
		printf("\Forca: %d",AB.forca);
		printf("\n\n-------VERSUS-------\n");
		printf("\nAtributos espadachim cont CD:\n");
		puts(CD.apelido);
		printf("\nElemento: %d",CD.elemento);
		printf("\Forca: %d",CD.forca);
		printf("")
		
	
		if(AB.forca > CD.forca){
			printf("\n\n\nEspadachim cont AB: GANHOU!\n");
			Enfileirar(filaAB , AB);
			j--;
		}else
		if(CD.forca > AB.forca){
			printf("\n\n\nEspadachim cont CD: GANHOU!\n");
			Enfileirar(filaCD , CD);
			i--;
		}
	}while(i != 0 && j != 0);
			
		
		
			
}


int main(){
	FILA contAB;
	FILA contCD;
	
	Espadachim t, remover,aux;
	int verificar,x;
	
	iniciarFila(&contAB);
 	filaVazia(&contAB);
 	
 	printf("\n\nNumeros dos elementos:\n[1] Ar\n[2] Agua\n[3] Fogo\n[4] Terra\n");
	
	do{
		printf("\n\n1-Verificar se o continente esta vazio:");
		printf("\n2-Adicionar mais um espadachim:");
		printf("\n3-Remover o primeiro espadachim:");
		printf("\n4-Visualizar o primeiro espadachim inscrito:");
		printf("\n5-Visualizar todos os espadachins:");
		printf("\n6-Excluir todos os espadachins do continente:");
		printf("       >> 7 << Para iniciar o Torneio!");
		scanf("%d",&x);
		
		switch(x);
		
			case 1:
				printf("Continente AB: 1 \tContinente CD:2");
				scanf("%d",&x);
				if(x==1){
					verificar=filaVazia(&contAB);
					if(verifica==1){
						printf("Continente AB vazio");
					}else{
						printf("Continente AB cheio");
					}
				}else{
					verifica=filaVazia(&contCD);
					if(verifica==1){
						printf("Continente CD vazio");
					}else{
						printf("Continente CD cheio");
					}
				}
				break;
			case 2:
				printf("Espadachim de qual continente?\n 1-AB\t 2-CD");
				scanf("%d",&x);
				if(x==1){
					fflush(stdin);
					printf("Nome Espadachim: ");
					gets(t.apelido);
					t.elemento=rand()%4+1;
					t.forca=rand()%200+900;
					printf("Forca: %d",t.forca);
					printf("Elemento: %d",t.elemento);
					enfileirar(&contAB,t);
				}else{
					fflush(stdin);
					printf("Nome Espadachim");
					gets(t.apelido);
					t.elemento=rand()%4;
					t.forca=rand()%200+900;
					printf("Forca: %d",t.forca);
					printf("Elemento: %d", t.elemento);
					enfileirar(&contCD,t);

				}
				break;
				
			case 3:
				printf("\nExcluir espadachim de qual conti?\n 1-AB\t 2-CD");
				scanf("%d",&x);
				if(x == 1){
					remover = desenfileirar(&contAB);
					if(remover.elemento != -1){
						printf("Nome: %s\nElemento: %d\nForca: %d\n", remover.apelido , remover.elemento , remover.forca);
					}else{
						printf("Erro!");
					}
									
				}else{
					remover = desenfileirar(&contCD);
					if(remover.elemento != -1){
							printf("Nome: %s\nElemento: %d\nForca: %d\n", remover.apelido , remover.elemento , remover.forca);
					}else{
						printf("Erro!");
					}
				}
				break;
			case 4:
				printf("\nEspadachim de qual cont?\n 1-AB\t 2-CD");
				scanf("%d",&x);
				if(x == 1){
					imprimirFila(&contAB);
				}else{
					imprimirFila(&contCD);
				}
				break;
			case 5:
				printf("\nEspadachim de qual cont?\n 1-AB\t 2-CD");
				scanf("%d",&x);
				if(x == 1){
					imprimirInicio(&contAB);
				}else{
					imprimirInicio(&contCD);
				}
				break;
			case 6:
				printf("\nEspadachim de qual cont?\n 1-AB\t 2-CD");
				scanf("%d",&x);
				if(x == 1){
					liberarFila(&contAB);
				}else{
					liberarFila(&contCD);
				}
				break;	
			case 7:
				iniciaTorneio(&contAB , &contCD);
				
				
				
				
		}while(x!=0);	

	return 0;
}
