#include <windows.h>
#include <iostream>
#include "funkcie.h"
#include "game.h"

using namespace std;


void Game::medzera(int x)
	{
		int a;
		for(a=0;a<x;a++) {cout<<" ";}
	}
void Game::mapa(int x, int y)
	{
		mapaX=x;
		mapaY=y;
		int sizeX, sizeY,popisX;
		gotoxy(1,1); 
		cout<<char(218);
		for (sizeX=0;sizeX<x-4;sizeX++) {cout<<char(196);}
		cout<<char(191)<<endl;
		for (sizeY=0;sizeY<y-6;sizeY++)
		{
			cout<<" "<<char(179);
			for (sizeX=0;sizeX<x-4;sizeX++) {cout<<" ";}
			cout<<char(179)<<endl;
		}
		cout<<" "<<char(192);
		for (sizeX=0;sizeX<x-4;sizeX++) {cout<<char(196);}
		cout<<char(217)<<endl<<endl<<"  ";
		cout<<"Po"<<char(159)<<"et zni"<<char(159)<<"en"<<char(236)<<"ch lod"<<char(161)<<":";
		popisX=(int)(x/2)-25;
		gotoxy(popisX,y-2);
		cout<<"[<-] V"<<char(150)<<"avo"<<"    "<<"[Medzern"<<char(161)<<"k] Vystreli"<<char(156)<<"    "<<"[->] Vpravo    [ESC] Koniec hry"; 
		
	}
Game::Game(int x, int y)
	{
		pocetlodi=0;
		pocetstriel=0;
		mapa(x,y);
	}	


