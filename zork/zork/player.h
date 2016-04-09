#include <stdio.h>




class Room;
class World;


class Player{
public:
	

	char name[30];
	char description[200];
	//World* w;
	Room* position;
	Player();
	~Player(){};
	void open(char * inst, int dir);
	void close(char * inst, int dir);
	bool go(char* inst, int dir);
	void look(char* inst, int dir)const;
	int inventory[30];

};



