//#include "Vector.h"
//#include "exit.h"
#ifndef _WORLD
#define _WORLD
#include "entity.h"
#include "vector.h"
#include "exit.h"
#include "object.h"

class Exit;
class Room;
class Player;

enum direction{
	north,
	south,
	east,
	west,
};

class World{
public:
	Vector <Room*> rooms;
	Player* player;
	Vector <Exit*> exits;
	Vector <Object*> objects;

	World(){};
	~World(){};
	void createworld();
	bool loop();
	
};
#endif