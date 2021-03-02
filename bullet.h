#ifndef bullet_h
#define bullet_h

class Bullet
{
	public:
	int polohaX, polohaY;	// poloha strely na hernej mape
	bool enemy;	// premenna do ktorej sa uklada informacia ci striela hrac alebo nepriatelska lod
	void drawbullet(int x, int y);	// vykreslenie hracovej strely na hernej mapa
	void drawenemybullet(int x, int y);	// vykreslenie nepriatelskej strely na hernej mape
	void erasebullet(int x, int y);	// vymazanie strely na hernej mape
	void enemyshoot();	// strela z nepriatelskej lode poleti smerom dole
	void playershoot();	// strela z hracovej lode poleti smerom hore
	Bullet(int x, int y, bool z);	// konstruktor, do premennej z sa dosadi true ak striela nepratelska lod, a false ak striela hrac/aby sa vedelo komu strela patri
	void bulletdestroy(int x, int y);	// zobrazenie "vybuchu" ked strela narazi na okraj hernej plochy
};


#endif 
