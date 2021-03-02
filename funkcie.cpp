#include <windows.h>
#include <iostream>
#include "funkcie.h"

using namespace std;

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} 

void drawpoint(int x, int y)
{
	gotoxy(x,y);
	cout<<char(219);
}

void erasepoint(int x, int y)
{
	gotoxy(x,y);
	cout<<" ";
}

void drawdestroy(int x, int y)
{
	gotoxy(x,y);
	cout<<"*";
}

void menu(int x, int y, int z)
{
	int riadky, stlpce, pociatokX, pociatokY,r,s;
	if (z==0)
	{
		riadky=12;
		stlpce=120;	
	}
	else
	{
		riadky=12;
		stlpce=90;
	}
	pociatokX=(int)(x/2) - stlpce/2;
	pociatokY=(int)(y/2) - riadky/2;
	gotoxy(pociatokX,pociatokY);
	cout<<char(218);
	for (s=0;s<stlpce-1;s++) {cout<<char(196);}
	cout<<char(191)<<endl;
	for (r=0;r<riadky-1;r++)
	{
		gotoxy(pociatokX,pociatokY+1+r);
		cout<<char(179);
		for(s=0;s<stlpce-1;s++)	{cout<<" ";}
		cout<<char(179)<<endl;
	}
	gotoxy(pociatokX,pociatokY+riadky);
	cout<<char(192);
	for (s=0;s<stlpce-1;s++) {cout<<char(196);}
	cout<<char(217);
	switch (z){	// 0-uvodna obrazovka/1-obrazovka prehry-znicenie tanku/2-obrazovka prehry-mimozemske lode dosiahly spodok hernej mapy/3-obrazovka vyhry-hrac znicil vsetky mimozemske lode
		case 0:
			{
			gotoxy(pociatokX,pociatokY-1);cout<<"C++ console...";
			gotoxy(pociatokX+93,pociatokY-1);cout<<"Developed by Peter "<<char(230)<< "talmach";
			gotoxy(pociatokX+stlpce/2-7,pociatokY+2);cout<<"SPACE INVANDERS";
			gotoxy(pociatokX+stlpce/2-16,pociatokY+5);cout<<"Na Zem zautocili mimozemstania!!!";
			gotoxy(pociatokX+stlpce/2-36,pociatokY+6);cout<<"Ty si nasou poslednou obrannou liniou, musis znicit vsetky mimozemske lode";
			gotoxy(pociatokX+stlpce/2-47,pociatokY+7);cout<<"Ak mimozemske lode pristanu na zemi, alebo znicia tvoj tank, Zem je stratena a vsetci zahynieme!";
			gotoxy(pociatokX+stlpce/2-17,pociatokY+10);cout<<"Stlac 'Enter' pre nastupenie do tanku";
			break;	
			}
		case 1:
			{
			gotoxy(pociatokX+stlpce/2-16,pociatokY+2);cout<<"Mimozemstania znicili tvoj tank!";
			gotoxy(pociatokX+stlpce/2-7,pociatokY+6);cout<<"Zem je stratena";
			gotoxy(pociatokX+stlpce/2-18,pociatokY+10);cout<<"Stlac 'Enter' pre ukoncenie trapenia";
			break;	
			}
		case 2:
			{
			gotoxy(pociatokX+stlpce/2-15,pociatokY+2);cout<<"Mimozemstania pristali na Zemi!";
			gotoxy(pociatokX+stlpce/2-7,pociatokY+6);cout<<"Zem je stratena";
			gotoxy(pociatokX+stlpce/2-18,pociatokY+10);cout<<"Stlac 'Enter' pre ukoncenie trapenia";
			break;	
			}
		case 3:
			{
			gotoxy(pociatokX+stlpce/2-6,pociatokY+2);cout<<"VYHRAL SI!!!";
			gotoxy(pociatokX+stlpce/2-8,pociatokY+6);cout<<"Zem je zachranena";
			gotoxy(pociatokX+stlpce/2-16,pociatokY+10);cout<<"Stlac 'Enter' pre zaciatok oslavy";
			break;	
			}	
	}	
}



