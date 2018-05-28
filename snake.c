#include<stdio.h>
#include<string.h>
#define x 20
#define y 20
void plansza()
{
	int plansza[x][y];
	int i,j;
	int x1,y1;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			plansza[i][j]=0;
		}
	}
}
int main()
{
	plansza();
	
}


