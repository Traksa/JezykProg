#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#ifdef _WIN32 
#include <windows.h> 
#include <conio.h>

#define glowao 254
#define ogono 219
#define owoco 178
#define kolorc system("color 4")
#define kolorz system("color 2")
#define ekran() system("cls") 
#define czas Sleep(predkosc)
#define czask Sleep(1500)
#define reset ResetObrazu()

void ResetObrazu()//Funkcja ktora odœwie¿a obraz 
    {
        HANDLE hOut;
        COORD Position;
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        Position.X = 0;
        Position.Y = 0;
        SetConsoleCursorPosition(hOut, Position);
    }
    
#endif 

#ifdef __linux__  
#include <curses.h>
#define glowao 62
#define ogono 35
#define owoco 64
#define kolorc printf("\033[1;33m") 
#define kolorz printf("\033[1;32m")
#define czas sleep(predkosc)
#define czask sleep(1500)
#define ekran() system("clear") 
#define reset sleep(100)
#endif

#define x 22
#define y 59

int plansza[x][y],owoc,ogon,glowa,gra,predkosc,punkty,i,j,x1,z,owox,owoy,gy1;
char poz,par;
void Snake(){//Funkcja g³owna 
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			plansza[i][j]=0;
		}
	}
	
	x1=x/2;//pozycja x weza na starcie
	z=y/2;//pozycja y weza na starcie 
	glowa=2; // poczatkowa liczba glowa + ogon 
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
void przesogon(){ //Funkcja przesuwa ogon
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(plansza[i][j]==ogon){ //blok wykononana siê jesli spe³nia warunek plansza == ogon
				plansza[i][j]=0;
			}	
		}	
	}
	ogon++;
}
void losowanieowocow(){//Funkcja losuje owoc 
	owox=1+rand()%20;//losowanie pozycji x 
	owoy=1+rand()%57;//losowanie pozycji y
	if(owoc == 0 && plansza[owox][owoy] == 0){ // blok wykononana siê jesli spe³nia warunek owoc=0 i plansza == 0
		plansza[owox][owoy]=-1;
		owoc=2;
	}
}
void rysowanieplanszy(){//funkcja ktora przysuje pole/weza/owoc
	for(i=0;i<=y+1;i++){
		if(i==0)//blok wykononana siê jesli spe³nia warunek i==0
			printf("%c",35 );//rysuje lewy gorny rog
		else if(i==y+1)//blok wykononana siê jesli spe³nia warunek i==y+1
			printf("%c",35);//rysuje prawy gorny rog
		else 
			printf("%c",61);//rysuje gore
	}
	printf(" Twoje punkty: %d",punkty); // wyswietla punkty
	printf("\n");
	for(i=0;i<x;i++){
		printf("%c",124);//rysuje lewa strone
		
		for(j=0;j<y;j++){
			if(plansza[i][j] == 0)//blok wykononana siê jesli spe³nia warunek plansza == 0
				printf(" ");//wyswietla nic  		
			if(plansza[i][j] == -1)//blok wykononana siê jesli spe³nia warunek plansza == -1
				printf("%c", owoco);//rysuje owoc	
			if(plansza[i][j]>0 && plansza[i][j] !=glowa)//blok wykononana siê jesli spe³nia warunek plansza >0 i plansza !=glowa
				printf("%c",ogono);//rysuje ogon
			if(plansza[i][j]==glowa)//blok wykononana siê jesli spe³nia warunek plansza == glowa
				printf("%c",glowao);//rysuje glowe
			if(j==y-1)//blok wykononana siê jesli spe³nia warunek j==y-1
				printf("%c\n",124);//rysuje prawa strone
		}	
	}
	for(i=0;i<=y+1;i++){
	if(i==0)//blok wykononana siê jesli spe³nia warunek i==0
		printf("%c",35);//rysuje lewy dolny rog
	else if(i==y+1)//blok wykononana siê jesli spe³nia warunek i==y+1
		printf("%c",35);//rysuje prawy dolny rog
	else 
		printf("%c",61);//rysuje dol 
	}
	printf("\n");
}
char klawa(){ //Funkcja ktora wyczytuje z klawiszy 
	if(kbhit()) //sprawdza, czy w buforze klawiatury znajduj¹ siê dane do odczytania
		return getch(); // czyta z klawiatury bez buforowania 
 	else 
		return -1;
}
void koniec (){
	printf("\a");
	kolorc;
	czask;
	ekran();
	printf("\n\n\n\n\n\n\n\n\n");
	printf("			  	    Koniec Gry\n");
	printf("				Zdobyles %d punktow\n",punkty);
	printf("		Wcisnij enter aby zagrac ponownie lub Esc aby wyjsc");
	while(1){	
		par = klawa();
		if(par == 13){ // blok wykononana siê jesli spe³nia warunek par == Enter 
			gra=0;
			Snake(); 
			break;
		}
		else if(par == 27){// blok wykononana siê jesli spe³nia warunek par == Esc
			gra=1;
			break;
		}
	}
	ekran();
}
void pozycja(){ // Funkcja ktora porusza wê¿a w cztery strony 
	par = klawa();
	par = tolower(par);//zamienia duze na male lub male na duze zalezy od sytuacji 
	if(((par == 'd' || par == 'a') || (par == 'w' || par == 's'))&&(abs(poz - par)>5))poz=par;
	if(poz=='d'){//blok wykononana siê jesli spe³nia warunek poz == d
		z++;
		if(plansza[x1][z] !=0 && plansza[x1][z] !=-1) //blok wykononana siê jesli spe³nia warunek plansza !=0 i plansza !=-1
			koniec();
		if(z == y)//blok wykononana siê  jesli spe³nia warunek z==y 
			z=0;
		if(plansza[x1][z]==-1){//blok wykononana siê  jesli spe³nia warunek plansza ==-1
			punkty=punkty+1;
			ogon--;
			ogon--;
			owoc=0;
		}
		glowa++;
		plansza[x1][z] = glowa;
	}
	if(poz=='a'){//blok wykononana siê  jesli spe³nia warunek poz == a
		z--;
		if(z==-1)//blok wykononana siê  jesli spe³nia warunek z==-1
			z=y-1;
		if(plansza[x1][z] !=0 && plansza[x1][z] !=-1) //blok wykononana siê  jesli spe³nia warunek plansza !=0 i plansza !=-1
			koniec();
		if(plansza[x1][z]==-1){//blok wykononana siê  jesli spe³nia warunek plansza ==-1
			punkty=punkty+1;
			ogon--;
			ogon--;
			owoc=0;
		}
		glowa++;
		plansza[x1][z] = glowa;
	}
	if(poz=='w'){//blok wykononana siê  jesli spe³nia warunek poz == w
		x1--;
		if(x1==-1)//blok wykononana siê  jesli spe³nia warunek x1==-1
			 x1=x-1;
		if(plansza[x1][z] !=0 && plansza[x1][z] !=-1) //blok wykononana siê  jesli spe³nia warunek plansza !=0 i plansza !=-1
			koniec();
		if(plansza[x1][z]==-1){//blok wykononana siê  jesli spe³nia warunek plansza ==-1
			punkty=punkty+1;
			ogon--;
			ogon--;
			owoc=0;
		}
		glowa++;
		plansza[x1][z] = glowa;
	}
	if(poz=='s'){//blok wykononana siê  jesli spe³nia warunek poz == s
		x1++;
		if(x1==x) //blok wykononana siê  jesli spe³nia warunek x1==x
			x1=0;
		if(plansza[x1][z] !=0 && plansza[x1][z] !=-1) //blok wykononana siê  jesli spe³nia warunek plansza !=0 i plansza !=-1
			koniec();
		if(plansza[x1][z]==-1){//blok wykononana siê  jesli spe³nia warunek plansza ==-1
			punkty=punkty+1;
			ogon--;
			ogon--;
			owoc=0;
		}
		glowa++;
		plansza[x1][z] = glowa;
	}	
}

void start(){
	printf("\n\n\n\n\n\n\n\n\n");
	printf("				 Game Snake\n");
	printf("	  		Kierowanie wezem klawiszami w,a,s,d .\n");
	printf("	  	 	Gra polega na zbieraniu owocow %c \n", owoco);
	printf("	  	 	Za kazdy owoc otrzymujemy 1 pkt  \n");	  	 	
	printf("		  wcisnij enter aby rozpoczac gre , Esc aby wyjsc\n");
}
int main()
{
	kolorz;
	start();
	while(1){	
		par = klawa();
		if(par == 13){//blok wykononana siê  jesli spe³nia warunek par == 13
			ekran();		
			Snake();
			while(gra == 0){ //pêtla wykononana siê jesli spe³ni warunek gra == 0 
				kolorz;
				rysowanieplanszy();
				losowanieowocow();	
				pozycja();
				przesogon();
				czas;
				reset;
				ResetObrazu();
			}
		}
		if(par == 27){//blok wykononana siê  jesli spe³nia warunek par == 27
			exit;
			break;
		}
	}		
}
