#ifndef enemy_h
#define enemy_h

class EnemyShip
{
	public:
	int polohaX, polohaY;	// poloha nepriatelskej lode na hernej mapy v suradniciach x a y
	void drawship(int x, int y);	// vykreslenie nepratelskej lode na zadanych suradniciach
	void destroyship(int x, int y);	// vykreslenie "vybuchu" lode po zasahu hracovou strelou
	void eraseship(int x, int y);	// vymazanie nepriatelskej lode na zadanych suradniciach
	EnemyShip(int x, int y);	// konstruktor na vytvorenie nepriatelskej lode na zadanych suradniciach
	void godown();	// pohyb nepriatelskej lode smerom dolu - nepriatelske lode sa pohybuju iba smerom dolu
	bool koliziastrela(int x, int y);	// kontrola ci nepriatelsku lod nezasiahla hracova strela
	bool canshoot(int x, int y);	// kontrola pred strelbou, ci pred nepriatelskou lodou nie je ina lod
};


#endif 
