#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,soma=0,cont=0,n;
	float media;
	
	do{
		printf("Numero: "),
		scanf("%d",&n);
		
		if(n%2==0){
			soma=soma+n;
			cont++;
		}	
	}while(n=!-1);
	
	media=soma/cont;
	printf("media: %f",media);
		
	return 0;
}
