#include <windows.h>
#include <iostream>
#include "funkcie.h"
#include "enemyship.h"

using namespace std;


void EnemyShip::drawship(int x, int y)
	{
		int p;
		for (p=0;p<3;p++) {drawpoint(x+2*p,y);}
		for (p=0;p<5;p++) {drawpoint(x+p,y+1);}
		for (p=0;p<3;p++) {drawpoint(x+1+p,y+2);}
		drawpoint(x+2,y+3);
	}
void EnemyShip::destroyship(int x, int y)
	{
		int p;
		for (p=0;p<3;p++) {drawdestroy(x+2*p,y);}
		for (p=0;p<5;p++) {drawdestroy(x+p,y+1);}
		for (p=0;p<3;p++) {drawdestroy(x+1+p,y+2);}
		drawdestroy(x+2,y+3);
	}
void EnemyShip::eraseship(int x, int y)
	{
		int p;
		
		for (p=0;p<3;p++) {erasepoint(x+2*p,y);}
		for (p=0;p<5;p++) {erasepoint(x+p,y+1);}
		for (p=0;p<3;p++) {erasepoint(x+1+p,y+2);}	
		erasepoint(x+2,y+3);
			
	}
EnemyShip::EnemyShip(int x, int y)
	{
		polohaX=x;
		polohaY=y;
		drawship(polohaX,polohaY);	
	}
void EnemyShip::godown()
	{
		eraseship(polohaX,polohaY);	
		polohaY++;
		drawship(polohaX,polohaY);	
	}
bool EnemyShip::koliziastrela(int x, int y)
	{
		bool z;
		if ((polohaX==x and polohaY+1==y) or (polohaX+4==x and polohaY+1==y) or (polohaX+1==x and polohaY+2==y) or (polohaX+3==x and polohaY+2==y) or (polohaX+2==x and polohaY+3==y)) z=true;
		else z=false;
		return z;
	}
bool EnemyShip::canshoot(int x, int y)
	{
		bool shoot;
		if(polohaX==x and polohaY+10==y) shoot=true;
		else shoot=false;
		return shoot;
	}		

