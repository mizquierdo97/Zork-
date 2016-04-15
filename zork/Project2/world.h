
#include "room.h"
//#include "exit.h"





class World{
public:
	Vector <Room*> rooms;
	Player* player;
	//Vector <Exit*> exits;
	//Vector <Object*> objects;

	World(){};
	~World(){};
	void createworld();
	
};