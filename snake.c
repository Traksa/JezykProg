#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
 #ifdef _WIN32 
 #include <windows.h> 
 #define ekran() system("cls") 
 #endif 
#ifdef __linux__  
 #define ekran() system("clear") 
  #endif
#include <ctype.h>
#define x 22
#define y 60

int plansza[x][y],owoc,ogon,glowa,gra,predkosc,punkty,i,j,x1,z,owox,owoy,gy1;
char poz,par;
void Snake(){
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			plansza[i][j]=0;
		}
	}
	x1=x/2; 
	z=y/2;//pozycja x i y weza na starcie 
	glowa=2;
	predkosc=80;
	owoc=0;
	ogon=1;
	gy1=z;
	poz='d';
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
	owox=1+rand()%20;//losowanie pozycji x 
	owoy=1+rand()%30;//losowanie pozycji y
	if(owoc == 0 && plansza[owox][owoy] == 0){
		plansza[owox][owoy]=-1;
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
	printf(" Twoje punkty: %d",punkty);
	printf("\n");
	for(i=0;i<x;i++){
		printf("%c",124);//lewa strona
		
		for(j=0;j<y;j++){
			if(plansza[i][j] == 0)//rysowanie pustego pola
				printf(" ");//puste pole 		
			if(plansza[i][j] == -1)//rysowanie owocu
				printf("%c", 178);//owoc	
			if(plansza[i][j]>0 && plansza[i][j] !=glowa)//rysowanie ogonu
				printf("%c",219);//ogon
			if(plansza[i][j]==glowa)//rysowanie glowy
				printf("%c",254);//glowa
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
	system("color 4");
	Sleep(1500);
	ekran();
	printf("\n\n\n\n\n\n\n\n\n");
	printf("			  	    Koniec Gry\n");
	printf("				Zdobyles %d punktow\n",punkty);
	printf("		Wcisnij enter aby zagrac ponownie lub Esc aby wyjsc");
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
	ekran();
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
			punkty=punkty+1;
			ogon--;
			ogon--;
			owoc=0;
		}
		glowa++;
		plansza[x1][z] = glowa;
	}
	if(poz=='a'){//LEFT 65 97
		z--;
		if(z==-1) 
			z=y-1;
		if(plansza[x1][z] !=0 && plansza[x1][z] !=-1) 
			koniec();
		if(plansza[x1][z]==-1){
			punkty=punkty+1;
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
			punkty=punkty+1;
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
			punkty=punkty+1;
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
void start(){
	printf("\n\n\n\n\n\n\n\n\n");
	printf("				 Game Snake\n");
	printf("	  		Kierowanie wezem klawiszami w,a,s,d .\n");
	printf("	  	 	Gra polega na zbieraniu owocow %c \n", 178);
	printf("	  	 	Za kazdy owoc otrzymujemy 1 pkt  \n");	  	 	
	printf("		  wcisnij enter aby rozpoczac gre , Esc aby wyjsc");
	printf("				    Lub za 30 sek gra wlaczy sie automatycznie ");
	Sleep(30000);
	ekran();
}
int main()
{
	system("color 2");
	start();

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
