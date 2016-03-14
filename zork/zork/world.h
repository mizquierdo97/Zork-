#include <stdio.h>


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
	

};



#endif  // Classes




