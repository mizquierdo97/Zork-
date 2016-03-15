#include <stdio.h>
#include "player.h"
#include "exit.h"
#include "room.h"

enum direction{
	north,
	south,
	east,
	west,
};


class World;
class Player;
class Room;
class Exit;





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
	bool loop();
	bool open(char * inst, int dir);
	
	

	bool Go(char* inst, int dir);
	

};








