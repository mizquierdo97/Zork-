#ifndef _EXIT
#define _EXIT
#include "entity.h"

class Exit :public Entity{
public:
	Exit();
	~Exit();
	Room* origin;
	Room* destination;
	bool open;
	int direction;

};
#endif