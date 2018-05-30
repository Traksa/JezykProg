#include<stdio.h>
#include<string.h>
#define x 22
#define y 77
void Snake(int plansza[x][y],int owoc){
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			plansza[i][j]=0;
		}
	}
}
void losowanieowocow(int plansza[x][y],int owoc){
	int x1,y1;
	x1=1+rand()%2;
	y1=1+rand()%3;
	if(owoc == 0 && plansza[x1][y1]){
		plansza[x1][y1]=-1;
		owoc=1;
	}
}
void rysowanieplanszy(int plansza[x][y]){
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
			if(plansza[i][j] == -1)
				printf("%c", 42);
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
	int plansza[x][y];
	int owoc;
Snake(plansza,owoc);
losowanieowocow(plansza,owoc);	
rysowanieplanszy(plansza);
}
