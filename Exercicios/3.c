#include<stdio.h>
#include <stdlib.h>

int dado()
{
    return (rand() % 6);
}

int main()
{
	int num1=0,num2=0,num3=0,num4=0,num5=0,num6=0;
	int i;
	for(i=0;i<100;i++)
	{
		switch (dado())
        {
            case 1:
                num1++;
                break;
            case 2:
                num2++;
                break;
            case 3:
                num3++;
                break;
            case 4:
                num4++;
                break;
            case 5:
                num5++;
                break;
            case 6:
                num6++;
                break;
        }
	}
	
	printf("Numero 1 foi sorteado %d vezes.\n", num1);
	printf("Numero 2 foi sorteado %d vezes.\n", num2);
	printf("Numero 3 foi sorteado %d vezes.\n", num3);
	printf("Numero 4 foi sorteado %d vezes.\n", num4);
	printf("Numero 5 foi sorteado %d vezes.\n", num5);
	printf("Numero 6 foi sorteado %d vezes.\n", num6);
	
	system("pause");
	return 0;
}
