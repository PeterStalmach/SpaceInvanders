#include <windows.h>
#include <iostream>
#include "funkcie.h"
#include "bullet.h"

using namespace std;



void Bullet::drawbullet(int x, int y)
	{
		gotoxy(x,y);
		cout<<char(248);
	}
void Bullet::drawenemybullet(int x, int y)
	{
		gotoxy(x,y);
		cout<<char(207);
	}
void Bullet::erasebullet(int x, int y)
	{
		gotoxy(x,y);
		cout<<" ";
	}
void Bullet::enemyshoot()
	{
		erasebullet(polohaX, polohaY);
		polohaY++;
		drawenemybullet(polohaX, polohaY);
	}
void Bullet::playershoot()
	{
		erasebullet(polohaX, polohaY);
		polohaY--;
		drawbullet(polohaX, polohaY);
	}
Bullet::Bullet(int x, int y, bool z)
	{
		enemy=z;
		polohaX=x;
		polohaY=y;
		drawbullet(polohaX,polohaY);
	}
void Bullet::bulletdestroy(int x, int y)
	{
		gotoxy(x,y);
		cout<<"*";
	}
	

