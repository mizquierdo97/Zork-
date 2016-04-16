//#include "Vector.h"
//#include "exit.h"
#ifndef _WORLD
#define _WORLD
#include "entity.h"
#include "vector.h"
#include "exit.h"

class Exit;
class Room;
class Player;

class World{
public:
	Vector <Room*> rooms;
	Player* player;
	//Vector <Player*> player;
	Vector <Exit*> exits;
	//Vector <Object*> objects;

	World(){};
	~World(){};
	void createworld();
	bool loop();
	
};
#endif