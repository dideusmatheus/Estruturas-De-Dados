#include<stdio.h>

int dobro(int n)
{
	int dobro;
	dobro = n+n;
	return(dobro);
}	

int main()
{
	int n,resultado;
	scanf("%d", &n);
	resultado = dobro(n);
	printf("Resultado = %d\n", resultado);
	
	system("pause");
	return 0;
}
