#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sAluno
{
	char nome[50];
	int mat;
	int an;
	float n1,n2,n3;
}Aluno;

void reprovados(Aluno *a, int n)
{
	float total,media;
	int i;
	printf("Alunos reprovados:\n");
	for(i=0;i<n;i++)
	{
		total = (a[i].n1 + a[i].n2 + a[i].n3);
		media = (total/3);
		if(media < 60)
			puts(a[i].nome);
	}
}

void maiornota2(Aluno *a, int n)
{
	int i,cont;
	float maior = 0;
	for(i=0;i<n;i++)
	{
		if(a[i].n2 > maior)
		{	
			maior = a[i].n2;
			cont = i;
		}
	}	
	printf("O aluno com maior nota da prova 2 e: ");
	puts(a[cont].nome);
}


int main()
{
	Aluno *a;
	int n,i;
	printf("Quantos alunos?");
	scanf("%d", &n);
	a = (Aluno*) malloc (n*sizeof(Aluno));
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		gets(a[i].nome);
		fflush(stdin);
		scanf("%d", &a[i].mat);
		scanf("%d", &a[i].an);
		scanf("%f", &a[i].n1);
		scanf("%f", &a[i].n2);
		scanf("%f", &a[i].n3);
	}
	reprovados(a,n);
	maiornota2(a,n);
	
	system("pause");
	return 0;
}
