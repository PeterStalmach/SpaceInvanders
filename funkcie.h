#ifndef funkcie_h
#define funkcie_h

void gotoxy(short x, short y); // funkcia na presun kurzoru po obrazovke na suradnice x a y /v poctoch znakov - z netu
void drawpoint(int x, int y);	// vykreslenie bodu na obrazovke na zadanych suradniciach
void erasepoint(int x, int y);	// zmazanie bodu na obrazovke na zadanych suradniciach 
void drawdestroy(int x, int y);	// vykreslenie hviezdicky na obrazovke na zadanzch suradniciach/akoze vybuch
void menu(int x, int y, int z);	// vykreslenie 4. roznych menu okienoch/ na zaciatku hry a pri vzhre alebo prehre

#endif 
