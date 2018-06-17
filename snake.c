#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>//zmienic 
#include <ctype.h>
#include <time.h>
#define x 22
#define y 60
/*
LEFT - 37
UP - 38
RIGHT - 39
DOWN - 40
*/
int plansza[x][y],owoc,ogon,glowa,gra,predkosc,punkty;
int i,j,x1,z,a,b,gy1;
char poz,par;
//y1=z
void Snake(){
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			plansza[i][j]=0;
		}
	}
	x1=x/2; z=y/2;//pozycja x i y weza na starcie 
	glowa=5;
	predkosc=80;
	owoc=0;
	ogon=1;
	gy1=z;
	poz='d';//100
	gra=0;
	punkty=0;
	for(i=0;i<glowa;i++){
		gy1++;
		plansza[x1][gy1-glowa]=i+1;
	}
}
void przesogon(){
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(plansza[i][j]==ogon){
				plansza[i][j]=0;
			}	
		}
	}
	ogon++;
}
void losowanieowocow(){
	a=1+rand()%30;//losowanie pozycji x 
	b=1+rand()%50;//losowanie pozycji y
	if(owoc == 0 && plansza[a][b] == 0){
		plansza[a][b]=-1;
		owoc=1;
	if(predkosc>10 && punkty !=0) predkosc--;
	}
}
void rysowanieplanszy(){
	for(i=0;i<=y+1;i++){
		if(i==0)//rysowanie lewego gornego rogu pola
			printf("%c",35 );//lewy gorny rog
		else if(i==y+1)//rysowanie prawego gornego rogu pola
			printf("%c",35);//prawy gorny rog
		else //rysowanie gornej granicy pola 
			printf("%c",61);//gora
	}
	printf("punkty: %d",punkty);
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
char klawa(){ //zmiana z void na char lub int 
	if(_kbhit())
		return _getch();
 	else 
		return -1;
}
void koniec (){
	printf("\a");
	Sleep(1500);
	system("Cls");
	printf("				Koniec Gry\n");
	printf("	Wcisnij enter aby zagrac ponownie lub esc aby wyjsc");
	while(1){	
		par = klawa();
		if(par == 13){
			gra=0;
			Snake();
			break;
		}
		else if(par == 27){
			gra=1;
			break;
		}
	}
	system("Cls");
}
void pozycja(){
	par = klawa();
	par = tolower(par);
	if(((par == 'd' || par == 'a') || (par == 'w' || par == 's'))&&(abs(poz - par)>5))poz=par;
	if(poz=='d'){//RIGHT 68 100
		z++;
		if(plansza[x1][z] !=0 && plansza[x1][z] !=-1) 
			koniec();
		if(z == y)
			z=0;
		if(plansza[x1][z]==-1){
			punkty=punkty+5;
			ogon--;
			ogon--;
			owoc=0;
		}
		glowa++;
		plansza[x1][z] = glowa;
	}
	if(poz=='a'){//LEFT 65 97
		z--;
		if(y==-1) z=y-1;
		if(plansza[x1][z] !=0 && plansza[x1][z] !=-1) 
			koniec();
		if(plansza[x1][z]==-1){
			punkty=punkty+5;
			ogon--;
			ogon--;
			owoc=0;
		}
		glowa++;
		plansza[x1][z] = glowa;
	}
	if(poz=='w'){//UP 87 119
		x1--;
		if(x1==-1) x1=x-1;
		if(plansza[x1][z] !=0 && plansza[x1][z] !=-1) 
			koniec();
		if(plansza[x1][z]==-1){
			punkty=punkty+5;
			ogon--;
			ogon--;
			owoc=0;
		}
		glowa++;
		plansza[x1][z] = glowa;
	}
	if(poz=='s'){//DOWN 63 115
		x1++;
		if(x1==x) x1=0;
		if(plansza[x1][z] !=0 && plansza[x1][z] !=-1) 
			koniec();
		if(plansza[x1][z]==-1){
			punkty=punkty+5;
			ogon--;
			ogon--;
			owoc=0;
		}
		glowa++;
		plansza[x1][z] = glowa;
	}	
}
void ResetScreenPosition() 
    {
        HANDLE hOut;
        COORD Position;
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        Position.X = 0;
        Position.Y = 0;
        SetConsoleCursorPosition(hOut, Position);
    }
int main()
{
	Snake();
	while(gra == 0){
	rysowanieplanszy();
	losowanieowocow();	
	pozycja();
	przesogon();
	Sleep(predkosc);
	ResetScreenPosition();
	}
}
