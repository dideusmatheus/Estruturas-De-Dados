#include<stdio.h>
#include<stdlib.h>

void somamatriz(int m[3][3])
{
	m[0][0] = (m[0][0] + 5);
	m[1][0] = (m[1][0] + 6);
	m[2][0] = (m[2][0] + 6);
	m[0][1] = (m[0][1] + 3);
	m[1][1] = (m[1][1] + 4);
	m[2][1] = (m[2][1] + 2);
	m[0][2] = (m[0][2] + 1);
	m[1][2] = (m[1][2] + 2);
	m[2][2] = (m[2][2] + 1);
}

int main()
{
	int i,j;
	int m[3][3];
	printf("Digite os valores da matriz:\n");
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
			scanf("%d", &m[i][j]);
	}
	somamatriz(m);
	
  	system("pause");
	return 0;
}
