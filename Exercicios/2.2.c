#include<stdio.h>

int dobro(int *p)
{
	int dobro;
	dobro = *p * 2;
	return(dobro);
}	

int main()
{
	int n,resultado;
	int *p;
	scanf("%d", &n);
	p = &n;
	resultado = dobro(p);
	printf("Resultado = %d\n", resultado);
	
	return 0;
}
