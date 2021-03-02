#ifndef mapa_h
#define mapa_h

class Game{
	public:
	int score, gamespeed,mapaX,mapaY,pocetstriel,pocetlodi;
	void medzera(int x);
	void mapa(int x, int y);
	Game(int x, int y);
};

#endif 
