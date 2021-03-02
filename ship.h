#ifndef ship_h
#define ship_h

class Ship
{
	public:
	int polohaX, polohaY;	// poloha hracovej lode na hernej mape v suradniciach x a y
	bool end,strela;
	
	void drawship(int x, int y);	// vykreslenie hracovej lode na zadanych suradniciach
	void eraseship(int x, int y);	// zmazanie hracovej lode na zadanych suradniciach

	Ship(int x, int y);	// konstruktor na vytvorenie lode na zadanych suradniciach

	void goleft();	// pohyb hracovej lode dolava

	void goright();	// pohyb hracovej lode doprava

	bool koliziastrela(int x, int y);	// kontrola, ci hracovu lod nezasiahla strela z nepriatelskej lode

	void koniec();	// nastavy premennu end na true

	void shoot();	// nastavy premennu strela na true
		
};


#endif 
