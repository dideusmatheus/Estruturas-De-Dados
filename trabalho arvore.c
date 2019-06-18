#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sAluno{
	int matricula;
	char nome[20];
	char curso[30];
	char email[25];
}ALUNO;

typedef struct sNo{
	ALUNO info;
	struct sNo *esq;
	struct sNo *dir;	
}NO;

void inicializar(NO **raiz){  // INICIAR ARVORE
	*raiz = NULL;
}

int ArvoreVazia(NO **raiz){ // ARVORE VAZIA
	if(*raiz == NULL){
		return 1;
	}
	return 0;
}

NO* CriarNo(){ // CRIAR NO
	NO *novo = (NO*)malloc(sizeof(NO));
	return novo;
}

int InserirIterativo(NO **raiz, ALUNO i){ // INSERIR ITERATIVO
	NO *novo = criarno();
	if(novo == NULL)
		return 0;
	novo->info = i;
	novo->dir = NULL;
	novo->esq = NULL;
	
	if(arvorevazia(raiz)){
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

void InserirRecursivo(NO **raiz, ALUNO i){ // INSERIR RECURSIVO
	NO *novo = criarno();
	if(novo == NULL){
		novo->info = i;
		novo->dir = NULL;
		novo->esq = NULL;
	}
	if(arvorevazia(raiz)){
		*raiz = novo;	
		return;
	}
	if(i.matricula < (*raiz)->info.matricula){
		inserirrecursivo(&(*raiz)->esq, i);
	}
	if(i.matricula > (*raiz)->info.matricula){
		inserirrecursivo(&(*raiz)->dir, i);
	}
}

NO *MenorDireita(NO **no){
    if((*no)->dir != NULL) 
       return MenorDireita(&(*no)->dir);
    else{
       NO *aux = *no; 
       if((*no)->esq != NULL) 
          *no = (*no)->esq;
       else
          *no = NULL;
       return aux;
       }
}

void remover1(NO **raiz, ALUNO i){
	NO *aux;
	if(arvorevazia(raiz)){
		printf("Erro: arvore vazia!");
		return;
	}
	if(i.matricula < (*raiz)->info.matricula)
		remover1(&(*raiz)->esq, i);
	else
		if(i.matricula > (*raiz)->info.matricula)
			remover1(&(*raiz)->dir, i);
		else{
			aux = *raiz;
		}
		if(((*raiz)->esq == NULL) && ((*raiz)->dir == NULL)){

			free(aux);
			(*raiz) = NULL;
		}
		else{
			if((*raiz)->esq == NULL){
				(*raiz) = (*raiz)->dir;
				aux->dir = NULL;
				free(aux);
			
				}
				else{
					aux = MenorDireita(&(*raiz)->esq);
					aux->esq = (*raiz)->esq;
					aux->dir = (*raiz)->dir;
					free((*raiz));
					*raiz = aux;
				}
			}
		
		
}

NO *MaiorEsquerda(NO **no){
    if((*no)->esq != NULL) 
       return MaiorEsquerda(&(*no)->esq);
    else{
       NO *aux = *no;
       if((*no)->dir != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
          *no = (*no)->dir;
       else
          *no = NULL;
       return aux;
       }
}

void remover2(NO **raiz, ALUNO i){
	NO *aux;
	if(arvorevazia(raiz)){
		printf("Erro: arvore vazia!");
		return;
	}
	if(i.matricula < (*raiz)->info.matricula)
		remover1(&(*raiz)->esq, i);
	else
		if(i.matricula > (*raiz)->info.matricula)
			remover1(&(*raiz)->dir, i);
		else{
			aux = *raiz;
		}
		if(((*raiz)->esq == NULL) && ((*raiz)->dir == NULL)){
			free(aux);
			(*raiz) = NULL;
		}
		else{
			if((*raiz)->esq == NULL){
				(*raiz) = (*raiz)->dir;
				aux->dir = NULL;
				free(aux);
			}
			else{
				if((*raiz)->dir == NULL){
					(*raiz) = (*raiz)->esq;
					aux->esq = NULL;
					free(aux);
				}
				else{
					aux = MaiorEsquerda(&(*raiz)->dir);
					aux->esq = (*raiz)->esq;
					aux->dir = (*raiz)->dir;
					free((*raiz));
					*raiz = aux;
				}
			}
		}		
}

NO *Pesquisar(NO *raiz, ALUNO a){
	if(raiz == NULL){
		return NULL;
	}
	if(raiz->info.matricula == a.matricula){
		return raiz;
	}
	else if(raiz->info.matricula > a.matricula){
		return(pesquisar(raiz->esq, a));
	}else{
		return(pesquisar(raiz->dir, a));
	}
}

void AlteraCurso(NO *raiz, ALUNO al){
	if(arvorevazia(&raiz)){
		printf("Erro!");
		return;
	}
	
	NO *aux = pesquisar(raiz, al);
	if(aux == NULL){
		printf("Matricula nao existe.");
		return;
	}
	printf("\nDigite o novo nome do curso: ");
	fflush(stdin);
	scanf("%s", &al.curso);
	fflush(stdin);
	strcpy(aux->info.curso, al.curso);
}

void AlteraEmail(NO *raiz, ALUNO alu){
	if(arvorevazia(&raiz)){
		printf("Erro!");
		return;
	}
	NO *aux = pesquisar(raiz, alu);
	if(aux == NULL){
		printf("Matricula nao existe.");
		return;
	}
	printf("Digite o novo nome do email: ");
	fflush(stdin);
	scanf("%s", &alu.email);
	fflush(stdin);
	strcpy(aux->info.email, alu.email);
}

void Imprimir(NO *raiz){
	printf("\nMatricula: %d", raiz->info.matricula);
	fflush(stdin);
	printf("\nNome: %s", raiz->info.nome);
	fflush(stdin);
	printf("\nCurso: %s", raiz->info.curso);
	fflush(stdin);
	printf("\nEmail: %s", raiz->info.email);
	fflush(stdin);
}

void ImprimirPelaMatricula(NO *raiz){
	NO *aux;
	aux = raiz;
	if(raiz!= NULL){
		if(aux->info.matricula<raiz->info.matricula){
			imprimirpelamatricula(raiz->esq);
			printf("Matrícula: %d", raiz->info.matricula);
			printf("Nome: %s", raiz->info.nome);
			printf("Curso: %s", raiz->info.curso);
			printf("Email: %s", raiz->info.email);
			imprimirpelamatricula(raiz->dir);
		}
	}
}

void ImprimirFolhas(NO *raiz){
	if(raiz == NULL){
		imprimirfolhas(raiz->esq);
		imprimirfolhas(raiz->dir);
		printf("\nMatricula: %d", raiz->info.matricula);
		fflush(stdin);
		printf("\nNome: %s", raiz->info.nome);
		fflush(stdin);
		printf("\nCurso: %s", raiz->info.curso);
		fflush(stdin);
		printf("\nEmail: %s", raiz->info.email);
		fflush(stdin);
	}
}


int main(){
	NO *raiz;
	inicializar(&raiz);
	int op;
	ALUNO n;
	do{
		printf("Menu:");								//MENU DE OPÇÕES	
		printf("\n1 - Inserir iterativo");
		printf("\n2 - Inserir recursivo");
		printf("\n3 - Remover 1 (Menor direita)");
		printf("\n4 - Remover 2 (Menor esquerda)");
		printf("\n5 - Pesquisar");
		printf("\n6 - Alterar curso");
		printf("\n7 - Alterar email");
		printf("\n8 - Imprimir alunos pela matricula em ordem crescente");
		printf("\n9 - Imprimir apenas alunos em nos folhas");
		printf("\n0 - Sair\n");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("\n Inserir iterativo:");
				printf("\nDigite a matricula do aluno: ");
				scanf("%d", &n.matricula);
				printf("\nDigite o nome do aluno: ");
				fflush(stdin);
				scanf("%s", &n.nome);
				fflush(stdin);
				printf("\nDigite o curso do aluno: ");
				fflush(stdin);
				scanf("%s", &n.curso);
				fflush(stdin);
				printf("\nDigite o email do aluno: ");
				fflush(stdin);
				scanf("%s", &n.email);
				fflush(stdin);
				inseririterativo(&raiz, n);
				system("pause>>null");
				break;
			case 2:
				printf("\n Inserir recursivo:");
				printf("\nDigite a matricula do aluno: ");
				scanf("%d", &n.matricula);
				printf("\nDigite o nome do aluno: ");
				fflush(stdin);
				scanf("%s", &n.nome);
				fflush(stdin);
				printf("\nDigite o curso do aluno: ");
				fflush(stdin);
				scanf("%s", &n.curso);
				fflush(stdin);
				printf("\nDigite o email do aluno: ");
				fflush(stdin);
				scanf("%s", &n.email);
				fflush(stdin);
				inserirrecursivo(&raiz, n);
				system("pause>>null");
				break;
			case 3:
				printf("Remover 1 (Menor direita)");
				printf("\nDigite a matricula do aluno: ");
				scanf("%d", &n.matricula);
				remover1(&raiz, n);
				printf("Removido com sucesso");
				system("pause>>null");
				break;
			case 4:
				printf("Remover 3 (Maior esquerda)");
				printf("\nDigite a matricula do aluno: ");
				scanf("%d", &n.matricula);
				remover2(&raiz, n);
				system("pause>>null");
				break;
			case 5:
				printf("Pesquisar: ");
				printf("\nDigite a matricula do aluno: ");
				scanf("%d", &n.matricula);
				pesquisar(raiz, n);
				system("pause>>null");
				break;
			case 6:
				printf("Alterar curso: ");
				printf("\nDigite a matricula do aluno: ");
				scanf("%d", &n.matricula);
				alteracurso(raiz, n);
				system("pause>>null");
				break;
			case 7:
				printf("Alterar email: ");
				printf("\nDigite a matricula do aluno: ");
				scanf("%d", &n.matricula);
				alteraemail(raiz, n);
				system("pause>>null");
				break;
				
			case 8:
				printf("Imprimindo pela matrícula:\n");
				imprimirpelamatricula(raiz);
				//imprimir(raiz);
				system("pause>>null");
				break;
			case 9:
				printf("Imprimindo folhas:\n");
				imprimirfolhas(raiz);
				system("pause>>null");
				break;
			default:
				printf("opcao invalida!\n Digite novamente: ");
				break;
			
			
		}
		
	}while(op!=0);
	return 0;
}

