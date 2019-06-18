#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct sLivro
{
	char nome[50];
	char autor[50];
	int np;	
}Livro;		

void preencher(Livro *p, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		gets(p[i].nome);
		fflush(stdin);
		gets(p[i].autor);
		fflush(stdin);
		scanf("%d", &p[i].np);
	}
}

void informar(Livro *p, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		puts(p[i].nome);
		puts(p[i].autor);
		printf("%d\n", p[i].np);
	}
}

void a(Livro *p, char autor, int n)
{
	int i,ret;
	for(i=0;i<n;i++)
	{
		ret = strcmp (autor,p[i].autor);
		if (ret == 0)
			puts(p[i].nome);
	}
}

void imprimir(Livro *p, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(p[i].np > 50)
			printf("%d", p[i].np);
	}
}

int main()
{
	Livro *p;
	int i,n,x;
	char autor[50];
	printf("Quantos livros?");
	scanf("%d", &n);
	p = (Livro*) malloc (n*sizeof(Livro));
	preencher(p,n);
	printf("Quer a informação de quantos livros?");
	scanf("%d", &x);
	informar(p,x);
	printf("Qual o autor vc deseja consultar?");
	fflush(stdin);
	gets(autor);
	a(p,autor,n);
	imprimir(p,n);
	
	system("pause");
	return 0;
	
}
