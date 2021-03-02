#include <windows.h>
#include <iostream>
#include "funkcie.h"
#include "ship.h"

using namespace std;

void Ship::drawship(int x, int y)
	{
		int p;
		drawpoint(x+3,y-1);
		for (p=0;p<7;p++) {drawpoint(x+p,y);}
	}
void Ship::eraseship(int x, int y)
	{
		int p;
		erasepoint(x+3,y-1);
		for (p=0;p<7;p++) {erasepoint(x+p,y);}
	}
Ship::Ship(int x, int y)
	{
		polohaX=x;
		polohaY=y;
		drawship(polohaX,polohaY);
		strela=false;	// nastavenie, ze lod na zaciatku pri vytvoreni nevystreli
	}
void Ship::goleft()
	{
		eraseship(polohaX,polohaY);	
		polohaX--;
		drawship(polohaX,polohaY);	
	}
void Ship::goright()
	{
		eraseship(polohaX,polohaY);	
		polohaX++;
		drawship(polohaX,polohaY);		
	}
bool Ship::koliziastrela(int x, int y)	// do premmennych x a y sa postupne dosadzaju polohy vsetkych nepriatelskych striel
	{
		bool z,a,b;
		int p;
		if (polohaX+3==x and polohaY-1==y) a=true;
		else a=false;
		for( p=0;p<7;p++)
			{
				if (polohaX+p==x and polohaY==y)
					{
						b=true;
						break;
					}
				else b=false;
			}
		if (a==true or b==true) z=true;
		else z==false;
		return z;
	}
void Ship::koniec()
	{
		end=true;
	}
void Ship::shoot()
	{
		strela=true;	
	}		


