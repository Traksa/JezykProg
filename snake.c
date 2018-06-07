#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>//zmienic 
#include <ctype.h>
#include <time.h>
#define x 22
#define y 77
#define predkosc 80
/*
LEFT - 37
UP - 38
RIGHT - 39
DOWN - 40
*/
void Snake(int plansza[x][y],int owoc,int ogon,int glowa){
	int i,j;
	int x1,y1;
	int gy1;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			plansza[i][j]=0;
		}
	}
	x1=x/2; y1=y/2;//pozycja x i y weza na starcie 
	glowa=5;
	owoc=0;
	ogon=1;
	gy1=y1;
	for(i=0;i<glowa;i++){
		gy1++;
		plansza[x1][gy1-glowa]=i+1;
	}
}
void losowanieowocow(int plansza[x][y],int owoc,int x1,int y1){
	x1=1+rand()%30;//losowanie pozycji x 
	y1=1+rand()%50;//losowanie pozycji y
	if(owoc == 0 && plansza[x1][y1] == 0){
		plansza[x1][y1]=-1;
		owoc=1;
	}
}
void rysowanieplanszy(int plansza[x][y],int glowa){
	int i,j;
	glowa=5;
	for(i=0;i<=y+1;i++){
		if(i==0)//rysowanie lewego gornego rogu pola
			printf("%c",35 );//lewy gorny rog
		else if(i==y+1)//rysowanie prawego gornego rogu pola
			printf("%c",35);//prawy gorny rog
		else //rysowanie gornej granicy pola 
			printf("%c",61);//gora
	}
	printf("\n");
	for(i=0;i<x;i++){
		printf("%c",124);//lewa strona

		for(j=0;j<y;j++){
			if(plansza[i][j] == 0)//rysowanie pustego pola
				printf(" ");//puste pole 		
			if(plansza[i][j] == -1)//rysowanie owocu
				printf("%c", 42);//owoc	
			if(plansza[i][j]>0 && plansza[i][j] !=glowa)//rysowanie ogonu
				printf("%c",91);//ogon
			if(plansza[i][j]==glowa)//rysowanie glowy
				printf("%c",62);//glowa
			if(j==y-1)//rysowanie prawej granicy pola
				printf("%c\n",124);//prawa strona
		}	
	}
	for(i=0;i<=y+1;i++){
	if(i==0)//rysowanie dolnego lewego rogu pola
		printf("%c",35);//lewy dolny rog
	else if(i==y+1)//rysowanie dolnego prawego regu pola
		printf("%c",35);//prawy dolny rog
	else //rysowanie dolnej granicy pola 
		printf("%c",61);//dol 
	}
}
void koniec (int gra,int plansza[x][y],int owoc,int ogon,int glowa){
	printf("\a");
	Sleep(1500);
	system("Cls");
	printf("Koniec Gry");
	printf("wcisnij enter aby zagrac ponownie lub esc aby wyjsc");
	while(1){
		char par;
		if(par== 13){
			gra=0;
			Snake(plansza,owoc,ogon,glowa);
			break;
		}
		else if(par== 27){
			gra=1;
			break;
		}
	}
	system("Cls");
}
void pozycja(char poz,int owoc,int plansza[x][y],int x1,int y1,int ogon,int glowa,int gra){
	if(poz=39){
		y1++;
		if(plansza[x1][y1] !=0 && plansza[x1][y1] !=-1) 
			koniec(gra,plansza,owoc,ogon,glowa);
		if(y1 == y)
			y1=0;
		if(plansza[x1][y1]==-1){
			ogon--;
			ogon--;
			owoc=0;
		}
		glowa++;
		plansza[x1][y1] = glowa;
	}	
}
int main()
{
	int plansza[x][y];
	int owoc;
	int x1,y1;
	int ogon,glowa;
	char poz;
Snake(plansza,owoc,ogon,glowa);
losowanieowocow(plansza,owoc,x1,y1);	
rysowanieplanszy(plansza,glowa);
}
