#include <stdio.h>

enum direction{
	north,
	south,
	east,
	west,
};

#ifndef _CLASSES
#define _CLASSES
class Player;
class Room;
class Exit;
class World;

class Player{
public:
	char name[30];
	char description[200];
	//Player();
	//~Player();
	Room* position;
	
	
	
};

class Room{
public:
	char name[30];
	char description[200];
};

class Exit{
public:
	char name[30];
	char description[200];
	
	Room* origin;
	Room* destination;
	bool open = false;
	int direction;  //0=North,1=South,2=East,3=West
};


class World{
public:
	
	Room* rooms;
	Exit* exits;
	Player* player;
	World();		
	~World(){
		delete[] rooms;
		delete[] exits;
		delete[] player;
	}
	

	void createworld();
	void loop();
	

};



#endif  // Classes




