#include <iostream>
#include <windows.h>   
#include <stdlib.h>
#include <ctime>
#include <vector>
#include "funkcie.h"
#include "game.h"
#include "ship.h"
#include "enemyship.h"
#include "bullet.h"

using namespace std;

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}


int main(int argc, char** argv) {
	
int columns, rows, pocitadlo, pl_bullet_desX=2,pl_bullet_desY=2, enemyinrow,key, counterloop=0, enemyspeed=0,bulletspeed=0,enemyshooting=0, innerloop, polohalinie=0, znicenelode=0, numberofwaves=1,flag;
	// konštanty pre nastavovanie parametrov hry, ?ím menšie ?íslo, tým rýchlejšia odozva, ?iže lode poletia rýchlejšie a pod.
	int es=40; // enemy speed
	int bs=3; // bullet speed
	int nov=3; // number of enemy vawes
	int est=1; // how often is enemy firing
	long long isshoot,p,r;
	bool bulletdestroyed = false, notshoot;
	srand (time(NULL));
		// maximalizovanie okna - z netu
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
		// skrytie kurzora
	ShowConsoleCursor(false);
		// zistenie maximálnej ve?kosti konzoly (obrazovky) merané v riadkoch a st?pcoch - z netu
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; 
    
	menu(columns,rows,0);
	flag=getchar();
    
    Game MyGame(columns,rows);
    Ship MyShip((int)(columns/2)-4,rows-5);
    vector<Bullet> MyBullet;
    vector<EnemyShip> Enemy;
    MyShip.end=false;
// po?et nepriatelských lodí v jednom rade, aby boli na celej sirke obrazovky s medzerou medzi 10 znakov
	enemyinrow=(int)((MyGame.mapaX-4)/15);
	
	for (pocitadlo=0;pocitadlo<enemyinrow;pocitadlo++)
	{
		if (pocitadlo==0) 
		{
			Enemy.push_back(EnemyShip(10+pocitadlo*enemyinrow,4));
			MyGame.pocetlodi++;
		}
		else 
		{
			Enemy.push_back(EnemyShip(10+pocitadlo*enemyinrow,4));
			MyGame.pocetlodi++;
		}
	}
	
// hlavná herná slu?ka	   
    while(MyShip.end!=true){
   	counterloop++;		// pocitadlo hernej slucky
   	if (counterloop==5000)	// po 5000 iteracii hernej slucky sa pocitadlo hernej slucky vynuluje - tymto sa da ovplyvnovat rychlost hry
   	{
   		enemyspeed++;
   		bulletspeed++;
   		enemyshooting++;
   		counterloop=0;
	}
   	if (polohalinie==10)
   	{
   		if (numberofwaves!=nov)
   		{
   			for (pocitadlo=0;pocitadlo<enemyinrow;pocitadlo++)
			{
				if (pocitadlo==0) 
				{
				Enemy.push_back(EnemyShip(10+pocitadlo*enemyinrow,4));
				MyGame.pocetlodi++;
				}
				else 
				{
				Enemy.push_back(EnemyShip(10+pocitadlo*enemyinrow,4));
				MyGame.pocetlodi++;
				}
			}
		numberofwaves++;
		}
   	polohalinie=0;	
	}
   	if (MyShip.strela==true)
   		{
   			MyBullet.push_back(Bullet(MyShip.polohaX+3,MyShip.polohaY-2,false));
   			MyGame.pocetstriel++;
   			MyShip.strela=false;
		}
	
	if (MyGame.pocetstriel!=0) 
		{
			for (pocitadlo=0;pocitadlo<MyGame.pocetstriel;pocitadlo++)
			{
				if (MyBullet[pocitadlo].enemy==false) 
				{
					if (MyBullet[pocitadlo].polohaY==2)
					{
						int p;
						MyBullet[pocitadlo].bulletdestroy(MyBullet[pocitadlo].polohaX, MyBullet[pocitadlo].polohaY);
						pl_bullet_desX=MyBullet[pocitadlo].polohaX;
						pl_bullet_desY=MyBullet[pocitadlo].polohaY;
						bulletdestroyed=true;
						for (p=pocitadlo;p<MyGame.pocetstriel-1;p++) {MyBullet[p]=MyBullet[p+1];}
						MyBullet.pop_back();	// zmazanie instancie z triedy bullet, aby sa tieto instancie zbytocne nehromadily v pameti PC, ked uz ich nie je treba
						MyGame.pocetstriel--;
					}
				}
			}
		}
	
	if (bulletspeed==bs)
	{
		if (MyGame.pocetstriel!=0) 
		{
			for (pocitadlo=0;pocitadlo<MyGame.pocetstriel;pocitadlo++)
			{
				if (MyBullet[pocitadlo].enemy==false) 
					{
						if (MyBullet[pocitadlo].polohaY!=2) {MyBullet[pocitadlo].playershoot();}
						for (innerloop=0;innerloop<MyGame.pocetlodi;innerloop++)
						{
							if ((Enemy[innerloop].koliziastrela(MyBullet[pocitadlo].polohaX, MyBullet[pocitadlo].polohaY))==true) 
							{
								Enemy[innerloop].destroyship(Enemy[innerloop].polohaX,Enemy[innerloop].polohaY);
								Sleep(200);	// kratke zastavenie hry, aby bolo vydiet "vybuch" nepriatelskej lode
								Enemy[innerloop].eraseship(Enemy[innerloop].polohaX,Enemy[innerloop].polohaY);
								for (p=innerloop;p<MyGame.pocetlodi-1;p++) {Enemy[p]=Enemy[p+1];}
								Enemy.pop_back();
								MyGame.pocetlodi--;
								znicenelode++;		// pocitadlo znicenych nepriatelskych lodi
								gotoxy(23,MyGame.mapaY-2);
								cout<<znicenelode;
								for (p=pocitadlo;p<MyGame.pocetstriel-1;p++) {MyBullet[p]=MyBullet[p+1];}
								MyBullet.pop_back();	// zmazanie instancie z triedy bullet, aby sa tieto instancie zbytocne nehromadily v pameti PC, ked uz ich nie je treba
								MyGame.pocetstriel--;
							}	
						}
					}		
				if (MyBullet[pocitadlo].enemy==true) 
					{
						
						if (MyBullet[pocitadlo].polohaY!=rows-5) {MyBullet[pocitadlo].enemyshoot();}
						else
						{
							gotoxy(MyBullet[pocitadlo].polohaX,MyBullet[pocitadlo].polohaY);
							cout<<" ";
							for (p=pocitadlo;p<MyGame.pocetstriel-1;p++) {MyBullet[p]=MyBullet[p+1];}
							MyBullet.pop_back();	// zmazanie instancie z triedy bullet, aby sa tieto instancie zbytocne nehromadily v pameti PC, ked uz ich nie je treba
							MyGame.pocetstriel--;
						}
						if ((MyShip.koliziastrela(MyBullet[pocitadlo].polohaX, MyBullet[pocitadlo].polohaY))==true) 
						{
							menu(columns,rows,1);
							flag=getchar();
							MyShip.end=true;
						}
					}
			}
		}
		bulletspeed=0;
		if (bulletdestroyed==true)
    	{
    		gotoxy(pl_bullet_desX,pl_bullet_desY);
			cout<<" ";
			bulletdestroyed=false;	
		}
	}
	if (enemyspeed==es) // pohyb vsetkych nepriatelskych lodi smerom dole
	{
 		for (pocitadlo=0;pocitadlo<MyGame.pocetlodi;pocitadlo++) 
		{
			if (Enemy[pocitadlo].polohaY!=rows-8) {Enemy[pocitadlo].godown();}
			else 
			{
		 		menu(columns,rows,2);
				flag=getchar();
				MyShip.end=true;
				break;
			}
		}
 		enemyspeed=0;
 		polohalinie++;
	}	
	
		if (enemyshooting=est) // strelba nepriatelskych lodi - strielat mozu len lode ktore pred sebou nemaju dalsiu lod
	{
		for (pocitadlo=0;pocitadlo<MyGame.pocetlodi-1;pocitadlo++)
		{
			notshoot=false;
			for (innerloop=0;innerloop<pocitadlo;innerloop++)
			{
				if(Enemy[pocitadlo].canshoot(Enemy[innerloop].polohaX,Enemy[innerloop].polohaY)==true) {notshoot=true;}	
			}
			if (notshoot!=true)	// pravdepodobnost s akou lod vystreli
			{
				r=(int)rand() % 2000;	// tieto premenne ovplyvnuju pravdepodobnost strelby nepriatelskej lode
				p=(int)rand() % 500;
				if (r==10 and p==99)
				{
					MyBullet.push_back(Bullet(Enemy[pocitadlo].polohaX+2,Enemy[pocitadlo].polohaY+4,true));
   					MyGame.pocetstriel++;
				}	
			}	
		}
		enemyshooting=0;
	}
	if (enemyinrow*numberofwaves==znicenelode)	// ak sa pocet vsetkych lodi v hre rovna poctu znicenych lodi, hrac vyhral
		{
		 	menu(columns,rows,3);
			flag=getchar();
			MyShip.end=true;
		}
		
	if (GetAsyncKeyState(VK_LEFT) & (0x8000 != 0)) {if (MyShip.polohaX!=3 )MyShip.goleft();} // pohyb hracovej lode dolava s obmedzením aby lod nevysla mimo hernu plochu 	
	if (GetAsyncKeyState(VK_RIGHT) & (0x8000 != 0)){if (MyShip.polohaX!=MyGame.mapaX-10) MyShip.goright();}	// pohyb hracovej lode doprava s obmedzením aby lod nevysla mimo hernu plochu 
	if (GetAsyncKeyState(VK_ESCAPE) & (0x8000 != 0)){MyShip.koniec();} // stlacenie ESC ukonci okamzite hru
	if (GetAsyncKeyState(VK_SPACE) & (0x8000 != 0)){MyShip.shoot();}	// po stlaceni Medzerniku hracova lod vystreli
	} 	

	return 0;
}
