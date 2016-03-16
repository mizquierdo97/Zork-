#include <stdio.h>
#include "player.h"
#include "exit.h"
#include "room.h"
#include "globals.h"

enum direction{
	north,
	south,
	east,
	west,
};



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
	void open(char * inst, int dir);
	void close(char * inst, int dir);
	bool Go(char* inst, int dir);
	void look(char* inst, int dir)const;
	

};








