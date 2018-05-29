#include<stdio.h>
#include<string.h>
#define x 20
#define y 40
void plansza(){
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
void rysowanieplanszy(){
	int plansza[x][y];
	int i,j;
	for(i=0;i<=y+1;i++){
		if(i==0)
			printf("%c",35 );
		else if(i==y+1)
			printf("%c",35);
		else 
			printf("%c",61);
	}
	printf("\n");
	for(i=0;i<x;i++){
		printf("%c",124);

		for(j=0;j<y;j++){
		if(plansza[i][j] == 0)
			printf(" ");
		if(j==y-1)
			printf("%c\n",124);
		}	
	}
	for(i=0;i<=y+1;i++){
	if(i==0)
		printf("%c",35);
	else if(i==y+1)
		printf("%c",35);
	else 
		printf("%c",61);
	}
}
int main()
{
	plansza();
	rysowanieplanszy();
	return 0;
}


